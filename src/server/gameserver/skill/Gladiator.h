//////////////////////////////////////////////////////////////////////////////
// Filename    : Gladiator.h
// Written By  :
// Description : Gladiator (skill 519, level 171 Blade). Ported from the v9 gameserver (GLADIATOR).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_GLADIATOR_HANDLER_H__
#define __SKILL_GLADIATOR_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Gladiator;
//////////////////////////////////////////////////////////////////////////////

class Gladiator : public SkillHandler
{
public:
	Gladiator() throw() {}
	~Gladiator() throw() {}

public :
    string getSkillHandlerName() const throw() { return "Gladiator"; }
	SkillType_t getSkillType() const throw() { return SKILL_GLADIATOR; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Gladiator g_Gladiator;

#endif // __SKILL_GLADIATOR_HANDLER_H__
