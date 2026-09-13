//////////////////////////////////////////////////////////////////////////////
// Filename    : PalusLongRangeMagic.h
// Description : Ruper Island monster skill SKILL_PALUS_LONG_RANGE_MAGIC (510)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_PALUS_LONG_RANGE_MAGIC_HANDLER_H__
#define __SKILL_PALUS_LONG_RANGE_MAGIC_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class PalusLongRangeMagic
//////////////////////////////////////////////////////////////////////////////

class PalusLongRangeMagic : public SkillHandler
{
public:
	PalusLongRangeMagic() throw() {}
	~PalusLongRangeMagic() throw() {}

public:
	string getSkillHandlerName() const throw() { return "PalusLongRangeMagic"; }
	SkillType_t getSkillType() const throw() { return SKILL_PALUS_LONG_RANGE_MAGIC; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern PalusLongRangeMagic g_PalusLongRangeMagic;

#endif // __SKILL_PALUS_LONG_RANGE_MAGIC_HANDLER_H__
