//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectDemolisher.h
// Written by  :
// Description : Demolisher chain (server-side, no effect class like EffectDestinies). One second after
//               the main hit it strikes up to 10 other enemies within 5 tiles of the first target.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_DEMOLISHER__
#define __EFFECT_DEMOLISHER__

#include "Effect.h"
#include "Creature.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectDemolisher
//////////////////////////////////////////////////////////////////////////////

class EffectDemolisher : public Effect
{
public:
	EffectDemolisher(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_MAX; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error) {}
	void unaffect(Creature* pCreature) throw(Error) {}

	string toString() const throw();

public:
	Damage_t getDamage(void) const { return m_Damage; }
	void setDamage(Damage_t Damage ) { m_Damage = Damage; }

	// the first target: it is not hit again, the chain spreads from where it stands
	void setChainTarget( Creature* pCreature );

private:
	Damage_t	m_Damage;
	ObjectID_t	m_FirstTargetOID;
	ZoneCoord_t	m_FirstX;
	ZoneCoord_t	m_FirstY;
};

#endif // __EFFECT_DEMOLISHER__
