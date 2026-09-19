//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectRageOfBlood.h
// Written by  :
// Description : Rage of Blood regeneration buff (effect 629), v9 EffectRageOfBlood.
//               The HP regeneration is done by Vampire::heartbeat while the flag is set.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_RAGE_OF_BLOOD__
#define __EFFECT_RAGE_OF_BLOOD__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectRageOfBlood
//////////////////////////////////////////////////////////////////////////////

class EffectRageOfBlood : public Effect
{
public:
	EffectRageOfBlood(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_RAGE_OF_BLOOD; }

	void affect() throw(Error) {}

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);

	string toString() const throw();
};

#endif // __EFFECT_RAGE_OF_BLOOD__
