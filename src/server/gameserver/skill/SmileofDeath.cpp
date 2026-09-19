//////////////////////////////////////////////////////////////////////////////
// Filename    : SmileofDeath.cpp
// Description : Gentis Dungeon boss skill SKILL_SMILE_OF_DEATH (515), used by Gentis.
//               Recovered from the v9 gameserver binary: a SimpleTileMissileSkill
//               with a 5x5 mask at 100%, physical hit roll and physical damage
//               added on top of the monster's own damage, Delay 10, Damage = 3500.
//
//               v9 exposes this as execute(Monster*, x, y). Live MonsterAI only ever
//               calls execute(Monster*, Creature*), so it aims at the enemy's tile the
//               way PalusMiddleRangeMagic does.
//
//               Added (not in v9's monster version): each player hit has a 25% chance
//               to be blinded for 2 seconds - EFFECT_CLASS_BLIND, which the client draws
//               as a white screen. v9 only blinds from the player-side
//               transformsmileofdeath skill (always, 4 seconds).
//////////////////////////////////////////////////////////////////////////////

#include "SmileofDeath.h"
#include "SimpleTileMissileSkill.h"
#include "EffectBlind.h"
#include "Creature.h"
#include "Player.h"
#include "Gpackets/GCAddEffect.h"

static const int BLIND_CHANCE_PERCENT = 25;
static const int BLIND_DURATION       = 20;		// 1/10 seconds

void SmileofDeath::execute(Monster* pMonster, Creature* pEnemy)
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
	param.bMagicHitRoll = false;
	param.bMagicDamage  = false;
	param.bAdd          = true;

	for (int i = -2; i <= 2; ++i)
	{
		for (int j = -2; j <= 2; ++j)
		{
			param.addMask(i, j, 100);
		}
	}

	SIMPLE_SKILL_OUTPUT result;

	g_SimpleTileMissileSkill.execute(pMonster, targetX, targetY, param, result);

	if (!result.bSuccess) return;

	for (SIMPLE_SKILL_OUTPUT::TTargetCreatureList::iterator itr = result.targetCreatures.begin();
		 itr != result.targetCreatures.end(); ++itr)
	{
		Creature* pTarget = *itr;

		if (pTarget == NULL || !pTarget->isPC() || pTarget->isFlag(Effect::EFFECT_CLASS_BLIND))
			continue;

		if (rand() % 100 >= BLIND_CHANCE_PERCENT)
			continue;

		EffectBlind* pEffect = new EffectBlind(pTarget);
		pEffect->setDeadline(BLIND_DURATION);
		pTarget->setFlag(Effect::EFFECT_CLASS_BLIND);
		pTarget->addEffect(pEffect);

		GCAddEffect gcAddEffect;
		gcAddEffect.setObjectID(pTarget->getObjectID());
		gcAddEffect.setEffectID(Effect::EFFECT_CLASS_BLIND);
		gcAddEffect.setDuration(BLIND_DURATION);
		pTarget->getPlayer()->sendPacket(&gcAddEffect);
	}

	__END_CATCH
}

void SmileofDeath::computeOutput(const SkillInput& input, SkillOutput& output)
{
	output.Delay  = 10;
	output.Damage = 3500;
}

SmileofDeath g_SmileofDeath;
