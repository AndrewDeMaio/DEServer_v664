//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectFolletFlame.h
// Description : The burn left by Follet's SKILL_FOLLET_POISON_FRAME. It shows as the
//               Fierce Flame status (so the fire the client draws matches what hits
//               you) but, unlike EffectFierceFlame, it works with a monster caster
//               and does not spread to neighbouring tiles.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_FOLLET_FLAME_H__
#define __EFFECT_FOLLET_FLAME_H__

#include "Effect.h"
#include "Creature.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectFolletFlame
//////////////////////////////////////////////////////////////////////////////

class EffectFolletFlame : public Effect
{
public:
	EffectFolletFlame(Creature* pCreature) throw(Error);

public:
	EffectClass getEffectClass() const throw() { return EFFECT_CLASS_FIERCE_FLAME; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	string toString() const throw();

public:
	void setUserOID(ObjectID_t UserOID) { m_UserOID = UserOID; }
	void setDamage(Damage_t Damage) { m_Damage = Damage; }
	void setTick(Turn_t Tick) { m_Tick = Tick; }

private:
	ObjectID_t	m_UserOID;
	Damage_t	m_Damage;
	Turn_t		m_Tick;
};

#endif // __EFFECT_FOLLET_FLAME_H__
