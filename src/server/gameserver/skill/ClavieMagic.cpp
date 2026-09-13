//////////////////////////////////////////////////////////////////////////////
// Filename    : ClavieMagic.cpp
// Description : Ruper Island monster skill SKILL_CLAVIE_MAGIC (512).
//               Recovered from the v9 gameserver binary: a SimpleMissileSkill
//               with physical hit roll and additive damage, one 100% tile mask, Delay 10, Damage = DEX * 0.1.
//////////////////////////////////////////////////////////////////////////////

#include "ClavieMagic.h"
#include "SimpleMissileSkill.h"

void ClavieMagic::execute(Monster* pMonster, Creature* pEnemy)
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

void ClavieMagic::computeOutput(const SkillInput& input, SkillOutput& output)
{
	output.Delay  = 10;
	output.Damage = (int)(input.DEX * 0.1);
}

ClavieMagic g_ClavieMagic;
