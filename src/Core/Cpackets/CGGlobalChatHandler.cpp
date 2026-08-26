//////////////////////////////////////////////////////////////////////////////
// Filename    : CGGlobalChatHandler.cc
// Written By  : reiot@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "CGGlobalChat.h"

#ifdef __GAME_SERVER__
	#include "GamePlayer.h"
	#include "IncomingPlayerManager.h"
	#include "Creature.h"
	#include "Zone.h"
	#include "Gpackets/GCGlobalChat.h"
	#include "LogNameManager.h"
	#include "ZoneGroupManager.h"
	#include "BroadcastFilter.h"
	#include "PlayerCreature.h"
	#include "Effect.h"

	#include "Inventory.h"
	#include "StringPool.h"
	#include "Gpackets/GCSystemMessage.h"

#endif

//////////////////////////////////////////////////////////////////////////////
// 머리위에 GlobalChat 스트링을 띄울때 사용하는 패킷이다.
// 이 크리처를 볼 수 있는 모든 플레이어에게 브로드캐스트한다.
// 일단은 현재 존의 모든 플레이어(또는 전체 플레이어)에게 
// GCGlobalChat 패킷을 브로드캐스트한다.
//////////////////////////////////////////////////////////////////////////////
void CGGlobalChatHandler::execute (CGGlobalChat* pPacket , Player* pPlayer)
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
		
#ifdef __GAME_SERVER__

	Assert(pPacket != NULL);
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pPlayer);
	Creature*   pCreature   = pGamePlayer->getCreature();
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	
	Inventory* pInventory = pPC->getInventory();
	Assert( pInventory != NULL );
	
	if (pGamePlayer->getPlayerStatus() == GPS_NORMAL) {

		if (pGamePlayer->isPenaltyFlag(PENALTY_TYPE_MUTE)) 
		{
			return;
		}
		Creature* pCreature = pGamePlayer->getCreature();

		Assert(pCreature != NULL);

		// 서버에서 클라이언트로 전송하므로 GC- 패킷을 사용해야 한다.
		GCGlobalChat gcGlobalChat;

		size_t i = pPacket->getMessage().find_first_of('*' , 0);

		if (i == 0) return;

		// text color setting
		// 오후 4:18 2010-02-16 shootkj 클라이언트에 존채팅인지 채널 채팅인지 구분 해서 보냄
		gcGlobalChat.setType( pPacket->getType() );
		gcGlobalChat.setColor( pPacket->getColor() );

		// 크리처 이름과 메시지를 패킷에 대입한다.
		StringStream msg;
		msg << pCreature->getName() << " " << pPacket->getMessage();
	
		gcGlobalChat.setMessage(msg.toString());
		gcGlobalChat.setRace(pCreature->getRace());
	
		if( pPacket->getType() == 0 )
		{
			// 주변 PC들에게 브로드캐스트한다.
			pCreature->getZone()->broadcastPacket(&gcGlobalChat , pCreature);
		}
		else if ( pPacket->getType() == 1 )
		{	
			if ( !pInventory->hasEnoughNumItem(Item::ITEM_CLASS_COMMON_QUEST_ITEM, 57, 1) )
			{
				// 아이템 없음
				GCSystemMessage gcSystemMessage;
				gcSystemMessage.setMessage( g_pStringPool->getString( STRID_NO_LAIR_ITEM ) );
				pPlayer->sendPacket(&gcSystemMessage);
				
				return ;
			}
			else
			{
				pInventory->decreaseNumItem(Item::ITEM_CLASS_COMMON_QUEST_ITEM, 57, 1, pPlayer);
				
				Race_t race = pCreature->getRace();
				BroadcastFilterRace filter( race );
				g_pZoneGroupManager->pushBroadcastPacket( &gcGlobalChat, &filter );
			}
		}

		// 채팅 로그를 남긴다. by sigi. 2002.10.30
		if (LogNameManager::getInstance().isExist( pCreature->getName() ))
		{
			filelog("chatLog.txt", "[Global] %s> %s", pCreature->getName().c_str(), pPacket->getMessage().c_str());
		}
	}
	
#endif
		
	__END_DEBUG_EX __END_CATCH
}
