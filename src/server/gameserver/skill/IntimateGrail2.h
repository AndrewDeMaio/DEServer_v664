//////////////////////////////////////////////////////////////////////////////
// Filename    : IntimateGrail2.h
// Written By  : 
// Description : Intimate Grail 2 (skill 522, level 171 Enchant). Ported from the v9 gameserver (IntimateGrail2).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_INTIMATE_GRAIL_2_HANDLER_H__
#define __SKILL_INTIMATE_GRAIL_2_HANDLER_H__

#include "SkillHandler.h"
#include "Creature.h"
//////////////////////////////////////////////////////////////////////////////
// class IntimateGrail2;
//////////////////////////////////////////////////////////////////////////////

class IntimateGrail2 : public SkillHandler 
{
public:
	IntimateGrail2() throw() {}
	~IntimateGrail2() throw() {}
	
public :
    string getSkillHandlerName() const throw() { return "IntimateGrail2"; }
	SkillType_t getSkillType() const throw() { return SKILL_INTIMATE_GRAIL_2; }

	virtual SkillResultType execute(Slayer* pSlayer, ObjectID_t ObjectID,  SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern IntimateGrail2 g_IntimateGrail2;

#endif // __SKILL_INTIMATE_GRAIL_2_HANDLER_H__
