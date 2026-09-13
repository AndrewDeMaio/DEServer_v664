//////////////////////////////////////////////////////////////////////////////
// Filename    : PalusMiddleRangeMagic.h
// Description : Ruper Island monster skill SKILL_PALUS_MIDDLE_RANGE_MAGIC (509)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_PALUS_MIDDLE_RANGE_MAGIC_HANDLER_H__
#define __SKILL_PALUS_MIDDLE_RANGE_MAGIC_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class PalusMiddleRangeMagic
//////////////////////////////////////////////////////////////////////////////

class PalusMiddleRangeMagic : public SkillHandler
{
public:
	PalusMiddleRangeMagic() throw() {}
	~PalusMiddleRangeMagic() throw() {}

public:
	string getSkillHandlerName() const throw() { return "PalusMiddleRangeMagic"; }
	SkillType_t getSkillType() const throw() { return SKILL_PALUS_MIDDLE_RANGE_MAGIC; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern PalusMiddleRangeMagic g_PalusMiddleRangeMagic;

#endif // __SKILL_PALUS_MIDDLE_RANGE_MAGIC_HANDLER_H__
