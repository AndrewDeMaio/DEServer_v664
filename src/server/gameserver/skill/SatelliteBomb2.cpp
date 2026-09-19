//////////////////////////////////////////////////////////////////////////////
// Filename    : SatelliteBomb2.cpp
// Written by  : excel96
// Description : Satellite Bomb 2 (skill 521). Same flow as Satellite Bomb (costs 10 bullets, aim then fire);
//               DEX-based damage from the v9 gameserver (SatelliteBomb2).
//////////////////////////////////////////////////////////////////////////////

#include "SatelliteBomb2.h"
#include "RareBookSkill.h"
#include "EffectSatelliteBombAim2.h"
#include "EffectSatelliteBombPoint2.h"

#include "ItemUtil.h"
#include "item/AR.h"
#include "item/SG.h"
#include "item/SR.h"
#include "item/SMG.h"

#include "Gpackets/GCSkillToTileOK1.h"
#include "Gpackets/GCSkillToTileOK2.h"
#include "Gpackets/GCSkillToTileOK3.h"
#include "Gpackets/GCSkillToTileOK4.h"
#include "Gpackets/GCSkillToTileOK5.h"
#include "Gpackets/GCSkillToTileOK6.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCAddEffectToTile.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
SkillResultType  SatelliteBomb2::execute(Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
    throw(Error)
{
    __BEGIN_TRY

	Assert(pSlayer != NULL);
	Assert(pSkillSlot != NULL);

    try
    {
		Zone* pZone = pSlayer->getZone();
		Assert(pZone != NULL);

		Creature* pTargetCreature = pZone->getCreature(TargetObjectID);
		//Assert(pTargetCreature != NULL);

		if (pTargetCreature==NULL
			|| !canAttack( pSlayer, pTargetCreature )
			|| pTargetCreature->isNPC()
			)
		{
			executeSkillFailException(pSlayer, getSkillType());
			
			return SKILL_RESULT_FAIL_INVALID_TARGET;
		}

		return execute(pSlayer, pTargetCreature->getX(), pTargetCreature->getY(), pSkillSlot, CEffectID);
    } 
	catch (Throwable & t) 
	{
		executeSkillFailException(pSlayer, getSkillType());
    }

    __END_CATCH
    
    return SKILL_RESULT_FAIL_UNKNOWN;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
SkillResultType SatelliteBomb2::execute(Slayer* pSlayer, ZoneCoord_t X, ZoneCoord_t Y, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	__BEGIN_TRY

	try 
	{
		Player* pPlayer = pSlayer->getPlayer();
		Zone* pZone = pSlayer->getZone();

		Assert(pPlayer != NULL);
		Assert(pZone != NULL);

		Item* pItem = pSlayer->getWearItem( Slayer::WEAR_RIGHTHAND );
		if ( pItem == NULL || isArmsWeapon( pItem ) == false )
		{
			executeSkillFailException( pSlayer, getSkillType() );
			
			return SKILL_RESULT_FAIL_INVALID_ITEM;
		}

		Item::ItemClass IClass = pItem->getItemClass();
		Bullet_t	bullet = 0;

		bool bBulletCheck = (getRemainBullet(pItem) > 0) ? true : false;
		
		if( !bBulletCheck )
		{
			executeSkillFailException( pSlayer, getSkillType() );
			
			return SKILL_RESULT_FAIL_NOT_ENOUGH_BULLET;

		}

		if( IClass == Item::ITEM_CLASS_AR )
		{
			AR* pAR = dynamic_cast<AR*>(pItem);
			bullet = max(0, (int)(pAR->getBulletCount() - 10));
			pAR->setBulletCount(bullet);
		}
		else if( IClass == Item::ITEM_CLASS_SR )
		{
			SR* pSR = dynamic_cast<SR*>(pItem);
			bullet = max(0, (int)(pSR->getBulletCount() - 10));
			pSR->setBulletCount(bullet);
		}
		else if( IClass == Item::ITEM_CLASS_SG )
		{
			SG* pSG = dynamic_cast<SG*>(pItem);
			bullet = max(0, (int)(pSG->getBulletCount() - 10));
			pSG->setBulletCount(bullet);
		}
		else if( IClass == Item::ITEM_CLASS_SMG )
		{
			SMG* pSMG = dynamic_cast<SMG*>(pItem);
			bullet = max(0, (int)(pSMG->getBulletCount() - 10));
			pSMG->setBulletCount(bullet);
		}

		GCSkillToTileOK1 _GCSkillToTileOK1;
		GCSkillToTileOK3 _GCSkillToTileOK3;
		GCSkillToTileOK4 _GCSkillToTileOK4;
		GCSkillToTileOK5 _GCSkillToTileOK5;
		GCSkillToTileOK6 _GCSkillToTileOK6;

		SkillType_t SkillType  = pSkillSlot->getSkillType();
		SkillInfo*  pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		//SkillDomainType_t DomainType = pSkillInfo->getDomainType();

		int  RequiredMP  = pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = verifyDistance(pSlayer, X, Y, pSkillInfo->getRange());
		bool bEffected	 = pSlayer->isFlag( Effect::EFFECT_CLASS_SATELLITE_BOMB_AIM_2 );

		bool bTileCheck = false;
		VSRect rect( 0, 0, pZone->getWidth()-1, pZone->getHeight()-1 );
		if ( rect.ptInRect( X, Y ) )
		{
			Tile& tile = pZone->getTile(X,Y);
			if ( tile.canAddEffect() ) bTileCheck = true;
		}

		if (bManaCheck && bTimeCheck && bRangeCheck && !bEffected && bTileCheck )
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToTileOK1);

			SkillInput input(pSlayer, pSkillSlot);
			SkillOutput output;
			computeOutput(input, output);

			Tile& tile = pZone->getTile( X, Y );

			Effect* pOldEffect = tile.getEffect(Effect::EFFECT_CLASS_SATELLITE_BOMB_POINT_2);
			if (pOldEffect != NULL)
			{
				ObjectID_t effectID = pOldEffect->getObjectID();
				pZone->deleteEffect(effectID);
			}

			EffectSatelliteBombAim2* pEffect = new EffectSatelliteBombAim2(pSlayer, pZone, X, Y);
//			pEffect->setDamage(output.Damage);
			pEffect->setDEX(input.DEX);

			// Satellite Bomb grows with the advancement level (Range - 10); book skills do not grow: use the max
			Attr_t skillLevel = RARE_BOOK_ADVANCEMENT_LEVEL - 10;
			pEffect->setSkillLevel(skillLevel);
			pEffect->setDeadline(output.Duration);
//			pEffect->setNextTime(10);

			pSlayer->addEffect( pEffect );
			pSlayer->setFlag( Effect::EFFECT_CLASS_SATELLITE_BOMB_AIM_2 );

			ZoneCoord_t myX = pSlayer->getX();
			ZoneCoord_t myY = pSlayer->getY();

			_GCSkillToTileOK1.setSkillType(SkillType);
			_GCSkillToTileOK1.setCEffectID(CEffectID);
			_GCSkillToTileOK1.setX(X);
			_GCSkillToTileOK1.setY(Y);
			_GCSkillToTileOK1.setDuration(output.Duration);
			_GCSkillToTileOK1.setRange(output.Range);
		
			_GCSkillToTileOK3.setObjectID(pSlayer->getObjectID());
			_GCSkillToTileOK3.setSkillType(SkillType);
			_GCSkillToTileOK3.setX(X);
			_GCSkillToTileOK3.setY(Y);
			
			_GCSkillToTileOK4.setSkillType(SkillType);
			_GCSkillToTileOK4.setX(X);
			_GCSkillToTileOK4.setY(Y);
			_GCSkillToTileOK4.setDuration(output.Duration);
			_GCSkillToTileOK4.setRange(output.Range);
		
			_GCSkillToTileOK5.setObjectID(pSlayer->getObjectID());
			_GCSkillToTileOK5.setSkillType(SkillType);
			_GCSkillToTileOK5.setX(X);
			_GCSkillToTileOK5.setY(Y);
			_GCSkillToTileOK5.setDuration(output.Duration);
			_GCSkillToTileOK5.setRange(output.Range);

			postSkillSuccessProcess( SkillType, pSlayer, &_GCSkillToTileOK1 );

			pPlayer->sendPacket(&_GCSkillToTileOK1);
		
			list<Creature*> cList;
			cList.push_back(pSlayer);

			cList = pZone->broadcastSkillPacket(myX, myY, X, Y, &_GCSkillToTileOK5, cList);

			pZone->broadcastPacket(myX, myY,  &_GCSkillToTileOK3 , cList);
			pZone->broadcastPacket(X, Y,  &_GCSkillToTileOK4 , cList);

			GCAddEffect gcAddAimEffect;
			gcAddAimEffect.setObjectID( pSlayer->getObjectID() );
			gcAddAimEffect.setEffectID( Effect::EFFECT_CLASS_SATELLITE_BOMB_AIM_2 );
			gcAddAimEffect.setDuration( output.Duration );
			pZone->broadcastPacket( myX, myY, &gcAddAimEffect );

			///////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////
			EffectSatelliteBombPoint2* pPointEffect = new EffectSatelliteBombPoint2( pZone, X, Y );
			pPointEffect->setDeadline( output.Duration );

			ObjectRegistry & objectRegister = pZone->getObjectRegistry();
			objectRegister.registerObject( pPointEffect );

			pZone->addEffect( pPointEffect );
			tile.addEffect( pPointEffect );

			GCAddEffectToTile gcAddEffectToTile;
			gcAddEffectToTile.setObjectID( pPointEffect->getObjectID() );
			gcAddEffectToTile.setEffectID( pPointEffect->getEffectClass() );
			gcAddEffectToTile.setXY( X, Y );
			gcAddEffectToTile.setDuration( output.Duration );

			pZone->broadcastPacket( X, Y, &gcAddEffectToTile );

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

SatelliteBomb2 g_SatelliteBomb2;
