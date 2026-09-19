//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBlizzard.cpp
// Written by  :
// Description : Blizzard / Blizzard 2 tile effect (server-side, uses the Sharp Hail effect class
//               like gameserver_664). EffectSharpHail without the physical hit roll, stops when the caster is gone.
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "Effect.h"
#include "EffectBlizzard.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"
#include "HitRoll.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectBlizzard::EffectBlizzard(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_UserObjectID = 0;
	m_bForce = false;
	m_SkillType = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBlizzard::affect()
	throw(Error)
{
	__BEGIN_TRY

	
	Assert(m_pZone != NULL);

	Creature * pCastCreature = m_pZone->getCreature( m_UserObjectID );

	if ( pCastCreature == NULL && !isForce() )
	{
		setDeadline(0);

		return;
	}

    Tile& tile = m_pZone->getTile(m_X, m_Y);

    const slist<Object*>& oList = tile.getObjectList();
	slist<Object*>::const_iterator itr = oList.begin();
    for (; itr != oList.end(); itr++) 
	{
		Assert(*itr != NULL);

		Object* pObject = *itr;
		Assert(pObject != NULL);

    	if (pObject->getObjectClass() == Object::OBJECT_CLASS_CREATURE)
		{
			Creature* pCreature = dynamic_cast<Creature*>(pObject);
			Assert(pCreature != NULL);

			if ( pCastCreature != NULL &&
				( !canAttack( pCastCreature, pCreature )
				|| pCreature->isFlag(Effect::EFFECT_CLASS_COMA) 
				|| !canHit( pCastCreature, pCreature, m_SkillType, getLevel() ))
			)
			{
				continue;
			}

			// 2003.1.10 by Sequoia
			if( !checkZoneLevelToHitTarget( pCreature ) ) continue;

			if (pCreature->getMoveMode() != Creature::MOVE_MODE_FLYING)
			{
				GCModifyInformation gcAttackerMI;
				GCModifyInformation gcDefenderMI;

				if (pCreature->isSlayer()) 
				{
					Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

					::setDamage( pSlayer, m_Damage, pCastCreature, m_SkillType, &gcDefenderMI, &gcAttackerMI, true, true );

					Player* pPlayer = pSlayer->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				} 
				else if (pCreature->isVampire())
				{
					Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

					::setDamage( pVampire, m_Damage, pCastCreature, m_SkillType, &gcDefenderMI, &gcAttackerMI, true, true );

					Player* pPlayer = pVampire->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				}
				else if (pCreature->isMonster())
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);
				
					::setDamage( pMonster, m_Damage, pCastCreature, m_SkillType, NULL, &gcAttackerMI, true, true );

					pMonster->addEnemy(pCastCreature);
				}
				else if (pCreature->isOusters() && isForce() )
				{
					Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

					::setDamage( pOusters, m_Damage, pCastCreature, m_SkillType, &gcDefenderMI, &gcAttackerMI, true, true );

					Player* pPlayer = pOusters->getPlayer();
					Assert(pPlayer != NULL);
					pPlayer->sendPacket(&gcDefenderMI);
				}
				else continue;

				if ( pCastCreature != NULL )
				{
					if (pCreature->isDead() && pCastCreature->isOusters())
					{
						Ousters* pCastOusters = dynamic_cast<Ousters*>( pCastCreature );
						Assert( pCastOusters != NULL );

						int exp = computeCreatureExp(pCreature, 100, pCastOusters);
						shareOustersExp(pCastOusters, exp, gcAttackerMI);
					}
				}

				if ( gcAttackerMI.getShortCount() != 0 || gcAttackerMI.getLongCount() != 0 ) pCastCreature->getPlayer()->sendPacket(&gcAttackerMI);
			}
		}
	}
	
	setNextTime(m_Tick);

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectBlizzard::unaffect()
	throw(Error)
{
	__BEGIN_TRY

    Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	__END_CATCH
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectBlizzard::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectBlizzard("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}
