//////////////////////////////////////////////////////////////////////////////
// Filename    : DraculeBloodyCarpe.h
// Description : Dracula Castle monster skill SKILL_DRACULE_BLOODY_CARPE (546)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_DRACULE_BLOODY_CARPE_HANDLER_H__
#define __SKILL_DRACULE_BLOODY_CARPE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class DraculeBloodyCarpe
//////////////////////////////////////////////////////////////////////////////

class DraculeBloodyCarpe : public SkillHandler
{
public:
	DraculeBloodyCarpe() throw() {}
	~DraculeBloodyCarpe() throw() {}

public:
	string getSkillHandlerName() const throw() { return "DraculeBloodyCarpe"; }
	SkillType_t getSkillType() const throw() { return SKILL_DRACULE_BLOODY_CARPE; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern DraculeBloodyCarpe g_DraculeBloodyCarpe;

#endif // __SKILL_DRACULE_BLOODY_CARPE_HANDLER_H__
