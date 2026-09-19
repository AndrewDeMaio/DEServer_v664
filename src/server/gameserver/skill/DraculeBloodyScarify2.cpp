//////////////////////////////////////////////////////////////////////////////
// Filename    : DraculeBloodyScarify2.cpp
// Description : Dracula Castle monster skill SKILL_DRACULE_BLOODY_SCARIFY_2 (545), cast by Vlad II Dracul.
//               Recovered from the v9 gameserver binary: a SimpleMissileSkill
//               with physical hit roll and additive damage, one 100% tile mask, Delay 20, Damage = DEX * 0.8.
//////////////////////////////////////////////////////////////////////////////

#include "DraculeBloodyScarify2.h"
#include "SimpleMissileSkill.h"

void DraculeBloodyScarify2::execute(Monster* pMonster, Creature* pEnemy)
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

void DraculeBloodyScarify2::computeOutput(const SkillInput& input, SkillOutput& output)
{
	output.Delay  = 20;
	output.Damage = (int)(input.DEX * 0.8);
}

DraculeBloodyScarify2 g_DraculeBloodyScarify2;
