////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionEnterDraculaCastle.cpp
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////

#include "Types.h"

#include "ActionEnterPVPSystem.h"
#include "Creature.h"
#include "NPC.h"
#include "GamePlayer.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Ousters.h"
#include "ZoneUtil.h"

#include "StringPool.h"
#include "PVPSystemManager.h"
//#include "EffectPVPSystem.h"

#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCNPCResponse.h"

#include "Gpackets/GCAddEffect.h"

#include "VariableManager.h"

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////

void ActionEnterPVPSystem::read (PropertyBuffer & propertyBuffer)
    throw (Error)
{
    __BEGIN_TRY

	try 
	{
	} 
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}
	
    __END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
//  .
////////////////////////////////////////////////////////////////////////////////
void ActionEnterPVPSystem::execute (Creature * pCreature1 , Creature * pCreature2) 
	throw (Error)
{
	__BEGIN_TRY

	cout << "ActionEnterPVPSystem::execute()" << endl;

	Assert(pCreature1 != NULL);
	Assert(pCreature2 != NULL);
	Assert(pCreature1->isNPC());
	Assert(pCreature2->isPC());

	ZoneID_t ZoneIDToMove;
	ZoneCoord_t XPosToMove;
	ZoneCoord_t YPosToMove;

	Player *pPlayer = pCreature2->getPlayer();
	PlayerCreature* pPC2  = dynamic_cast<PlayerCreature*>(pCreature2);

	Zone* pZone = pCreature2->getZone();

	if( !g_PVPSystemManager.hasWar() &&
		!g_pVariableManager->getVariable(EVENT_OPEN_PVP_ZONE) )
	{
	        GCSystemMessage gcSystemMessage;

	        gcSystemMessage.setMessage( "The PVP Event is not open." );
	        pPlayer->sendPacket(&gcSystemMessage);

	        GCNPCResponse response;

	        response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
	        pPlayer->sendPacket( &response );

		return;		
	}

	if ( !g_PVPSystemManager.getDoungeonZoneToMove(pCreature2, ZoneIDToMove, XPosToMove, YPosToMove) )
	{
	        GCNPCResponse response;

	        response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
	        pPlayer->sendPacket( &response );

			return;
	}

		if ( !g_PVPSystemManager.isValidLevel(pCreature2) )
		{
		        GCSystemMessage gcSystemMessage;

		        gcSystemMessage.setMessage( "You cannot enter Event stadium as you've passed the level." );
		        pPlayer->sendPacket(&gcSystemMessage);

		        GCNPCResponse response;

		        response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
		        pPlayer->sendPacket( &response );

			return;
		}
/*
		if ( !g_PVPSystemManager.hasRequiredEntranceItems(pCreature2) )
		{
		        GCSystemMessage gcSystemMessage;

		        gcSystemMessage.setMessage( "You do not have enough Fobiddon Blood  to enter." );
		        pPlayer->sendPacket(&gcSystemMessage);

		        GCNPCResponse response;

		        response.setCode( NPC_RESPONSE_QUIT_DIALOGUE );
		        pPlayer->sendPacket( &response );


		        return;
	    	}
	    
		g_PVPSystemManager.takeRequiredEntranceItems(pCreature2);
*/

		transportCreature( pCreature2, ZoneIDToMove, XPosToMove, YPosToMove, false );


	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string ActionEnterPVPSystem::toString () const 
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionEnterPVPSystem("
	    << ")";

	return msg.toString();

	__END_CATCH
}

