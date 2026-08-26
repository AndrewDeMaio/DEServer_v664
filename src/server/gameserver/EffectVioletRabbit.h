//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectVioletRabbit.h
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_VIOLET_RABBIT__
#define __EFFECT_VIOLET_RABBIT__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectVioletRabbit
//////////////////////////////////////////////////////////////////////////////

class EffectVioletRabbit : public Effect
{
public:
	EffectVioletRabbit(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_VIOLET_RABBIT; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error); 
	void unaffect(Creature* pCreature) throw(Error);

	bool isPossibleAffect () throw(Error); 
	string toString() const throw();

	void setOptionType(int optionType) throw() { m_OptionType = optionType; }
	int getOptionType() const throw() { return m_OptionType; }

private:
	int m_OptionType;
};


#endif 
