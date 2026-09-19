//////////////////////////////////////////////////////////////////////////////
// Filename    : CrushingStorm.h
// Written By  : excel96
// Description : Crushing Storm (skill 520, level 171 Sword). Ported from the v9 gameserver (Crushingstorm).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_CRUSHING_STORM_HANDLER_H__
#define __SKILL_CRUSHING_STORM_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class CrushingStorm;
//////////////////////////////////////////////////////////////////////////////

class CrushingStorm : public SkillHandler 
{
public:
	CrushingStorm() throw() {}
	~CrushingStorm() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "CrushingStorm"; }
	SkillType_t getSkillType() const throw() { return SKILL_CRUSHING_STORM; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, ZoneCoord_t X, ZoneCoord_t Y, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern CrushingStorm g_CrushingStorm;

#endif // __SKILL_CRUSHING_STORM_HANDLER_H__
