//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectGloryGround.cpp
// Written by  :
// Description : Glory Ground tile (effect 624). Based on EffectRegeneration and v9 EffectGloryGround:
//               Slayers on the tile are healed by the skill damage every tick; enemies on it take
//               that much magic damage from the caster. The field keeps healing after the caster
//               leaves, but stops hurting enemies.
//////////////////////////////////////////////////////////////////////////////

#include "EffectGloryGround.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "ZoneUtil.h"
#include "SkillUtil.h"
#include "Gpackets/GCDeleteEffectFromTile.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCSkillToSelfOK1.h"
#include "Gpackets/GCSkillToSelfOK2.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectGloryGround::EffectGloryGround( Zone* pZone, ZoneCoord_t X, ZoneCoord_t Y )
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = X;
	m_Y = Y;
	m_Delay = 10;
	m_Damage = 0;
	m_UserObjectID = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGloryGround::affect()
	throw(Error)
{
	__BEGIN_TRY

	Assert( m_pZone != NULL );

	affect( m_pZone, m_X, m_Y );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGloryGround::affect(Zone* pZone, ZoneCoord_t X, ZoneCoord_t Y)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pZone != NULL);

	setNextTime( m_Delay );

	VSRect rect( 0, 0, pZone->getWidth() - 1, pZone->getHeight() - 1 );
	if ( !rect.ptInRect( X, Y ) ) return;

	Creature* pCaster = pZone->getCreature( m_UserObjectID );

	// copy the creatures first; damage must not run while walking the tile list
	list<Creature*> cList;
	const slist<Object*>& oList = pZone->getTile( X, Y ).getObjectList();
	for ( slist<Object*>::const_iterator itr = oList.begin(); itr != oList.end(); itr++ )
	{
		Object* pTargetObject = (*itr);
		if ( pTargetObject != NULL && pTargetObject->getObjectClass() == Object::OBJECT_CLASS_CREATURE )
			cList.push_back( dynamic_cast<Creature*>(pTargetObject) );
	}

	for ( list<Creature*>::iterator citr = cList.begin(); citr != cList.end(); citr++ )
	{
		Creature* pCreature = *citr;

		if ( pCreature == NULL || pCreature->isFlag(Effect::EFFECT_CLASS_COMA) || pCreature->isDead() )
			continue;

		if ( pCreature->isSlayer() )
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			HP_t CurrentHP	= pSlayer->getHP( ATTR_CURRENT );
			HP_t MaxHP		= pSlayer->getHP( ATTR_MAX	   );

			if ( CurrentHP >= MaxHP ) continue;

			HP_t RemainHP	= min((int)MaxHP, (int)CurrentHP + m_Damage);
			pSlayer->setHP(RemainHP, ATTR_CURRENT);

			GCModifyInformation gcMI;
			gcMI.addShortData( MODIFY_CURRENT_HP, RemainHP );
			pSlayer->getPlayer()->sendPacket( &gcMI );

			GCSkillToSelfOK1 _GCSkillToSelfOK1;
			_GCSkillToSelfOK1.setSkillType( SKILL_CURE_EFFECT );
			_GCSkillToSelfOK1.setDuration( 0 );
			pSlayer->getPlayer()->sendPacket( &_GCSkillToSelfOK1 );

			GCSkillToSelfOK2 _GCSkillToSelfOK2;
			_GCSkillToSelfOK2.setObjectID( pSlayer->getObjectID() );
			_GCSkillToSelfOK2.setSkillType( SKILL_CURE_EFFECT );
			_GCSkillToSelfOK2.setDuration( 0 );
			pZone->broadcastPacket( X, Y, &_GCSkillToSelfOK2, pCreature );

			GCStatusCurrentHP gcStatusCurrentHP;
			gcStatusCurrentHP.setObjectID( pSlayer->getObjectID() );
			gcStatusCurrentHP.setCurrentHP( RemainHP );
			pZone->broadcastPacket( X, Y, &gcStatusCurrentHP );

			continue;
		}

		// hurting needs the caster in the zone
		if ( pCaster == NULL
			|| pCreature->isNPC()
			|| !canAttack( pCaster, pCreature )
			|| !checkZoneLevelToHitTarget( pCreature ) )
		{
			continue;
		}

		Damage_t Damage = computeMagicDamage( pCreature, m_Damage, SKILL_GLORY_GROUND, false, pCaster );

		if ( pCreature->isPC() )
		{
			GCModifyInformation gcMI;
			::setDamage( pCreature, Damage, pCaster, SKILL_GLORY_GROUND, &gcMI );
			pCreature->getPlayer()->sendPacket( &gcMI );
		}
		else if ( pCreature->isMonster() )
		{
			Monster* pMonster = dynamic_cast<Monster*>(pCreature);
			::setDamage( pMonster, Damage, pCaster, SKILL_GLORY_GROUND );
			pMonster->addEnemy( pCaster );
		}
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectGloryGround::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Tile& tile = m_pZone->getTile( m_X, m_Y );
	tile.deleteEffect( m_ObjectID );

	if ( isBroadcastingEffect() )
	{
		GCDeleteEffectFromTile gcDeleteEffectFromTile;
		gcDeleteEffectFromTile.setXY( m_X, m_Y );
		gcDeleteEffectFromTile.setObjectID( getObjectID() );
		gcDeleteEffectFromTile.setEffectID( getEffectClass() );
		m_pZone->broadcastPacket( m_X, m_Y, &gcDeleteEffectFromTile );
	}

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectGloryGround::toString() const
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectGloryGround("
		<< "Damage:" << (int)m_Damage
		<< ")";
	return msg.toString();

	__END_CATCH
}
