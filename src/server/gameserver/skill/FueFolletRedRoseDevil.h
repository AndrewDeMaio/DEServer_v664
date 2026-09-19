//////////////////////////////////////////////////////////////////////////////
// Filename    : FueFolletRedRoseDevil.h
// Description : Dracula Castle monster skill SKILL_FUE_FOLLET_RED_ROSE_DEVIL (543)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_FUE_FOLLET_RED_ROSE_DEVIL_HANDLER_H__
#define __SKILL_FUE_FOLLET_RED_ROSE_DEVIL_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class FueFolletRedRoseDevil
//////////////////////////////////////////////////////////////////////////////

class FueFolletRedRoseDevil : public SkillHandler
{
public:
	FueFolletRedRoseDevil() throw() {}
	~FueFolletRedRoseDevil() throw() {}

public:
	string getSkillHandlerName() const throw() { return "FueFolletRedRoseDevil"; }
	SkillType_t getSkillType() const throw() { return SKILL_FUE_FOLLET_RED_ROSE_DEVIL; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern FueFolletRedRoseDevil g_FueFolletRedRoseDevil;

#endif // __SKILL_FUE_FOLLET_RED_ROSE_DEVIL_HANDLER_H__
