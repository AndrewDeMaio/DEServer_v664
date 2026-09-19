//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBreathOfDryad.h
// Written by  : crazydog
// Description : Breath of Dryad buff (effect 635), v9 EffectBreathofDryad. Same as EffectSharpChakram.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_BREATH_OF_DRYAD__
#define __EFFECT_BREATH_OF_DRYAD__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectBreathOfDryad
//////////////////////////////////////////////////////////////////////////////

class EffectBreathOfDryad : public Effect 
{
public:
	EffectBreathOfDryad(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_BREATH_OF_DRYAD; }

	void affect() throw(Error){}

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);

	string toString() const throw();
};

#endif // __EFFECT_BREATH_OF_DRYAD__
