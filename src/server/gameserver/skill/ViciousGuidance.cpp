//////////////////////////////////////////////////////////////////////////////
// Filename    : ViciousGuidance.cpp
// Written by  : excel96
// Description : Vicious Guidance (skill 551). Same flow as Divine Guidance (damage over time on one
//               target); numbers from the v9 gameserver (ViciousGuidance). Shares its cooldown with
//               Divine Guidance on the client.
//////////////////////////////////////////////////////////////////////////////

#include "ViciousGuidance.h"
#include "EffectViciousGuidance.h"
#include "Gpackets/GCSkillToObjectOK1.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK5.h"
#include "Gpackets/GCSkillToSelfOK1.h"
#include "Gpackets/GCSkillToSelfOK2.h"
#include "Gpackets/GCAddEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
SkillResultType ViciousGuidance::execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
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
			|| !canAttack( pSlayer, pTargetCreature )
		)
		{
			executeSkillFailException(pSlayer, getSkillType());

			return SKILL_RESULT_FAIL_INVALID_TARGET;
		}

		SkillInput input(pSlayer, pSkillSlot);
		SkillOutput output;
		if ( pTargetCreature->isPC() )
		{
			input.TargetType = SkillInput::TARGET_PC;
		}
		else
		{
			input.TargetType = SkillInput::TARGET_MONSTER;
		}
		computeOutput(input, output);

		GCSkillToObjectOK1 _GCSkillToObjectOK1;
		GCSkillToObjectOK2 _GCSkillToObjectOK2;
		GCSkillToObjectOK5 _GCSkillToObjectOK5;

		SkillType_t       SkillType  = pSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		SkillDomainType_t DomainType = pSkillInfo->getDomainType();

		bool bIncreaseDomainExp = pSlayer->isRealWearingEx(Slayer::WEAR_RIGHTHAND);

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = verifyDistance(pSlayer, pTargetCreature, pSkillInfo->getRange());
		bool bHitRoll    = (rand()%100 < output.ToHit);//HitRoll::isSuccessMagic(pSlayer, pSkillInfo, pSkillSlot);
#ifdef VERSION_SKILL_1
		bHitRoll	 &= HitRoll::isSuccessMagic(pSlayer, pTargetCreature);
#endif
		bool bEffected   = pTargetCreature->isFlag(Effect::EFFECT_CLASS_VICIOUS_GUIDANCE);
		bool bPK         = verifyPK(pSlayer, pTargetCreature);

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && !bEffected && bPK)
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToObjectOK1);

			if (!pTargetCreature->isSlayer())
			{
				//SkillGrade Grade = g_pSkillInfoManager->getGradeByDomainLevel(pSlayer->getSkillDomainLevel(DomainType));
				//Exp_t      ExpUp = 10* (Grade + 1);
				//shareAttrExp(pSlayer, ExpUp, 1, 1, 8, _GCSkillToObjectOK1);
				//
				if ( bIncreaseDomainExp )
				{
					increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), _GCSkillToObjectOK1, pTargetCreature->getLevel());
				}

				increaseSkillExp(pSlayer, DomainType,  pSkillSlot, pSkillInfo, _GCSkillToObjectOK1);
			}
		
			EffectViciousGuidance* pEffect = new EffectViciousGuidance(pTargetCreature);
			Assert(pEffect != NULL);
			pEffect->setDeadline(output.Duration);
			pEffect->setTick(output.Tick);
			pEffect->setPoint(output.Damage); 
			pEffect->setUserObjectID( pSlayer->getObjectID() );
			pEffect->setNextTime(0);

			pTargetCreature->addEffect(pEffect);
			pTargetCreature->setFlag(Effect::EFFECT_CLASS_VICIOUS_GUIDANCE);

			_GCSkillToObjectOK1.setSkillType(SkillType);
			_GCSkillToObjectOK1.setCEffectID(CEffectID);
			_GCSkillToObjectOK1.setTargetObjectID(TargetObjectID);
			_GCSkillToObjectOK1.setDuration(output.Duration);

			_GCSkillToObjectOK2.setObjectID(pSlayer->getObjectID());
			_GCSkillToObjectOK2.setSkillType(SkillType);
			_GCSkillToObjectOK2.setDuration (output.Duration);

			_GCSkillToObjectOK5.setObjectID(pSlayer->getObjectID());
			_GCSkillToObjectOK5.setSkillType(SkillType);
			_GCSkillToObjectOK5.setTargetObjectID (TargetObjectID);
			_GCSkillToObjectOK5.setDuration (output.Duration);

			postSkillSuccessProcess( SkillType, pSlayer, &_GCSkillToObjectOK1 );

			// Send Packet
			pPlayer->sendPacket(&_GCSkillToObjectOK1);

			if (pSlayer != pTargetCreature && pTargetCreature->isPC()) 
			{
				Player* pTargetPlayer = pTargetCreature->getPlayer();
				Assert(pTargetPlayer != NULL);
				pTargetPlayer->sendPacket(&_GCSkillToObjectOK2);
			}
			else if ( pTargetCreature->isMonster() )
			{
				Monster* pMonster = dynamic_cast<Monster*>(pTargetCreature);
				if ( pMonster != NULL ) pMonster->addEnemy(pSlayer);
			}

			list<Creature*> cList;
			cList.push_back(pSlayer);
			cList.push_back(pTargetCreature);
		
			pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(),  &_GCSkillToObjectOK5 , cList);

//			GCAddEffect gcAddEffect;
//			gcAddEffect.setObjectID(pTargetCreature->getObjectID());
//			gcAddEffect.setEffectID(Effect::EFFECT_CLASS_VICIOUS_GUIDANCE);
//			gcAddEffect.setDuration(output.Duration);
//			pZone->broadcastPacket(pTargetCreature->getX(), pTargetCreature->getY(), &gcAddEffect, pTargetCreature);
//
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

ViciousGuidance g_ViciousGuidance;
