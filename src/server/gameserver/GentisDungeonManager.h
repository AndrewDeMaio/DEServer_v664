//////////////////////////////////////////////////////////////////////////////
// Filename    : HellGardenTowerManager.h 
// Written by  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __GENTIS_DUNGEON_MANAGER_H__
#define __GENTIS_DUNGEON_MANAGER_H__

#include "Timeval.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class GentisDungeonManager
//////////////////////////////////////////////////////////////////////////////

class Zone;
class Creature;
class PlayerCreature;

class GentisDungeonManager
{
public : 
	enum GentisDungeonState
	{ 
		STATE_OPEN,
		STATE_WAIT,
		STATE_STAGE_1,		//  Clear    ()
		STATE_STAGE_2,
		STATE_STAGE_3,
		STATE_STAGE_4,
		STATE_STAGE_5,
		STATE_STAGE_6,
		STATE_STAGE_7,
		STATE_STAGE_8,
		STATE_STAGE_9,
		STATE_STAGE_10,
		STATE_BOSS_KILLED,
		STATE_INIT,			//    (, ) 

		STATE_MAX
	}; 

	//     .
	enum HellGardenType
	{
		TYPE_HELLGARDEN_1,
		TYPE_HELLGARDEN_2,
		TYPE_HELLGARDEN_3,
		TYPE_HELLGARDEN_4,
		TYPE_HELLGARDEN_5,
		TYPE_HELLGARDEN_MAX
	};

	//      4  .
	enum GentisDungeonType
	{
		TYPE_GENTIS_DUNGEON_0,
		TYPE_GENTIS_DUNGEON_1,
		TYPE_GENTIS_DUNGEON_2,
		TYPE_GENTIS_DUNGEON_3,
		TYPE_GENTIS_DUNGEON_4,
		TYPE_GENTIS_DUNGEON_MAX
	};

	struct MonsterTypeList
	{
		MonsterType_t	MonsterType;
		int				MonsterCount;
	};

public:
	GentisDungeonManager(Zone* pZone) throw(Error);
	~GentisDungeonManager() throw();

	int getCurrentState() const { return m_State; }

	bool isSummonTiming() throw(Error);

	bool enterPC(PlayerCreature* pPC) throw(Error);  //   ? 
	bool leaveCreature(Creature* pCreature) throw(Error);  //   

	void resetStateTime() { m_StateTime.tv_sec = 0; }

	bool heartbeat() throw (Error);

	void lock() throw(Error) { m_Mutex.lock(); }
    void ulnock() throw(Error) { m_Mutex.unlock(); }

	string toString() const throw(Error);

	// 2007.01.02
	void setMaxPassPlayer( int player ) { m_nMaxPassPlayer = player; }
	int	 getMaxPassPlayer() { return m_nMaxPassPlayer; }

	void initHellGarden();
protected :
	void processCloseState() throw (Error);
	void processTantacleCombatState() throw (Error);
	void processMikllizzCombatState() throw (Error);
	void processGentisDungeonState() throw (Error);

	void summonMonster() throw (Error);	//  
	void addMikllizzCorpse() throw (Error);	//   
	void removeMikllizzCorpse() throw (Error);	//   
	void activeMikllizz() throw (Error);	//  
	void kickOutAllPC() throw (Error);		//   
	void setStateClose() throw (Error);		// State Close  .
	void giveKillingReward() throw (Error);		//     
	void decreaseSealingStone() throw (Error); //     
	void broadcastClosingMessage( ) throw (Error);
	void broadcastResurrectMikllizMessage( int minute ) throw (Error);

	void addMonsterToZone(MonsterType_t monsterType, int monsternum, Zone* pZone) throw(Error);

	void summonTopf() throw(Error);


private : 
	Zone*				m_pZone;
	ObjectID_t			m_MikllizzID;
	ObjectID_t			m_MikllizzCorpseID;
	ZoneCoord_t			m_MikllizzX;
	ZoneCoord_t			m_MikllizzY;

	int					m_ClosingMessageStep;
	int					m_ResurrectMikllizzMessageStep;

	int					m_nMaxPassPlayer;	   //    
	int					m_nPassPlayer;       // Pass    

	Timeval				m_TimeOutMessageNextTime;

	int					m_State;             //  State
	Timeval				m_StateTime;         //  State  

	//   
	//  4  
	int					m_GentisDungeonType;
	// 1  5
	int					m_HellGardenType;
	int					m_KickZoneID; //  
	int					m_SummonStep;
	bool				m_StartCombat; // 

	MonsterTypeList		m_MonterList[STATE_MAX];
//	int					m_CurrentMonstCount;

	int					m_PartyID; //    ID

	mutable Mutex		m_Mutex;				// m_nPassPlayer  ..
};

#endif
