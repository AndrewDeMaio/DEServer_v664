//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectSatelliteBombAim2.h
// Written by  : bezz
// Description : Satellite Bomb 2 aim (effect 618). Same as EffectSatelliteBombAim, DEX-based.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_SATELLITE_BOMB_AIM_2__
#define __EFFECT_SATELLITE_BOMB_AIM_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectSatelliteBombAim2
//////////////////////////////////////////////////////////////////////////////

class EffectSatelliteBombAim2 : public Effect 
{
public:
	EffectSatelliteBombAim2(Creature* pCreature, Zone* pZone, ZoneCoord_t x, ZoneCoord_t y) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_SATELLITE_BOMB_AIM_2; }

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
