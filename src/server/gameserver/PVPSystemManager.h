////////////////////////////////////////////////////////////////////////////////
// Filename    : MenegrothDoungeonManager.h 
// Written By  : rappi76 
// Description :
////////////////////////////////////////////////////////////////////////////////

#ifndef _PVP_SYSTEM_MANAGER_H_
#define _PVP_SYSTEM_MANAGER_H_

#include "Creature.h"


typedef vector<ZONE_COORD> TTrapPosList;

class PVPSystemManager
{
public : 
	class RequiredItem
	{
	public :
		RequiredItem()
		{
			m_ItemClass = Item::ITEM_CLASS_MAX;
			m_ItemType = 0;
			m_iItemCount = 0;
		}

		Item::ItemClass m_ItemClass;
		ItemType_t m_ItemType;
		int m_iItemCount;
	};

	typedef vector<PVPSystemManager::RequiredItem> TRequiredItems;

	bool hasItems(Creature *pCreature, TRequiredItems& requiredItems);
	void takeItems(Creature *pCreature, TRequiredItems& requiredItems);
	void getRequiredEntranceItems(Creature *pCreature, TRequiredItems& requiredItems);
	bool hasRequiredEntranceItems(Creature *pCreature);
	void takeRequiredEntranceItems(Creature *pCreature);
	bool getAltarPosToMove(Creature *pCreature, ZoneID_t& ZoneIDToMove, ZoneCoord_t& XPosToMove, ZoneCoord_t& YPosToMove);
	bool isValidLevel(Creature *pCreature);
	bool getDoungeonZoneToMove(Creature *pCreature, ZoneID_t& ZoneIDToMove, ZoneCoord_t& XPosToMove, ZoneCoord_t& YPosToMove);

	typedef list<string> PARTYNAMELIST;
	typedef struct _PARTYINFO
	{
		int PartyID;
		PARTYNAMELIST m_listPartyName;
		~_PARTYINFO()
		{
			m_listPartyName.clear();
		}
	}PARTYINFO, *PPARTYINFO;
	typedef queue<PPARTYINFO> QUEUEPARTY;
	
protected :
	Level_t getPlayerLevel(Creature *pCreature);
	//by viva
	Timeval				m_StateTime; 
	bool					m_hasWar;
	Zone* 				m_pZone;

//	typedef list<Creature*> PARTYLIST;
//	typedef hash_map<int, PARTYNAMELIST*>	 PARTYMAP;


	QUEUEPARTY m_queuePartyInfo;
	
	PPARTYINFO m_pPartyInfo1;
	PPARTYINFO m_pPartyInfo2;
	bool m_bParty1Inside;
	bool m_bParty2Inside;
	int m_MatchNum;
	Timeval	m_MatchTime;
	int		m_ResultMatch;
	int 					m_StartPVPWarMessageMinuteStep;
	int	m_LevelRange;
	
	
//by viva
public :

	PVPSystemManager() throw(Error);
	~PVPSystemManager() throw(Error);

	bool isStartTime() throw(Error);
	void setNextStartTime() throw(Error);
	bool hasWar() const { return m_hasWar; };
	void setWar(bool isWar) { m_hasWar = isWar; };
	void setZone(Zone* pZone) { m_pZone = pZone; };
	void startWar();
	void transNextPartyToStage();
	bool isPartyDeadInStage();
	void removeWar();
	void transAllBodyOutStage();
	bool isInStage(Creature* pCreature);
	PPARTYINFO getPartyInfo1()	{ return m_pPartyInfo1; };
	PPARTYINFO getPartyInfo2()  { return m_pPartyInfo2; };

	bool isParty1Inside()	{return m_bParty1Inside; };
	void setParty1Inside(bool bInside)	{ m_bParty1Inside = bInside; };

	bool isParty2Inside()	{ return m_bParty2Inside; };
	void setParty2Inside(bool bInside)	{ m_bParty2Inside = bInside; };
	void getReward(PPARTYINFO pPartyInfo, int coinNum);
	void getReward2(PPARTYINFO pPartyInfo, Item::ItemClass itemClass, ItemType_t itemType, int Num);
	bool isMatchTimeOut();
	bool isInStageByXY(Coord_t X, Coord_t Y);
	

};

extern PVPSystemManager g_PVPSystemManager;

class PVPSystemZoneManager
{
	public:
		PVPSystemZoneManager(Zone *pZone) throw(Error);
		~PVPSystemZoneManager() throw(Error);
	public:
		bool heartbeat() throw(Error);
		ZoneID_t getZoneID() const { return m_ZoneID; };
		bool enter2FPC(Creature* pCreature) throw(Error);
		bool leaveCreature(Creature* pCreature) throw(Error);	
		void setPassPlayer2F(int nNum) { m_nPassPlayer2F = nNum; };


	protected:
		mutable Mutex		m_Mutex;
		ZoneID_t 			m_ZoneID;
		bool					m_bIsTrap;
		Zone* 				m_pZone;
		int 					m_nMaxPassPlayer;
		int 					m_nPassPlayer2F;

		
		
};




#endif /* _PVP_SYSTEM_MANAGER_H_ */
