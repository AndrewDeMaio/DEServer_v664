//////////////////////////////////////////////////////////////////////////////
// Filename    : Bless2.h
// Written By  :
// Description : Bless 2 (skill 525, level 171 Enchant). Ported from the v9 gameserver (Bless2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BLESS_2_HANDLER_H__
#define __SKILL_BLESS_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Bless2;
//////////////////////////////////////////////////////////////////////////////

class Bless2 : public SkillHandler
{
public:
	Bless2() throw() {}
	~Bless2() throw() {}

public :
    string getSkillHandlerName() const throw() { return "Bless2"; }
	SkillType_t getSkillType() const throw() { return SKILL_BLESS_2; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Bless2 g_Bless2;

#endif // __SKILL_BLESS_2_HANDLER_H__
