//////////////////////////////////////////////////////////////////////////////
// Filename    : ViciousGuidance.h
// Written By  : excel96
// Description : Vicious Guidance (skill 551, level 181 Enchant). Ported from the v9 gameserver (ViciousGuidance).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_VICIOUS_GUIDANCE_HANDLER_H__
#define __SKILL_VICIOUS_GUIDANCE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class ViciousGuidance;
//////////////////////////////////////////////////////////////////////////////

class ViciousGuidance: public SkillHandler 
{
public:
	ViciousGuidance() throw() {}
	~ViciousGuidance() throw() {}

public:
    string getSkillHandlerName() const throw() { return "ViciousGuidance"; }
	SkillType_t getSkillType() const throw() { return SKILL_VICIOUS_GUIDANCE; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern ViciousGuidance g_ViciousGuidance;

#endif // __SKILL_VICIOUS_GUIDANCE_HANDLER_H__
