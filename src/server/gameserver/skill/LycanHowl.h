//////////////////////////////////////////////////////////////////////////////
// Filename    : LycanHowl.h
// Description : Ruper Island boss skill SKILL_LYCAN_HOWL (507)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_LYCAN_HOWL_HANDLER_H__
#define __SKILL_LYCAN_HOWL_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class LycanHowl
//////////////////////////////////////////////////////////////////////////////

class LycanHowl : public SkillHandler
{
public:
	LycanHowl() throw() {}
	~LycanHowl() throw() {}

public:
	string getSkillHandlerName() const throw() { return "LycanHowl"; }
	SkillType_t getSkillType() const throw() { return SKILL_LYCAN_HOWL; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern LycanHowl g_LycanHowl;

#endif // __SKILL_LYCAN_HOWL_HANDLER_H__
