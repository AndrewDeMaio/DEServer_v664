//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectGloryGround.h
// Written by  :
// Description : Glory Ground tile (effect 624). Each tick heals the Slayers on its tile and hurts
//               the enemies on it. Based on EffectRegeneration and v9 EffectGloryGround.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_GLORY_GROUND__
#define __EFFECT_GLORY_GROUND__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectGloryGround
//////////////////////////////////////////////////////////////////////////////

class EffectGloryGround : public Effect
{
public:
	EffectGloryGround(Zone* pZone, ZoneCoord_t X, ZoneCoord_t Y) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_GLORY_GROUND; }

	void affect() throw(Error);
	void affect(Zone* pZone, ZoneCoord_t X, ZoneCoord_t Y) throw(Error);

	void unaffect() throw(Error);

	string toString() const throw();

public:
	Damage_t getDamage() const { return m_Damage; }
	void setDamage( Damage_t damage ) { m_Damage = damage; }

	void setDelay(Turn_t delay) { m_Delay = delay; }
	Turn_t getDelay() const { return m_Delay; }

	void setUserObjectID(ObjectID_t oid) { m_UserObjectID = oid; }
	ObjectID_t getUserObjectID() const { return m_UserObjectID; }

private:
	Turn_t		m_Delay;
	Damage_t	m_Damage;
	ObjectID_t	m_UserObjectID;
};

#endif
