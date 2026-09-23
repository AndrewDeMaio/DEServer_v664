//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectFolletFlame.cpp
// Description : See EffectFolletFlame.h. The per-tick damage follows EffectPoison
//               (one setDamage per race, nothing in safe zones), the status and its
//               removal follow EffectFierceFlame.
//////////////////////////////////////////////////////////////////////////////

#include "EffectFolletFlame.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Monster.h"
#include "Player.h"
#include "SkillUtil.h"
#include "Zone.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCRemoveEffect.h"

EffectFolletFlame::EffectFolletFlame(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	m_pTarget = pCreature;
	m_UserOID = 0;
	m_Damage  = 0;
	m_Tick    = 10;

	__END_CATCH
}

void EffectFolletFlame::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	affect(pCreature);

	__END_CATCH
}

void EffectFolletFlame::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	Creature* pCastCreature = pZone->getCreature(m_UserOID);

	// The tile's level, not the zone's: Dracula Castle 1F is ZoneInfo.Level 0
	// with its safe zone in the .ssi, so the zone-wide level never read as safe
	// and the burn kept ticking after the target stepped into the safe zone.
	if (!(pZone->getZoneLevel(pCreature->getX(), pCreature->getY()) & SAFE_ZONE) && canAttack(pCastCreature, pCreature))
	{
		if (pCreature->isSlayer())
		{
			Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

			GCModifyInformation gcMI;
			::setDamage(pSlayer, m_Damage, pCastCreature, SKILL_FOLLET_POISON_FRAME, &gcMI);
			pSlayer->getPlayer()->sendPacket(&gcMI);
		}
		else if (pCreature->isVampire())
		{
			Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

			GCModifyInformation gcMI;
			::setDamage(pVampire, m_Damage, pCastCreature, SKILL_FOLLET_POISON_FRAME, &gcMI);
			pVampire->getPlayer()->sendPacket(&gcMI);
		}
		else if (pCreature->isOusters())
		{
			Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);

			GCModifyInformation gcMI;
			::setDamage(pOusters, m_Damage, pCastCreature, SKILL_FOLLET_POISON_FRAME, &gcMI);
			pOusters->getPlayer()->sendPacket(&gcMI);
		}
		else if (pCreature->isMonster())
		{
			Monster* pMonster = dynamic_cast<Monster*>(pCreature);

			::setDamage(pMonster, m_Damage, pCastCreature, SKILL_FOLLET_POISON_FRAME);
		}
	}

	setNextTime(m_Tick);

	__END_CATCH
}

void EffectFolletFlame::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);
	pCreature->removeFlag(Effect::EFFECT_CLASS_FIERCE_FLAME);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_FIERCE_FLAME);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	__END_CATCH
}

void EffectFolletFlame::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

string EffectFolletFlame::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectFolletFlame("
		<< "ObjectID:" << getObjectID()
		<< ",Damage:" << (int)m_Damage
		<< ")";
	return msg.toString();

	__END_CATCH
}
