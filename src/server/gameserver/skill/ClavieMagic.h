//////////////////////////////////////////////////////////////////////////////
// Filename    : ClavieMagic.h
// Description : Ruper Island monster skill SKILL_CLAVIE_MAGIC (512)
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_CLAVIE_MAGIC_HANDLER_H__
#define __SKILL_CLAVIE_MAGIC_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class ClavieMagic
//////////////////////////////////////////////////////////////////////////////

class ClavieMagic : public SkillHandler
{
public:
	ClavieMagic() throw() {}
	~ClavieMagic() throw() {}

public:
	string getSkillHandlerName() const throw() { return "ClavieMagic"; }
	SkillType_t getSkillType() const throw() { return SKILL_CLAVIE_MAGIC; }

	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern ClavieMagic g_ClavieMagic;

#endif // __SKILL_CLAVIE_MAGIC_HANDLER_H__
