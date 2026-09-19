//////////////////////////////////////////////////////////////////////////////
// Filename    : LarStroke.cpp
// Written by  : elca@ewestsoft.com
// Description : Lar Stroke (skill 549). Same flow as Lar Slash (fast single-target sword hit);
//               damage from the v9 gameserver (LarStroke).
//////////////////////////////////////////////////////////////////////////////

#include "LarStroke.h"
#include "Gpackets/GCSkillToObjectOK1.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK5.h"
#include "CrossCounter.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
SkillResultType LarStroke::execute(Slayer * pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot * pSkillSlot, CEffectID_t CEffectID)
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
		//Assert(pTargetCreature != NULL);
		
		if (pTargetCreature==NULL
			|| pTargetCreature->isNPC())
		{
			executeSkillFailException(pSlayer, getSkillType());
			
			return SKILL_RESULT_FAIL_INVALID_TARGET;
		}

		Item* pItem = pSlayer->getWearItem(Slayer::WEAR_RIGHTHAND);
		if (pItem == NULL || pItem->getItemClass() != Item::ITEM_CLASS_SWORD)
		{
			executeSkillFailException(pSlayer, getSkillType());
			
			return SKILL_RESULT_FAIL_INVALID_ITEM;
		}

		bool bIncreaseExp = pSlayer->isRealWearingEx(Slayer::WEAR_RIGHTHAND);

		GCSkillToObjectOK1 _GCSkillToObjectOK1;
		GCSkillToObjectOK2 _GCSkillToObjectOK2;
		GCSkillToObjectOK5 _GCSkillToObjectOK5;

		SkillType_t       SkillType  = pSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		SkillDomainType_t DomainType = pSkillInfo->getDomainType();
		SkillLevel_t      SkillLevel = pSkillSlot->getExpLevel();

		bool bCriticalHit = false;

		SkillInput input(pSlayer, pSkillSlot);
		SkillOutput output;
		computeOutput(input, output);

		Damage_t Damage = computeDamage(pSlayer, pTargetCreature, SkillLevel/5, bCriticalHit);
		Damage += output.Damage;

		int  RequiredMP         = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck         = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck         = verifyRunTime(pSkillSlot);
		bool bRangeCheck        = verifyDistance(pSlayer, pTargetCreature, pSkillInfo->getRange());
		bool bHitRoll           = (rand()%10)?HitRoll::isSuccess(pSlayer, pTargetCreature, SkillLevel / 2):(true);
		bool bCanHit            = canHit(pSlayer, pTargetCreature, SkillType);
		bool bPK                = verifyPK(pSlayer, pTargetCreature);

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && bCanHit && bPK && canAttack( pSlayer, pTargetCreature ))
		{
			CheckCrossCounter(pSlayer, pTargetCreature, Damage, pSkillInfo->getRange());

			decreaseMana(pSlayer, RequiredMP, _GCSkillToObjectOK1);

//			Exp_t Point = pSkillInfo->getPoint();

			setDamage(pTargetCreature, Damage, pSlayer, SkillType, &_GCSkillToObjectOK2, &_GCSkillToObjectOK1);
			computeAlignmentChange(pTargetCreature, Damage, pSlayer, &_GCSkillToObjectOK2, &_GCSkillToObjectOK1);
			decreaseDurability(pSlayer, pTargetCreature, pSkillInfo, &_GCSkillToObjectOK1, &_GCSkillToObjectOK2);

			if (bCriticalHit)
			{
				knockbackCreature(pZone, pTargetCreature, pSlayer->getX(), pSlayer->getY());

				if ( pSlayer->isFlag( Effect::EFFECT_CLASS_BURST_GUN ) )
				{
					broadcastSimpleCreatureEffect( Effect::EFFECT_CLASS_SLAYER_BLOOD_BURST_HIT, pTargetCreature );
				}
			}

			if (!pTargetCreature->isSlayer())
			{
				
				if (bIncreaseExp)
				{
					shareAttrExp(pSlayer, Damage, 8, 1, 1, _GCSkillToObjectOK1);
					increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), _GCSkillToObjectOK1, pTargetCreature->getLevel());
					increaseSkillExp(pSlayer, DomainType,  pSkillSlot, pSkillInfo, _GCSkillToObjectOK1);
				}
				increaseAlignment(pSlayer, pTargetCreature, _GCSkillToObjectOK1);
			}

			_GCSkillToObjectOK1.setSkillType(SkillType);
			_GCSkillToObjectOK1.setCEffectID(CEffectID);
			_GCSkillToObjectOK1.setTargetObjectID(TargetObjectID);
			_GCSkillToObjectOK1.setDuration(0);
		
			_GCSkillToObjectOK2.setObjectID(pSlayer->getObjectID());
			_GCSkillToObjectOK2.setSkillType(SkillType);
			_GCSkillToObjectOK2.setDuration(0);
		
			_GCSkillToObjectOK5.setObjectID(pSlayer->getObjectID());
			_GCSkillToObjectOK5.setSkillType(SkillType);
			_GCSkillToObjectOK5.setTargetObjectID (TargetObjectID);
			_GCSkillToObjectOK5.setDuration(0);
		
			postSkillSuccessProcess( SkillType, pSlayer, &_GCSkillToObjectOK1 );

			pPlayer->sendPacket(&_GCSkillToObjectOK1);
		
			if (pTargetCreature->isPC()) 
			{
				Player* pTargetPlayer = pTargetCreature->getPlayer();
				Assert(pTargetPlayer != NULL);
				pTargetPlayer->sendPacket(&_GCSkillToObjectOK2);
			} 
			else 
			{
				Monster * pMonster = dynamic_cast<Monster*>(pTargetCreature);
				pMonster->addEnemy(pSlayer);
			}

			list< Creature*> cList;
			cList.push_back(pSlayer);
			cList.push_back(pTargetCreature);

			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(),  &_GCSkillToObjectOK5, cList);

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

LarStroke g_LarStroke;
