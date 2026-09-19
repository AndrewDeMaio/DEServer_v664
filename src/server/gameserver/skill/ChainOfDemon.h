//////////////////////////////////////////////////////////////////////////////
// Filename    : ChainOfDemon.h
// Written By  :
// Description : Chain of Demon (skill 529, level 171 Vampire). Ported from the v9 gameserver (ChainofDemon).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_CHAIN_OF_DEMON_HANDLER_H__
#define __SKILL_CHAIN_OF_DEMON_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class ChainOfDemon;
//////////////////////////////////////////////////////////////////////////////

class ChainOfDemon: public SkillHandler
{
public:
	ChainOfDemon() throw() {}
	~ChainOfDemon() throw() {}

public:
    string getSkillHandlerName() const throw() { return "ChainOfDemon"; }
	SkillType_t getSkillType() const throw() { return SKILL_CHAIN_OF_DEMON; }

	virtual SkillResultType execute(Vampire* pVampire, ObjectID_t targetObject, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern ChainOfDemon g_ChainOfDemon;

#endif // __SKILL_CHAIN_OF_DEMON_HANDLER_H__
