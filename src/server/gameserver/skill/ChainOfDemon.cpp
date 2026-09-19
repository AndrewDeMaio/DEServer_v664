//////////////////////////////////////////////////////////////////////////////
// Filename    : ChainOfDemon.cpp
// Written by  :
// Description : Chain of Demon (skill 529). Single-target vampire stun, same flow as the v9 gameserver
//               (ChainofDemon), which was Paralyze without the curse resist rolls: the target cannot
//               move or act (effect 626, checked next to Paralyze/Stun) and takes less damage meanwhile.
//               Not usable on vampires in the holy land during a race war.
//////////////////////////////////////////////////////////////////////////////

#include "ChainOfDemon.h"
#include "EffectChainOfDemon.h"
#include "Gpackets/GCSkillToObjectOK1.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK3.h"
#include "Gpackets/GCSkillToObjectOK4.h"
#include "Gpackets/GCSkillToObjectOK5.h"
#include "Gpackets/GCSkillToObjectOK6.h"
#include "Gpackets/GCAddEffect.h"
#include "Vampire.h"
#include "Reflection.h"
#include "Tile.h"
#include "war/WarSystem.h"

//////////////////////////////////////////////////////////////////////////////
// Vampire object handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType ChainOfDemon::execute(Vampire* pVampire, ObjectID_t TargetObjectID, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pVampire != NULL);
	Assert(pVampireSkillSlot != NULL);

	try
	{
		Player* pPlayer = pVampire->getPlayer();
		Zone* pZone = pVampire->getZone();
		Assert(pPlayer != NULL);
		Assert(pZone != NULL);

		Creature* pTargetCreature = pZone->getCreature(TargetObjectID);
		SkillType_t       SkillType  = pVampireSkillSlot->getSkillType();

		if (pTargetCreature==NULL
			|| pTargetCreature->isFlag(Effect::EFFECT_CLASS_IMMUNE_TO_PARALYZE)
			|| !canAttack( pVampire, pTargetCreature )
			|| pTargetCreature->isNPC())
		{
			executeSkillFailException(pVampire, getSkillType());

			return SKILL_RESULT_FAIL_INVALID_TARGET;
		}

		// v9: vampires cannot chain each other in the holy land during a race war
		if (g_pWarSystem->hasActiveRaceWar() && pZone->isHolyLand() && pTargetCreature->isVampire())
		{
			executeSkillFailException(pVampire, getSkillType());

			return SKILL_RESULT_FAIL_INVALID_TARGET;
		}

		GCSkillToObjectOK1 _GCSkillToObjectOK1;
		GCSkillToObjectOK2 _GCSkillToObjectOK2;
		GCSkillToObjectOK3 _GCSkillToObjectOK3;
		GCSkillToObjectOK4 _GCSkillToObjectOK4;
		GCSkillToObjectOK5 _GCSkillToObjectOK5;
		GCSkillToObjectOK6 _GCSkillToObjectOK6;

		SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);

		Tile& rTile = pZone->getTile( pTargetCreature->getX(), pTargetCreature->getY() );

		int  RequiredMP  = decreaseConsumeMP(pVampire, pSkillInfo);
		bool bManaCheck  = hasEnoughMana(pVampire, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pVampireSkillSlot);
		bool bRangeCheck = verifyDistance(pVampire, pTargetCreature, pSkillInfo->getRange());
		bool bCanHit     = canHit(pVampire, pTargetCreature, SkillType);
		bool bEffected   = pTargetCreature->isFlag(Effect::EFFECT_CLASS_CHAIN_OF_DEMON) || rTile.getEffect(Effect::EFFECT_CLASS_TRYING_POSITION)!=NULL;
		bool bPK         = verifyPK(pVampire, pTargetCreature);

		ZoneCoord_t vampX   = pVampire->getX();
		ZoneCoord_t vampY   = pVampire->getY();
		ZoneCoord_t targetX = pTargetCreature->getX();
		ZoneCoord_t targetY = pTargetCreature->getY();

		if (bManaCheck && bTimeCheck && bRangeCheck && bCanHit && !bEffected && bPK && pTargetCreature->getCompetence() == 3)
		{
			decreaseMana(pVampire, RequiredMP, _GCSkillToObjectOK1);

			bool bCanSeeCaster = canSee(pTargetCreature, pVampire);

			SkillInput input(pVampire);
			SkillOutput output;
			computeOutput(input, output);

			// the target reflects curses
			if (CheckReflection(pVampire, pTargetCreature, getSkillType()))
			{
				pTargetCreature = (Creature*)pVampire;
				TargetObjectID = pVampire->getObjectID();
			}

			EffectChainOfDemon* pEffectChainOfDemon = new EffectChainOfDemon(pTargetCreature);
			pEffectChainOfDemon->setLevel(pSkillInfo->getLevel()/2);
			pEffectChainOfDemon->setDamageReduceRatio( 50 - pVampire->getLevel() / 10  );
			pEffectChainOfDemon->setDeadline(output.Duration);
			pTargetCreature->addEffect(pEffectChainOfDemon);
			pTargetCreature->setFlag(Effect::EFFECT_CLASS_CHAIN_OF_DEMON);

			if ( pTargetCreature->isFlag( Effect::EFFECT_CLASS_BURNING_SOL_CHARGE_1 ) )
			{
				Effect* pEffect = pTargetCreature->findEffect( Effect::EFFECT_CLASS_BURNING_SOL_CHARGE_1 );
				if ( pEffect != NULL ) pEffect->setDeadline(0);
			}

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pTargetCreature->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_CHAIN_OF_DEMON);
			gcAddEffect.setDuration(output.Duration);
			pZone->broadcastPacket(targetX, targetY, &gcAddEffect);

			_GCSkillToObjectOK1.setSkillType(SkillType);
			_GCSkillToObjectOK1.setCEffectID(CEffectID);
			_GCSkillToObjectOK1.setTargetObjectID(TargetObjectID);
			_GCSkillToObjectOK1.setDuration(output.Duration);

			_GCSkillToObjectOK2.setObjectID(pVampire->getObjectID());
			_GCSkillToObjectOK2.setSkillType(SkillType);
			_GCSkillToObjectOK2.setDuration(output.Duration);

			_GCSkillToObjectOK3.setObjectID(pVampire->getObjectID());
			_GCSkillToObjectOK3.setSkillType(SkillType);
			_GCSkillToObjectOK3.setTargetXY(targetX, targetY);

			_GCSkillToObjectOK4.setSkillType(SkillType);
			_GCSkillToObjectOK4.setTargetObjectID(TargetObjectID);

			_GCSkillToObjectOK5.setObjectID(pVampire->getObjectID());
			_GCSkillToObjectOK5.setTargetObjectID(TargetObjectID);
			_GCSkillToObjectOK5.setSkillType(SkillType);
			_GCSkillToObjectOK5.setDuration(output.Duration);

			_GCSkillToObjectOK6.setXY(vampX, vampY);
			_GCSkillToObjectOK6.setSkillType(SkillType);
			_GCSkillToObjectOK6.setDuration(output.Duration);

			if (bCanSeeCaster)
			{
				computeAlignmentChange(pTargetCreature, 10, pVampire, &_GCSkillToObjectOK2, &_GCSkillToObjectOK1);
			}
			else
			{
				computeAlignmentChange(pTargetCreature, 10, pVampire, &_GCSkillToObjectOK6, &_GCSkillToObjectOK1);
			}

			postSkillSuccessProcess( SkillType, pVampire, &_GCSkillToObjectOK1 );

			pPlayer->sendPacket(&_GCSkillToObjectOK1);

			if (pTargetCreature->isPC())
			{
				Player* pTargetPlayer = pTargetCreature->getPlayer();
				Assert(pTargetPlayer != NULL);

				if (bCanSeeCaster) pTargetPlayer->sendPacket(&_GCSkillToObjectOK2);
				else pTargetPlayer->sendPacket(&_GCSkillToObjectOK6);
			}
			else
			{
				Monster* pTargetMonster = dynamic_cast<Monster*>(pTargetCreature);
				pTargetMonster->addEnemy(pVampire);
			}

			list<Creature*> cList;
			cList.push_back(pVampire);
			cList.push_back(pTargetCreature);

			cList = pZone->broadcastSkillPacket(vampX, vampY, targetX, targetY, &_GCSkillToObjectOK5, cList);

			pZone->broadcastPacket(vampX, vampY,  &_GCSkillToObjectOK3 , cList);
			pZone->broadcastPacket(targetX, targetY,  &_GCSkillToObjectOK4 , cList);

			pVampireSkillSlot->setRunTime(output.Delay);

			return SKILL_RESULT_SUCCESS;
		}
		else
		{
			executeSkillFailNormal(pVampire, getSkillType(), pTargetCreature);
		}
	}
	catch(Throwable & t)
	{
		executeSkillFailException(pVampire, getSkillType());
	}

	__END_CATCH

	return SKILL_RESULT_FAIL_UNKNOWN;
}

ChainOfDemon g_ChainOfDemon;
