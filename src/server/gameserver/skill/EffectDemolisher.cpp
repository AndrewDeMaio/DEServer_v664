//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectDemolisher.cpp
// Written by  :
// Description : Demolisher chain (server-side, no effect class like EffectDestinies). One second after
//               the main hit it strikes up to 10 other enemies within 5 tiles of the first target.
//               Same as EffectDestinies except: any attackable enemy (Destinies: the same kind as the
//               first target), 11x11 tiles (Destinies: 7x7), the first target is not hit again, and the
//               first target is looked up by object id instead of keeping a pointer to it.
//////////////////////////////////////////////////////////////////////////////

#include "EffectDemolisher.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"
#include "ZoneUtil.h"
#include "Zone.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCSkillToObjectOK4.h"
#include "Gpackets/GCSkillToObjectOK6.h"

#ifdef VERSION_SKILL_1
	#include "HitRoll.h"
#endif

static const int DEMOLISHER_CHAIN_TILES   = 121;	// 11x11, walked as a spiral from the first target
static const int DEMOLISHER_CHAIN_TARGETS = 10;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectDemolisher::EffectDemolisher(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	m_pTarget = pCreature;
	m_Damage = 0;
	m_FirstTargetOID = 0;
	m_FirstX = 0;
	m_FirstY = 0;

	__END_CATCH
}

void EffectDemolisher::setChainTarget( Creature* pCreature )
{
	if ( pCreature == NULL ) return;

	m_FirstTargetOID = pCreature->getObjectID();
	m_FirstX = pCreature->getX();
	m_FirstY = pCreature->getY();
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectDemolisher::affect()
	throw(Error)
{
	__BEGIN_TRY

	setDeadline(0);

	Creature* pCaster = dynamic_cast<Creature*>(m_pTarget);
	if ( pCaster == NULL ) return;

	Zone* pZone = pCaster->getZone();
	if ( pZone == NULL ) return;

	// the chain spreads from where the first target stands now (or stood, if it is gone)
	int cx = m_FirstX;
	int cy = m_FirstY;

	Creature* pFirstTarget = pZone->getCreature( m_FirstTargetOID );
	if ( pFirstTarget != NULL )
	{
		cx = pFirstTarget->getX();
		cy = pFirstTarget->getY();
	}

	int targetNum = 0;

	int tx = cx;
	int ty = cy;
	int sx = 1;
	int sy = 0;
	int maxCount = 1;
	int count = 1;
	int checkCount = DEMOLISHER_CHAIN_TILES;

	VSRect rect( 0, 0, pZone->getWidth()-1, pZone->getHeight()-1 );

	do
	{
		if ( rect.ptInRect( tx, ty ) )
		{
			Tile& tile = pZone->getTile( tx, ty );

			// copy first: a hit can kill and remove the creature from the tile
			list<Creature*> targets;

			slist<Object*>& olist = tile.getObjectList();
			slist<Object*>::iterator itr = olist.begin();

			for ( ; itr != olist.end() ; ++itr )
			{
				Object* pObject = *itr;
				if ( pObject == NULL || pObject->getObjectClass() != Object::OBJECT_CLASS_CREATURE ) continue;

				Creature* pCreature = dynamic_cast<Creature*>(pObject);
				if ( pCreature == NULL
					|| pCreature == pCaster
					|| pCreature->getObjectID() == m_FirstTargetOID
					|| pCreature->isNPC()
					|| pCreature->isDead()
					|| pCreature->isFlag(Effect::EFFECT_CLASS_COMA)
					|| !canAttack( pCaster, pCreature )
					|| !checkZoneLevelToHitTarget( pCreature ) )
				{
					continue;
				}

				targets.push_back( pCreature );
			}

			list<Creature*>::iterator titr = targets.begin();
			for ( ; titr != targets.end() ; ++titr )
			{
				affect( *titr );

				if ( ++targetNum >= DEMOLISHER_CHAIN_TARGETS )
					return;
			}
		}

		tx += sx;
		ty += sy;

		if ( --count == 0 )
		{
			if ( sx == 0 ) maxCount++;

			int temp = sx;
			sx = -sy;
			sy = temp;

			count = maxCount;
		}
	} while ( --checkCount );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectDemolisher::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	if ( pCreature == NULL ) return;

	Zone* pZone = pCreature->getZone();
	Assert( pZone != NULL );

	Ousters* pOusters = dynamic_cast<Ousters*>(m_pTarget);
	if ( pOusters == NULL ) return;

	GCModifyInformation gcMI, gcAttackerMI;

	if ( canAttack( pOusters, pCreature )
	&& !(pZone->getZoneLevel() & COMPLETE_SAFE_ZONE)
#ifdef VERSION_SKILL_1
	&& HitRoll::isSuccessMagic( pOusters, pCreature )
#endif
	   )
	{
#ifndef VERSION_SKILL_1
		Damage_t damage = computeMagicDamage( pCreature, computeOustersMagicDamage( pOusters, pCreature, getDamage(), SKILL_DEMOLISHER ), SKILL_DEMOLISHER );
#else
		Damage_t damage = getDamage();
#endif
		if ( pCreature->isPC() )
		{
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);

			::setDamage( pPC, damage, pOusters, SKILL_DEMOLISHER, &gcMI, &gcAttackerMI, true, false );
			pPC->getPlayer()->sendPacket( &gcMI );
		}
		else if ( pCreature->isMonster() )
		{
			::setDamage( pCreature, damage, pOusters, SKILL_DEMOLISHER, NULL, &gcAttackerMI, true, false );

			Monster* pMonster = dynamic_cast<Monster*>(pCreature);
			if ( pMonster != NULL ) pMonster->addEnemy( pOusters );
		}
		else return;

		computeAlignmentChange(pCreature, damage, pOusters, &gcMI, &gcAttackerMI);
		increaseAlignment(pOusters, pCreature, gcAttackerMI);

		if (pCreature->isDead())
		{
			int exp = computeCreatureExp(pCreature, 100, pOusters);
			shareOustersExp(pOusters, exp, gcAttackerMI);
		}

		pOusters->getPlayer()->sendPacket( &gcAttackerMI );

		GCSkillToObjectOK4 gcOK;
		gcOK.setTargetObjectID( pCreature->getObjectID() );
		gcOK.setSkillType( SKILL_DEMOLISHER );

		pZone->broadcastPacket( pCreature->getX(), pCreature->getY(), &gcOK, pCreature );

		if ( pCreature->isPC() )
		{
			GCSkillToObjectOK6 gcOK6;
			gcOK6.setXY( pCreature->getX(), pCreature->getY() );
			gcOK6.setSkillType( SKILL_DEMOLISHER );

			pCreature->getPlayer()->sendPacket( &gcOK6 );
		}
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectDemolisher::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectDemolisher("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH
}
