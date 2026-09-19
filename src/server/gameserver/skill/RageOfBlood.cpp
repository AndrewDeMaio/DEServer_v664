//////////////////////////////////////////////////////////////////////////////
// Filename    : RageOfBlood.cpp
// Written by  :
// Description : Rage of Blood (skill 531). Vampire self buff: rapid HP regeneration while it lasts
//               (Vampire::heartbeat, effect 629). Same flow as the v9 gameserver (RageOfBlood).
//////////////////////////////////////////////////////////////////////////////
#include "RageOfBlood.h"
#include "EffectRageOfBlood.h"

#include "Gpackets/GCSkillToSelfOK1.h"
#include "Gpackets/GCSkillToSelfOK2.h"
#include "Gpackets/GCAddEffect.h"

//////////////////////////////////////////////////////////////////////////////
// Vampire self handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType RageOfBlood::execute(Vampire* pVampire, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID)
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

		GCSkillToSelfOK1 _GCSkillToSelfOK1;
		GCSkillToSelfOK2 _GCSkillToSelfOK2;

		SkillType_t       SkillType  = pVampireSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pVampire, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pVampireSkillSlot);
		bool bRangeCheck = checkZoneLevelToUseSkill(pVampire);
		bool bEffected   = pVampire->isFlag(Effect::EFFECT_CLASS_RAGE_OF_BLOOD);

		if (bManaCheck && bTimeCheck && bRangeCheck && !bEffected)
		{
			decreaseMana(pVampire, RequiredMP, _GCSkillToSelfOK1);

			SkillInput input( pVampire );
			SkillOutput output;
			computeOutput(input, output);

			// set Next Run Time
			pVampireSkillSlot->setRunTime(output.Delay);

			EffectRageOfBlood* pEffect = new EffectRageOfBlood(pVampire);
			pEffect->setDeadline(output.Duration);
			pVampire->addEffect(pEffect);
			pVampire->setFlag(Effect::EFFECT_CLASS_RAGE_OF_BLOOD);

			pVampire->initAllStatAndSend();

			_GCSkillToSelfOK1.setSkillType(SkillType);
			_GCSkillToSelfOK1.setCEffectID(CEffectID);
			_GCSkillToSelfOK1.setDuration(output.Duration);

			_GCSkillToSelfOK2.setObjectID(pVampire->getObjectID());
			_GCSkillToSelfOK2.setSkillType(SkillType);
			_GCSkillToSelfOK2.setDuration(output.Duration);

			postSkillSuccessProcess( SkillType, pVampire, &_GCSkillToSelfOK1 );

			pPlayer->sendPacket(&_GCSkillToSelfOK1);

			pZone->broadcastPacket(pVampire->getX(), pVampire->getY(),  &_GCSkillToSelfOK2, pVampire);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pVampire->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_RAGE_OF_BLOOD);
			gcAddEffect.setDuration(output.Duration);
			pZone->broadcastPacket(pVampire->getX(), pVampire->getY(), &gcAddEffect);

			return SKILL_RESULT_SUCCESS;
		}
		else
		{
			executeSkillFailNormal(pVampire, getSkillType(), NULL);
		}
	}
	catch (Throwable & t)
	{
		executeSkillFailException(pVampire, getSkillType());
	}

	__END_CATCH

	return SKILL_RESULT_FAIL_UNKNOWN;
}

RageOfBlood g_RageOfBlood;
