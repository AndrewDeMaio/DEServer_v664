//////////////////////////////////////////////////////////////////////////////
// Filename    : Radchia.h
// Written By  : 
// Description : Life Aqua of Radchia (skill 535, level 171 Ousters). Ported from the v9 gameserver (radchia).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_RADCHIA_HANDLER_H__
#define __SKILL_RADCHIA_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Radchia;
//////////////////////////////////////////////////////////////////////////////

class Radchia : public SkillHandler 
{
public:
	Radchia() throw();
	~Radchia() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "Radchia"; }
	SkillType_t getSkillType() const throw() { return SKILL_RADCHIA; }

	virtual SkillResultType execute(Ousters* pOusters, ZoneCoord_t X, ZoneCoord_t Y, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Ousters* pOusters, ObjectID_t, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);

};

// global variable declaration
extern Radchia g_Radchia;

#endif // __SKILL_RADCHIA_HANDLER_H__
