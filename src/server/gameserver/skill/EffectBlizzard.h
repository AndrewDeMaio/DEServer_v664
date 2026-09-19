//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBlizzard.h
// Written by  : elca@ewestsoft.com
// Description : Blizzard / Blizzard 2 tile effect (server-side, uses the Sharp Hail effect class
//               like gameserver_664). EffectSharpHail without the physical hit roll, stops when the caster is gone.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_BLIZZARD__
#define __EFFECT_BLIZZARD__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectBlizzard
//////////////////////////////////////////////////////////////////////////////

class EffectBlizzard : public Effect 
{
public:
	EffectBlizzard(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_PROMINENCE; }

	void affect() throw(Error);
	void unaffect() throw(Error);
	string toString() const throw();

public:
	int getDamage(void) const { return m_Damage; }
	void setDamage(int damage) { m_Damage = damage; }

	Turn_t getTick() const { return m_Tick; }
	void setTick(Turn_t Tick) { m_Tick = Tick; }

	int getLevel(void) const { return m_Level; }
	void setLevel(int level) { m_Level = level; }

	void setForce( bool force ) { m_bForce = force; }
	bool isForce() const { return m_bForce; }

	SkillType_t getSkillType() const { return m_SkillType; }
	void setSkillType( SkillType_t SkillType ) { m_SkillType = SkillType; }

	ObjectID_t getUserObjectID() const { return m_UserObjectID; }
	void setUserObjectID( ObjectID_t UserObjectID ) { m_UserObjectID = UserObjectID; }

private:
	int     m_Damage;
	Turn_t  m_Tick;
	int     m_Level;
	bool	m_bForce;
	SkillType_t	m_SkillType;

	ObjectID_t	m_UserObjectID;
};

#endif // __EFFECT_BLIZZARD__
