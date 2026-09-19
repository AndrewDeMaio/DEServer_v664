//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectFlameSight.h
// Written by  :
// Description : Flame Sight buff (effect 631), v9 EffectFlameSight without the DB persistence.
//               Works like EffectLightness for Ousters.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_FLAME_SIGHT__
#define __EFFECT_FLAME_SIGHT__

#include "Effect.h"
#include "ModifyInfo.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectFlameSight
//////////////////////////////////////////////////////////////////////////////

class EffectFlameSight : public Effect
{
public:
	EffectFlameSight(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_FLAME_SIGHT; }

	void affect() throw(Error) {}

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);

	string toString() const throw();
};

//////////////////////////////////////////////////////////////////////////////
// Puts Flame Sight on pCreature (caster or party member): effect + flag, sight update and
// GCAddEffect to the zone. The vision change is added to pMI, or sent to the player when pMI is NULL.
//////////////////////////////////////////////////////////////////////////////
void addFlameSight(Creature* pCreature, Turn_t Duration, ModifyInfo* pMI) throw(Error);

#endif // __EFFECT_FLAME_SIGHT__
