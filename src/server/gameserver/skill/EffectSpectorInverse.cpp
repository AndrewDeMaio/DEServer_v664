//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectSpectorInverse.cpp
// Written by  : excel96
// Description : Spector Inverse drain (effect 657). Same as EffectIllusionInversion.
//////////////////////////////////////////////////////////////////////////////

#include "EffectSpectorInverse.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "DB.h"
#include "Player.h"
#include "SkillUtil.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCRemoveEffect.h"

#ifdef VERSION_SKILL_1
	#include "HitRoll.h"
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectSpectorInverse::EffectSpectorInverse(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	m_UserObjectID = 0;
	setTarget(pCreature);
	m_Damage = 10;
	m_Tick = 10;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectSpectorInverse::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	affect(pCreature);

	__END_CATCH 

}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectSpectorInverse::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	// by bezz. 2003.1.4
	Creature* pCastCreature = pZone->getCreature( m_UserObjectID );

//	Damage_t SpectorInverseDamage = m_Damage;
///////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef VERSION_SKILL_1
	Damage_t SpectorInverseDamage = computeMagicDamage(pCreature, m_Damage, SKILL_SPECTOR_INVERSE);
#else
	Damage_t SpectorInverseDamage = m_Damage;

	bool bHitRoll = HitRoll::isSuccessMagic( pCastCreature, pCreature );
#endif

	if ( !(pZone->getZoneLevel() & COMPLETE_SAFE_ZONE) 
#ifdef VERSION_SKILL_1
		&& bHitRoll
#endif
			)
	{
		if (pCreature->isSlayer())
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			GCModifyInformation gcMI;
			::setDamage( pSlayer, SpectorInverseDamage, pCastCreature, SKILL_SPECTOR_INVERSE, &gcMI, NULL, true, false );
			pSlayer->getPlayer()->sendPacket(&gcMI);
		}
		else if (pCreature->isVampire())
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

			GCModifyInformation gcMI;
			::setDamage( pVampire, SpectorInverseDamage, pCastCreature, SKILL_SPECTOR_INVERSE, &gcMI, NULL, true, false );
			pVampire->getPlayer()->sendPacket(&gcMI);
		}
		else if (pCreature->isOusters())
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

			GCModifyInformation gcMI;
			::setDamage( pOusters, SpectorInverseDamage, pCastCreature, SKILL_SPECTOR_INVERSE, &gcMI, NULL, true, false );
			pOusters->getPlayer()->sendPacket(&gcMI);
		}
		else if(pCreature->isMonster())
		{
			Monster* pMonster = dynamic_cast<Monster*>(pCreature);

			::setDamage( pMonster, SpectorInverseDamage, pCastCreature, SKILL_SPECTOR_INVERSE, NULL, NULL, true, false );
		}
	}
	else 
	{
		return;
	}

	GCStatusCurrentHP	pkt;
	Slayer* pSlayer = dynamic_cast<Slayer*>(pCastCreature);

	if( pSlayer == NULL )
		return;

	HP_t RemainHP = HP_t(pSlayer->getHP(ATTR_CURRENT)+(getHealDamage()));

	if( RemainHP >= pSlayer->getHP(ATTR_MAX) )
		RemainHP = pSlayer->getHP(ATTR_MAX);

	pSlayer->setHP( RemainHP, ATTR_CURRENT );

	pkt.setObjectID(pSlayer->getObjectID());
	pkt.setCurrentHP(RemainHP);
	pZone->broadcastPacket( pSlayer->getX(), pSlayer->getY(), &pkt);
	
	setNextTime(m_Tick);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectSpectorInverse::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG
	Zone* pZone = pCreature->getZone();
	Assert( pZone != NULL );

	pCreature->removeFlag(Effect::EFFECT_CLASS_SPECTOR_INVERSE);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_SPECTOR_INVERSE);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	__END_DEBUG
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectSpectorInverse::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectSpectorInverse::toString() const 
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectSpectorInverse("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
