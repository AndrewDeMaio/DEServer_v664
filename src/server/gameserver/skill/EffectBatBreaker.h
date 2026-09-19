//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBatBreaker.h
// Written by  : elca@ewestsoft.com
// Description : Bat Breaker ground effect (effect 658). Same as EffectBatStorm1.
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_BAT_BREAKER__
#define __EFFECT_BAT_BREAKER__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectBatBreaker
//////////////////////////////////////////////////////////////////////////////

class EffectBatBreaker : public Effect 
{
public:
	EffectBatBreaker(Zone* pZone, ZoneCoord_t zoneX, ZoneCoord_t zoneY, bool bPlayer = false) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_BAT_BREAKER; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	string toString() const throw();

public:
	int getDamage(void) const { return m_Damage; }
	void setDamage(int damage) { m_Damage = damage; }

	Turn_t getDelay() const { return m_Delay; }
	void setDelay(Turn_t Delay) { m_Delay = Delay; }

//	string getCasterName(void) const { return m_CasterName; }
//	void setCasterName(const string & CasterName ) { m_CasterName = CasterName; }

	ObjectID_t getUserObjectID(void) const { return m_UserObjectID; }
	void setUserObjectID(ObjectID_t UserObjectID ) { m_UserObjectID = UserObjectID; }

	Turn_t getTick() { return m_Tick; }
	void setTick(Turn_t tick) { m_Tick = tick; }

private:
	int     m_Damage;
	Turn_t  m_Delay;
//	string  m_CasterName;
	ObjectID_t   m_UserObjectID;
	bool	m_bPlayer;
	Turn_t	m_Tick;
};

#endif // __EFFECT_BAT_BREAKER__
