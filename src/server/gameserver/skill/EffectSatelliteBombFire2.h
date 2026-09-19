//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectSatelliteBombFire2.h
// Written by  : bezz
// Description : Satellite Bomb 2 fire phase (server-only effect class 983). Same as EffectSatelliteBombFire.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_SATELLITE_BOMB_FIRE_2__
#define __EFFECT_SATELLITE_BOMB_FIRE_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectSatelliteBombFire2
//////////////////////////////////////////////////////////////////////////////

class EffectSatelliteBombFire2 : public Effect 
{
public:
	EffectSatelliteBombFire2(Creature* pCreature, Zone* pZone, ZoneCoord_t x, ZoneCoord_t y) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_SATELLITE_BOMB_FIRE_2; }

	void affect() throw(Error){}
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	string toString() const throw();

public:
	void setDEX(Attr_t dex) { m_DEX = dex; }
	Attr_t getDEX() { return m_DEX; }

	void setSkillLevel( Attr_t level ) { m_SkillLevel = level; }
	Attr_t getSkillLevel()  { return m_SkillLevel; }

private:
	Attr_t	m_DEX;
	Attr_t	m_SkillLevel;
};

#endif
