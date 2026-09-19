//////////////////////////////////////////////////////////////////////////////
// Filename    : FlameSpike.h
// Written By  : 
// Description : Flame Spike (skill 556, level 181 Ousters). Ported from the v9 gameserver (FlameSpike).
//////////////////////////////////////////////////////////////////////////////

#ifndef __SKILL_FLAME_SPIKE_HANDLER_H__
#define __SKILL_FLAME_SPIKE_HANDLER_H__

#include "SkillHandler.h"

//////////////////////////////////////////////////////////////////////////////
// class FlameSpike;
//////////////////////////////////////////////////////////////////////////////

class FlameSpike : public SkillHandler 
{
public:
	FlameSpike() throw() {}
	~FlameSpike() throw() {}
	
public:
    string getSkillHandlerName() const throw() { return "FlameSpike"; }
	SkillType_t getSkillType() const throw() { return SKILL_FLAME_SPIKE; }

	virtual SkillResultType execute(Ousters* pOusters, ZoneCoord_t X, ZoneCoord_t Y, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	virtual SkillResultType execute(Ousters* pOusters, ObjectID_t, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID) throw(Error);
	void computeOutput(const SkillInput& input, SkillOutput& output);
};

// global variable declaration
extern FlameSpike g_FlameSpike;

#endif // __SKILL_FLAME_SPIKE_HANDLER_H__
