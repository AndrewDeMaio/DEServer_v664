//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectThorns.cpp
// Written by  : bezz
//////////////////////////////////////////////////////////////////////////////

#include "EffectThorns.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"
#include "GamePlayer.h"
#include "PCFinder.h"
#include "ZoneUtil.h"
#include "ZoneInfoManager.h"
#include "SkillUtil.h"
#include "Gpackets/GCRemoveEffect.h"
#include "Gpackets/GCAddEffectToTile.h"
#include "Gpackets/GCSkillToObjectOK2.h"
#include "Gpackets/GCSkillToObjectOK4.h"
#include "Gpackets/GCStatusCurrentHP.h"

#include "SkillInfo.h"
#include "SkillSlot.h"

#ifdef VERSION_SKILL_1
	#include "HitRoll.h"
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectThorns::EffectThorns(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectThorns::affect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);	// by Sequoia

	if ( pCreature != NULL )
	{
		affect(pCreature);
	}
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectThorns::affect(Creature* pEffectedCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pEffectedCreature != NULL);

	if ( !pEffectedCreature->isSlayer() )
		return;

	Player* pPlayer = dynamic_cast<Player*>(pEffectedCreature->getPlayer());
	Assert( pPlayer != NULL );

	Slayer* pSlayer = dynamic_cast<Slayer*>(pEffectedCreature);
	Assert( pSlayer != NULL );

//	20080508 Thorns �� ��� ����Ʈ�� ���� �پ� �ٴϹǷ� ���� �̵��ص� ��� ���ӵǵ��� �Ѵ�.
//	Creature* pEffectedCreature = pSlayer->getZone()->getCreature( getCasterID() );
//	bool isCaster = pEffectedCreature == pEffectedCreature;

	SkillInfo* pSkillInfo = g_pSkillInfoManager->getSkillInfo( SKILL_THORNS );
	if ( pSkillInfo == NULL )
	{
		return;
	}

	GCModifyInformation gcAttackerMI;

	Zone* pZone = pEffectedCreature->getZone();
	Assert( pZone != NULL );

	VSRect rect( 0, 0, pZone->getWidth()-1, pZone->getHeight()-1 );

	ZoneCoord_t Cx = pEffectedCreature->getX();
	ZoneCoord_t Cy = pEffectedCreature->getY();

	bool isHit = false;

	Level_t maxEnemyLevel = 0;
	uint EnemyNum = 0;

	// radius 2 (5x5 around the caster); Spirit Guard, the base skill, keeps the 3x3 ring
	for ( int x=-2; x<=2; x++ )
	{
		for ( int y=-2; y<=2; y++ )
		{
			if ( x == 0 && y == 0 ) continue;

			int X = Cx + x;
			int Y = Cy + y;

			if ( !rect.ptInRect( X, Y ) ) continue;

			// Ÿ�Ͼȿ� �����ϴ� ������Ʈ�� �����´�.
			Tile& tile = pZone->getTile( X, Y );

			if( tile.hasCreature(Creature::MOVE_MODE_WALKING) )
			{
				Creature* pCreature = tile.getCreature(Creature::MOVE_MODE_WALKING);
				Assert( pCreature != NULL );

				// �ڽ��� ���� �ʴ´�. ������ �� �´´�. �����̾ �� �´���.
				// �������� üũ
				// 2003.1.10 by bezz, Sequoia
				if ( pCreature == m_pTarget
				  || !canAttack( pEffectedCreature, pCreature )
				  || pCreature->isFlag( Effect::EFFECT_CLASS_COMA )
				  || pCreature->isSlayer() 
				  || pCreature->isNPC()
				  || !checkZoneLevelToHitTarget(pCreature)
#ifdef VERSION_SKILL_1
				  || !HitRoll::isSuccessMagic(pEffectedCreature, pCreature)
#endif
				)
				{
					continue;
				}

				isHit = true;

				if ( maxEnemyLevel < pCreature->getLevel() ) maxEnemyLevel = pCreature->getLevel();
				EnemyNum++;
///////////////////////////////////////////////////////////////////////////////////////////////////////
//		���װ��� ����...
#ifndef VERSION_SKILL_1
				Damage_t damage = computeMagicDamage(pCreature, m_Damage, SKILL_THORNS);
#else
				Damage_t damage = m_Damage;
#endif

				if ( pCreature->isVampire() || pCreature->isOusters() )
				{
//					Vampire* pVampire = dynamic_cast<Vampire*>(pCreature);

					GCModifyInformation gcMI;
					::setDamage( pCreature, damage, pEffectedCreature, SKILL_THORNS, &gcMI, &gcAttackerMI );

					pCreature->getPlayer()->sendPacket( &gcMI );

					// �´� ������ �����ش�.
					GCSkillToObjectOK2 gcSkillToObjectOK2;
					gcSkillToObjectOK2.setObjectID( 1 );    // �ǹ� ����.
					gcSkillToObjectOK2.setSkillType( SKILL_ATTACK_MELEE );
					gcSkillToObjectOK2.setDuration(0);
					pCreature->getPlayer()->sendPacket(&gcSkillToObjectOK2);

				}
				else if ( pCreature->isMonster() )
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);

					::setDamage( pMonster, damage, pEffectedCreature, SKILL_THORNS, NULL, &gcAttackerMI );

					pMonster->addEnemy( pEffectedCreature );
				}
				else Assert(false);

				GCSkillToObjectOK4 gcSkillToObjectOK4;
				gcSkillToObjectOK4.setSkillType( SKILL_ATTACK_MELEE );
				gcSkillToObjectOK4.setTargetObjectID( pCreature->getObjectID() );
				gcSkillToObjectOK4.setDuration(0);

				pZone->broadcastPacket( X, Y, &gcSkillToObjectOK4, pCreature );
			}
		}
	}

	if ( isHit )
	{
		SkillDomainType_t DomainType = pSkillInfo->getDomainType();
		SlayerSkillSlot* pSkillSlot = pSlayer->getSkill( SKILL_THORNS );

		if ( pSkillSlot != NULL )
		{
			increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), gcAttackerMI, maxEnemyLevel, EnemyNum);
			increaseSkillExp(pSlayer, DomainType, pSkillSlot, pSkillInfo, gcAttackerMI);
		}
	}

	pPlayer->sendPacket(&gcAttackerMI);

	setNextTime( m_Delay );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectThorns::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	
	// cout << "EffectThorns " << "unaffect BEGIN" << endl;
	Assert(pCreature != NULL);

	if ( !pCreature->isSlayer() )
		return;

	Player* pPlayer = dynamic_cast<Player*>(pCreature->getPlayer());
	Assert( pPlayer != NULL );

	Zone* pZone = pCreature->getZone();
	Assert( pZone != NULL );

	// Effect�� ���ְ� �˸���.
	pCreature->removeFlag( Effect::EFFECT_CLASS_THORNS );

	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID( pCreature->getObjectID() );
	gcRemoveEffect.addEffectList( Effect::EFFECT_CLASS_THORNS );

	pPlayer->sendPacket( &gcRemoveEffect );
	pZone->broadcastPacket( pCreature->getX(), pCreature->getY(), &gcRemoveEffect, pCreature );

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectThorns::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature*>(m_pTarget);	// by Sequoia

	if ( pCreature != NULL )
	{
		unaffect(pCreature);
	}
	
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//void EffectThorns::setLevel(SkillLevel_t Level)
//{
//	if( Level <= GRADE_ADEPT_LIMIT_LEVEL ) m_EffectClass = EFFECT_CLASS_THORNS;
//	else if( Level <= GRADE_EXPERT_LIMIT_LEVEL ) m_EffectClass = EFFECT_CLASS_THORNS_2;
//	else if( Level <= GRADE_MASTER_LIMIT_LEVEL ) m_EffectClass = EFFECT_CLASS_THORNS_3;
//	else m_EffectClass = EFFECT_CLASS_THORNS_4;
//}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectThorns::toString() const 
	throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectThorns("
		<< "Damage:" << (int)m_Damage
		<< ", EffectClass:" << (int)Effect::EFFECT_CLASS_THORNS
		<< ")";
	return msg.toString();

	__END_CATCH
}

