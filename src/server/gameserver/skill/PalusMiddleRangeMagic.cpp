//////////////////////////////////////////////////////////////////////////////
// Filename    : PalusMiddleRangeMagic.cpp
// Description : Ruper Island monster skill SKILL_PALUS_MIDDLE_RANGE_MAGIC (509).
//               Recovered from the v9 gameserver binary: a SimpleTileMissileSkill
//               with a 5x5 mask at 100%, magic hit roll and magic damage,
//               Delay 20, Damage = DEX * 0.1.
//
//               v9 exposes this as execute(Monster*, x, y). Live MonsterAI only ever
//               calls execute(Monster*, Creature*), so it aims at the enemy's tile the
//               way BlackAstralMagicCrystal does.
//////////////////////////////////////////////////////////////////////////////

#include "PalusMiddleRangeMagic.h"
#include "SimpleTileMissileSkill.h"
#include "Creature.h"

void PalusMiddleRangeMagic::execute(Monster* pMonster, Creature* pEnemy)
	throw(Error)
{
	__BEGIN_TRY

	if (pEnemy == NULL) return;

	ZoneCoord_t targetX = pEnemy->getX();
	ZoneCoord_t targetY = pEnemy->getY();

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

	for (int i = -2; i <= 2; ++i)
	{
		for (int j = -2; j <= 2; ++j)
		{
			param.addMask(i, j, 100);
		}
	}

	SIMPLE_SKILL_OUTPUT result;

	g_SimpleTileMissileSkill.execute(pMonster, targetX, targetY, param, result);

	__END_CATCH
}

void PalusMiddleRangeMagic::computeOutput(const SkillInput& input, SkillOutput& output)
{
	output.Delay  = 20;
	output.Damage = (int)(input.DEX * 0.1);
}

PalusMiddleRangeMagic g_PalusMiddleRangeMagic;
