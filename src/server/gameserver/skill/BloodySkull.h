//////////////////////////////////////////////////////////////////////////////
// Filename    : BloodySkull.h
// Written By  : excel96
// Description : Bloody Skull (skill 530, level 171 Vampire). Ported from gameserver_664 (BLOODYSKULL).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_BLOODY_SKULL_HANDLER_H__
#define __SKILL_BLOODY_SKULL_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class BloodySkull;
//////////////////////////////////////////////////////////////////////////////

class BloodySkull : public SkillHandler 
{
public:
	BloodySkull() throw() {}
	~BloodySkull() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "BloodySkull"; }
	SkillType_t getSkillType() const throw() { return SKILL_BLOODY_SKULL; }

	virtual SkillResultType execute(Vampire* pVampire, ZoneCoord_t X, ZoneCoord_t Y,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Vampire* pVampire, ObjectID_t,  VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern BloodySkull g_BloodySkull;

#endif // __SKILL_BLOODY_SKULL_HANDLER_H__
