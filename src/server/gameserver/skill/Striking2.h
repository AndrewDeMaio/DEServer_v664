//////////////////////////////////////////////////////////////////////////////
// Filename    : Striking2.h
// Written By  :
// Description : Striking 2 (skill 524, level 171 Enchant). Ported from the v9 gameserver (Striking2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_STRIKING_2_HANDLER_H__
#define __SKILL_STRIKING_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Striking2;
//////////////////////////////////////////////////////////////////////////////

class Striking2 : public SkillHandler
{
public:
	Striking2() throw() {}
	~Striking2() throw() {}

public:
    string getSkillHandlerName() const throw() { return "Striking2"; }
	SkillType_t getSkillType() const throw() { return SKILL_STRIKING_2; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Striking2 g_Striking2;

#endif // __SKILL_STRIKING_2_HANDLER_H__
