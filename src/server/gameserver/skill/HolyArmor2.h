//////////////////////////////////////////////////////////////////////////////
// Filename    : HolyArmor2.h
// Written By  :
// Description : Holy Armor 2 (skill 523, level 171 Enchant). Ported from the v9 gameserver (HolyArmor2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_HOLY_ARMOR_2_HANDLER_H__
#define __SKILL_HOLY_ARMOR_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class HolyArmor2;
//////////////////////////////////////////////////////////////////////////////

class HolyArmor2 : public SkillHandler
{
public:
	HolyArmor2() throw() {}
	~HolyArmor2() throw() {}

public:
    string getSkillHandlerName() const throw() { return "HolyArmor2"; }
	SkillType_t getSkillType() const throw() { return SKILL_HOLY_ARMOR_2; }

	virtual SkillResultType execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern HolyArmor2 g_HolyArmor2;

#endif // __SKILL_HOLY_ARMOR_2_HANDLER_H__
