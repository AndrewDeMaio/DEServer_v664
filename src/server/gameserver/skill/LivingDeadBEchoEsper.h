//////////////////////////////////////////////////////////////////////////////
// Filename    : LivingDeadBEchoEsper.h
// Description : Dracula Castle monster skill SKILL_LIVINGDEAD_B_ECHO_ESPER (539)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_LIVINGDEAD_B_ECHO_ESPER_HANDLER_H__
#define __SKILL_LIVINGDEAD_B_ECHO_ESPER_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class LivingDeadBEchoEsper
//////////////////////////////////////////////////////////////////////////////

class LivingDeadBEchoEsper : public SkillHandler
{
public:
	LivingDeadBEchoEsper() throw() {}
	~LivingDeadBEchoEsper() throw() {}

public:
	string getSkillHandlerName() const throw() { return "LivingDeadBEchoEsper"; }
	SkillType_t getSkillType() const throw() { return SKILL_LIVINGDEAD_B_ECHO_ESPER; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern LivingDeadBEchoEsper g_LivingDeadBEchoEsper;

#endif // __SKILL_LIVINGDEAD_B_ECHO_ESPER_HANDLER_H__
