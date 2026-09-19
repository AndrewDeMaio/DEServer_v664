//////////////////////////////////////////////////////////////////////////////
// Filename    : DraculeTalonOfDracule.h
// Description : Dracula Castle monster skill SKILL_DRACULE_TALON_OF_DRACULE (544)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_DRACULE_TALON_OF_DRACULE_HANDLER_H__
#define __SKILL_DRACULE_TALON_OF_DRACULE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class DraculeTalonOfDracule
//////////////////////////////////////////////////////////////////////////////

class DraculeTalonOfDracule : public SkillHandler
{
public:
	DraculeTalonOfDracule() throw() {}
	~DraculeTalonOfDracule() throw() {}

public:
	string getSkillHandlerName() const throw() { return "DraculeTalonOfDracule"; }
	SkillType_t getSkillType() const throw() { return SKILL_DRACULE_TALON_OF_DRACULE; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern DraculeTalonOfDracule g_DraculeTalonOfDracule;

#endif // __SKILL_DRACULE_TALON_OF_DRACULE_HANDLER_H__
