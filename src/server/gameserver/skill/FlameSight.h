//////////////////////////////////////////////////////////////////////////////
// Filename    : FlameSight.h
// Written By  :
// Description : Flame Sight (skill 533, level 171 Ousters). Ported from the v9 gameserver (FlameSight).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_FLAME_SIGHT_HANDLER_H__
#define __SKILL_FLAME_SIGHT_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class FlameSight;
//////////////////////////////////////////////////////////////////////////////

class FlameSight : public SkillHandler
{
public:
	FlameSight() throw() {}
	~FlameSight() throw() {}

public:
    string getSkillHandlerName() const throw() { return "FlameSight"; }
	SkillType_t getSkillType() const throw() { return SKILL_FLAME_SIGHT; }

	virtual SkillResultType execute(Ousters* pOusters, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern FlameSight g_FlameSight;

#endif // __SKILL_FLAME_SIGHT_HANDLER_H__
