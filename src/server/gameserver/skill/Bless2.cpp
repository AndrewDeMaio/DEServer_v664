//////////////////////////////////////////////////////////////////////////////
// Filename    : Bless2.cpp
// Written by  :
// Description : Bless 2 (skill 525). Same flow as Bless and the v9 gameserver (Bless2);
//               gameserver_664 formula capped at +65%. Bless and Bless 2 do not stack.
//////////////////////////////////////////////////////////////////////////////

#include "Bless2.h"
#include "EffectBless.h"
#include "EffectBless2.h"
#include "PacketUtil.h"

#include "Gpackets/GCSkillToSelfOK1.h"
#include "Gpackets/GCSkillToSelfOK2.h"
#include "Gpackets/GCSkillToObjectOK1.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK3.h"
#include "Gpackets/GCSkillToObjectOK4.h"
#include "Gpackets/GCSkillToObjectOK5.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCOtherModifyInfo.h"

//////////////////////////////////////////////////////////////////////////////
// Slayer object handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType Bless2::execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pSlayer != NULL);
	Assert(pSkillSlot != NULL);

	try
	{
		Player* pPlayer = pSlayer->getPlayer();
		Zone* pZone = pSlayer->getZone();
		Assert(pPlayer != NULL);
		Assert(pZone != NULL);

		Creature* pTargetCreature = pZone->getCreature(TargetObjectID);

		if (pTargetCreature==NULL
			|| pTargetCreature->isSlayer() == false)
		{
			executeSkillFailException(pSlayer, getSkillType());

			return SKILL_RESULT_FAIL_INVALID_TARGET;
		}

		GCSkillToObjectOK1 _GCSkillToObjectOK1;
		GCSkillToObjectOK2 _GCSkillToObjectOK2;
		GCSkillToObjectOK3 _GCSkillToObjectOK3;
		GCSkillToObjectOK4 _GCSkillToObjectOK4;
		GCSkillToObjectOK5 _GCSkillToObjectOK5;

		Slayer* pTargetSlayer = dynamic_cast<Slayer*>(pTargetCreature);

		SkillType_t       SkillType  = pSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		SkillDomainType_t DomainType = pSkillInfo->getDomainType();

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = verifyDistance(pSlayer, pTargetCreature, pSkillInfo->getRange());
		bool bHitRoll    = HitRoll::isSuccessMagic(pSlayer, pSkillInfo, pSkillSlot);
		bool bEffected   = pTargetSlayer->isFlag(Effect::EFFECT_CLASS_BLESS_2)
						|| pTargetSlayer->isFlag(Effect::EFFECT_CLASS_BLESS);

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && !bEffected)
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToObjectOK1);

			SkillInput input(pSlayer, pSkillSlot);

			// The caster's own Bless / Bless 2 INT bonus does not count towards the buff it gives others.
			if (pSlayer->isFlag(Effect::EFFECT_CLASS_BLESS))
			{
				EffectBless* pBless = dynamic_cast<EffectBless*>(pSlayer->findEffect(Effect::EFFECT_CLASS_BLESS));
				if (pBless != NULL) input.INTE -= pBless->getINTBonus();
			}
			if (pSlayer->isFlag(Effect::EFFECT_CLASS_BLESS_2))
			{
				EffectBless2* pBless2 = dynamic_cast<EffectBless2*>(pSlayer->findEffect(Effect::EFFECT_CLASS_BLESS_2));
				if (pBless2 != NULL) input.INTE -= pBless2->getINTBonus();
			}

			input.TargetType = SkillInput::TARGET_OTHER;
			SkillOutput output;
			computeOutput(input, output);

			uint AttrBonus = output.Damage;

			EffectBless2* pEffect = new EffectBless2(pTargetCreature);
			pEffect->setDeadline(output.Duration);
			pEffect->setSTRBonus(AttrBonus);
			pEffect->setDEXBonus(AttrBonus);
			pEffect->setINTBonus(AttrBonus);
			pTargetCreature->setFlag(Effect::EFFECT_CLASS_BLESS_2);
			pTargetCreature->addEffect(pEffect);

			SLAYER_RECORD prev;
			pTargetSlayer->getSlayerRecord(prev);
			pTargetSlayer->initAllStat();
			pTargetSlayer->sendRealWearingInfo();
			pTargetSlayer->addModifyInfo(prev, _GCSkillToObjectOK2);

			SkillGrade Grade = g_pSkillInfoManager->getGradeByDomainLevel(pSlayer->getSkillDomainLevel(DomainType));
			Exp_t ExpUp = 10* (Grade + 1);
			shareAttrExp(pSlayer, ExpUp, 1, 1, 8, _GCSkillToObjectOK1);
        	increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), _GCSkillToObjectOK1);
			increaseSkillExp(pSlayer, DomainType, pSkillSlot, pSkillInfo, _GCSkillToObjectOK1);

			Coord_t targetX = pTargetCreature->getX();
			Coord_t targetY = pTargetCreature->getY();
			Coord_t myX     = pSlayer->getX();
			Coord_t myY     = pSlayer->getY();

			_GCSkillToObjectOK1.setSkillType(SkillType);
			_GCSkillToObjectOK1.setCEffectID(CEffectID);
			_GCSkillToObjectOK1.setTargetObjectID(TargetObjectID);
			_GCSkillToObjectOK1.setDuration(0);

			_GCSkillToObjectOK2.setObjectID(pSlayer->getObjectID());
			_GCSkillToObjectOK2.setSkillType(SkillType);
			_GCSkillToObjectOK2.setDuration(0);

			_GCSkillToObjectOK3.setObjectID(pSlayer->getObjectID());
			_GCSkillToObjectOK3.setSkillType(SkillType);
			_GCSkillToObjectOK3.setTargetXY (targetX, targetY);

			_GCSkillToObjectOK4.setSkillType(SkillType);
			_GCSkillToObjectOK4.setTargetObjectID(TargetObjectID);
			_GCSkillToObjectOK4.setDuration(0);

			_GCSkillToObjectOK5.setObjectID(pSlayer->getObjectID());
			_GCSkillToObjectOK5.setSkillType(SkillType);
			_GCSkillToObjectOK5.setTargetObjectID (TargetObjectID);
			_GCSkillToObjectOK5.setDuration(0);

			list<Creature *> cList;
			cList.push_back(pTargetCreature);
			cList.push_back(pSlayer);
			cList = pZone->broadcastSkillPacket(myX, myY, targetX, targetY, &_GCSkillToObjectOK5, cList);
			pZone->broadcastPacket(myX, myY, &_GCSkillToObjectOK3, cList);
			pZone->broadcastPacket(targetX, targetY, &_GCSkillToObjectOK4, cList);

			postSkillSuccessProcess( SkillType, pSlayer, &_GCSkillToObjectOK1 );

			pPlayer->sendPacket(&_GCSkillToObjectOK1);

			if (pTargetCreature->isPC())
			{
				Player* pTargetPlayer = pTargetCreature->getPlayer();
				Assert(pTargetPlayer != NULL);

				_GCSkillToObjectOK2.setObjectID(pSlayer->getObjectID());

				pTargetPlayer->sendPacket(&_GCSkillToObjectOK2);
			}
			else
			{
				Assert(false);
			}

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(TargetObjectID);
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_BLESS_2);
			gcAddEffect.setDuration(output.Duration);
			pZone->broadcastPacket(targetX, targetY, &gcAddEffect);

			GCOtherModifyInfo gcOtherModifyInfo;
			makeGCOtherModifyInfo(&gcOtherModifyInfo, pTargetSlayer, &prev);
			pZone->broadcastPacket(targetX, targetY, &gcOtherModifyInfo, pTargetSlayer);

			pSkillSlot->setRunTime(output.Delay);

			return SKILL_RESULT_SUCCESS;
		}
		else
		{
			executeSkillFailNormal(pSlayer, getSkillType(), pTargetCreature);
		}

	}
	catch (Throwable & t)
	{
		executeSkillFailException(pSlayer, getSkillType());
	}

	__END_CATCH

	return SKILL_RESULT_FAIL_UNKNOWN;
}

//////////////////////////////////////////////////////////////////////////////
// Slayer self handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType Bless2::execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pSlayer != NULL);
	Assert(pSkillSlot != NULL);

	try
	{
		Player* pPlayer = pSlayer->getPlayer();
		Zone* pZone = pSlayer->getZone();
		Assert(pPlayer != NULL);
		Assert(pZone != NULL);

		GCSkillToSelfOK1 _GCSkillToSelfOK1;
		GCSkillToSelfOK2 _GCSkillToSelfOK2;

		SkillType_t       SkillType  = pSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		SkillDomainType_t DomainType = pSkillInfo->getDomainType();

		ZoneCoord_t myX = pSlayer->getX();
		ZoneCoord_t myY = pSlayer->getY();

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = checkZoneLevelToUseSkill(pSlayer);
		bool bHitRoll    = HitRoll::isSuccessMagic(pSlayer, pSkillInfo, pSkillSlot);
		bool bEffected   = pSlayer->isFlag(Effect::EFFECT_CLASS_BLESS_2)
						|| pSlayer->isFlag(Effect::EFFECT_CLASS_BLESS);

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && !bEffected)
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToSelfOK1);

			SkillInput input(pSlayer, pSkillSlot);
			input.TargetType = SkillInput::TARGET_SELF;
			SkillOutput output;
			computeOutput(input, output);

			EffectBless2* pEffect = new EffectBless2(pSlayer);
			pEffect->setDeadline(output.Duration);
			pEffect->setSTRBonus(output.Damage);
			pEffect->setDEXBonus(output.Damage);
			pEffect->setINTBonus(output.Damage);
			pSlayer->setFlag(Effect::EFFECT_CLASS_BLESS_2);
			pSlayer->addEffect(pEffect);

			SLAYER_RECORD prev;
			pSlayer->getSlayerRecord(prev);
			pSlayer->initAllStat();
			pSlayer->sendRealWearingInfo();
			pSlayer->addModifyInfo(prev, _GCSkillToSelfOK1);

			SkillGrade Grade = g_pSkillInfoManager->getGradeByDomainLevel(pSlayer->getSkillDomainLevel(DomainType));
			Exp_t ExpUp = 10* (Grade + 1);
			shareAttrExp(pSlayer, ExpUp, 1, 1, 8, _GCSkillToSelfOK1);
        	increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), _GCSkillToSelfOK1);
			increaseSkillExp(pSlayer, DomainType, pSkillSlot, pSkillInfo, _GCSkillToSelfOK1);

			_GCSkillToSelfOK1.setSkillType(SkillType);
			_GCSkillToSelfOK1.setCEffectID(CEffectID);
			_GCSkillToSelfOK1.setDuration(0);

			_GCSkillToSelfOK2.setObjectID(pSlayer->getObjectID());
			_GCSkillToSelfOK2.setSkillType(SkillType);
			_GCSkillToSelfOK2.setDuration(0);

			postSkillSuccessProcess( SkillType, pSlayer, &_GCSkillToSelfOK1 );

			pPlayer->sendPacket(&_GCSkillToSelfOK1);
			pZone->broadcastPacket(myX, myY, &_GCSkillToSelfOK2, pSlayer);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_BLESS_2);
			gcAddEffect.setDuration(output.Duration);
			pZone->broadcastPacket(myX, myY, &gcAddEffect);

			GCOtherModifyInfo gcOtherModifyInfo;
			makeGCOtherModifyInfo(&gcOtherModifyInfo, pSlayer, &prev);
			pZone->broadcastPacket(myX, myY, &gcOtherModifyInfo, pSlayer);

			pSkillSlot->setRunTime(output.Delay);

			return SKILL_RESULT_SUCCESS;
		}
		else
		{
			executeSkillFailNormal(pSlayer, getSkillType(), NULL);
		}
	}
	catch (Throwable & t)
	{
		executeSkillFailException(pSlayer, getSkillType());
	}

	__END_CATCH

	return SKILL_RESULT_FAIL_UNKNOWN;
}

Bless2 g_Bless2;
