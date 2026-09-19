//////////////////////////////////////////////////////////////////////////////
// Filename    : DraculeBloodyScarify2.h
// Description : Dracula Castle monster skill SKILL_DRACULE_BLOODY_SCARIFY_2 (545)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_DRACULE_BLOODY_SCARIFY_2_HANDLER_H__
#define __SKILL_DRACULE_BLOODY_SCARIFY_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class DraculeBloodyScarify2
//////////////////////////////////////////////////////////////////////////////

class DraculeBloodyScarify2 : public SkillHandler
{
public:
	DraculeBloodyScarify2() throw() {}
	~DraculeBloodyScarify2() throw() {}

public:
	string getSkillHandlerName() const throw() { return "DraculeBloodyScarify2"; }
	SkillType_t getSkillType() const throw() { return SKILL_DRACULE_BLOODY_SCARIFY_2; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern DraculeBloodyScarify2 g_DraculeBloodyScarify2;

#endif // __SKILL_DRACULE_BLOODY_SCARIFY_2_HANDLER_H__
