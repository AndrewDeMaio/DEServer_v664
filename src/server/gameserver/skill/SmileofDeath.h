//////////////////////////////////////////////////////////////////////////////
// Filename    : SmileofDeath.h
// Description : Gentis Dungeon boss skill SKILL_SMILE_OF_DEATH (515)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SMILE_OF_DEATH_HANDLER_H__
#define __SKILL_SMILE_OF_DEATH_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class SmileofDeath
//////////////////////////////////////////////////////////////////////////////

class SmileofDeath : public SkillHandler
{
public:
	SmileofDeath() throw() {}
	~SmileofDeath() throw() {}

public:
	string getSkillHandlerName() const throw() { return "SmileofDeath"; }
	SkillType_t getSkillType() const throw() { return SKILL_SMILE_OF_DEATH; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SmileofDeath g_SmileofDeath;

#endif // __SKILL_SMILE_OF_DEATH_HANDLER_H__
