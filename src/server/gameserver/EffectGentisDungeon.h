//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectMenegrothDoungeon.h
// Written by  : rappi76
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_GENTIS_DUNGEON__
#define __EFFECT_GENTIS_DUNGEON__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectGentisDungeon
//////////////////////////////////////////////////////////////////////////////

class EffectGentisDungeon : public Effect 
{
public:
	EffectGentisDungeon(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_GENTIS_DUNGEON; }

	void affect(Creature* pCreature) throw(Error);
	void affect() throw(Error);

	void unaffect(Creature* pCreature) throw(Error);
	void unaffect() throw(Error);

	void setTransportPos(ZoneID_t targetZoneID, ZoneCoord_t  targetX, ZoneCoord_t targetY, bool bTrans) throw(Error);

	string toString() const throw();

	virtual void create( const string& ownerID ) throw(Error);
	virtual void destroy( const string& ownerID ) throw(Error);
	virtual void save( const string& ownerID ) throw(Error);
	
public:

private:
	Creature* m_pCreature;
	ZoneID_t m_targetZoneID;
	ZoneCoord_t m_targetX;
	ZoneCoord_t m_targetY;
	bool		m_bTrans;

};

//////////////////////////////////////////////////////////////////////////////
// class EffectGentisDungeonLoader
//////////////////////////////////////////////////////////////////////////////

class EffectGentisDungeonLoader : public EffectLoader 
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_GENTIS_DUNGEON; }
	virtual string getEffectClassName() const throw() { return "EffectGentisDungeon"; }

public:
	virtual void load(Creature* pCreature) throw(Error);
};

extern EffectGentisDungeonLoader* g_pEffectGentisDungeonLoader;

#endif // __EFFECT_GENTIS_DUNGEON__
