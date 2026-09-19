//////////////////////////////////////////////////////////////////////////////
// Filename    : TsarBlueRoseDevil.h
// Description : Dracula Castle monster skill SKILL_TSAR_BLUE_ROSE_DEVIL (541)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_TSAR_BLUE_ROSE_DEVIL_HANDLER_H__
#define __SKILL_TSAR_BLUE_ROSE_DEVIL_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class TsarBlueRoseDevil
//////////////////////////////////////////////////////////////////////////////

class TsarBlueRoseDevil : public SkillHandler
{
public:
	TsarBlueRoseDevil() throw() {}
	~TsarBlueRoseDevil() throw() {}

public:
	string getSkillHandlerName() const throw() { return "TsarBlueRoseDevil"; }
	SkillType_t getSkillType() const throw() { return SKILL_TSAR_BLUE_ROSE_DEVIL; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern TsarBlueRoseDevil g_TsarBlueRoseDevil;

#endif // __SKILL_TSAR_BLUE_ROSE_DEVIL_HANDLER_H__
