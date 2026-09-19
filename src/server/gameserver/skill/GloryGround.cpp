//////////////////////////////////////////////////////////////////////////////
// Filename    : GloryGround.cpp
// Written by  :
// Description : Glory Ground (skill 526). Ported from the v9 gameserver (GloryGround): a 5x5 field
//               (one EffectGloryGround per tile) that heals Slayers and hurts enemies standing in it.
//               Clears Darkness / Bloody Wall from the area like Heaven Ground does, and cannot
//               overlap another Glory Ground or be cast into a safe zone. Shares its cooldown with
//               Regeneration on the client.
//////////////////////////////////////////////////////////////////////////////

#include "GloryGround.h"
#include "EffectGloryGround.h"

#include "Gpackets/GCSkillToTileOK1.h"
#include "Gpackets/GCSkillToTileOK3.h"
#include "Gpackets/GCSkillToTileOK4.h"
#include "Gpackets/GCSkillToTileOK5.h"
#include "Gpackets/GCAddEffectToTile.h"
#include "Gpackets/GCDeleteEffectFromTile.h"

static const int GLORY_GROUND_RADIUS = 2;	// 5x5

//////////////////////////////////////////////////////////////////////////////
// Slayer object handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType GloryGround::execute( Slayer* pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID )
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

		if (pTargetCreature == NULL)
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
// Slayer tile handler
//////////////////////////////////////////////////////////////////////////////
SkillResultType GloryGround::execute( Slayer* pSlayer, ZoneCoord_t X, ZoneCoord_t Y, SlayerSkillSlot* pSkillSlot, CEffectID_t CEffectID )
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

		GCSkillToTileOK1 _GCSkillToTileOK1;
		GCSkillToTileOK3 _GCSkillToTileOK3;
		GCSkillToTileOK4 _GCSkillToTileOK4;
		GCSkillToTileOK5 _GCSkillToTileOK5;

		SkillType_t       SkillType  = pSkillSlot->getSkillType();
		SkillInfo*        pSkillInfo = g_pSkillInfoManager->getSkillInfo(SkillType);
		SkillDomainType_t DomainType = pSkillInfo->getDomainType();

		ZoneCoord_t myX = pSlayer->getX();
		ZoneCoord_t myY = pSlayer->getY();

		int  RequiredMP  = (int)pSkillInfo->getConsumeMP();
		bool bManaCheck  = hasEnoughMana(pSlayer, RequiredMP);
		bool bTimeCheck  = verifyRunTime(pSkillSlot);
		bool bRangeCheck = verifyDistance(pSlayer, X, Y, pSkillInfo->getRange()) && checkZoneLevelToUseSkill(pSlayer);
		bool bHitRoll    = HitRoll::isSuccessMagic(pSlayer, pSkillInfo, pSkillSlot);
		bool bEffected   = pSlayer->isFlag(Effect::EFFECT_CLASS_GLORY_GROUND);
		bool bTileCheck  = false;

		VSRect rect(0, 0, pZone->getWidth()-1, pZone->getHeight()-1);

		if (rect.ptInRect(X, Y))
		{
			Tile& tile = pZone->getTile(X, Y);

			// v9: not into a vampire or complete safe zone, not onto a Summon Clay
			ZoneLevel_t ZoneLevel = pZone->getZoneLevel(X, Y);
			if (tile.canAddEffect()
				&& tile.getEffect(Effect::EFFECT_CLASS_SUMMON_CLAY) == NULL
				&& !(ZoneLevel & VAMPIRE_SAFE_ZONE)
				&& !(ZoneLevel & COMPLETE_SAFE_ZONE))
			{
				bTileCheck = true;
			}
		}

		// Glory Grounds do not overlap
		for (int oY = -GLORY_GROUND_RADIUS; bTileCheck && oY <= GLORY_GROUND_RADIUS; oY++)
		for (int oX = -GLORY_GROUND_RADIUS; bTileCheck && oX <= GLORY_GROUND_RADIUS; oX++)
		{
			int tileX = X + oX;
			int tileY = Y + oY;
			if (rect.ptInRect(tileX, tileY) && pZone->getTile(tileX, tileY).getEffect(Effect::EFFECT_CLASS_GLORY_GROUND) != NULL)
				bTileCheck = false;
		}

		if (bManaCheck && bTimeCheck && bRangeCheck && bHitRoll && !bEffected && bTileCheck)
		{
			decreaseMana(pSlayer, RequiredMP, _GCSkillToTileOK1);

			SkillInput input(pSlayer, pSkillSlot);
			SkillOutput output;
			computeOutput(input, output);

			Range_t Range = 5;

			for (int oY = -GLORY_GROUND_RADIUS; oY <= GLORY_GROUND_RADIUS; oY++)
			for (int oX = -GLORY_GROUND_RADIUS; oX <= GLORY_GROUND_RADIUS; oX++)
			{
				int tileX = X + oX;
				int tileY = Y + oY;

				if (!rect.ptInRect(tileX, tileY)) continue;

				Tile& tile = pZone->getTile(tileX, tileY);
				if (!tile.canAddEffect()) continue;

				// the field burns away Darkness and Bloody Wall
				Effect* pDeleteEffects[2] = { tile.getEffect(Effect::EFFECT_CLASS_DARKNESS), tile.getEffect(Effect::EFFECT_CLASS_BLOODY_WALL) };
				for (int i = 0; i < 2; i++)
				{
					Effect* pDeleteEffect = pDeleteEffects[i];
					if (pDeleteEffect == NULL) continue;

					pDeleteEffect->setDeadline(0);

					GCDeleteEffectFromTile gcDeleteEffectFromTile;
					gcDeleteEffectFromTile.setXY(tileX, tileY);
					gcDeleteEffectFromTile.setObjectID(pDeleteEffect->getObjectID());
					gcDeleteEffectFromTile.setEffectID(pDeleteEffect->getEffectClass());
					pZone->broadcastPacket(tileX, tileY, &gcDeleteEffectFromTile);
				}

				EffectGloryGround* pEffect = new EffectGloryGround(pZone, tileX, tileY);
				pEffect->setDeadline(output.Duration);
				pEffect->setDamage(output.Damage);
				pEffect->setUserObjectID(pSlayer->getObjectID());
				pEffect->setDelay(output.Tick);
				pEffect->setNextTime(0);
				// only the center tile tells the client; the field visual covers the area
				pEffect->setBroadcastingEffect(oX == 0 && oY == 0);

				ObjectRegistry& objectRegister = pZone->getObjectRegistry();
				objectRegister.registerObject(pEffect);

				pZone->addEffect(pEffect);
				tile.addEffect(pEffect);

				if (oX == 0 && oY == 0)
				{
					GCAddEffectToTile gcAddEffectToTile;
					gcAddEffectToTile.setEffectID(pEffect->getEffectClass());
					gcAddEffectToTile.setObjectID(pEffect->getObjectID());
					gcAddEffectToTile.setXY(tileX, tileY);
					gcAddEffectToTile.setDuration(output.Duration);
					pZone->broadcastPacket(tileX, tileY, &gcAddEffectToTile);
				}
			}

			SkillGrade Grade = g_pSkillInfoManager->getGradeByDomainLevel(pSlayer->getSkillDomainLevel(DomainType));
			Exp_t ExpUp = 10* (Grade + 1);
			shareAttrExp(pSlayer, ExpUp, 1, 1, 8, _GCSkillToTileOK1);
			increaseDomainExp(pSlayer, DomainType, pSkillInfo->getPoint(), _GCSkillToTileOK1);
			increaseSkillExp(pSlayer, DomainType, pSkillSlot, pSkillInfo, _GCSkillToTileOK1);

			_GCSkillToTileOK1.setSkillType(SkillType);
			_GCSkillToTileOK1.setCEffectID(CEffectID);
			_GCSkillToTileOK1.setX(X);
			_GCSkillToTileOK1.setY(Y);
			_GCSkillToTileOK1.setDuration(output.Duration);
			_GCSkillToTileOK1.setRange(Range);

			_GCSkillToTileOK3.setObjectID(pSlayer->getObjectID());
			_GCSkillToTileOK3.setSkillType(SkillType);
			_GCSkillToTileOK3.setX(X);
			_GCSkillToTileOK3.setY(Y);

			_GCSkillToTileOK4.setSkillType(SkillType);
			_GCSkillToTileOK4.setX(X);
			_GCSkillToTileOK4.setY(Y);
			_GCSkillToTileOK4.setRange(Range);
			_GCSkillToTileOK4.setDuration(output.Duration);

			_GCSkillToTileOK5.setObjectID(pSlayer->getObjectID());
			_GCSkillToTileOK5.setSkillType(SkillType);
			_GCSkillToTileOK5.setX(X);
			_GCSkillToTileOK5.setY(Y);
			_GCSkillToTileOK5.setRange(Range);
			_GCSkillToTileOK5.setDuration(output.Duration);

			postSkillSuccessProcess( SkillType, pSlayer, &_GCSkillToTileOK1 );

			pPlayer->sendPacket(&_GCSkillToTileOK1);

			list<Creature*> cList;
			cList.push_back(pSlayer);

			cList = pZone->broadcastSkillPacket(myX, myY, X, Y, &_GCSkillToTileOK5, cList);

			pZone->broadcastPacket(myX, myY, &_GCSkillToTileOK3, cList);
			pZone->broadcastPacket(X, Y, &_GCSkillToTileOK4, cList);

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

GloryGround g_GloryGround;
