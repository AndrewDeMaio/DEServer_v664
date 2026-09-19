//////////////////////////////////////////////////////////////////////////////
// Filename    : GreatHeal2.h
// Written By  : elca@ewestsoft.com
// Description : Great Heal 2 (skill 528, level 171 Healing). Ported from the v9 gameserver (GreatHeal2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_GREAT_HEAL_2_HANDLER_H__
#define __SKILL_GREAT_HEAL_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class GreatHeal2;
//////////////////////////////////////////////////////////////////////////////

class GreatHeal2: public SkillHandler 
{
public:
	GreatHeal2() throw() {}
	~GreatHeal2() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "GreatHeal2"; }
	SkillType_t getSkillType() const throw() { return SKILL_GREAT_HEAL_2; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern GreatHeal2 g_GreatHeal2;

#endif // __SKILL_GREAT_HEAL_2_HANDLER_H__
