//////////////////////////////////////////////////////////////////////////////
// Filename    : Blizzard.h
// Written By  : 
// Description : Blizzard (skill 557, level 181 Ousters). Ported from the v9 gameserver (Blizzard).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BLIZZARD_HANDLER_H__
#define __SKILL_BLIZZARD_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Blizzard;
//////////////////////////////////////////////////////////////////////////////

class Blizzard : public SkillHandler 
{
public:
	Blizzard() throw() {}
	~Blizzard() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "Blizzard"; }
	SkillType_t getSkillType() const throw() { return SKILL_BLIZZARD; }

	virtual SkillResultType execute(Ousters* pOusters, ZoneCoord_t X, ZoneCoord_t Y, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Ousters* pOusters, ObjectID_t, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Blizzard g_Blizzard;

#endif // __SKILL_BLIZZARD_HANDLER_H__
