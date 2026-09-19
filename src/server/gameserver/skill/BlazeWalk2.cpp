//////////////////////////////////////////////////////////////////////////////
// Filename    : BlazeWalk2.cpp
// Written by  : 
// Description : Blaze Walk 2 (skill 518). Blaze Walk (jump, hit, follow-up hits) with the level-171
//               damage, plus a splash on the other enemies around the target (custom design; v9 and
//               gameserver_664 only had a single area hit).
//////////////////////////////////////////////////////////////////////////////

#include "BlazeWalk2.h"
#include "EffectBlazeWalk.h"
#include "Gpackets/GCSkillToObjectOK1.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK3.h"
#include "Gpackets/GCSkillToObjectOK4.h"
#include "Gpackets/GCSkillToObjectOK5.h"
#include "Gpackets/GCSkillToObjectOK6.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "Gpackets/GCModifyInformation.h"
#include "Monster.h"
#include "ZoneUtil.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Splash: every other enemy within BLAZE_WALK_2_SPLASH_RANGE tiles of the target takes
// BLAZE_WALK_2_SPLASH_PERCENT of a normal hit (its own weapon damage + the skill damage).
//////////////////////////////////////////////////////////////////////////////
static const int BLAZE_WALK_2_SPLASH_RANGE   = 2;
static const int BLAZE_WALK_2_SPLASH_PERCENT = 50;

static void splashBlazeWalk2(Slayer* pSlayer, Creature* pTargetCreature, SkillType_t SkillType, SkillLevel_t SkillLevel, Damage_t SkillDamage, ModifyInfo& AttackerMI)
{
	Zone* pZone = pSlayer->getZone();
	Assert(pZone != NULL);

	VSRect rect(0, 0, pZone->getWidth()-1, pZone->getHeight()-1);

	int cx = pTargetCreature->getX();
	int cy = pTargetCreature->getY();

	GCSkillToObjectOK2 gcSkillToObjectOK2;
	GCSkillToObjectOK4 gcSkillToObjectOK4;

	for (int x = cx - BLAZE_WALK_2_SPLASH_RANGE; x <= cx + BLAZE_WALK_2_SPLASH_RANGE; x++)
	{
		for (int y = cy - BLAZE_WALK_2_SPLASH_RANGE; y <= cy + BLAZE_WALK_2_SPLASH_RANGE; y++)
		{
			if (!rect.ptInRect(x, y)) continue;

			// copy the creatures first; setDamage must not run while walking the tile list
			list<Creature*> cList;
			const slist<Object*>& oList = pZone->getTile(x, y).getObjectList();
			for (slist<Object*>::const_iterator itr = oList.begin(); itr != oList.end(); itr++)
			{
				Object* pObject = *itr;
				if (pObject != NULL && pObject->getObjectClass() == Object::OBJECT_CLASS_CREATURE)
					cList.push_back(dynamic_cast<Creature*>(pObject));
			}

			for (list<Creature*>::iterator citr = cList.begin(); citr != cList.end(); citr++)
			{
				Creature* pCreature = *citr;

				if (pCreature == NULL
					|| pCreature == pSlayer
					|| pCreature == pTargetCreature
					|| pCreature->isNPC()
					|| pCreature->isDead()
					|| pCreature->isFlag(Effect::EFFECT_CLASS_COMA)
					|| !canAttack(pSlayer, pCreature)
					|| !verifyPK(pSlayer, pCreature)
					|| !checkZoneLevelToHitTarget(pCreature))
				{
					continue;
				}

				bool bCritical = false;
				Damage_t Damage = computeDamage(pSlayer, pCreature, SkillLevel/5, bCritical) + SkillDamage;
				Damage = max(1, getPercentValue(Damage, BLAZE_WALK_2_SPLASH_PERCENT));

				if (pCreature->isPC() && pCreature->getCreatureClass() != pSlayer->getCreatureClass())
				{
					GCModifyInformation gcMI;
					::setDamage(pCreature, Damage, pSlayer, SkillType, &gcMI, &AttackerMI);
					computeAlignmentChange(pCreature, Damage, pSlayer, &gcMI, &AttackerMI);
					pCreature->getPlayer()->sendPacket(&gcMI);

					gcSkillToObjectOK2.setObjectID(pSlayer->getObjectID());
					gcSkillToObjectOK2.setSkillType(SKILL_ATTACK_MELEE);
					gcSkillToObjectOK2.setDuration(0);
					pCreature->getPlayer()->sendPacket(&gcSkillToObjectOK2);
				}
				else if (pCreature->isMonster())
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);
					::setDamage(pMonster, Damage, pSlayer, SkillType, NULL, &AttackerMI);
					pMonster->addEnemy(pSlayer);
				}
				else continue;

				gcSkillToObjectOK4.setTargetObjectID(pCreature->getObjectID());
				gcSkillToObjectOK4.setSkillType(SKILL_ATTACK_MELEE);
				gcSkillToObjectOK4.setDuration(0);
				pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcSkillToObjectOK4, pCreature);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////
// Slayer object handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType BlazeWalk2::execute(Slayer * pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot * pSkillSlot, CEffectID_t CEffectID)
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
			|| pTargetCreature->isNPC()
			|| !canAttack(pSlayer, pTargetCreature) )
		{
			executeSkillFailException(pSlayer, getSkillType());

			return SKILL_RESULT_FAIL_INVALID_TARGET;
		}

		bool bIncreaseDomainExp = pSlayer->isRealWearingEx(Slayer::WEAR_RIGHTHAND);

		Item* pItem = pSlayer->getWearItem(Slayer::WEAR_RIGHTHAND);
		if (pItem == NULL)
		{
			executeSkillFailException(pSlayer, getSkillType());
			
			return SKILL_RESULT_FAIL_INVALID_ITEM;
		}

		GCSkillToObjectOK1 _GCSkillToObjectOK1;
		GCSkillToObjectOK2 _GCSkillToObjectOK2;
		GCSkillToObjectOK3 _GCSkillToObjectOK3;
		GCSkillToObjectOK4 _GCSkillToObjectOK4;
		GCSkillToObjectOK5 _GCSkillToObjectOK5;
		GCSkillToObjectOK6 _GCSkillToObjectOK6;

		SkillType_t       SkillType  = pSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		SkillDomainType_t DomainType = pSkillInfo->getDomainType();
		SkillLevel_t      SkillLevel = pSkillSlot->getExpLevel();

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = verifyDistance(pSlayer, pTargetCreature, computeSkillRange(pSkillSlot, pSkillInfo));
		bool bHitRoll    = HitRoll::isSuccess(pSlayer, pTargetCreature, SkillLevel/2);
		bool bCanHit     = canHit(pSlayer, pTargetCreature, SkillType);
		bool bPK         = verifyPK(pSlayer, pTargetCreature);
		bool bEffected	 = !isAbleToUseSelfSkill(pSlayer); // 20071228

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && bCanHit && bPK && !bEffected )
		{
			if (pZone->moveFastPC(pSlayer, pSlayer->getX(), pSlayer->getY(), pTargetCreature->getX(), pTargetCreature->getY(), getSkillType())) 
			{
				decreaseMana(pSlayer, RequiredMP, _GCSkillToObjectOK1);

				SkillInput input(pSlayer, pSkillSlot);
				SkillOutput output;
				computeOutput(input, output);

				bool bCriticalHit = false;

				Damage_t BasicDamage = computeDamage(pSlayer, pTargetCreature, SkillLevel/5, bCriticalHit);
				Damage_t Damage = BasicDamage + output.Damage;
				setDamage(pTargetCreature, Damage, pSlayer, SkillType, &_GCSkillToObjectOK2, &_GCSkillToObjectOK1);
				computeAlignmentChange(pTargetCreature, Damage, pSlayer, &_GCSkillToObjectOK2, &_GCSkillToObjectOK1);
				decreaseDurability( pSlayer, pTargetCreature, pSkillInfo, &_GCSkillToObjectOK1, &_GCSkillToObjectOK2 );

				if (bCriticalHit)
				{
					knockbackCreature(pZone, pTargetCreature, pSlayer->getX(), pSlayer->getY());

					if ( pSlayer->isFlag( Effect::EFFECT_CLASS_BURST_GUN ) )
					{
						broadcastSimpleCreatureEffect( Effect::EFFECT_CLASS_SLAYER_BLOOD_BURST_HIT, pTargetCreature );
					}
				}

				splashBlazeWalk2(pSlayer, pTargetCreature, SkillType, SkillLevel, output.Damage, _GCSkillToObjectOK1);

				if (!pTargetCreature->isSlayer())
				{
					if ( bIncreaseDomainExp )
					{
						shareAttrExp(pSlayer, Damage, 8, 1, 1, _GCSkillToObjectOK1);
						increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), _GCSkillToObjectOK1, pTargetCreature->getLevel());
						increaseSkillExp(pSlayer, DomainType,  pSkillSlot, pSkillInfo, _GCSkillToObjectOK1);
					}
					increaseAlignment(pSlayer, pTargetCreature, _GCSkillToObjectOK1);
				}

				int AttackNum = 0;

				if ( input.SkillLevel < 50 ) AttackNum = 0;
				else if ( input.SkillLevel < 100 ) AttackNum = 1;
				else AttackNum = 2;

				EffectBlazeWalk* pEffect = new EffectBlazeWalk( pTargetCreature );
				pEffect->setPoint( 20 + input.SkillLevel/5 );
				pEffect->setSkillType( SkillType );
				pEffect->setUserObjectID( pSlayer->getObjectID() );
				pEffect->setAttackNum( AttackNum+1 );
				pEffect->setNextTime(5);
				pTargetCreature->setFlag( Effect::EFFECT_CLASS_BLAZE_WALK );
				pTargetCreature->addEffect( pEffect );

				_GCSkillToObjectOK1.setSkillType(SkillType);
				_GCSkillToObjectOK1.setCEffectID(CEffectID);
				_GCSkillToObjectOK1.setTargetObjectID(TargetObjectID);
				_GCSkillToObjectOK1.setDuration(0);
				_GCSkillToObjectOK1.setGrade( AttackNum );

				_GCSkillToObjectOK2.setObjectID(pSlayer->getObjectID());
				_GCSkillToObjectOK2.setSkillType(SkillType);
				_GCSkillToObjectOK2.setDuration(0);
				_GCSkillToObjectOK2.setGrade( AttackNum );

				_GCSkillToObjectOK3.setObjectID(pSlayer->getObjectID());
				_GCSkillToObjectOK3.setSkillType(getSkillType());
				_GCSkillToObjectOK3.setTargetXY(pTargetCreature->getX(), pTargetCreature->getY());
				_GCSkillToObjectOK3.setGrade( AttackNum );
			
				_GCSkillToObjectOK4.setSkillType(getSkillType());
				_GCSkillToObjectOK4.setTargetObjectID(TargetObjectID);
				_GCSkillToObjectOK4.setGrade( AttackNum );

				_GCSkillToObjectOK5.setObjectID(pSlayer->getObjectID());
				_GCSkillToObjectOK5.setTargetObjectID(TargetObjectID);
				_GCSkillToObjectOK5.setSkillType(getSkillType());
				_GCSkillToObjectOK5.setDuration(0);
				_GCSkillToObjectOK5.setGrade( AttackNum );
				
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

				list<Creature*> cList;
				cList.push_back(pSlayer);
				cList.push_back(pTargetCreature);

				cList = pZone->broadcastSkillPacket(pSlayer->getX(), pSlayer->getY(), pTargetCreature->getX(), pTargetCreature->getY(), &_GCSkillToObjectOK5, cList);
				
				pZone->broadcastPacket(pSlayer->getX(), pSlayer->getY(),  &_GCSkillToObjectOK3 , cList);
				pZone->broadcastPacket(pTargetCreature->getX(), pTargetCreature->getY(),  &_GCSkillToObjectOK4 , cList);

				pSkillSlot->setRunTime(output.Delay);
				
				return SKILL_RESULT_SUCCESS;
			} 
			else 
			{
				executeSkillFailNormal(pSlayer, getSkillType(), pTargetCreature);
			}
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

BlazeWalk2 g_BlazeWalk2;
