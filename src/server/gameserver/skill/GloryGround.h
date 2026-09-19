//////////////////////////////////////////////////////////////////////////////
// Filename    : GloryGround.h
// Written By  :
// Description : Glory Ground (skill 526, level 171 Healing). Ported from the v9 gameserver (GloryGround).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_GLORY_GROUND_HANDLER_H__
#define __SKILL_GLORY_GROUND_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class GloryGround;
//////////////////////////////////////////////////////////////////////////////

class GloryGround : public SkillHandler
{
public:
	GloryGround() throw() {}
	~GloryGround() throw() {}

public:
    string getSkillHandlerName() const throw() { return "GloryGround"; }
	SkillType_t getSkillType() const throw() { return SKILL_GLORY_GROUND; }

	virtual SkillResultType execute( Slayer* pSlayer, ObjectID_t ObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID ) throw(Error);
	virtual SkillResultType execute( Slayer* pSlayer, ZoneCoord_t X, ZoneCoord_t Y, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID ) throw(Error);

	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern GloryGround g_GloryGround;

#endif // __SKILL_GLORY_GROUND_HANDLER_H__
