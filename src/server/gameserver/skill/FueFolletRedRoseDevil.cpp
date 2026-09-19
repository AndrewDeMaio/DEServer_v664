//////////////////////////////////////////////////////////////////////////////
// Filename    : FueFolletRedRoseDevil.cpp
// Description : Dracula Castle monster skill SKILL_FUE_FOLLET_RED_ROSE_DEVIL (543), cast by Fue-Follet and Mihai.
//               Recovered from the v9 gameserver binary: a SimpleMissileSkill
//               with physical hit roll and additive damage, one 100% tile mask, Delay 20, Damage = DEX * 0.5.
//////////////////////////////////////////////////////////////////////////////

#include "FueFolletRedRoseDevil.h"
#include "SimpleMissileSkill.h"

void FueFolletRedRoseDevil::execute(Monster* pMonster, Creature* pEnemy)
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
	param.bMagicHitRoll = false;
	param.bMagicDamage  = false;
	param.bAdd          = true;
	param.addMask(0, 0, 100);

	SIMPLE_SKILL_OUTPUT result;

	g_SimpleMissileSkill.execute(pMonster, pEnemy, param, result);

	__END_CATCH
}

void FueFolletRedRoseDevil::computeOutput(const SkillInput& input, SkillOutput& output)
{
	output.Delay  = 20;
	output.Damage = (int)(input.DEX * 0.5);
}

FueFolletRedRoseDevil g_FueFolletRedRoseDevil;
