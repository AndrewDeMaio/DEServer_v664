//////////////////////////////////////////////////////////////////////////////
// Filename    : DragonHurricane.h
// Written By  : excel96
// Description : Dragon Hurricane (skill 548, level 181 Blade). Ported from the v9 gameserver (DragonHurricane).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_DRAGON_HURRICANE_HANDLER_H__
#define __SKILL_DRAGON_HURRICANE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class DragonHurricane;
//////////////////////////////////////////////////////////////////////////////

class DragonHurricane : public SkillHandler 
{
public:
	DragonHurricane() throw() {}
	~DragonHurricane() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "DragonHurricane"; }
	SkillType_t getSkillType() const throw() { return SKILL_DRAGON_HURRICANE; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern DragonHurricane g_DragonHurricane;

#endif // __SKILL_DRAGON_HURRICANE_HANDLER_H__
