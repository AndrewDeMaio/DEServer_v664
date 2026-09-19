//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectGladiator.h
// Written by  :
// Description : Gladiator buff (effect 616). The caster's own effect carries the protection %, max HP and
//               damage bonuses; the copies shared with party members (isShared) carry only the damage bonus.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_GLADIATOR__
#define __EFFECT_GLADIATOR__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectGladiator
//////////////////////////////////////////////////////////////////////////////

class EffectGladiator : public Effect
{
public:
	EffectGladiator(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_GLADIATOR; }

	void affect() throw(Error) {}
	void affect(Creature* pCreature) throw(Error);
	void affect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) throw(Error);

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect(Zone* pZone, ZoneCoord_t x, ZoneCoord_t y, Object* pObject) throw(Error);
	void unaffect() throw(Error);
	void unaffect(Item* pItem) throw(Error) {}

	string toString() const throw();

public:
	int getProtectionBonus(void) const { return m_ProtectionBonus; }
	void setProtectionBonus(int bonus) { m_ProtectionBonus = bonus; }

	int getHPBonus(void) const { return m_HPBonus; }
	void setHPBonus(int bonus) { m_HPBonus = bonus; }

	int getDamageBonus(void) const { return m_DamageBonus; }
	void setDamageBonus(int bonus) { m_DamageBonus = bonus; }

	bool isShared(void) const { return m_bShared; }
	void setShared(bool bShared) { m_bShared = bShared; }

private :
	int  m_ProtectionBonus;	// percent of current protection (the caster only)
	int  m_HPBonus;			// flat max HP (the caster only)
	int  m_DamageBonus;		// flat, current and max damage
	bool m_bShared;			// received from a party member's Gladiator: damage bonus only
};

#endif // __EFFECT_GLADIATOR__
