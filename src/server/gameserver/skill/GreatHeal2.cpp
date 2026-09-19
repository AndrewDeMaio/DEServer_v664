//////////////////////////////////////////////////////////////////////////////
// Filename    : GreatHeal2.cpp
// Written by  : elca@ewestsoft.com
// Description : Great Heal 2 (skill 528). Same flow as Great Heal (SimpleCureSkill);
//               formula from the v9 gameserver (GreatHeal2).
//////////////////////////////////////////////////////////////////////////////

#include "GreatHeal2.h"
#include "SimpleCureSkill.h"

static const uint LightBloodDrainLevel = 10000;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
SkillResultType GreatHeal2::execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	SkillInput input(pSlayer, pSkillSlot);
	SkillOutput output;
	input.TargetType = SkillInput::TARGET_OTHER;
	computeOutput(input, output);

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;
	param.Delay         = output.Delay;
	param.STRMultiplier = 1;
	param.DEXMultiplier = 1;
	param.INTMultiplier = 8;
	param.Level         = LightBloodDrainLevel;

	SIMPLE_SKILL_OUTPUT result;

	return g_SimpleCureSkill.execute(pSlayer, TargetObjectID, pSkillSlot, param, result);
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
SkillResultType GreatHeal2::execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	SkillInput input(pSlayer, pSkillSlot);
	SkillOutput output;
	input.TargetType = SkillInput::TARGET_SELF;
	computeOutput(input, output);

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;
	param.Delay         = output.Delay;
	param.STRMultiplier = 1;
	param.DEXMultiplier = 1;
	param.INTMultiplier = 8;
	param.Level         = LightBloodDrainLevel;

	SIMPLE_SKILL_OUTPUT result;

	return g_SimpleCureSkill.execute(pSlayer, pSkillSlot, param, result);

	__END_CATCH
}

GreatHeal2 g_GreatHeal2;
