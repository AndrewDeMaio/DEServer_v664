//////////////////////////////////////////////////////////////////////////////
// Filename    : PassingHeal2.h
// Written By  : excel96
// Description : Passing Heal 2 (skill 527, level 171 Healing). Ported from the v9 gameserver (PassingHeal2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_PASSING_HEAL_2_HANDLER_H__
#define __SKILL_PASSING_HEAL_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class PassingHeal2;
//////////////////////////////////////////////////////////////////////////////

class PassingHeal2: public SkillHandler 
{
public:
	PassingHeal2() throw() {}
	~PassingHeal2() throw() {}

public:
    string getSkillHandlerName() const throw() { return "PassingHeal2"; }
	SkillType_t getSkillType() const throw() { return SKILL_PASSING_HEAL_2; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern PassingHeal2 g_PassingHeal2;

#endif // __SKILL_PASSING_HEAL_2_HANDLER_H__
