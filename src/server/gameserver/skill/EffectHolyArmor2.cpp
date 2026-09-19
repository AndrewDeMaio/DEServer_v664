//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectHolyArmor2.cpp
// Written by  :
// Description : Holy Armor 2 defense buff (effect 621). Same as EffectHolyArmor.
//////////////////////////////////////////////////////////////////////////////

#include "EffectHolyArmor2.h"
#include "Slayer.h"
#include "Player.h"

#include "Gpackets/GCModifyInformation.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCRemoveEffect.h"

EffectHolyArmor2::EffectHolyArmor2(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);
	m_DefBonus = 0;

	__END_CATCH
}

void EffectHolyArmor2::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

void EffectHolyArmor2::unaffect()
	    throw(Error)
{
    __BEGIN_TRY

    Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
    unaffect(pCreature);

    __END_CATCH
}

void EffectHolyArmor2::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pCreature != NULL);
	Assert(pCreature->isSlayer());

	pCreature->removeFlag(Effect::EFFECT_CLASS_HOLY_ARMOR_2);

	Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

	pSlayer->initAllStatAndSend();

	Zone* pZone = pSlayer->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pSlayer->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_HOLY_ARMOR_2);
	pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(), &gcRemoveEffect);

	__END_DEBUG
	__END_CATCH
}

string EffectHolyArmor2::toString() const
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectHolyArmor2("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
