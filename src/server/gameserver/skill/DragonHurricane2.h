//////////////////////////////////////////////////////////////////////////////
// Filename    : DragonHurricane2.h
// Written By  : excel96
// Description : Dragon Hurricane 2 (skill 705, level 181 Blade). Ported from the v9 gameserver (DragonHurricane2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_DRAGON_HURRICANE_2_HANDLER_H__
#define __SKILL_DRAGON_HURRICANE_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class DragonHurricane2;
//////////////////////////////////////////////////////////////////////////////

class DragonHurricane2 : public SkillHandler 
{
public:
	DragonHurricane2() throw() {}
	~DragonHurricane2() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "DragonHurricane2"; }
	SkillType_t getSkillType() const throw() { return SKILL_DRAGON_HURRICANE_2; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern DragonHurricane2 g_DragonHurricane2;

#endif // __SKILL_DRAGON_HURRICANE_2_HANDLER_H__
