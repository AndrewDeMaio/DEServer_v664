//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectLoaderManager.cpp
// Written By  : elca, excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectLoaderManager.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "Zone.h"

#include "EffectBloodDrain.h"
#include "EffectLight.h"
#include "EffectAftermath.h"
#include "EffectEnemyErase.h"
#include "EffectRestore.h"
#include "EffectKillAftermath.h"
#include "EffectMute.h"
#include "EffectOnBridge.h"

#include "EffectGreenPoison.h"
#include "EffectYellowPoison.h"
#include "EffectDarkness.h"
#include "EffectAcidSwamp.h"
#include "EffectContinualBloodyWall.h"
#include "EffectIceField.h"
#include "EffectProminence.h"

#include "EffectCanEnterGDRLair.h"
#include "EffectBehemothForceScroll.h"
#include "EffectSafeForceScroll.h"
#include "EffectCarnelianForceScroll.h"

#include "EffectGreyfellForceScroll.h"
#include "EffectSoviusForceScroll.h"
#include "EffectMirForceScroll.h"
#include "EffectAccuraForceScroll.h"
#include "EffectLifeForceScroll.h"

#include "EffectHoodlumStigma.h"

#include "EffectBleeding.h"

#include "EffectBonusExp.h"

#include "EffectMysteryPotion.h"

//20070724
#include "EffectOdinForceScroll.h"
#include "EffectTituosForceScroll.h"
//20070907
#include "EffectPetBonusExp.h"
//20080226 DSG by Kim Sung Yong
#include "EffectDSG.h"
// 20080310 계급 모래시계 by Kim sung yong
#include "EffectRankBonusExpRed.h"
#include "EffectRankBonusExpBlue.h"
// 20081028 wlzzi - Extreme Force Scroll
#include "EffectExtremeForceScroll.h"

#include "EffectBonusExpSecond.h"
#include "EffectBonusExpAdvance.h"
#include "EffectChaoticExp.h"

//------------------------------------------------------------------------------
// One failing loader must not kill the server.
//
// These loaders read optional per-character effect state. A missing table or
// column used to throw all the way out to "UNHANDLED EXCEPTION" and take the
// gameserver down with it. Log it, skip that effect, carry on loading.
//------------------------------------------------------------------------------
#define SAFE_EFFECT_LOAD(loader, pc) \
	try { (loader)->load(pc); } \
	catch (Throwable & t) \
	{ \
		filelog("EffectLoaderError.log", "%s : %s", #loader, t.toString().c_str()); \
	}


EffectLoaderManager::EffectLoaderManager () 
	throw ()
{
	__BEGIN_TRY
	__END_CATCH
}

EffectLoaderManager::~EffectLoaderManager () 
	throw ()
{
	__BEGIN_TRY

	SAFE_DELETE(g_pEffectBloodDrainLoader);
	SAFE_DELETE(g_pEffectLightLoader);
	SAFE_DELETE(g_pEffectAftermathLoader);
	SAFE_DELETE(g_pEffectEnemyEraseLoader);
	SAFE_DELETE(g_pEffectRestoreLoader);
	SAFE_DELETE(g_pEffectKillAftermathLoader);
	SAFE_DELETE(g_pEffectMuteLoader);
	SAFE_DELETE(g_pEffectGreenPoisonLoader);
	SAFE_DELETE(g_pEffectYellowPoisonLoader);
	SAFE_DELETE(g_pEffectDarknessLoader);
	SAFE_DELETE(g_pEffectAcidSwampLoader);
	SAFE_DELETE(g_pEffectContinualBloodyWallLoader);
	SAFE_DELETE(g_pEffectIceFieldLoader);
	SAFE_DELETE(g_pEffectProminenceLoader);
	SAFE_DELETE(g_pEffectOnBridgeLoader);
	SAFE_DELETE(g_pEffectCanEnterGDRLairLoader);
	SAFE_DELETE(g_pEffectBehemothForceScrollLoader);
	SAFE_DELETE(g_pEffectSafeForceScrollLoader);
	SAFE_DELETE(g_pEffectCarnelianForceScrollLoader);
	SAFE_DELETE(g_pEffectHoodlumStigmaLoader);
	SAFE_DELETE(g_pEffectMysteryPotionLoader);
	SAFE_DELETE(g_pEffectGreyfellForceScrollLoader);
	SAFE_DELETE(g_pEffectSoviusForceScrollLoader);
	SAFE_DELETE(g_pEffectMirForceScrollLoader);
	SAFE_DELETE(g_pEffectBonusExpLoader);
	SAFE_DELETE(g_pEffectOdinForceScrollLoader);
	SAFE_DELETE(g_pEffectTituosForceScrollLoader);
	SAFE_DELETE(g_pEffectPetBonusExpLoader);
	SAFE_DELETE(g_pEffectDSGLoader);
	SAFE_DELETE(g_pEffectRankBonusExpRedLoader);
	SAFE_DELETE(g_pEffectRankBonusExpBlueLoader);
	SAFE_DELETE(g_pEffectExtremeForceScrollLoader);
	SAFE_DELETE(g_pEffectBonusExpSecondLoader);
	SAFE_DELETE(g_pEffectBonusExpAdvanceLoader);
	SAFE_DELETE(g_pEffectAccuraForceScrollLoader);
	SAFE_DELETE(g_pEffectLifeForceScrollLoader);
	SAFE_DELETE(g_pEffectChaoticExpLoader);
	
	__END_CATCH
}

void EffectLoaderManager::init () 
	throw (Error)
{
	__BEGIN_TRY

	m_pEffectLoaders[Effect::EFFECT_CLASS_BLOOD_DRAIN] = g_pEffectBloodDrainLoader = new EffectBloodDrainLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_LIGHT] = g_pEffectLightLoader = new EffectLightLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_AFTERMATH] = g_pEffectAftermathLoader = new EffectAftermathLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_ENEMY_ERASE] = g_pEffectEnemyEraseLoader = new EffectEnemyEraseLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_RESTORE] = g_pEffectRestoreLoader = new EffectRestoreLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_KILL_AFTERMATH] = g_pEffectKillAftermathLoader = new EffectKillAftermathLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_MUTE] = g_pEffectMuteLoader = new EffectMuteLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_GREEN_POISON] = g_pEffectGreenPoisonLoader = new EffectGreenPoisonLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_YELLOW_POISON] = g_pEffectYellowPoisonLoader = new EffectYellowPoisonLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_DARKNESS] = g_pEffectDarknessLoader = new EffectDarknessLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_ACID_SWAMP] = g_pEffectAcidSwampLoader = new EffectAcidSwampLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_CONTINUAL_BLOODY_WALL] = g_pEffectContinualBloodyWallLoader = new EffectContinualBloodyWallLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_ICE_FIELD] = g_pEffectIceFieldLoader = new EffectIceFieldLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_PROMINENCE] = g_pEffectProminenceLoader = new EffectProminenceLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_ON_BRIDGE] = g_pEffectOnBridgeLoader = new EffectOnBridgeLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_CAN_ENTER_GDR_LAIR] = g_pEffectCanEnterGDRLairLoader = new EffectCanEnterGDRLairLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_BEHEMOTH_FORCE_SCROLL] = g_pEffectBehemothForceScrollLoader = new EffectBehemothForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_SAFE_FORCE_SCROLL] = g_pEffectSafeForceScrollLoader = new EffectSafeForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_CARNELIAN_FORCE_SCROLL] = g_pEffectCarnelianForceScrollLoader = new EffectCarnelianForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_HOODLUM_STIGMA] = g_pEffectHoodlumStigmaLoader = new EffectHoodlumStigmaLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_GREYFELL_FORCE_SCROLL] = g_pEffectGreyfellForceScrollLoader = new EffectGreyfellForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_SOVIUS_FORCE_SCROLL] = g_pEffectSoviusForceScrollLoader = new EffectSoviusForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_MIR_FORCE_SCROLL] = g_pEffectMirForceScrollLoader = new EffectMirForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_BONUS_EXP] = g_pEffectBonusExpLoader = new EffectBonusExpLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_MYSTERY_POTION] = g_pEffectMysteryPotionLoader = new EffectMysteryPotionLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_ODIN_FORCE_SCROLL] = g_pEffectOdinForceScrollLoader = new EffectOdinForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_TITUOS_FORCE_SCROLL] = g_pEffectTituosForceScrollLoader = new EffectTituosForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_PET_BONUS_EXP] = g_pEffectPetBonusExpLoader = new EffectPetBonusExpLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_DSG] = g_pEffectDSGLoader = new EffectDSGLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_RANK_BONUS_EXP_RED] = g_pEffectRankBonusExpRedLoader = new EffectRankBonusExpRedLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_RANK_BONUS_EXP_BLUE] = g_pEffectRankBonusExpBlueLoader = new EffectRankBonusExpBlueLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_EXTREME_FORCE_SCROLL] = g_pEffectExtremeForceScrollLoader = new EffectExtremeForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_BONUS_EXP_SECOND] = g_pEffectBonusExpSecondLoader = new EffectBonusExpSecondLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_BONUS_EXP_ADVANCE] = g_pEffectBonusExpAdvanceLoader = new EffectBonusExpAdvanceLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_ACCURA_FORCE_SCROLL] = g_pEffectAccuraForceScrollLoader = new EffectAccuraForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_LIFE_FORCE_SCROLL] = g_pEffectLifeForceScrollLoader = new EffectLifeForceScrollLoader();
	m_pEffectLoaders[Effect::EFFECT_CLASS_CHAOTIC_STONE_EXP] = g_pEffectChaoticExpLoader = new EffectChaoticExpLoader();
	
	__END_CATCH
}

void EffectLoaderManager::load (Slayer* pSlayer) 
	throw (Error)
{
	__BEGIN_TRY

	SAFE_EFFECT_LOAD(g_pEffectBloodDrainLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectLightLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectAftermathLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectEnemyEraseLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectRestoreLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectKillAftermathLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectMuteLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectCanEnterGDRLairLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectBehemothForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectSafeForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectCarnelianForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectHoodlumStigmaLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectGreyfellForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectSoviusForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectMirForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectMysteryPotionLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectOdinForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectTituosForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectPetBonusExpLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectDSGLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectRankBonusExpRedLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectRankBonusExpBlueLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectExtremeForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpSecondLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpAdvanceLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectAccuraForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectLifeForceScrollLoader, pSlayer);
	SAFE_EFFECT_LOAD(g_pEffectChaoticExpLoader, pSlayer);
	
	__END_CATCH
}

void EffectLoaderManager::load (Vampire* pVampire) 
	throw (Error)
{
	__BEGIN_TRY

	SAFE_EFFECT_LOAD(g_pEffectBloodDrainLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectLightLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectAftermathLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectEnemyEraseLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectRestoreLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectKillAftermathLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectMuteLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectCanEnterGDRLairLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectBehemothForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectSafeForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectCarnelianForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectHoodlumStigmaLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectGreyfellForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectSoviusForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectMirForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectMysteryPotionLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectOdinForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectTituosForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectPetBonusExpLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectDSGLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectRankBonusExpRedLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectRankBonusExpBlueLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectExtremeForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpSecondLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpAdvanceLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectAccuraForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectLifeForceScrollLoader, pVampire);
	SAFE_EFFECT_LOAD(g_pEffectChaoticExpLoader, pVampire);

	__END_CATCH
}

void EffectLoaderManager::load (Ousters* pOusters) 
	throw (Error)
{
	__BEGIN_TRY

	SAFE_EFFECT_LOAD(g_pEffectBloodDrainLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectAftermathLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectKillAftermathLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectMuteLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectCanEnterGDRLairLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectBehemothForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectSafeForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectCarnelianForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectHoodlumStigmaLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectGreyfellForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectSoviusForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectMirForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectMysteryPotionLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectOdinForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectTituosForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectPetBonusExpLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectDSGLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectRankBonusExpRedLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectRankBonusExpBlueLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectExtremeForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpSecondLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectBonusExpAdvanceLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectAccuraForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectLifeForceScrollLoader, pOusters);
	SAFE_EFFECT_LOAD(g_pEffectChaoticExpLoader, pOusters);

	__END_CATCH
}

void EffectLoaderManager::load (Zone* pZone)
	throw (Error)
{
	__BEGIN_TRY

	SAFE_EFFECT_LOAD(g_pEffectGreenPoisonLoader, pZone);
	SAFE_EFFECT_LOAD(g_pEffectYellowPoisonLoader, pZone);
	SAFE_EFFECT_LOAD(g_pEffectDarknessLoader, pZone);
	SAFE_EFFECT_LOAD(g_pEffectAcidSwampLoader, pZone);
	SAFE_EFFECT_LOAD(g_pEffectContinualBloodyWallLoader, pZone);
	SAFE_EFFECT_LOAD(g_pEffectIceFieldLoader, pZone);
	SAFE_EFFECT_LOAD(g_pEffectProminenceLoader, pZone);
	SAFE_EFFECT_LOAD(g_pEffectOnBridgeLoader, pZone);

	__END_CATCH
}

string EffectLoaderManager::toString () const
	throw ()
{
	__BEGIN_TRY

	return "";

	__END_CATCH
}

// global variable definition
EffectLoaderManager* g_pEffectLoaderManager = NULL;
