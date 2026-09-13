//////////////////////////////////////////////////////////////////////////////
// Filename    : BifronzeMagic.h
// Description : Ruper Island monster skill SKILL_BIRFRONZE_MAGIC (508)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BIFRONZE_MAGIC_HANDLER_H__
#define __SKILL_BIFRONZE_MAGIC_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class BifronzeMagic
//////////////////////////////////////////////////////////////////////////////

class BifronzeMagic : public SkillHandler
{
public:
	BifronzeMagic() throw() {}
	~BifronzeMagic() throw() {}

public:
	string getSkillHandlerName() const throw() { return "BifronzeMagic"; }
	SkillType_t getSkillType() const throw() { return SKILL_BIRFRONZE_MAGIC; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BifronzeMagic g_BifronzeMagic;

#endif // __SKILL_BIFRONZE_MAGIC_HANDLER_H__
