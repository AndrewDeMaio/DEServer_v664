//////////////////////////////////////////////////////////////////////////////
// Filename    : Blizzard2.h
// Written By  : 
// Description : Blizzard 2 (skill 698, level 181 Ousters). Ported from the v9 gameserver (Blizzard2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BLIZZARD_2_HANDLER_H__
#define __SKILL_BLIZZARD_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Blizzard2;
//////////////////////////////////////////////////////////////////////////////

class Blizzard2 : public SkillHandler 
{
public:
	Blizzard2() throw() {}
	~Blizzard2() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "Blizzard2"; }
	SkillType_t getSkillType() const throw() { return SKILL_BLIZZARD_2; }

	virtual SkillResultType execute(Ousters* pOusters, ZoneCoord_t X, ZoneCoord_t Y, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Ousters* pOusters, ObjectID_t, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Blizzard2 g_Blizzard2;

#endif // __SKILL_BLIZZARD_2_HANDLER_H__
