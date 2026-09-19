//////////////////////////////////////////////////////////////////////////////
// Filename    : FolletPoisonFrame.h
// Description : Dracula Castle monster skill SKILL_FOLLET_POISON_FRAME (542)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_FOLLET_POISON_FRAME_HANDLER_H__
#define __SKILL_FOLLET_POISON_FRAME_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class FolletPoisonFrame
//////////////////////////////////////////////////////////////////////////////

class FolletPoisonFrame : public SkillHandler
{
public:
	FolletPoisonFrame() throw() {}
	~FolletPoisonFrame() throw() {}

public:
	string getSkillHandlerName() const throw() { return "FolletPoisonFrame"; }
	SkillType_t getSkillType() const throw() { return SKILL_FOLLET_POISON_FRAME; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern FolletPoisonFrame g_FolletPoisonFrame;

#endif // __SKILL_FOLLET_POISON_FRAME_HANDLER_H__
