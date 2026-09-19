//////////////////////////////////////////////////////////////////////////////
// Filename    : MikllizzLairManager.h 
// Written by  : ��
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __MIKLLIZZ_LAIR_MANAGER_H__
#define __MIKLLIZZ_LAIR_MANAGER_H__

#include "Timeval.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class MikllizzLairManager
//////////////////////////////////////////////////////////////////////////////

class Zone;
class Creature;
class PlayerCreature;

class MikllizzLairManager
{
public : 
	enum MikllizzLairState
	{ 
		STATE_CLOSE,
		STATE_TANTACLE_COMBAT,	// �˼����� ����. ���� �ð�
		STATE_MIKLLIZZ_COMBAT,	// ��Ŭ������� �ο�

		STATE_MAX
	}; 


public:
	MikllizzLairManager(Zone* pZone) throw(Error);
	~MikllizzLairManager() throw();

	MikllizzLairState getCurrentState() const { return m_State; }

	bool isSummonTiming() throw(Error);

	bool enterPC(PlayerCreature* pPC) throw(Error);  // ���� ������ �����Ѱ�? 
	bool leaveCreature(Creature* pCreature) throw(Error);  // ������ ���� ���

	void resetStateTime() { m_StateTime.tv_sec = 0; }

	bool heartbeat() throw (Error);

	void lock() throw(Error) { m_Mutex.lock(); }
    void ulnock() throw(Error) { m_Mutex.unlock(); }

	string toString() const throw(Error);

	// 2007.01.02
	void setMaxPassPlayer( int player ) { m_nMaxPassPlayer = player; }
	int	 getMaxPassPlayer() { return m_nMaxPassPlayer; }

protected :
	void processCloseState() throw (Error);
	void processTantacleCombatState() throw (Error);
	void processMikllizzCombatState() throw (Error);

	void summonTantacle() throw (Error);	// ��ŸŬ ��ȯ
	void addMikllizzCorpse() throw (Error);	// ��Ŭ���� ��ü �߰�
	void removeMikllizzCorpse() throw (Error);	// ��Ŭ���� ��ü ����
	void activeMikllizz() throw (Error);	// ��Ŭ���� Ȱ��ȭ
	void kickOutAllPC() throw (Error);		// �÷��̾� ��� �ѾƳ���
	void setStateClose() throw (Error);		// State Close ���·� �����.
	void giveKillingReward() throw (Error);		// ������ �׿��� �� �޴� ����
	void decreaseSealingStone() throw (Error); // ���� �ִ� �������� ���μ��� ����
	void broadcastClosingMessage( int minute ) throw (Error);
	void broadcastResurrectMikllizMessage( int minute ) throw (Error);


private : 
	Zone*				m_pZone;
	ObjectID_t			m_MikllizzID;
	ObjectID_t			m_MikllizzCorpseID;
	ZoneCoord_t			m_MikllizzX;
	ZoneCoord_t			m_MikllizzY;

	int					m_ClosingMessageStep;
	int					m_ResurrectMikllizzMessageStep;

	int					m_nMaxPassPlayer;	   // �ִ� ���� ����� ��
	int					m_nPassPlayer;       // Pass�� ���� ��� �� 

	Timeval				m_SummonNextTime;

	MikllizzLairState	m_State;             // ������ State
	Timeval				m_StateTime;         // ������ State ���ӵ� �ð�

	mutable Mutex		m_Mutex;				// m_nPassPlayer�� Ȯ���� üũ�ҷ���..

public:
	// B5F normal monster regen is held from the moment the lair opens until it has closed AND the last player has
	// left the zone (players are kicked to B4F on close). Kept last so existing member offsets do not move.
	bool isRegenPaused() const { return m_bRegenPaused; }

private:
	bool				m_bRegenPaused;
};

#endif
