//////////////////////////////////////////////////////////////////////////////
// Filename    : HolyArmor2.cpp
// Written by  :
// Description : Holy Armor 2 (skill 523). Same flow as HolyArmor (costs 100 HP, party share);
//               formula and effect from the v9 gameserver (HolyArmor2). Holy Armor and Holy Armor 2
//               do not stack: either effect blocks both skills.
//////////////////////////////////////////////////////////////////////////////

#include "HolyArmor2.h"
#include "EffectHolyArmor2.h"

#include "Gpackets/GCSkillToSelfOK1.h"
#include "Gpackets/GCSkillToSelfOK2.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCAddEffect.h"

//////////////////////////////////////////////////////////////////////////////
// Slayer self handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType HolyArmor2::execute(Slayer* pSlayer, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
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

		ZoneCoord_t X = pSlayer->getX();
		ZoneCoord_t Y = pSlayer->getY();

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP) && pSlayer->getHP() > 100;
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = checkZoneLevelToUseSkill(pSlayer);
		bool bHitRoll    = HitRoll::isSuccessMagic(pSlayer, pSkillInfo, pSkillSlot);
		bool bEffected   = pSlayer->isFlag(Effect::EFFECT_CLASS_HOLY_ARMOR_2)
						|| pSlayer->isFlag(Effect::EFFECT_CLASS_HOLY_ARMOR);

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && !bEffected)
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToSelfOK1);

			pSlayer->setHP( pSlayer->getHP()-100 );
			_GCSkillToSelfOK1.addShortData( MODIFY_CURRENT_HP, pSlayer->getHP() );

			SkillInput input(pSlayer, pSkillSlot);
			SkillOutput output;
			computeOutput(input, output);

			pSkillSlot->setRunTime(output.Delay);

			EffectHolyArmor2* pEffect = new EffectHolyArmor2(pSlayer);
			pEffect->setDeadline(output.Duration);
			pEffect->setDefBonus(output.Damage);
			pSlayer->addEffect(pEffect);
			pSlayer->setFlag(Effect::EFFECT_CLASS_HOLY_ARMOR_2);

			pSlayer->initAllStatAndSend();

			SkillGrade Grade = g_pSkillInfoManager->getGradeByDomainLevel(pSlayer->getSkillDomainLevel(DomainType));
			Exp_t ExpUp = 10*(Grade+1);

			shareAttrExp(pSlayer, ExpUp, 1, 1, 8, _GCSkillToSelfOK1);
			increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), _GCSkillToSelfOK1);
			increaseSkillExp(pSlayer, DomainType,  pSkillSlot, pSkillInfo, _GCSkillToSelfOK1);

			_GCSkillToSelfOK1.setSkillType(SkillType);
			_GCSkillToSelfOK1.setCEffectID(CEffectID);
			_GCSkillToSelfOK1.setDuration(output.Duration);

			_GCSkillToSelfOK2.setObjectID(pSlayer->getObjectID());
			_GCSkillToSelfOK2.setSkillType(SkillType);
			_GCSkillToSelfOK2.setDuration(output.Duration);

			GCAddEffect gcAddEffect;
			gcAddEffect.setObjectID(pSlayer->getObjectID());
			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_HOLY_ARMOR_2);
			gcAddEffect.setDuration(output.Duration);
			pZone->broadcastPacket(X, Y, &gcAddEffect);

			postSkillSuccessProcess( SkillType, pSlayer, &_GCSkillToSelfOK1 );

			pPlayer->sendPacket(&_GCSkillToSelfOK1);
			pZone->broadcastPacket(X, Y, &_GCSkillToSelfOK2, pSlayer);

			uint PartyID = pSlayer->getPartyID();
			if (PartyID != 0)
			{
				LocalPartyManager* pLPM = pZone->getLocalPartyManager();
				pLPM->shareHolyArmor2(PartyID, pSlayer, output.Damage, input.SkillLevel);
			}

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

	return SKILL_RESULT_FAIL_UNKNOWN;

	__END_CATCH
}

HolyArmor2 g_HolyArmor2;
