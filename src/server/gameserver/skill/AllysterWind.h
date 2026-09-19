//////////////////////////////////////////////////////////////////////////////
// Filename    : AllysterWind.h
// Written By  : 
// Description : Allyster Wind (skill 532, level 171 Ousters). Ported from the v9 gameserver (AllysterWind).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_ALLYSTER_WIND_HANDLER_H__
#define __SKILL_ALLYSTER_WIND_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class AllysterWind;
//////////////////////////////////////////////////////////////////////////////

class AllysterWind : public SkillHandler 
{
public:
	AllysterWind() throw() {}
	~AllysterWind() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "AllysterWind"; }
	SkillType_t getSkillType() const throw() { return SKILL_ALLYSTER_WIND; }

	virtual SkillResultType execute(Ousters* pOusters, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern AllysterWind g_AllysterWind;

#endif // __SKILL_ALLYSTER_WIND_HANDLER_H__
