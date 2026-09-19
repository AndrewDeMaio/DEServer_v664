//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectCrushingStorm.h
// Written by  : bezz
// Description : Crushing Storm field tile (effect 633). Same as EffectSwordOfThor.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_CRUSHING_STORM__
#define __EFFECT_CRUSHING_STORM__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectCrushingStorm
//////////////////////////////////////////////////////////////////////////////

class EffectCrushingStorm : public Effect 
{
public:
	EffectCrushingStorm(Zone* pZone, ZoneCoord_t X, ZoneCoord_t Y) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_CRUSHING_STORM; }

	void unaffect() throw(Error);

	string toString() const throw();

public:
	Level_t getLevel() const { return m_Level; }
	void setLevel( Level_t level ) { m_Level = level; }
	
private:
	Level_t m_Level;
};

#endif
