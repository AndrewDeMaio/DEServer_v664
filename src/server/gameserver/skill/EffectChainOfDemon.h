//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectChainOfDemon.h
// Written by  :
// Description : Chain of Demon stun (effect 626), v9 EffectChainofDemon. Same as EffectParalyze;
//               the "cannot act" checks look at the flag.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_CHAIN_OF_DEMON__
#define __EFFECT_CHAIN_OF_DEMON__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectChainOfDemon
//////////////////////////////////////////////////////////////////////////////

class EffectChainOfDemon : public Effect
{
public:
	EffectChainOfDemon(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_CHAIN_OF_DEMON; }

	void affect() throw(Error) {}
	void affect(Creature* pCreature) throw(Error) {}

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	string toString() const throw();

public:
	Level_t getLevel() const throw() { return m_Level; }
	void setLevel(Level_t level) throw() { m_Level = level; }

	int getDamageReduceRatio() const { return m_DamageReduceRatio; }
	void setDamageReduceRatio( int ratio ) { m_DamageReduceRatio = ratio; }

private:
	Level_t	m_Level;
	int		m_DamageReduceRatio;
};

#endif // __EFFECT_CHAIN_OF_DEMON__
