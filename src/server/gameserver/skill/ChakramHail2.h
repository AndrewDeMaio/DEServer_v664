//////////////////////////////////////////////////////////////////////////////
// Filename    : ChakramHail2.h
// Written By  : 
// Description : Chakram Hail 2 (skill 700, level 181 Ousters). Ported from the v9 gameserver (ChakramHail2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_CHAKRAM_HAIL_2_HANDLER_H__
#define __SKILL_CHAKRAM_HAIL_2_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class ChakramHail2;
//////////////////////////////////////////////////////////////////////////////

class ChakramHail2 : public SkillHandler 
{
public:
	ChakramHail2() throw() {}
	~ChakramHail2() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "ChakramHail2"; }
	SkillType_t getSkillType() const throw() { return SKILL_CHAKRAM_HAIL_2; }

	virtual SkillResultType execute(Ousters* pOusters, ZoneCoord_t X, ZoneCoord_t Y, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Ousters* pOusters, ObjectID_t, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern ChakramHail2 g_ChakramHail2;

#endif // __SKILL_CHAKRAM_HAIL_2_HANDLER_H__
