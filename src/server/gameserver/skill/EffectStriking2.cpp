//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectStriking2.cpp
// Written by  :
// Description : Striking 2 weapon damage buff (effect 622). Same as EffectStriking.
//////////////////////////////////////////////////////////////////////////////

#include "EffectStriking2.h"
#include "Slayer.h"
#include "Player.h"

#include "Gpackets/GCRemoveEffect.h"

EffectStriking2::EffectStriking2(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);
	Assert(pCreature->isSlayer());

	setTarget(pCreature);
	m_DamageBonus = 0;

	__END_CATCH
}

void EffectStriking2::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

void EffectStriking2::affect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

void EffectStriking2::unaffect()
	throw(Error)
{
    Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);
	unaffect(pCreature);
}

void EffectStriking2::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);
	Assert(pCreature->isSlayer());

	pCreature->removeFlag(Effect::EFFECT_CLASS_STRIKING_2);

	Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);

	pSlayer->initAllStatAndSend();

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);
	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_STRIKING_2);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	__END_CATCH
}

void EffectStriking2::unaffect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

string EffectStriking2::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectStriking2("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH
}
