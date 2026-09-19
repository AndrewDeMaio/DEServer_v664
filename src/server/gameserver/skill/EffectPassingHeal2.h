//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectPassingHeal2.h
// Written by  : excel96
// Description : Passing Heal 2 chain heal (effect 625). Same as EffectPassingHeal.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_PASSING_HEAL_2__
#define __EFFECT_PASSING_HEAL_2__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectPassingHeal2
//////////////////////////////////////////////////////////////////////////////

class EffectPassingHeal2 : public Effect 
{
public:
	EffectPassingHeal2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_PASSING_HEAL_2; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	int getPassingCount() const { return m_PassingCount; }
	void setPassingCount(int PassingCount) { m_PassingCount = PassingCount; }

	int getCureCount() const { return m_CureCount; }
	void setCureCount(int CureCount) { m_CureCount = CureCount; }

	int getHealPoint() const { return m_HealPoint; }
	void setHealPoint(int HealPoint) { m_HealPoint = HealPoint; }

	Attr_t getINT() const { return m_INT; }
	void setINT( Attr_t inte ) { m_INT = inte; }

	string toString() const throw();

private:
	int	m_PassingCount;
	int	m_CureCount;
	int	m_HealPoint;
	Attr_t	m_INT;
};

#endif // __EFFECT_PASSING_HEAL_2__
