//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectRadchia.cpp
// Written by  :
// Description : Life Aqua of Radchia heal field tile (effect 632), v9 Effectradchia: heals the Ousters on the tile
//               every Tick. Same as EffectIceHorizon.
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "EffectRadchia.h"
#include "Slayer.h"
#include "Ousters.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "SkillUtil.h"
#include "ZoneUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCAddEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectRadchia::EffectRadchia(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) 
	throw(Error)
{
	__BEGIN_TRY

	m_pZone = pZone;
	m_X = zoneX;
	m_Y = zoneY;
	m_CasterName ="";
	m_CasterID = 0;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectRadchia::affect()
	throw(Error)
{
	__BEGIN_TRY

	
	Assert(m_pZone != NULL);

	// by bezz. 2003.1.4
	Creature* pCastCreature = m_pZone->getCreature( m_CasterID );

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

			if ( pCreature->isFlag(Effect::EFFECT_CLASS_COMA) )
			{
				continue;
			}
			
			if ( !pCreature->isOusters() )
			{
				continue;
			}

			if (pCreature->getMoveMode() != Creature::MOVE_MODE_FLYING)
			{
				Ousters* pTargetOusters = dynamic_cast<Ousters*>(pCreature);
				Assert( pTargetOusters != NULL );

				GCModifyInformation gcTargetMI;
				GCStatusCurrentHP gcTargetHP;
				
				HP_t final = min( (int)pTargetOusters->getHP(ATTR_MAX), pTargetOusters->getHP() + m_IncreaseAmount );
				if ( final > pTargetOusters->getHP(ATTR_MAX) - pTargetOusters->getSilverDamage() )
				{
					pTargetOusters->setSilverDamage( pTargetOusters->getHP(ATTR_MAX) - final );
					gcTargetMI.addShortData(MODIFY_SILVER_DAMAGE, pTargetOusters->getSilverDamage());
				}

				if ( pTargetOusters->getHP() != final )
				{
					pTargetOusters->setHP( final );
					gcTargetMI.addShortData(MODIFY_CURRENT_HP, final);
				}

				gcTargetHP.setObjectID( pTargetOusters->getObjectID() );
				gcTargetHP.setCurrentHP( final );

				pTargetOusters->getPlayer()->sendPacket( &gcTargetMI );
				m_pZone->broadcastPacket( pTargetOusters->getX(), pTargetOusters->getY(), &gcTargetHP, pTargetOusters );

				GCAddEffect gcAE;
				gcAE.setObjectID( pTargetOusters->getObjectID() );
				gcAE.setEffectID( Effect::EFFECT_CLASS_RADCHIA );
				gcAE.setDuration( 0 );
				m_pZone->broadcastPacket( pTargetOusters->getX(), pTargetOusters->getY(), &gcAE );
			}
		}
	}
	
	setNextTime(m_Tick);

	__END_CATCH 
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectRadchia::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectRadchia::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectRadchia::unaffect()
	throw(Error)
{
	__BEGIN_TRY

    Tile& tile = m_pZone->getTile(m_X, m_Y);
	tile.deleteEffect(m_ObjectID);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectRadchia::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;

	msg << "EffectRadchia("
		<< "ObjectID:" << getObjectID()
		<< ")";

	return msg.toString();

	__END_CATCH

}
