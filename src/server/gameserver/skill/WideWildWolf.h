//////////////////////////////////////////////////////////////////////////////
// Filename    : WideWildWolf.h
// Description : Ruper Island boss skill SKILL_WIDE_WILD_WOLF (513)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_WIDE_WILD_WOLF_HANDLER_H__
#define __SKILL_WIDE_WILD_WOLF_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class WideWildWolf
//////////////////////////////////////////////////////////////////////////////

class WideWildWolf : public SkillHandler
{
public:
	WideWildWolf() throw() {}
	~WideWildWolf() throw() {}

public:
	string getSkillHandlerName() const throw() { return "WideWildWolf"; }
	SkillType_t getSkillType() const throw() { return SKILL_WIDE_WILD_WOLF; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern WideWildWolf g_WideWildWolf;

#endif // __SKILL_WIDE_WILD_WOLF_HANDLER_H__
