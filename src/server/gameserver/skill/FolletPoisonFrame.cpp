//////////////////////////////////////////////////////////////////////////////
// Filename    : FolletPoisonFrame.cpp
// Description : Dracula Castle monster skill SKILL_FOLLET_POISON_FRAME (542), cast by Follet.
//               Recovered from the v9 gameserver binary: no hit roll; range and attack checks, then a
//               6 second burn that hits every second for Damage = DEX * 0.5. v9 used its own
//               EffectPoisonFlame; this uses EffectFolletFlame, which shows the Fierce Flame status
//               so the fire the client draws matches the effect.
//////////////////////////////////////////////////////////////////////////////

#include "FolletPoisonFrame.h"
#include "EffectFolletFlame.h"

#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK5.h"
#include "Gpackets/GCSkillToObjectOK6.h"
#include "Gpackets/GCAddEffect.h"

void FolletPoisonFrame::execute(Monster* pMonster, Creature* pEnemy)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pMonster != NULL);
	Assert(pEnemy != NULL);

	try
	{
		Zone* pZone = pMonster->getZone();
		Assert(pZone != NULL);

		GCSkillToObjectOK2 _GCSkillToObjectOK2;
		GCSkillToObjectOK5 _GCSkillToObjectOK5;
		GCSkillToObjectOK6 _GCSkillToObjectOK6;

		SkillType_t SkillType  = getSkillType();
		SkillInfo*  pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);

		bool bRangeCheck = verifyDistance(pMonster, pEnemy, pSkillInfo->getRange());
		bool bCanAttack  = canAttack(pMonster, pEnemy) && !pEnemy->isNPC();
		bool bEffected   = pEnemy->isFlag(Effect::EFFECT_CLASS_FIERCE_FLAME);

		ZoneCoord_t casterX = pMonster->getX();
		ZoneCoord_t casterY = pMonster->getY();
		ZoneCoord_t targetX = pEnemy->getX();
		ZoneCoord_t targetY = pEnemy->getY();

		if (bRangeCheck && bCanAttack && !bEffected)
		{
			bool bCanSeeCaster = canSee(pEnemy, pMonster);

			SkillInput input(pMonster);
			SkillOutput output;
			computeOutput(input, output);

			EffectFolletFlame* pEffect = new EffectFolletFlame(pEnemy);
			pEffect->setUserOID(pMonster->getObjectID());
			pEffect->setDamage(output.Damage);
			pEffect->setTick(output.Tick);
			pEffect->setDeadline(output.Duration);
			pEffect->setNextTime(output.Tick);
			pEnemy->addEffect(pEffect);
			pEnemy->setFlag(Effect::EFFECT_CLASS_FIERCE_FLAME);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pEnemy->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_FIERCE_FLAME);
			gcAddEffect.setDuration(output.Duration);
			pZone->broadcastPacket(targetX, targetY, &gcAddEffect);

			_GCSkillToObjectOK2.setObjectID(pMonster->getObjectID());
			_GCSkillToObjectOK2.setSkillType(SkillType);
			_GCSkillToObjectOK2.setDuration(0);

			_GCSkillToObjectOK5.setObjectID(pMonster->getObjectID());
			_GCSkillToObjectOK5.setTargetObjectID(pEnemy->getObjectID());
			_GCSkillToObjectOK5.setSkillType(SkillType);
			_GCSkillToObjectOK5.setDuration(0);

			_GCSkillToObjectOK6.setXY(casterX, casterY);
			_GCSkillToObjectOK6.setSkillType(SkillType);
			_GCSkillToObjectOK6.setDuration(0);

			if (pEnemy->isPC())
			{
				Player* pTargetPlayer = pEnemy->getPlayer();
				if (pTargetPlayer == NULL) return;

				if (bCanSeeCaster) pTargetPlayer->sendPacket(&_GCSkillToObjectOK2);
				else pTargetPlayer->sendPacket(&_GCSkillToObjectOK6);
			}
			else
			{
				Monster* pTargetMonster = dynamic_cast<Monster*>(pEnemy);
				pTargetMonster->addEnemy(pMonster);
			}

			list<Creature*> cList;
			cList.push_back(pMonster);
			cList.push_back(pEnemy);

			pZone->broadcastSkillPacket(casterX, casterY, targetX, targetY, &_GCSkillToObjectOK5, cList);
		}
		else
		{
			executeSkillFailNormal(pMonster, getSkillType(), pEnemy);
		}
	}
	catch (Throwable & t)
	{
		executeSkillFailException(pMonster, getSkillType());
	}

	__END_CATCH
}

void FolletPoisonFrame::computeOutput(const SkillInput& input, SkillOutput& output)
{
	output.Damage   = (int)(input.DEX * 0.5);
	output.Duration = 60;
	output.Tick     = 10;
	output.Delay    = output.Duration;
}

FolletPoisonFrame g_FolletPoisonFrame;
