//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectShrineShield.h
// Written by  : 
// Description : Doom    effect
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_CASTLE_MIHNEA_SHIELD__
#define __EFFECT_CASTLE_MIHNEA_SHIELD__

#include "Effect.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectCastleMihneaShield
//////////////////////////////////////////////////////////////////////////////
//    .

class EffectCastleMihneaShield : public Effect 
{
public:
	EffectCastleMihneaShield(Creature* pCreature) throw(Error);
	EffectCastleMihneaShield(Item* pItem) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_CASTLE_MIHNEA_SHIELD; }

	void affect() throw(Error) {}
	void affect(Creature* pCreature) throw(Error);
	void affect(Item* pItem) throw(Error);

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect(Item* pItem) throw(Error);
	void unaffect() throw(Error); 

	string toString() const throw();

public:
	int getTick(void) const { return m_Tick; }
	void   setTick(Turn_t Tick) throw() { m_Tick = Tick; }

	int getShrineID() const { return m_ShrineID; }
	void setShrineID(int id) { m_ShrineID = id; }

private:
	int		m_ShrineID;
	Turn_t 	m_Tick;
};

#endif // __EFFECT_DOOM__
