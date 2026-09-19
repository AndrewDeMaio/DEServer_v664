//////////////////////////////////////////////////////////////////////////////
// Filename    : RageOfBlood.h
// Written By  :
// Description : Rage of Blood (skill 531, level 171 Vampire). Ported from the v9 gameserver (RageOfBlood).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_RAGE_OF_BLOOD_HANDLER_H__
#define __SKILL_RAGE_OF_BLOOD_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class RageOfBlood;
//////////////////////////////////////////////////////////////////////////////

class RageOfBlood : public SkillHandler
{
public:
	RageOfBlood() throw() {}
	~RageOfBlood() throw() {}

public:
    string getSkillHandlerName() const throw() { return "RageOfBlood"; }
	SkillType_t getSkillType() const throw() { return SKILL_RAGE_OF_BLOOD; }

	virtual SkillResultType execute(Vampire* pVampire, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern RageOfBlood g_RageOfBlood;

#endif // __SKILL_RAGE_OF_BLOOD_HANDLER_H__
