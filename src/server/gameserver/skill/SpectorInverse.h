//////////////////////////////////////////////////////////////////////////////
// Filename    : SpectorInverse.h
// Written By  : 
// Description : Spector Inverse (skill 552, level 181 Healing). Ported from the v9 gameserver (SpectorInverse).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SPECTOR_INVERSE_HANDLER_H__
#define __SKILL_SPECTOR_INVERSE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class SpectorInverse;
//////////////////////////////////////////////////////////////////////////////

class SpectorInverse : public SkillHandler 
{
public:
	SpectorInverse() throw() {}
	~SpectorInverse() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "SpectorInverse"; }

	SkillType_t getSkillType() const throw() { return SKILL_SPECTOR_INVERSE; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SpectorInverse g_SpectorInverse;

#endif // __SKILL_SPECTOR_INVERSE_HANDLER_H__
