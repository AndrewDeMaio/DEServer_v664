//////////////////////////////////////////////////////////////////////////////
// Filename    : SiusCrash.h
// Description : Ruper Island boss skill SKILL_SIUS_CRASH (506)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SIUS_CRASH_HANDLER_H__
#define __SKILL_SIUS_CRASH_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class SiusCrash
//////////////////////////////////////////////////////////////////////////////

class SiusCrash : public SkillHandler
{
public:
	SiusCrash() throw() {}
	~SiusCrash() throw() {}

public:
	string getSkillHandlerName() const throw() { return "SiusCrash"; }
	SkillType_t getSkillType() const throw() { return SKILL_SIUS_CRASH; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SiusCrash g_SiusCrash;

#endif // __SKILL_SIUS_CRASH_HANDLER_H__
