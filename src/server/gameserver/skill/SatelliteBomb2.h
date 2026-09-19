//////////////////////////////////////////////////////////////////////////////
// Filename    : SatelliteBomb2.h
// Written By  : excel96
// Description : Satellite Bomb 2 (skill 521, level 171 Gun). Ported from the v9 gameserver (SatelliteBomb2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SATELLITE_BOMB_2_HANDLER_H__
#define __SKILL_SATELLITE_BOMB_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class SatelliteBomb2;
//////////////////////////////////////////////////////////////////////////////

class SatelliteBomb2 : public SkillHandler 
{
public:
	SatelliteBomb2() throw() {}
	~SatelliteBomb2() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "SatelliteBomb2"; }
	SkillType_t getSkillType() const throw() { return SKILL_SATELLITE_BOMB_2; }

	virtual SkillResultType execute(Slayer* pSlayer, ZoneCoord_t X, ZoneCoord_t Y,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SatelliteBomb2 g_SatelliteBomb2;

#endif // __SKILL_SATELLITE_BOMB_2_HANDLER_H__
