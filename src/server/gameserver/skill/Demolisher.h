//////////////////////////////////////////////////////////////////////////////
// Filename    : Demolisher.h
// Written By  : excel96
// Description : Demolisher (skill 558, level 181 Ousters). An upgraded Destinies.
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_DEMOLISHER_HANDLER_H__
#define __SKILL_DEMOLISHER_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class Demolisher;
//////////////////////////////////////////////////////////////////////////////

class Demolisher: public SkillHandler 
{
public:
	Demolisher() throw() {}
	~Demolisher() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "Demolisher"; }

	SkillType_t getSkillType() const throw() { return SKILL_DEMOLISHER; }

	virtual SkillResultType execute(Ousters* pOusters, ObjectID_t targetObject, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern Demolisher g_Demolisher;

#endif // __SKILL_DEMOLISHER_HANDLER_H__
