//////////////////////////////////////////////////////////////////////////////
// Filename    : ShadyDouble.h
// Written By  : excel96
// Description : Shady Double (skill 554, level 181 Vampire). Ported from the v9 gameserver (ShadyDouple).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SHADY_DOUBLE_HANDLER_H__
#define __SKILL_SHADY_DOUBLE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class ShadyDouble;
//////////////////////////////////////////////////////////////////////////////

class ShadyDouble : public SkillHandler 
{
public:
	ShadyDouble() throw() {}
	~ShadyDouble() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "ShadyDouble"; }
	SkillType_t getSkillType() const throw() { return SKILL_SHADY_DOUPLE; }

	virtual SkillResultType execute(Vampire* pVampire, ObjectID_t ObjectID,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern ShadyDouble g_ShadyDouble;

#endif // __SKILL_SHADY_DOUBLE_HANDLER_H__
