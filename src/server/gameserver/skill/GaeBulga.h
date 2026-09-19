//////////////////////////////////////////////////////////////////////////////
// Filename    : GaeBulga.h
// Written By  : elca@ewestsoft.com
// Description : Gae Bulga (skill 550, level 181 Gun). Ported from the v9 gameserver (GaeBulga).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_GAE_BULGA_HANDLER_H__
#define __SKILL_GAE_BULGA_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class GaeBulga;
//////////////////////////////////////////////////////////////////////////////

class GaeBulga : public SkillHandler 
{
public:
	GaeBulga() throw() {}
	~GaeBulga() throw() {}

public:
    string getSkillHandlerName() const throw() { return "GaeBulga"; }
	SkillType_t getSkillType() const throw() { return SKILL_GAE_BULGA; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	void execute(Monster* pMonster, Creature* pEnemy) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern GaeBulga g_GaeBulga;

#endif // __SKILL_GAE_BULGA_HANDLER_H__
