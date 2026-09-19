//////////////////////////////////////////////////////////////////////////////
// Filename    : BreathOfDryad.h
// Written By  : 
// Description : Breath of Dryad (skill 537, level 171 Ousters). Ported from the v9 gameserver (BreathofDryad).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BREATH_OF_DRYAD_HANDLER_H__
#define __SKILL_BREATH_OF_DRYAD_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class BreathOfDryad;
//////////////////////////////////////////////////////////////////////////////

class BreathOfDryad : public SkillHandler 
{
public:
	BreathOfDryad() throw() {}
	~BreathOfDryad() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "BreathOfDryad"; }
	SkillType_t getSkillType() const throw() { return SKILL_BREATH_OF_DRYAD; }

	virtual SkillResultType execute(Ousters* pOusters, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BreathOfDryad g_BreathOfDryad;

#endif // __SKILL_BREATH_OF_DRYAD_HANDLER_H__
