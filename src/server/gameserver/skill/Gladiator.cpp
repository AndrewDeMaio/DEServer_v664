//////////////////////////////////////////////////////////////////////////////
// Filename    : Gladiator.cpp
// Written by  :
// Description : Gladiator (skill 519, level 171 Blade), designed by the user (2026-09-17). Cast on yourself:
//               the caster gets protection + ProtectionBonus% and max HP + HPBonus, the caster and the party
//               members around them (Party::shareGladiator) get weapon damage + DamageBonus. The bonuses are
//               applied in Slayer::initAllStat. Numbers in Gladiator::computeOutput.
//////////////////////////////////////////////////////////////////////////////

#include "Gladiator.h"
#include "EffectGladiator.h"
#include "PacketUtil.h"
#include "Party.h"

#include "Gpackets/GCSkillToSelfOK1.h"
#include "Gpackets/GCSkillToSelfOK2.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCOtherModifyInfo.h"

//////////////////////////////////////////////////////////////////////////////
// Slayer object handler: Gladiator always goes on the caster
//////////////////////////////////////////////////////////////////////////////
SkillResultType Gladiator::execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	return execute(pSlayer, pSkillSlot, CEffectID);

	__END_CATCH

	return SKILL_RESULT_FAIL_UNKNOWN;
}

//////////////////////////////////////////////////////////////////////////////
// Slayer self handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType Gladiator::execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
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

		// a Gladiator shared by a party member (damage bonus only) does not block casting your own
		EffectGladiator* pOld = NULL;
		if (pSlayer->isFlag(Effect::EFFECT_CLASS_GLADIATOR))
		{
			pOld = dynamic_cast<EffectGladiator*>(pSlayer->findEffect(Effect::EFFECT_CLASS_GLADIATOR));
		}

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = checkZoneLevelToUseSkill(pSlayer);
		bool bHitRoll    = HitRoll::isSuccessMagic(pSlayer, pSkillInfo, pSkillSlot);
		bool bEffected   = pSlayer->isFlag(Effect::EFFECT_CLASS_GLADIATOR) && (pOld == NULL || !pOld->isShared());

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && !bEffected)
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToSelfOK1);

			SkillInput input(pSlayer, pSkillSlot);
			input.TargetType = SkillInput::TARGET_SELF;
			SkillOutput output;
			computeOutput(input, output);

			EffectGladiator* pEffect = pOld;
			if (pEffect == NULL)
			{
				pEffect = new EffectGladiator(pSlayer);
				pEffect->setDeadline(output.Duration);
				pSlayer->setFlag(Effect::EFFECT_CLASS_GLADIATOR);
				pSlayer->addEffect(pEffect);
			}
			else
			{
				pEffect->setDeadline(output.Duration);
			}
			pEffect->setShared(false);
			pEffect->setProtectionBonus(output.ToHit);
			pEffect->setHPBonus(output.Tick);
			pEffect->setDamageBonus(output.Damage);

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
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_GLADIATOR);
			gcAddEffect.setDuration(output.Duration);
			pZone->broadcastPacket(myX, myY, &gcAddEffect);

			GCOtherModifyInfo gcOtherModifyInfo;
			makeGCOtherModifyInfo(&gcOtherModifyInfo, pSlayer, &prev);
			pZone->broadcastPacket(myX, myY, &gcOtherModifyInfo, pSlayer);

			// the damage part reaches the party members around the caster
			uint PartyID = pSlayer->getPartyID();
			if (PartyID != 0)
			{
				LocalPartyManager* pLPM = pZone->getLocalPartyManager();
				pLPM->shareGladiator(PartyID, pSlayer, output.Damage, output.Range, output.Duration);
			}

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

Gladiator g_Gladiator;
