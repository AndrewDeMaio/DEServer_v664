//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectVioletRabbit.h
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_DRAGON_OF_FORCE__
#define __EFFECT_DRAGON_OF_FORCE__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectDragonOfForce
//////////////////////////////////////////////////////////////////////////////

class EffectDragonOfForce : public Effect
{
public:
	EffectDragonOfForce(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_DRAGON_OF_FORCE; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error); 
	void unaffect(Creature* pCreature) throw(Error);

	bool isPossibleAffect () throw(Error); 
	string toString() const throw();

//	void setOptionType(int optionType) throw() { m_OptionType = optionType; }
//	int getOptionType() const throw() { return m_OptionType; }

//private:
//	int m_OptionType;
};


#endif 
