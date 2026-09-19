//////////////////////////////////////////////////////////////////////////////
// Filename    : BlazeWalk2.h
// Written By  : 
// Description : Blaze Walk 2 (skill 518, level 171 Blade). Blaze Walk plus a splash around the target.
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BLAZE_WALK_2_HANDLER_H__
#define __SKILL_BLAZE_WALK_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class BlazeWalk2;
//////////////////////////////////////////////////////////////////////////////

class BlazeWalk2 : public SkillHandler 
{
public:
	BlazeWalk2() throw() {}
	~BlazeWalk2() throw() {}

public :
    string getSkillHandlerName() const throw() { return "BlazeWalk2"; }
	SkillType_t getSkillType() const throw() { return SKILL_BLAZE_WALK_2; }

	virtual SkillResultType execute(Slayer* pSlayer,ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BlazeWalk2 g_BlazeWalk2;

#endif // __SKILL_BLAZE_WALK_2_HANDLER_H__
