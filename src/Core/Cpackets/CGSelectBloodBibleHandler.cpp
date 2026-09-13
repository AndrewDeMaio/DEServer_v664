//////////////////////////////////////////////////////////////////////////////
// Filename    : CGSelectBloodBibleHandler.cpp
// Written By  :
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "CGSelectBloodBible.h"

#ifdef __GAME_SERVER__
	#include "PlayerCreature.h"
	#include "GamePlayer.h"
	#include "BloodBibleBonus.h"
	#include "BloodBibleBonusManager.h"
	#include "BloodBibleSignInfo.h"
	#include "Gpackets/GCBloodBibleSignInfo.h"
	#include "Gpackets/GCSystemMessage.h"
	#include "StringPool.h"
	#include <algorithm>
#endif	// __GAME_SERVER__

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void CGSelectBloodBibleHandler::execute (CGSelectBloodBible* pPacket , Player* pPlayer)
	 throw (Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __GAME_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pGamePlayer->getCreature());
	Assert( pPC != NULL );

	BloodBibleBonus* pBonus = NULL;

	// Only the twelve base bibles have a row in BloodBibleBonusInfo, so a
	// clan tier token has to be looked up by the base bible it derives from.
	// Looking the raw type up threw NoSuchElementException and returned
	// without sending the client anything, so picking a tiered token from the
	// rent menu looked like nothing happening at all.
	const int bloodBibleID = (int)pPacket->getBloodBibleID();

	if ( bloodBibleID < 0 || bloodBibleID >= BLOOD_BIBLE_TYPE_MAX )
		return;

	try
	{
		pBonus = g_pBloodBibleBonusManager->getBloodBibleBonus( bloodBibleID % BLOOD_BIBLE_PER_TIER );
		if ( pBonus == NULL ) return;
	}
	catch ( NoSuchElementException& e )
	{
		return;
	}

	if ( pPC->getRace() != pBonus->getRace() )
	{
		GCSystemMessage gcSM;
		gcSM.setMessage( g_pStringPool->c_str( STRID_CANNOT_USE_MARK )); // 20070814
		pGamePlayer->sendPacket( &gcSM );
		return;
	}

	BloodBibleSignInfo* pInfo = pPC->getBloodBibleSign();
	if ( pInfo->getOpenNum() <= pInfo->getList().size() )
	{
		GCSystemMessage gcSM;
		gcSM.setMessage( g_pStringPool->c_str(STRID_NOT_EMPTY_SLOT) ); // 20070814
		pGamePlayer->sendPacket( &gcSM );
		return;
	}
	
	vector<ItemType_t>::iterator itr = pInfo->getList().begin();

	for ( ; itr != pInfo->getList().end() ; ++itr )
	{
		if ( (*itr % 12) == (pPacket->getBloodBibleID() % 12) )
		{
			GCSystemMessage gcSM;
			gcSM.setMessage( g_pStringPool->c_str(STRID_ALREADY_EQUIP_MARK) ); // 20070814
			pGamePlayer->sendPacket( &gcSM );
			return;
		}
	}

//	if ( find( pInfo->getList().begin(), pInfo->getList().end(), pPacket->getBloodBibleID() ) != pInfo->getList().end() )
//	{
//		GCSystemMessage gcSM;
//		gcSM.setMessage( g_pStringPool->c_str(STRID_ALREADY_EQUIP_MARK) ); // 20070814
//		pGamePlayer->sendPacket( &gcSM );
//		return;
//	}

	GCSystemMessage gcSM;
	gcSM.setMessage( g_pStringPool->c_str(STRID_EQUIPED_BLOOD_BIBLE_MARK) );
	pGamePlayer->sendPacket( &gcSM );

	pInfo->getList().push_back( pPacket->getBloodBibleID() );
	GCBloodBibleSignInfo gcInfo;
	gcInfo.setSignInfo( pInfo );
	pGamePlayer->sendPacket( &gcInfo );

	pPC->initAllStatAndSend();

#endif	// __GAME_SERVER__
		
	__END_DEBUG_EX __END_CATCH
}

