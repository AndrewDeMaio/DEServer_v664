//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectChainOfDemon.cpp
// Written by  :
// Description : Chain of Demon stun (effect 626), v9 EffectChainofDemon. Same as EffectParalyze;
//               the "cannot act" checks look at the flag.
//////////////////////////////////////////////////////////////////////////////

#include "EffectChainOfDemon.h"
#include "Creature.h"
#include "Zone.h"
#include "Gpackets/GCRemoveEffect.h"

EffectChainOfDemon::EffectChainOfDemon(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);
	m_Level = 0;
	m_DamageReduceRatio = 0;

	__END_CATCH
}

void EffectChainOfDemon::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);
	pCreature->removeFlag(Effect::EFFECT_CLASS_CHAIN_OF_DEMON);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_CHAIN_OF_DEMON);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	__END_CATCH
}

void EffectChainOfDemon::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

string EffectChainOfDemon::toString() const
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectChainOfDemon("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
