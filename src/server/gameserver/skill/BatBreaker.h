//////////////////////////////////////////////////////////////////////////////
// Filename    : BatBreaker.h
// Written By  : excel96
// Description : Bat Breaker (skill 553, level 181 Vampire). Ported from the v9 gameserver (BatBreaker).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BAT_BREAKER_HANDLER_H__
#define __SKILL_BAT_BREAKER_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class BatBreaker;
//////////////////////////////////////////////////////////////////////////////

class BatBreaker : public SkillHandler 
{
public:
	BatBreaker() throw() {}
	~BatBreaker() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "BatBreaker"; }
	SkillType_t getSkillType() const throw() { return SKILL_BAT_BREAKER; }

	virtual SkillResultType execute(Vampire* pVampire, ZoneCoord_t X, ZoneCoord_t Y,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Vampire* pVampire, ObjectID_t,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BatBreaker g_BatBreaker;

#endif // __SKILL_BAT_BREAKER_HANDLER_H__
