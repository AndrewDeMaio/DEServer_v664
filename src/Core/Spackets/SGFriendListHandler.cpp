//----------------------------------------------------------------------
//
// Filename    : SGFriendListHandler.cpp
// Written By  : 
// Description :
//
//----------------------------------------------------------------------

// include files
#include "SGFriendList.h"
#include "Assert.h"

#ifdef __GAME_SERVER__
	#include "Creature.h"
	#include "PCFinder.h"
	#include "Player.h"

	#include "Gpackets/GCFriendList.h"
#endif

void SGFriendListHandler::execute ( SGFriendList* pPacket, Player* pPlayer )
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY

#ifdef __GAME_SERVER__

	GCFriendList gcFriendList;
	
	for(int i = 0; i < pPacket->GetFriendListCount(); ++i )
	{
		gcFriendList.AddFriendInfo(*pPacket->GetFriendSimpleInfo(i));	
	}
	gcFriendList.SetFriendGlobalOptionInfo(pPacket->GetFriendGlobalOptionInfo());
	
	__ENTER_CRITICAL_SECTION((*g_pPCFinder))

	Creature* pCreature = g_pPCFinder->getCreature_LOCKED( pPacket->GetReceiver() );
	
	if ( pCreature != NULL && pCreature->isPC() )
	{
		Player* pPlayer = pCreature->getPlayer();
		Assert( pPlayer != NULL );

		//----------------------------------------------------------------------
		// NOT sent: the client cannot receive this packet.
		//
		// GCFriendList is id 511, inside the client's
		// #if __CONTENTS(__FRIEND_ADDITION) block, and that flag is __OFF for
		// __DESIGNED_INTERNATION -- so PacketFactoryManager never registers a
		// factory for 511. Sending it made createPacket() throw
		// InvalidProtocolException, which UpdateSocketInput() catches by
		// dropping to MODE_MAINMENU and closing the socket. The character had
		// already loaded into the zone; this push is what disconnected it.
		//
		// The client also has no friend UI in this build, so it can never ask
		// for this data -- suppressing the unsolicited push loses nothing.
		//----------------------------------------------------------------------
		//pPlayer->sendPacket(&gcFriendList);
	}
	
	__LEAVE_CRITICAL_SECTION((*g_pPCFinder))
	
	
	
#endif
		
	__END_CATCH
}
