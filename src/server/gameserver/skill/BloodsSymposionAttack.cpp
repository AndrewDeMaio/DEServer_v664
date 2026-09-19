//////////////////////////////////////////////////////////////////////////////
// Filename    : BloodsSymposionAttack.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "BloodsSymposionAttack.h"
#include "SimpleMissileSkill.h"
#include "EffectBloodsSymposionAttack.h"
#include "EffectBloodCurse.h"
#include "Effect.h"

#include "Gpackets/GCSkillToTileOK1.h"
#include "Gpackets/GCSkillToTileOK2.h"
#include "Gpackets/GCSkillToTileOK3.h"
#include "Gpackets/GCSkillToTileOK4.h"
#include "Gpackets/GCSkillToTileOK5.h"
#include "Gpackets/GCSkillToTileOK6.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCStatusCurrentHP.h"
#include "RankBonus.h"

//////////////////////////////////////////////////////////////////////////////
// Puts the Symposion effect on one creature.
// Monsters lose the stats directly instead of through Monster::initAllStat, which
// would reset max HP that was set elsewhere (summons, event monsters). The effect
// keeps the amounts actually taken so unaffect gives back exactly that much.
//////////////////////////////////////////////////////////////////////////////
static void addBloodsSymposionEffect(Zone* pZone, Creature* pCreature, Duration_t duration, int DefensePenalty, int ProtectionPenalty, int HPPenalty)
{
	if( pCreature->isMonster() )
	{
		Monster* pMonster = dynamic_cast<Monster*>(pCreature);

		DefensePenalty    = min( DefensePenalty, (int)pMonster->getDefense() );
		ProtectionPenalty = min( ProtectionPenalty, (int)pMonster->getProtection() );
		HPPenalty         = max( 0, min( HPPenalty, (int)pMonster->getHP(ATTR_MAX) - 1 ) );

		pMonster->setDefense( pMonster->getDefense() - DefensePenalty );
		pMonster->setProtection( pMonster->getProtection() - ProtectionPenalty );
		pMonster->setHP( pMonster->getHP(ATTR_MAX) - HPPenalty, ATTR_MAX );

		if( pMonster->getHP(ATTR_CURRENT) > pMonster->getHP(ATTR_MAX) )
		{
			pMonster->setHP( pMonster->getHP(ATTR_MAX), ATTR_CURRENT );

			GCStatusCurrentHP gcHP;
			gcHP.setObjectID( pMonster->getObjectID() );
			gcHP.setCurrentHP( pMonster->getHP(ATTR_CURRENT) );
			pZone->broadcastPacket( pMonster->getX(), pMonster->getY(), &gcHP );
		}
	}

	EffectBloodsSymposionAttack* pEffect = new EffectBloodsSymposionAttack(pCreature);
	pEffect->setDeadline( duration );
	pEffect->setDefensePenalty( DefensePenalty );
	pEffect->setProtectionPenalty( ProtectionPenalty );
	pEffect->setHPPenalty( HPPenalty );

	pCreature->setFlag(Effect::EFFECT_CLASS_BLOODS_SYMPOSION_ATTACK);
	pCreature->addEffect(pEffect);

	if( pCreature->isSlayer() )
	{
		Slayer* pSlayer = dynamic_cast<Slayer*>(pCreature);
		SLAYER_RECORD prev;
		pSlayer->getSlayerRecord(prev);
		pSlayer->initAllStat();
		pSlayer->sendModifyInfo(prev);
	}
	else if( pCreature->isOusters() )
	{
		Ousters* pOusters = dynamic_cast<Ousters*>(pCreature);
		OUSTERS_RECORD prev;
		pOusters->getOustersRecord(prev);
		pOusters->initAllStat();
		pOusters->sendModifyInfo(prev);
	}

	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID( pCreature->getObjectID() );
	gcAddEffect.setEffectID( Effect::EFFECT_CLASS_BLOODS_SYMPOSION_ATTACK );
	gcAddEffect.setDuration( duration );
	pZone->broadcastPacket( pCreature->getX(), pCreature->getY(), &gcAddEffect );
}

//////////////////////////////////////////////////////////////////////////////
// 뱀파이어 오브젝트 핸들러
//////////////////////////////////////////////////////////////////////////////
SkillResultType BloodsSymposionAttack::execute(Vampire* pVampire, ObjectID_t TargetObjectID, VampireSkillSlot* pVampireSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	//cout << "TID[" << Thread::self() << "]" << getSkillHandlerName() << " Begin(vampire)" << endl;
	Zone* pZone = pVampire->getZone();
	Assert(pZone != NULL);

	Creature* pTargetCreature = pZone->getCreature(TargetObjectID);

	if( pTargetCreature == NULL	)
	{
		executeSkillFailException(pVampire, getSkillType());

		return SKILL_RESULT_FAIL_INVALID_TARGET;
	}

	Player* pPlayer = pVampire->getPlayer();
	ZoneCoord_t	X	= pTargetCreature->getX();
	ZoneCoord_t	Y	= pTargetCreature->getY();

	SkillInput input(pVampire);
	SkillOutput output;
	computeOutput(input, output);

	GCSkillToTileOK1		_GCSkillToTileOK1;
	GCSkillToTileOK2		_GCSkillToTileOK2;
	GCSkillToTileOK3		_GCSkillToTileOK3;
	GCSkillToTileOK4		_GCSkillToTileOK4;
	GCSkillToTileOK5		_GCSkillToTileOK5;
	GCSkillToTileOK6		_GCSkillToTileOK6;

	SkillType_t	SkillType = getSkillType();
	SkillInfo*	pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);

	EffectManager* pEffectManager = pVampire->getEffectManager();
	Assert( pEffectManager != NULL );

	Effect* pEffectCurse = NULL;
	Effect* pEffectBloodsSymposion = NULL;
	pEffectCurse = dynamic_cast<EffectBloodCurse*>( pEffectManager->findEffect( Effect::EFFECT_CLASS_BLOOD_CURSE ) );
	pEffectBloodsSymposion = dynamic_cast<EffectBloodsSymposionAttack*>( pEffectManager->findEffect( Effect::EFFECT_CLASS_BLOODS_SYMPOSION_ATTACK) );

	if( pEffectCurse == NULL || pEffectBloodsSymposion != NULL )
	{
		executeSkillFailNormal(pVampire, getSkillType(), pTargetCreature);

		return SKILL_RESULT_FAIL_NOT_ENOUGH_PRECONDITIONS;
	}

	Damage_t	SkillDamage = 0;
	Dir_t		dir			= calcDirection(pVampire->getX(), pVampire->getY(), pTargetCreature->getX(), pTargetCreature->getY());
	VSRect rect(1, 1, pZone->getWidth()-2, pZone->getHeight()-2);
	list<Creature*> cList;

	// Advancement levels past 10 feed the hit bonus, the penalties and the duration.
	Level_t advenceClassLevel = max( 0, input.Range - 10 );

	// canAttack also rejects dead, coma and NPC targets. Everything is checked before
	// the dash, so a bad target can no longer use up the Blood Curse.
	int  RequiredMP		= (int)pSkillInfo->getConsumeMP();
	bool bCanAttack		= canAttack( pVampire, pTargetCreature );
	bool bRangeCheck	= verifyDistance( pVampire, pTargetCreature, pSkillInfo->getRange() );
	bool bPK			= verifyPK( pVampire, pTargetCreature );
	bool bZoneLevelCheck= checkZoneLevelToHitTarget(pTargetCreature);
	bool bManaCheck		= hasEnoughMana(pVampire, RequiredMP);

	if( !bCanAttack || !bRangeCheck || !bPK || !bZoneLevelCheck || !bManaCheck
		|| !HitRoll::isSuccess( pVampire, pTargetCreature, advenceClassLevel/2 ) )
	{
		executeSkillFailException(pVampire, getSkillType());

		return SKILL_RESULT_FAIL_INVALID_TARGET;
	}

	if( !pZone->moveFastPC( pVampire, pVampire->getX(), pVampire->getY(), X, Y, getSkillType() ) )
	{
		executeSkillFailNormal(pVampire, getSkillType(), pTargetCreature);

		return SKILL_RESULT_FAIL_CANNOT_USE_IN_ZONE;
	}

	decreaseMana( pVampire, RequiredMP, _GCSkillToTileOK1 );

	for( int x = -2; x <= 2; ++x )
	{
		for( int y = -2; y <= 2; ++y )
		{
			int tileX = pVampire->getX()+x;
			int tileY = pVampire->getY()+y;

			if( !rect.ptInRect( tileX, tileY ) )
				continue;

			Tile& tile = pZone->getTile(tileX, tileY);
			Creature* pCreature = NULL;

			if( tile.hasCreature( Creature::MOVE_MODE_WALKING) )
				pCreature = tile.getCreature(Creature::MOVE_MODE_WALKING);
			else if( tile.hasCreature( Creature::MOVE_MODE_FLYING) )
				pCreature = tile.getCreature(Creature::MOVE_MODE_FLYING);
			else if( tile.hasCreature( Creature::MOVE_MODE_BURROWING) )
				pCreature = tile.getCreature(Creature::MOVE_MODE_BURROWING);

			_GCSkillToTileOK1.addCListElement(TargetObjectID);
			_GCSkillToTileOK2.addCListElement(TargetObjectID);
			_GCSkillToTileOK5.addCListElement(TargetObjectID);

			if( pCreature == NULL || pCreature == pVampire )
				continue;

			bool bMainTarget = ( pCreature == pTargetCreature );

			// The splash gets the same checks as the main target, and other vampires
			// (party members included) are left alone.
			if( !bMainTarget
				&& ( pCreature->isVampire()
					|| !canAttack( pVampire, pCreature )
					|| !verifyPK( pVampire, pCreature )
					|| !checkZoneLevelToHitTarget( pCreature ) ) )
				continue;

			cList.push_back( pCreature );

			SkillDamage = min( 215, input.STR/3 + input.STR/50 + input.DEX/10 + input.Range*2 );
			if( !bMainTarget )
				SkillDamage = Damage_t(SkillDamage * 0.75);

			GCModifyInformation	gcMI;

			setDamage( pCreature, SkillDamage, pVampire, SkillType, &gcMI, &_GCSkillToTileOK1);

			if( pCreature->isPC() )
			{
				pCreature->getPlayer()->sendPacket(&gcMI);
			}

			computeAlignmentChange( pCreature, SkillDamage, pVampire, &gcMI, &_GCSkillToTileOK1);
			decreaseDurability(pVampire, pCreature, pSkillInfo, &_GCSkillToTileOK1, &_GCSkillToTileOK6);

			increaseAlignment(pVampire, pCreature, _GCSkillToTileOK1);

			if( pCreature->isDead() )
			{
				int exp = computeCreatureExp(pCreature, KILL_EXP);
				shareVampExp(pVampire, exp, _GCSkillToTileOK1);
			}

			if( pCreature->isMonster() )
			{
				Monster* pMonster = dynamic_cast<Monster*>(pCreature);
				pMonster->addEnemy(pVampire);
			}
		}
	}

	_GCSkillToTileOK1.setSkillType(SkillType);
	_GCSkillToTileOK1.setCEffectID(NULL);
	_GCSkillToTileOK1.setX(X);
	_GCSkillToTileOK1.setY(Y);
	_GCSkillToTileOK1.setRange(dir);
	_GCSkillToTileOK1.setDuration(0);
	_GCSkillToTileOK1.setGrade(advenceClassLevel);

	_GCSkillToTileOK2.setObjectID(pVampire->getObjectID());
	_GCSkillToTileOK2.setSkillType(SkillType);
	_GCSkillToTileOK2.setX(X);
	_GCSkillToTileOK2.setY(Y);
	_GCSkillToTileOK2.setRange(dir);
	_GCSkillToTileOK2.setDuration(0);
	_GCSkillToTileOK2.setGrade(advenceClassLevel);

	_GCSkillToTileOK5.setObjectID(pVampire->getObjectID());
	_GCSkillToTileOK5.setSkillType(SkillType);
	_GCSkillToTileOK5.setX(X);
	_GCSkillToTileOK5.setY(Y);
	_GCSkillToTileOK5.setRange(dir);
	_GCSkillToTileOK5.setDuration(0);
	_GCSkillToTileOK5.setGrade(advenceClassLevel);

	postSkillSuccessProcess( SkillType, pVampire, &_GCSkillToTileOK1);

	pPlayer->sendPacket(&_GCSkillToTileOK1);

//	Duration_t duration = (10+input.DEX/30+advenceClassLevel)*10;
	Duration_t duration = min(450, (10+(input.DEX/20+advenceClassLevel*2))*10);
	int PenaltyBase = input.STR/3 + input.DEX/8 + advenceClassLevel*2;
	int DefensePenalty = min( 150, int(PenaltyBase*0.8) );
	int HPPenalty = min( 250, int(PenaltyBase*1.3) );

	for( list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr )
	{
		Creature* pTargetCreature1 = *itr;
		Assert( pTargetCreature1 != NULL );

		// A second copy would wipe the first one's penalty when either expires.
		if( pTargetCreature1->isDead()
			|| pTargetCreature1->isFlag(Effect::EFFECT_CLASS_BLOODS_SYMPOSION_ATTACK)
			|| ( pTargetCreature1->isMonster() && pTargetCreature1->isFlag(Effect::EFFECT_CLASS_IMMUNE_TO_CURSE) ) )
			continue;

		addBloodsSymposionEffect( pZone, pTargetCreature1, duration, DefensePenalty, DefensePenalty, HPPenalty );
	}

	// The caster carries the effect too, with no penalty. It keeps Blood Curse and
	// this skill locked until it ends.
	addBloodsSymposionEffect( pZone, pVampire, duration, 0, 0, 0 );

	pEffectCurse->setDeadline(0);

	cList.push_back(pVampire);

	pZone->broadcastPacket(X, Y, &_GCSkillToTileOK5, cList);

	return SKILL_RESULT_SUCCESS;

	__END_CATCH
}

BloodsSymposionAttack g_BloodsSymposionAttack;
