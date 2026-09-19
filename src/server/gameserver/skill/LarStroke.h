//////////////////////////////////////////////////////////////////////////////
// Filename    : LarStroke.h
// Written By  : 
// Description : Lar Stroke (skill 549, level 181 Sword). Ported from the v9 gameserver (LarStroke).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_LAR_STROKE_HANDLER_H__
#define __SKILL_LAR_STROKE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class LarStroke;
//////////////////////////////////////////////////////////////////////////////

class LarStroke : public SkillHandler 
{
public:
	LarStroke() throw() {}
	~LarStroke() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "LarStroke"; }
	SkillType_t getSkillType() const throw() { return SKILL_LAR_STROKE; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern LarStroke g_LarStroke;

#endif // __SKILL_LAR_STROKE_HANDLER_H__
