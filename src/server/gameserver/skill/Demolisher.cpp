//////////////////////////////////////////////////////////////////////////////
// Filename    : Demolisher.cpp
// Written by  : 
// Description : Demolisher (skill 558). An upgraded Destinies: a magic hit on one enemy (wristlet), then after
//               1 s the chain (EffectDemolisher) hits up to 10 other enemies within 5 tiles of it for half damage.
//////////////////////////////////////////////////////////////////////////////

#include "Demolisher.h"
#include "SimpleMissileSkill.h"
#include "EffectDemolisher.h"
#include "Zone.h"
#include "ZoneUtil.h"
#include "Utility.h"

SkillResultType Demolisher::execute(Ousters* pOusters, ObjectID_t TargetObjectID, OustersSkillSlot* pOustersSkillSlot, CEffectID_t CEffectID)
	throw(Error)
{
	SkillResultType skillResult;
	
	__BEGIN_TRY

	SkillInput input(pOusters, pOustersSkillSlot);
	SkillOutput output;
	computeOutput(input, output);

	SIMPLE_SKILL_INPUT param;
	param.SkillType     = getSkillType();
	param.SkillDamage   = output.Damage;
	param.Delay         = output.Delay;
	param.ItemClass     = Item::ITEM_CLASS_OUSTERS_WRISTLET;
	param.STRMultiplier = 0;
	param.DEXMultiplier = 0;
	param.INTMultiplier = 0;
	param.bMagicHitRoll = true;
	param.bMagicDamage  = true;
	param.bAdd          = false;

	SIMPLE_SKILL_OUTPUT result;

	skillResult = g_SimpleMissileSkill.execute(pOusters, TargetObjectID, pOustersSkillSlot, param, result, CEffectID);

	if ( result.bSuccess )
	{
		if ( !result.pTargetCreature->isOusters() ) 
		{
			EffectDemolisher* pEffect = new EffectDemolisher( pOusters );
			pEffect->setChainTarget( result.pTargetCreature );
			pEffect->setDamage( output.Damage / 2 );
			pEffect->setNextTime( 10 );
			pEffect->setBroadcastingEffect(false);
	
			pOusters->addEffect( pEffect );
		}
	}

	__END_CATCH
	
	return skillResult;
}

Demolisher g_Demolisher;
