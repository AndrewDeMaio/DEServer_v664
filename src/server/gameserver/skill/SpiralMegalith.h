//////////////////////////////////////////////////////////////////////////////
// Filename    : SpiralMegalith.h
// Written By  : excel96
// Description : Spiral Megalith (skill 534, level 171 Ousters). Ported from the v9 gameserver (Spiralmegalith).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_SPIRAL_MEGALITH_HANDLER_H__
#define __SKILL_SPIRAL_MEGALITH_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class SpiralMegalith;
//////////////////////////////////////////////////////////////////////////////

class SpiralMegalith: public SkillHandler 
{
public:
	SpiralMegalith() throw() {}
	~SpiralMegalith() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "SpiralMegalith"; }

	SkillType_t getSkillType() const throw() { return SKILL_SPIRAL_MEGALITH; }

	virtual SkillResultType execute(Ousters* pOusters, ObjectID_t targetObject, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern SpiralMegalith g_SpiralMegalith;

#endif // __SKILL_SPIRAL_MEGALITH_HANDLER_H__
