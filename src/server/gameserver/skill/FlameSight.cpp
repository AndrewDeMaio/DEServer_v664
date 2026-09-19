//////////////////////////////////////////////////////////////////////////////
// Filename    : FlameSight.cpp
// Written by  :
// Description : Flame Sight (skill 533). Ousters (wristlet) self buff that works like the Slayer skill
//               Lightness: the sight cannot be reduced (Creature::getEffectedSight) and the client treats
//               effect 631 like Lightness. Party members nearby get it too (v9 Party::shareFlameSight).
//               Same flow as the v9 gameserver (FlameSight); it is not saved across logouts, like Lightness.
//////////////////////////////////////////////////////////////////////////////

#include "FlameSight.h"
#include "EffectFlameSight.h"
#include "Party.h"

#include "Gpackets/GCSkillToSelfOK1.h"
#include "Gpackets/GCSkillToSelfOK2.h"

//////////////////////////////////////////////////////////////////////////////
// Ousters self handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType FlameSight::execute(Ousters* pOusters, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pOusters != NULL);
	Assert(pOustersSkillSlot != NULL);

	try
	{
		Player* pPlayer = pOusters->getPlayer();
		Zone* pZone = pOusters->getZone();

		Assert(pPlayer != NULL);
		Assert(pZone != NULL);

		Item* pWeapon = pOusters->getWearItem(Ousters::WEAR_RIGHTHAND);
		if (pWeapon == NULL || pWeapon->getItemClass() != Item::ITEM_CLASS_OUSTERS_WRISTLET || !pOusters->isRealWearingEx(Ousters::WEAR_RIGHTHAND))
		{
			executeSkillFailException(pOusters, pOustersSkillSlot->getSkillType());

			return SKILL_RESULT_FAIL_INVALID_ITEM;
		}

		GCSkillToSelfOK1 _GCSkillToSelfOK1;
		GCSkillToSelfOK2 _GCSkillToSelfOK2;

		SkillType_t       SkillType  = pOustersSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pOusters, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pOustersSkillSlot);
		bool bRangeCheck = checkZoneLevelToUseSkill(pOusters);
		bool bHitRoll    = HitRoll::isSuccessMagic(pOusters, pSkillInfo, pOustersSkillSlot);
		bool bEffected   = pOusters->isFlag(Effect::EFFECT_CLASS_FLAME_SIGHT);
		bool bSatisfyRequire = pOusters->satisfySkillRequire( pSkillInfo );

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && !bEffected && bSatisfyRequire)
		{
			decreaseMana(pOusters, RequiredMP, _GCSkillToSelfOK1);

			SkillInput input(pOusters, pOustersSkillSlot);
			SkillOutput output;
			computeOutput(input, output);

			pOustersSkillSlot->setRunTime(output.Delay);

			addFlameSight(pOusters, output.Duration, &_GCSkillToSelfOK1);

			_GCSkillToSelfOK1.setSkillType(SkillType);
			_GCSkillToSelfOK1.setCEffectID(CEffectID);
			_GCSkillToSelfOK1.setDuration(output.Duration);

			_GCSkillToSelfOK2.setObjectID(pOusters->getObjectID());
			_GCSkillToSelfOK2.setSkillType(SkillType);
			_GCSkillToSelfOK2.setDuration(output.Duration);

			postSkillSuccessProcess( SkillType, pOusters, &_GCSkillToSelfOK1 );

			pPlayer->sendPacket(&_GCSkillToSelfOK1);
			pZone->broadcastPacket(pOusters->getX(), pOusters->getY(),  &_GCSkillToSelfOK2, pOusters);

			uint PartyID = pOusters->getPartyID();
			if (PartyID != 0)
			{
				LocalPartyManager* pLPM = pZone->getLocalPartyManager();
				pLPM->shareFlameSight(PartyID, pOusters, output.Duration);
			}

			return SKILL_RESULT_SUCCESS;
		}
		else
		{
			executeSkillFailNormal(pOusters, getSkillType(), NULL);
		}
	}
	catch (Throwable & t)
	{
		executeSkillFailException(pOusters, getSkillType());
	}

	__END_CATCH

	return SKILL_RESULT_FAIL_UNKNOWN;
}

FlameSight g_FlameSight;
