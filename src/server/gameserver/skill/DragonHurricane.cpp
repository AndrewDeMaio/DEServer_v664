//////////////////////////////////////////////////////////////////////////////
// Filename    : DragonHurricane.cpp
// Written by  : elca@ewestsoft.com
// Description : Dragon Hurricane (skill 548, level 181 Blade): a Blade hit that leaves a tornado which splits into
//               smaller tornados (same flow as Dragon Tornado); ported from the v9 gameserver (DragonHurricane).
//////////////////////////////////////////////////////////////////////////////

#include "DragonHurricane.h"
#include "SimpleMeleeSkill.h"
#include "EffectDragonHurricane.h"

#include "Gpackets/GCAddEffectToTile.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
SkillResultType DragonHurricane::execute(Slayer * pSlayer, ObjectID_t TargetObjectID, SlayerSkillSlot * pSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	SkillResultType skillResult;
	
	__BEGIN_TRY

	SkillInput input(pSlayer, pSkillSlot);
	SkillOutput output;
	computeOutput(input, output);

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;
	param.Delay         = output.Delay;
	param.ItemClass     = Item::ITEM_CLASS_BLADE;
	param.STRMultiplier = 8;
	param.DEXMultiplier = 1;
	param.INTMultiplier = 1;
	param.bMagicHitRoll = false;
	param.bMagicDamage  = false;
	param.bAdd          = true;

	SIMPLE_SKILL_OUTPUT result;

	skillResult = g_SimpleMeleeSkill.execute(pSlayer, TargetObjectID, pSkillSlot, param, result);

	if (result.bSuccess)
	{
		Zone* pZone = pSlayer->getZone();
		Assert(pZone!=NULL);

		Creature* pCreature = pZone->getCreature( TargetObjectID );

		if (pCreature!=NULL)
		{
			if (pCreature->isMonster())
			{
				Monster* pMonster = dynamic_cast<Monster*>(pCreature);

				if (!pMonster->isMaster())
				{
					Timeval delay;
					delay.tv_sec  = 1;
					delay.tv_usec = 0;//500000;
					pMonster->addAccuDelay(delay);
				}
			}

			Tile& tile = pZone->getTile( pCreature->getX(), pCreature->getY() );

			if ( tile.canAddEffect() )
			{
				EffectDragonHurricane* pEffect = new EffectDragonHurricane( pZone, pCreature->getX(), pCreature->getY() );
				pEffect->setUserOID( pSlayer->getObjectID() );
				pEffect->setTargetOID( TargetObjectID );
				pEffect->setDamage( output.Range );
				pEffect->setChildDamage( output.Tick );
				pEffect->setDeadline( output.Duration );
				pEffect->setNextTime(10);
				pZone->registerObject( pEffect );
				tile.addEffect( pEffect );
				pZone->addEffect( pEffect );

				GCAddEffectToTile gcAE;
				gcAE.setEffectID( pEffect->getSendEffectClass() );
				gcAE.setObjectID( pEffect->getObjectID() );
				gcAE.setDuration( output.Duration );
				gcAE.setXY( pCreature->getX(), pCreature->getY() );
				pZone->broadcastPacket( pCreature->getX(), pCreature->getY(), &gcAE );
			}
		}
	}
	
	__END_CATCH
	
	return skillResult;
}

DragonHurricane g_DragonHurricane;
