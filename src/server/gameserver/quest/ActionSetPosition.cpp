////////////////////////////////////////////////////////////////////////////////
// Filename    : ActionSetPosition.cpp
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////

#include "ActionSetPosition.h"
#include "Zone.h"
#include "NPC.h"
#include "NPCInfo.h"
#include "Tile.h"
#include <fstream>

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
void ActionSetPosition::read (PropertyBuffer & propertyBuffer)
	throw (Error)
{
	__BEGIN_TRY

	try
	{
		m_ZoneID = propertyBuffer.getPropertyInt("ZoneID");
		m_X      = propertyBuffer.getPropertyInt("X");
		m_Y      = propertyBuffer.getPropertyInt("Y");
		m_Dir    = propertyBuffer.getPropertyInt("Dir");
	}
	catch (NoSuchElementException & nsee)
	{
		throw Error(nsee.toString());
	}

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// 액션을 실행한다.
////////////////////////////////////////////////////////////////////////////////
void ActionSetPosition::execute (Creature * pCreature1 , Creature * pCreature2) 
	throw (Error)
{
	__BEGIN_TRY

	try {
		Assert(pCreature1 != NULL);
		Assert(pCreature2 == NULL);
		Assert(!pCreature1->isPC());

		////////////////////////////////////////////////////////////////////////////////
		// 크리처의 존을 지정한다.
		// 내부에서 ZoneInfoManager, ZoneGroupManager 를 
		// 검색해서 적절하게 존 포인터를 지정해준다.
		////////////////////////////////////////////////////////////////////////////////
		pCreature1->setZoneID(m_ZoneID);

		////////////////////////////////////////////////////////////////////////////////
		// 존에 크리처를 추가한다.
		// 내부에서 크리처의 좌표, 방향을 지정해준다.
		////////////////////////////////////////////////////////////////////////////////
		Zone * pZone = pCreature1->getZone();
		Assert(pZone != NULL);

		// addCreature() throws EmptyTileNotExistException when no free tile can be
		// found near the requested spot (the search is randomised and gives up).
		// MonsterManager::ArrangeMonsterList already catches and skips this; the
		// NPC path did not, so one unplaceable NPC aborted the whole zone load and
		// with it the server. Skip that NPC and carry on.
		try
		{
			pZone->addCreature(pCreature1 , m_X , m_Y , m_Dir);
		}
		catch (EmptyTileNotExistException&)
		{
			filelog( "ZoneAddCreature.log",
				"could not place NPC [%s] in zone %d at (%d,%d) : no free tile",
				pCreature1->getName().c_str(), (int)pZone->getZoneID(),
				(int)m_X, (int)m_Y );
			return;
		}

		NPC* pNPC = dynamic_cast<NPC*>(pCreature1);
		
		pNPC->setGlobal(false);	// 존에 속하는 NPC 임		

		if (pNPC->isShowInMinimap())
		{
			NPCInfo* pNPCInfo = new NPCInfo();
			pNPCInfo->setName(pNPC->getName());
			pNPCInfo->setNPCID(pNPC->getNPCID());
			pNPCInfo->setX(pNPC->getX());
			pNPCInfo->setY(pNPC->getY());

			pZone->addNPCInfo(pNPCInfo);
			pZone->getTile( m_X-1, m_Y ).setBlocked(Creature::MOVE_MODE_WALKING);
		}
	} catch (Throwable &t) {
		cout << t.toString() << endl;
		throw; // -_-;
	}
	
	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string ActionSetPosition::toString () const
	throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "ActionSetPosition("
		<< "ZoneID:" << (int)m_ZoneID
		<< ",X:"     << (int)m_X
		<< ",Y:"     << (int)m_Y
		<< ",Dir:"   << Dir2String[m_Dir]
		<< ")";
	return msg.toString();

	__END_CATCH
}
