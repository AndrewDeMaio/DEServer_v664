//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectRageOfBlood.cpp
// Written by  :
// Description : Rage of Blood regeneration buff (effect 629), v9 EffectRageOfBlood.
//               The HP regeneration is done by Vampire::heartbeat while the flag is set.
//////////////////////////////////////////////////////////////////////////////

#include "EffectRageOfBlood.h"
#include "Creature.h"
#include "Vampire.h"
#include "Player.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"

EffectRageOfBlood::EffectRageOfBlood(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);

	setTarget(pCreature);

	__END_CATCH
}

void EffectRageOfBlood::unaffect()
	    throw(Error)
{
    __BEGIN_TRY

    Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
    unaffect(pCreature);

    __END_CATCH
}

void EffectRageOfBlood::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pCreature != NULL);
	Assert(pCreature->isVampire());

	pCreature->removeFlag(Effect::EFFECT_CLASS_RAGE_OF_BLOOD);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);
	Assert(pVampire != NULL);

	pVampire->initAllStatAndSend();

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pVampire->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_RAGE_OF_BLOOD);
	pZone->broadcastPacket(pVampire->getX(), pVampire->getY(), &gcRemoveEffect);

	__END_DEBUG
	__END_CATCH
}

string EffectRageOfBlood::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectRageOfBlood("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
