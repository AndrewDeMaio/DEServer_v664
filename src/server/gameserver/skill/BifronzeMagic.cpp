//////////////////////////////////////////////////////////////////////////////
// Filename    : BifronzeMagic.cpp
// Description : Ruper Island monster skill SKILL_BIRFRONZE_MAGIC (508).
//               Recovered from the v9 gameserver binary: a SimpleMissileSkill
//               with magic hit roll and magic damage, one 100% tile mask, Delay 40, Damage = DEX * 0.1.
//////////////////////////////////////////////////////////////////////////////

#include "BifronzeMagic.h"
#include "SimpleMissileSkill.h"

void BifronzeMagic::execute(Monster* pMonster, Creature* pEnemy)
	throw(Error)
{
	__BEGIN_TRY

	if (pEnemy == NULL) return;

	SkillInput input(pMonster);
	SkillOutput output;
	computeOutput(input, output);

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;
	param.Delay         = output.Delay;
	param.ItemClass     = Item::ITEM_CLASS_MAX;
	param.STRMultiplier = 0;
	param.DEXMultiplier = 0;
	param.INTMultiplier = 0;
	param.bMagicHitRoll = true;
	param.bMagicDamage  = true;
	param.bAdd          = false;
	param.addMask(0, 0, 100);

	SIMPLE_SKILL_OUTPUT result;

	g_SimpleMissileSkill.execute(pMonster, pEnemy, param, result);

	__END_CATCH
}

void BifronzeMagic::computeOutput(const SkillInput& input, SkillOutput& output)
{
	output.Delay  = 40;
	output.Damage = (int)(input.DEX * 0.1);
}

BifronzeMagic g_BifronzeMagic;
