//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectAllysterWind.h
// Written by  : crazydog
// Description : Allyster Wind buff (effect 630), v9 EffectAllysterWind. Same as EffectSharpChakram.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_ALLYSTER_WIND__
#define __EFFECT_ALLYSTER_WIND__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectAllysterWind
//////////////////////////////////////////////////////////////////////////////

class EffectAllysterWind : public Effect 
{
public:
	EffectAllysterWind(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_ALLYSTER_WIND; }

	void affect() throw(Error){}

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);

	string toString() const throw();

public:
	void setBonus( uint bonus ) { m_Bonus = bonus; }
	uint getBonus() const { return m_Bonus; }

private:
	uint	m_Bonus;
};

#endif // __EFFECT_ALLYSTER_WIND__
