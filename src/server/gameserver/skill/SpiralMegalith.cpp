//////////////////////////////////////////////////////////////////////////////
// Filename    : SpiralMegalith.cpp
// Written by  : 
// Description : Spiral Megalith (skill 534). Single-target earth magic missile (wristlet). Same flow as the
//               missile part of Destinies; damage from the v9 gameserver (Spiralmegalith).
//////////////////////////////////////////////////////////////////////////////

#include "SpiralMegalith.h"
#include "SimpleMissileSkill.h"
#include "Zone.h"
#include "ZoneUtil.h"
#include "Utility.h"

SkillResultType SpiralMegalith::execute(Ousters* pOusters, ObjectID_t TargetObjectID, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	SkillResultType skillResult;
	
	__BEGIN_TRY

	SkillInput input(pOusters, pOustersSkillSlot);
	SkillOutput output;
	computeOutput(input, output);

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;
	param.Delay         = output.Delay;
	param.ItemClass     = Item::ITEM_CLASS_OUSTERS_WRISTLET;
	param.STRMultiplier = 0;
	param.DEXMultiplier = 0;
	param.INTMultiplier = 0;
	param.bMagicHitRoll = true;
	param.bMagicDamage  = true;
	param.bAdd          = false;

	SIMPLE_SKILL_OUTPUT result;

	skillResult = g_SimpleMissileSkill.execute(pOusters, TargetObjectID, pOustersSkillSlot, param, result, CEffectID);

	__END_CATCH
	
	return skillResult;
}

SpiralMegalith g_SpiralMegalith;
