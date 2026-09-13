//////////////////////////////////////////////////////////////////////////////
// Filename    : GarumMagic.h
// Description : Ruper Island monster skill SKILL_GARUM_MAGIC (511)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_GARUM_MAGIC_HANDLER_H__
#define __SKILL_GARUM_MAGIC_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class GarumMagic
//////////////////////////////////////////////////////////////////////////////

class GarumMagic : public SkillHandler
{
public:
	GarumMagic() throw() {}
	~GarumMagic() throw() {}

public:
	string getSkillHandlerName() const throw() { return "GarumMagic"; }
	SkillType_t getSkillType() const throw() { return SKILL_GARUM_MAGIC; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern GarumMagic g_GarumMagic;

#endif // __SKILL_GARUM_MAGIC_HANDLER_H__
