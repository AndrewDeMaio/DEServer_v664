////////////////////////////////////////////////////////////////////////////////
// Filename    : MonsterManager.h 
// Written By  : Reiot
// Revised by  : �輺��
// Description : 
////////////////////////////////////////////////////////////////////////////////


#include "MonsterManager.h"
#include <stdlib.h>			// atoi()
#include "Assert.h"
#include "LogClient.h"
#include "MonsterInfo.h"
#include "ItemInfoManager.h"
#include "Creature.h"
#include "GamePlayer.h"
#include "MonsterCorpse.h"
#include "Tile.h"
#include "Zone.h"
#include "Player.h"
#include "Monster.h"
#include "OptionInfo.h"
#include "Skull.h"
#include "EventStar.h"
#include "DB.h"
#include "Treasure.h"
#include "Thread.h"
#include "ItemFactoryManager.h"
#include "ZoneUtil.h"
#include "CreatureUtil.h"
#include "VariableManager.h"
#include "MonsterNameManager.h"
#include "MasterLairInfoManager.h"
#include "LuckInfo.h"
#include "ItemUtil.h"
#include "EventItemUtil.h"
#include "WarSystem.h"
#include "Properties.h"
#include "CastleInfoManager.h"
#include "SweeperBonusManager.h"
#include "skill/SummonGroundElemental.h"
#include "skill/EffectHarpoonBomb.h"
#include "EffectPacketSend.h"
#include "ItemGradeManager.h"
#include "StringPool.h"
#include "Viewable.h"
#include "CastleDungeonMonsterManager.h"
#include "RelicUtil.h"
#include "PCManager.h"
#include "PlayerCreature.h"
#include "Inventory.h"
#include "EffectPrecedence.h"
#include "PacketUtil.h"
#include "Gpackets/GCCreateItem.h"
#include "Gpackets/GCSystemMessage.h"

#include <fstream>

#include "Gpackets/GCCreatureDied.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCAddEffectToTile.h"
#include "Gpackets/GCDeleteObject.h"
#include "Gpackets/GCSay.h"

#include "Profile.h"
#include "GDRLairManager.h"
#include "MikllizzLairManager.h"
#include "DynamicZone.h"
#include "DynamicZoneGateOfAlter.h"

#include "TimeChecker.h"

#define __MONSTER_FIGHTING__
extern bool isPotentialEnemy(Monster* pMonster, Creature* pCreature);
extern void countResurrectItem();

//#define __PROFILE_MONSTER__

#ifdef __PROFILE_MONSTER__
	#define __BEGIN_PROFILE_MONSTER(name)	beginProfileEx(name);
	#define __END_PROFILE_MONSTER(name)		endProfileEx(name);
#else
	#define __BEGIN_PROFILE_MONSTER(name)	((void)0);
	#define __END_PROFILE_MONSTER(name)		((void)0);
#endif

////////////////////////////////////////////////////////////////////////////////
// ����ȭ�� ������ ����Ȯ�� ���ʽ� �ۼ�Ʈ
////////////////////////////////////////////////////////////////////////////////
//const uint g_pVariableManager->getPremiumItemProbePercent() = 220;

bool isLottoWinning();

////////////////////////////////////////////////////////////////////////////////
//
// constructor
//
////////////////////////////////////////////////////////////////////////////////
MonsterManager::MonsterManager (Zone* pZone) 
	throw (Error)
{
	__BEGIN_TRY
		
	Assert(pZone != NULL);
	m_pZone = pZone;

	Assert(g_pCastleInfoManager!=NULL);
	m_CastleZoneID = 0;
	g_pCastleInfoManager->getCastleZoneID( m_pZone->getZoneID(), m_CastleZoneID );

	m_nEventMonster = 0;
	m_pEventMonsterInfo = NULL;

	getCurrentTime(m_RegenTime);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
//
// destructor
//
////////////////////////////////////////////////////////////////////////////////
MonsterManager::~MonsterManager () 
	throw ()
{
	__BEGIN_TRY

	SAFE_DELETE(m_pEventMonsterInfo);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// load from database
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::load ()
	throw (Error)
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result*    pResult = NULL;
	string     text, eventText;
	//081216 wlzzi ������ �̺�Ʈ���� (���θ�Ǹ��ͷ� Ī�Ѵ�)
	string		promotionText;

	m_RICE_CAKE_PROB_RATIO[0] = 100;
	m_RICE_CAKE_PROB_RATIO[1] = 33;
	m_RICE_CAKE_PROB_RATIO[2] = 33;
	m_RICE_CAKE_PROB_RATIO[3] = 33;
	m_RICE_CAKE_PROB_RATIO[4] = 1;
	m_SumOfCakeRatio = 0;

	for (int i=0; i<5; i++)
		m_SumOfCakeRatio += m_RICE_CAKE_PROB_RATIO[i];

	// �̹� �ִٸ� ������ MonsterCounter���� ��� �����.
	bool bReload = false;
	hash_map< SpriteType_t, MonsterCounter* >::iterator iMC = m_Monsters.begin();
	while (iMC!=m_Monsters.end())
	{
		MonsterCounter* pMC = iMC->second;
		SAFE_DELETE(pMC);

		iMC ++;

		// m_Monsters�� �̹� �־��ٸ� reload�� ���̴�..��� ����. by sigi. 2002.9.19
		bReload = true;
	}

	BEGIN_DB
	{
		// DynamicZone �� ���� ó��
		ZoneID_t zoneID = m_pZone->getZoneID();
		if ( m_pZone->isDynamicZone() )
		{
			DynamicZone* pDynamicZone = m_pZone->getDynamicZone();
			Assert( pDynamicZone != NULL );

			zoneID = pDynamicZone->getTemplateZoneID();
		}

		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pResult = pStmt->executeQuery(
//081216 wlzzi - ������ �̺�Ʈ ����(���θ�Ǹ���)
//		"SELECT MonsterList, EventMonsterList from ZoneInfo WHERE ZoneID=%d", zoneID );
		"SELECT MonsterList, EventMonsterList, PromotionMonsterList from ZoneInfo WHERE ZoneID=%d", zoneID );

		if (pResult->getRowCount() <= 0) 
		{
			SAFE_DELETE(pStmt);
//			throw Error("MonsterManager::load() : ���� �������� �ʽ��ϴ�.");
			return;
		}

		pResult->next();
		text = pResult->getString(1);
		eventText = pResult->getString(2);
		//081216~19 wlzzi - ������ �̺�Ʈ ����(���θ�Ǹ���)
		if (g_pVariableManager->getVariable( GEN_PROMOTIONMONSTER ))
			promotionText = pResult->getString(3);
		//-
		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)


	parseMonsterList( text, bReload );
	parseEventMonsterList( eventText, bReload );
	//081216 wlzzi - ������ �̺�Ʈ ����(���θ�Ǹ���)
	//	> �����~ �̺�Ʈ ����(���� ġ�����Ͱ� �ǰڴ�)�� �����ϰ� ó���Ѵ�.
	//	> ����, ���θ�Ǹ��͸��� ó���� �ʿ��� ��, �̺�Ʈ ���Ϳ��� �����Ͽ� Ȯ���ϵ��� �Ѵ�.
	parseEventMonsterList( promotionText, bReload );

	__END_CATCH
}

void MonsterManager::parseMonsterList(const string& text, bool bReload)
	throw (Error)
{
	if (text.size() <= 0) return;

	//--------------------------------------------------------------------------------
	//
	// text �Ķ���ʹ� ZoneInfo ���̺��� Monsters (TEXT) �÷����� ��Ÿ����.
	// ������ ������ ����.
	//
	// (MonsterType1,#Monster1) (MonsterType2,#Monter2)(..,..)
	// i            j         k i            j        k    
	//
	//--------------------------------------------------------------------------------
	
	size_t i = 0 , j = 0 , k = 0;

	do 
	{
		// parse string
		i = text.find_first_of('(',k);
		j = text.find_first_of(',',i+1);
		k = text.find_first_of(')',j+1);

		if (i==string::npos || j==string::npos || k==string::npos
			|| i > j || j > k) break;

		// ���� Ÿ�԰� �ִ� ������ ���Ѵ�. ���� Ÿ�԰� �ִ� ������ ���Ѵ�.
		uint monsterType = atoi(text.substr(i+1,j-i-1).c_str());
		uint maxMonsters = atoi(text.substr(j+1,k-j-1).c_str());

		Assert(maxMonsters > 0);

		// ���� ������ ���� Monster Sprite Type�� �޾ƿ´�.
		const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(monsterType);
		SpriteType_t spriteType = pMonsterInfo->getSpriteType();

		// �̹� �����ϴ����� ���θ� üũ�Ѵ�.
		hash_map< SpriteType_t , MonsterCounter* >::iterator itr = m_Monsters.find(spriteType);

		if (itr != m_Monsters.end()) 
		{
			WORD CurrentMaxCount = itr->second->getMaxMonsters();
			WORD NewMaxCount = CurrentMaxCount + maxMonsters;
			itr->second->setMaxMonsters(NewMaxCount);
		} 
		else 
		{
			// ����ī���� ��ü�� ����, hash_map �� ����Ѵ�.
			MonsterCounter* pMonsterCounter = new MonsterCounter(monsterType , maxMonsters, 0);

			// �������� �ʴ� ���, �߰��Ѵ�.
			m_Monsters[spriteType] = pMonsterCounter;
		}
	} while (k < text.size() - 1);
}

void MonsterManager::ArrangeMonsterList()
{
	MonsterCounter* pMonsterCounter;
	uint monsterType;
	
	hash_map< SpriteType_t, MonsterCounter* >::iterator iter;
	iter = m_Monsters.begin();
	for( ; iter != m_Monsters.end(); ++iter )
	{
		pMonsterCounter = iter->second;
		if ( pMonsterCounter == NULL )
		{
			continue;
		}
		
		monsterType = pMonsterCounter->getSpriteType();
		
		for (size_t m = pMonsterCounter->getCurrentMonsters() ; m < pMonsterCounter->getMaxMonsters() ; ++m ) 
		{
			ZoneCoord_t x, y;
			if (!findPosition(monsterType, x, y))
			{
				Assert(false);
				return;
			}
			
			Monster* pMonster = new Monster(monsterType);
			
			Assert(pMonster != NULL);

			try
			{
				m_pZone->addCreature(pMonster , x , y , Directions(rand() & 0x07));
			}
			catch (EmptyTileNotExistException&)
			{
				//cerr << "MonsterManager::load() : �ڸ��� ����?" << endl;
				SAFE_DELETE(pMonster);
			}
		}
	}
}

void MonsterManager::parseEventMonsterList(const string& text, bool bReload)
	throw (Error)
{
	if (text.size() <= 0) return;

	//--------------------------------------------------------------------------------
	//
	// text �Ķ���ʹ� ZoneInfo ���̺��� Monsters (TEXT) �÷����� ��Ÿ����.
	// ������ ������ ����.
	//
	// (MonsterType1,#Monster1,RegenDelay) (MonsterType2,#Monter2,RegenDelay)(..,..)
	// i            j         k          l i            j        k          l
	//
	//--------------------------------------------------------------------------------
	
	size_t i = 0 , j = 0 , k = 0, l = 0, m = 0, n = 0;

	do 
	{
		// parse string
		i = text.find_first_of('(',l);
		j = text.find_first_of(',',i+1);
		k = text.find_first_of(',',j+1);
		l = text.find_first_of(')',k+1);
		m = text.find_first_of(',',k+1);
		n = text.find_first_of(',',m+1);

		if (i==string::npos || j==string::npos || k==string::npos || l==string::npos
			|| i > j || j > k || k > l) break;

		int tx = -1;
		int ty = -1;
		if ( m != string::npos && n != string::npos && k < m && m < n && n < l )
		{
			tx = atoi(text.substr(m+1, n-m-1).c_str());
			ty = atoi(text.substr(n+1, l-n-1).c_str());
			cout << "x : " << tx << endl;
			cout << "y : " << ty << endl;
			l = m;
		}

		// ���� Ÿ�԰� �ִ� ������ ���Ѵ�. ���� Ÿ�԰� �ִ� ������ ���Ѵ�.
		uint monsterType = atoi(text.substr(i+1,j-i-1).c_str());
		uint maxMonsters = atoi(text.substr(j+1,k-j-1).c_str());
		uint regenDelay  = atoi(text.substr(k+1,l-k-1).c_str());

		Assert(maxMonsters > 0);

		//--------------------------------------------------------------------------------
		// �ش��ϴ� Ÿ���� ���͸� ���� �߰��Ѵ�.
		//--------------------------------------------------------------------------------
		if (!bReload) // reload�� �ƴϸ�..
		{
			//cout << "[MM] load EventMonsterList: [" << m_pZone->getZoneID() << "] mtype=" << monsterType
			//	<< ", maxMonsters=" << maxMonsters
			//	<< ", regenDelay=" << regenDelay << endl;
			if (m_pEventMonsterInfo==NULL)
			{
				m_pEventMonsterInfo = new vector<EventMonsterInfo>;
				//m_pEventMonsterInfo->resize( maxMonsters );
			}

			/*
			if (m_pEventMonsterInfo->size() + maxMonsters < m_pEventMonsterInfo->capacity())
			{
				m_pEventMonsterInfo->resize( m_pEventMonsterInfo->size() + maxMonsters );
			}
			*/

			for (size_t m = 0 ; m < maxMonsters ; m ++) 
			{
//				if (g_pVariableManager->isActiveChiefMonster())
//				{
					EventMonsterInfo info;
					info.monsterType = monsterType;
					info.regenDelay = regenDelay;
					info.bExist = true;
					info.bCanAppear = true;
					info.x = tx;
					info.y = ty;

					// ����𸮴��� �ٷ� �߰����� �ʰ� ������ �����ϱ� ��ٸ���.
					if ( info.monsterType == 814 )
					{
						info.bExist = false;
						info.bCanAppear = false;
						info.regenTime.tv_sec = 0;
					}

					// ����� ���ʹ� �������� �Ͼ�� ���������� ���ȴ�.
					if ( info.monsterType == 815
						|| info.monsterType == 816
						|| info.monsterType == 817 )
					{
						if ( !g_pVariableManager->isActiveGuildWar() )
						{
							info.bExist = false;
							info.bCanAppear = false;
						}
					}

					m_pEventMonsterInfo->push_back( info );

					
//				}
//				else
//				{
//					m_nEventMonster++;
//
//					EventMonsterInfo info;
//					info.monsterType = monsterType;
//					info.regenDelay = regenDelay;
//					getCurrentTime( info.regenTime );
//					info.bExist = false;
//					info.bCanAppear = false;
//
//					m_pEventMonsterInfo->push_back( info );
//				}

			}
		}
	} while (l < text.size() - 1);


}

void MonsterManager::ArrangeEventMonsterList()
{
	if ( m_pEventMonsterInfo == NULL )
	{
		return;
	}
	
	vector<EventMonsterInfo>::iterator iter;
	
	iter = m_pEventMonsterInfo->begin();
	for( ; iter != m_pEventMonsterInfo->end() ; ++iter )
	{
		EventMonsterInfo *pEventMonsterInfo = &(*iter);
		
		if (g_pVariableManager->isActiveChiefMonster())
		{
			// ���� �� ��ǥ�� ã�Ƴ���.
			ZoneCoord_t x, y;
			if ( pEventMonsterInfo->x != -1 )
			{
				x = pEventMonsterInfo->x; 
				y = pEventMonsterInfo->y;
			}
			else if (!findPosition(pEventMonsterInfo->monsterType, x, y))
			{
				Assert(false);
				return;
			}

			// ���� ��ü�� �����ϰ� �ɷ�ġ ���� �ʱ�ȭ�Ѵ�.
			Monster* pMonster = new Monster(pEventMonsterInfo->monsterType);
			Assert(pMonster != NULL);

			pMonster->setEventMonsterIndex( m_nEventMonster );			

			try
			{
				if ( pEventMonsterInfo->bCanAppear )
					m_pZone->addCreature(pMonster , x , y , Directions(rand() & 0x07));
				
				// �׷���Ʈ ���Ǿ�
/*						if ( monsterType == 764 )
				{
					static TPOINT pos[] = {
						{ 41, 52 },
						{ 72, 114 },
						{ 104, 35 } };
					// ��ġ�� 20����
					for ( int j=0; j<3; ++j )
					for ( int i=0; i<20; ++i )
					{
						pMonster = new Monster( 493 + (i%10) );
						m_pZone->addCreature(pMonster , pos[j].x , pos[j].y , Directions(rand()%8));
					}
				}*/				
			}
			catch (EmptyTileNotExistException&)
			{
				//cerr << "MonsterManager::load() : �ڸ��� ����?" << endl;
				SAFE_DELETE(pMonster);
			}
		}
		
		m_nEventMonster++;
	}
}

////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addCreature (Creature* pCreature)
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	Monster* pMonster = dynamic_cast<Monster*>(pCreature);

	// ũ��ó �ؽ��ʿ� �߰��Ѵ�.
	CreatureManager::addCreature(pMonster);

	// event monster�� MonsterCounter�� ���� �ʰ� �Ѵ�. by sigi. 2002.10.14
	if (m_pEventMonsterInfo!=NULL 
		&& pMonster->isEventMonster())
	{
		uint index = pMonster->getEventMonsterIndex();

		if (index < m_pEventMonsterInfo->size())
		{
			EventMonsterInfo& info = (*m_pEventMonsterInfo)[index];

			getCurrentTime( info.regenTime );
			info.regenTime.tv_sec += info.regenDelay;

			info.bExist = true;
		}

		//cout << "[MM] add EventMonster: [" << pMonster->getEventMonsterIndex()
		//	<< "] = " << info.monsterType << ", delay = " << info.regenDelay << endl;
		return;
	}

	// �׷� ���� Ÿ���� ���� ������ �� �ִ��� üũ�Ѵ�.
	hash_map< SpriteType_t , MonsterCounter* >::iterator itr = m_Monsters.find(pMonster->getSpriteType());

	if (itr == m_Monsters.end()) 
	{
		// ��ŸŬ�� ���ܷ� �ϰ� ī�����Ѵ�.
		if ( pMonster->getSpriteType() == 255 )
		{
			m_Monsters[pMonster->getSpriteType()] = new MonsterCounter( pMonster->getSpriteType(), 0, 1 );
		}

		StringStream msg;
		msg << "���� ���� ������ �� ���� Ÿ���� ���Ͱ� �߰��Ǿ����ϴ�.\n" 
			<< "���� ���� [" << m_pZone->getZoneID() << "]�Դϴ�.\n"
			<< "�߰��Ϸ��� �� ������ Ÿ���� [" << pMonster->getMonsterType() << "]�Դϴ�.\n";
		//throw Error(msg.toString());
	}
	else
	{ 
		// ���� ī���͸� ������Ų��.
		itr->second->addMonster();
	}

	__END_CATCH
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::deleteCreature (ObjectID_t creatureID)
	throw ()//NoSuchElementException , Error)
{
	__BEGIN_TRY

	// ũ��ó �ؽ��ʿ� �׷� OID �� ���� ���Ͱ� �����ϴ��� üũ�Ѵ�.
	hash_map<ObjectID_t , Creature* >::iterator itr = m_Creatures.find(creatureID);

	if (itr == m_Creatures.end()) 
	{
		cerr << "MonsterManager::deleteCreature() : NoSuchElementException" << endl;
		
		// �̰͵� �ܺο��� ����� ó�� �ȵǰ� �ִ°� ����.
		// by sigi. 2002.5.9
		//throw NoSuchElementException("�׷� ObjectID�� ���� ���ʹ� �������� �ʽ��ϴ�.");
		
		return;
	}

	Monster* pMonster = dynamic_cast<Monster*>(itr->second);

	// ũ��ó �ؽ����� �ش� ��带 �����Ѵ�.
	// �Լ� ���� �ִ��� ����� �÷ȴ�. by sigi
	// �ٺ���~ itr ������ ������ ��带 ������¡~. 2002.10.12 by bezz
	m_Creatures.erase(itr);


	// event monster�� MonsterCounter�� �������. by sigi .2002.10.14
	if (m_pEventMonsterInfo!=NULL
		&& pMonster->isEventMonster()
		&& pMonster->getMonsterType() != 764)
	{
		uint index = pMonster->getEventMonsterIndex();

		if (index < m_pEventMonsterInfo->size())
		{
			EventMonsterInfo& info = (*m_pEventMonsterInfo)[index];
			info.bExist = false;
			//cout << "[MM] delete EventMonster: [" << pMonster->getEventMonsterIndex()
			//	<< "] = " << info.monsterType << endl;
		}

		return;
	}

	// ���� ī���Ϳ� �׷� ���� Ÿ���� �����ϴ��� üũ�Ѵ�.
	hash_map< SpriteType_t , MonsterCounter *>::iterator itr2 = m_Monsters.find(pMonster->getSpriteType());

	if (itr2 == m_Monsters.end()) 
	{
		cerr << "MonsterManager::deleteCreature() : NoSuchElementException" << endl;
		//throw NoSuchElementException("�׷� SpriteType�� ���� ���ʹ� �������� �ʽ��ϴ�.");
	}
	else 
	{
		// ������ ���ڸ� ���δ�.
		itr2->second->deleteMonster();
	}


	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��ü�� �������� ������ �ν��Ѵ�. 2002.7.22 by sigi
// pAttackedMonster�� pCreature�� ������ ��쿡
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addPotentialEnemy(Monster* pAttackedMonster, Creature* pCreature) 
	throw(Error)
{
	__BEGIN_TRY

	//cout << "MonsterManager::addPotentialEnemy()" << endl;
		
	hash_map< ObjectID_t , Creature* >::const_iterator itr = m_Creatures.begin();

	for (; itr!=m_Creatures.end(); itr++) 
	{
		Creature* pMonsterCreature = itr->second;

		// ���� ���� ���� �ִ� �Ÿ����� �Ѵ�.
		Distance_t dist = pMonsterCreature->getDistance(pCreature->getX(), pCreature->getY());

		if (dist <= pMonsterCreature->getSight() 
			// �ڽ��� �ٸ� �ڵ忡�� üũ�Ѵ�.
			&& pMonsterCreature!=pAttackedMonster)
		{
			Monster* pMonster = dynamic_cast<Monster*>(pMonsterCreature);
			//cout << "addPotentialEnemy: " << pMonster->getName().c_str() << endl;
			pMonster->addPotentialEnemy( pCreature );
		}
	}
		

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��ü�� ������ �ν��Ѵ�. 2002.7.22 by sigi
// pAttackedMonster�� pCreature�� ������ ��쿡
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addEnemy(Monster* pAttackedMonster, Creature* pCreature) 
	throw(Error)
{
	__BEGIN_TRY
		
	//cout << "MonsterManager::addEnemy()" << endl;

	hash_map< ObjectID_t , Creature* >::const_iterator itr = m_Creatures.begin();

	for (; itr!=m_Creatures.end(); itr++) 
	{
		Creature* pMonsterCreature = itr->second;

		// ���� ���� ���� �ִ� �Ÿ����� �Ѵ�.
		Distance_t dist = pMonsterCreature->getDistance(pCreature->getX(), pCreature->getY());

		if (dist <= pMonsterCreature->getSight() 
			// �ڽ��� �ٸ� �ڵ忡�� üũ�Ѵ�.
			&& pMonsterCreature!=pAttackedMonster)
		{
			Monster* pMonster = dynamic_cast<Monster*>(pMonsterCreature);
			//cout << "addEnemy: " << pMonster->getName().c_str() << endl;
			pMonster->addEnemy( pCreature );
		}
	}
		

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ũ��ó �Ŵ����� ���ӵ� ���͵��� AI�� ���� �׼��� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::processCreatures ()
	throw (Error)
{
	__BEGIN_TRY

//	__BEGIN_PROFILE_MONSTER("MM_PROCESS_CREATURES");

	Timeval currentTime;
	getCurrentTime(currentTime);

	try
	{
		hash_map< ObjectID_t , Creature* >::iterator before = m_Creatures.end();
		hash_map< ObjectID_t , Creature* >::iterator current = m_Creatures.begin();

		while (current != m_Creatures.end()) 
		{
			Creature* pCreature = current->second;

			if ( pCreature == NULL )
			{
				// 2009.01.16 rappi76
				// pCreature�� NULL�Ǵ� ������ ���ؼ��� �� ���� ����......
				
				filelog("MonsterManagerBug.log", "processCreatures() : pCreature == NULL, ZoneID=%d", 
					m_pZone->getZoneID()
				);
				
				if (before == m_Creatures.end()) 
				{
					m_Creatures.erase(current);
					current = m_Creatures.begin();
				} 
				else 
				{
					m_Creatures.erase(current);
					current = before;
					current++;
				}
				
				continue;
			}
			

			__BEGIN_PROFILE_MONSTER("MM_EFFECTMANAGER");

			pCreature->getEffectManager()->heartbeat(currentTime);

			__END_PROFILE_MONSTER("MM_EFFECTMANAGER");

			if (pCreature->isAlive()) 
			{
				/*
				Monster* pMonster = dynamic_cast<Monster*>(pCreature);

				if (pMonster->isEnemyLimit())
				{
					Zone* 		pZone 	= pMonster->getZone();
					ZoneCoord_t cx 		= pMonster->getX();
					ZoneCoord_t cy 		= pMonster->getY();
					ObjectID_t 	monsterID = pMonster->getObjectID();

					hash_map< SpriteType_t , MonsterCounter *>::iterator itr = m_Monsters.find(pMonster->getSpriteType());

					if (itr == m_Monsters.end()) 
					{
						//cerr << "MonsterManager::processCreatures() : NoSuchElementException" << endl;
						//throw NoSuchElementException("�׷� SpriteType�� ���� ���ʹ� �������� �ʽ��ϴ�.");
					}
					else
					{
						// ������ ���ڸ� ���δ�.
						itr->second->deleteMonster();
					}


					// Ÿ�ϰ� ���� �Ŵ������� ũ��ó�� �����Ѵ�.
					Tile & tile = pZone->getTile(cx , cy);
					tile.deleteCreature(monsterID);

					SAFE_DELETE(pMonster);

					if (before == m_Creatures.end()) 
					{
						m_Creatures.erase(current);
						current = m_Creatures.begin();
					} 
					else 
					{
						m_Creatures.erase(current);
						current = before;
						current ++;
					}

					GCDeleteObject gcDeleteObject;
					gcDeleteObject.setObjectID(monsterID);

					pZone->broadcastPacket(cx, cy , &gcDeleteObject);
				}
			*/
				__BEGIN_PROFILE_MONSTER("MM_CREATURE_ACT");
				pCreature->act(currentTime);
				before = current ++;
				__END_PROFILE_MONSTER("MM_CREATURE_ACT");
			} 
			else
			{

				Monster* pMonster = dynamic_cast<Monster*>(pCreature);
				Assert(pMonster != NULL);

				/*if ( pMonster->getMonsterType() == 371 ||
				     pMonster->getMonsterType() == 372 ||
				     pMonster->getMonsterType() == 373 ||
				     pMonster->getMonsterType() == 374 ||
				     pMonster->getMonsterType() == 375 ||
				     pMonster->getMonsterType() == 376)
					return;
				else
				{*/

					if (pMonster->isEventMonster())		// by sigi. 2002.10.14
					{
						if (m_pEventMonsterInfo!=NULL)
						{
							uint index = pMonster->getEventMonsterIndex();

							if (index < m_pEventMonsterInfo->size())
							{
								EventMonsterInfo& info = (*m_pEventMonsterInfo)[index];
								info.bExist = false;

								// ����� ������ �׾��� ��� ���� �������� ��ٷ����Ѵ�.
								if ( info.monsterType == 814 )
								{
									info.bCanAppear = false;
								}

								// �� ����1���� ������� �׾��� ��� ����� ������ �������� �����ϴ��� Ȯ���غ���.
								if ( info.monsterType == 815
									|| info.monsterType == 816
									|| info.monsterType == 817
								   )
								{
									if ( m_pZone->isCastleZone() )
									{
										CastleDungeonMonsterManager::checkAndRegenGuardianLeader( m_pZone->getZoneID() );
									}
								}

								//cout << "[MM] dead EventMonster: [" << pMonster->getEventMonsterIndex()
								//	<< "] = " << info.monsterType << endl;
							}
						}
					}
					else
					{
						// ���� ī���͸� �ϳ� ���δ�.
						hash_map< SpriteType_t , MonsterCounter *>::iterator itr = m_Monsters.find(pMonster->getSpriteType());

						if (itr == m_Monsters.end()) 
						{
							//cerr << "MonsterManager::processCreatures() : NoSuchElementException" << endl;
							//throw NoSuchElementException("�׷� SpriteType�� ���� ���ʹ� �������� �ʽ��ϴ�.");
						}
						else
						{
							// ������ ���ڸ� ���δ�.
							itr->second->deleteMonster();
						}
					}

				__BEGIN_PROFILE_MONSTER("MM_CREATURE_DEADACTION");
					// ���� ���͸� ���̱� ���� ������ �׼��� ���ϰ� �Ѵ�.
					pMonster->actDeadAction();
				__END_PROFILE_MONSTER("MM_CREATURE_DEADACTION");

				__BEGIN_PROFILE_MONSTER("MM_KILL_CREATURE");
					// ���͸� ������ �����ϰ�, ��ε�ĳ��Ʈ�Ѵ�.
					killCreature(pMonster);
				__END_PROFILE_MONSTER("MM_KILL_CREATURE");

					// ���Ϳ� ���� ũ��ó�� �ؽ����� ��带 �����Ѵ�.
					// �߸� ������ ���, ������ ���� ����� ������ ������ ��.
					if (before == m_Creatures.end()) 
					{
						m_Creatures.erase(current);
						current = m_Creatures.begin();
					} 
					else 
					{
						m_Creatures.erase(current);
						current = before;
						current ++;
					}
				//}

			}
		}

		// ���� ��� �ڵ忡 findPosition�̶�� ���� ���� �Լ��� �ϳ� �ִ�.
		// 30�� ���� ���� ������ ���Ͱ� �׾��� ��, �� ���͵��� ������ �ڸ��� ã�µ� 
		// �ɸ��� �ð��� ����� ���� �ִ�. �׸��� �� �ð��� ������� ����
		// �߻��Ѵ�. ��������δ� �� ����������, ���� ���̱� ���ؼ� 
		// ������ ���� �˻縦 ���� �ϵ��� �����Ѵ�. -- �輺��
		// ���� �ֱ⸶�� ���� ���ڸ� Ȯ���ؼ� ���������ش�.
		if (m_RegenTime < currentTime)
		{
			__BEGIN_PROFILE_MONSTER("MM_REGENERATE_CREATURES");

			regenerateCreatures();

			m_RegenTime.tv_sec  = currentTime.tv_sec + 5;	// 5�� �� ����
			m_RegenTime.tv_usec = currentTime.tv_usec;

			__END_PROFILE_MONSTER("MM_REGENERATE_CREATURES");
		}

		// �̰� �� �ּ�ó�� �ȵǾ��־���.. by sigi. 2002.5.3
		//regenerateCreatures();
	}
	catch (Throwable & t)
	{
		filelog("MonsterManagerBug.log", "ProcessCreatures Exception: %s", t.toString().c_str());
		//cerr << t.toString() << endl;
	}

//	__END_PROFILE_MONSTER("MM_PROCESS_CREATURES");

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ������ ���ڰ� �پ��� ���͸� ������Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::regenerateCreatures ()
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	// ���� �߿� ���� ���� �ȵǰ�..
	if (m_pZone->isHolyLand()) 
	{
		// ���� ���� ��
		if (g_pWarSystem->hasActiveRaceWar())
			return;

		// ��� ���� ��..
		if (m_CastleZoneID!=0 && g_pWarSystem->hasCastleActiveWar(m_CastleZoneID))
		{
			CastleInfo* pCastleInfo = g_pCastleInfoManager->getCastleInfo( m_CastleZoneID );
			if (pCastleInfo!=NULL)
			{
				GuildID_t OwnerGuildID = pCastleInfo->getGuildID();

				// ���뼺�� �ƴ� ���� ���� ���Ѵ�.==���뼺�� ���� �Ѵ�.
				if (OwnerGuildID!=SlayerCommon
					&& OwnerGuildID!=VampireCommon
					&& OwnerGuildID!=OustersCommon
					)
				{
					return;
				}
			}
		}
	}

	// ������ ������ �ϴ� ���̶�� -_-;; 
	ZoneID_t zoneID = m_pZone->getZoneID(); 
	if (zoneID == 1131 || zoneID == 1132 || zoneID == 1133 || zoneID == 1134)
	{
		if (!g_pSweeperBonusManager->isAble( zoneID ) )
			return;
	}

	// Raohm B5F (Mikllizz lair): no normal spawns from the moment the lair opens until it has closed and every
	// player has been moved out to B4F (MikllizzLairManager::isRegenPaused). Monsters killed at the opening
	// stay dead meanwhile; their regen times are long past by then, so the zone refills on the next regen
	// tick after the next visitor arrives. Mikllizz's summons are a skill, not regen.
	if (m_pZone->isMikllizzLair())
	{
		MikllizzLairManager* pLair = m_pZone->getMikllizzLairManager();
		if (pLair != NULL && pLair->isRegenPaused())
			return;
	}

	hash_map<SpriteType_t, MonsterCounter*>::iterator itr = m_Monsters.begin();
	for (; itr != m_Monsters.end() ; itr ++) 
	{
		MonsterCounter* pCounter = itr->second;

		// ���Ͱ� �پ����� ���...
		while (pCounter->getCurrentMonsters() < pCounter->getMaxMonsters()) 
		{
			SpriteType_t  SpriteType  = itr->first;
			MonsterType_t monsterType = 0;

			vector<MonsterType_t> RegenVector = g_pMonsterInfoManager->getMonsterTypeBySprite(SpriteType);
			Assert(RegenVector.size() > 0);

			monsterType = RegenVector[rand()%RegenVector.size()];

			// ���� �� ��ǥ�� ã�Ƴ���.
			ZoneCoord_t x, y;
			if (!findPosition(monsterType, x, y))
			{
				Assert(false);
				return;
			}

			// ���� ��ü�� �����ϰ� �ɷ�ġ ���� �ʱ�ȭ�Ѵ�.
			Monster* pMonster = new Monster(monsterType);
			Assert(pMonster != NULL);

			/////////////////////////////////////////////////////////////////////
			// ���͸� �߰��ϴ� �������� �̺�Ʈ �������� �˻縦 �Ѵ�.
			///  7�� 1���ڷ� ���� (������ �̺�Ʈ ��)
			/*
			if(rand()%g_pVariableManager->getEventRatio()==0 && 
					g_pVariableManager->getEventActivate() == 1 )
			{		
				pMonster->setEventMonsterFlag(true);
				string MonsterName = g_pMonsterNameManager->getRandomName(pMonster, true);
				pMonster->setName(MonsterName);

				//cout << "�̺�Ʈ ���� �̸�: " << MonsterName;
			}
			*/
			/////////////////////////////////////////////////////////////////////

			try
			{
				m_pZone->addCreature(pMonster , x , y , Directions(rand()%8));
			}
			catch (EmptyTileNotExistException&)
			{
				//cerr << "MonsterManager::processCreatures() : �ڸ��� ����?" << endl;
				SAFE_DELETE(pMonster);
			}

			if ( g_pTimeChecker->isInPeriod(TIME_PERIOD_DOUBLE_MONSTER) )
			{
				static SpriteType_t doubleSTypes[] = 
				{
					/* ����ٵ�     */     5 ,
					/* Ű��         */     6 ,
					/* �ʹ׵���     */     8 ,
					/* ĸƾ         */     9 ,
					/* �񷹸�       */    40 ,
					/* ī��������� */    47 ,
					/* ����Ʈ       */    60 ,
					/* ī��������Ʈ */    71 ,
					/* ũ���������� */    72 ,
					/* �ε�ī����   */    89 ,
					/* ī�����׸��� */    90 ,
					/* ��ũ����Ʈ   */   105 ,
					/* ����Ʈũ���� */   107 ,
					/* ������       */   238 ,
					/* ����ī�ٺ�� */   241 ,
					                       0 ,
				};

				for ( int i = 0; doubleSTypes[i] != 0; ++i )
				{
					if ( SpriteType == doubleSTypes[i] )
					{
						pMonster = new Monster(monsterType);
						Assert(pMonster != NULL);

						pMonster->setEventMonsterIndex(0xfffe);

						try
						{
							m_pZone->addCreature(pMonster , x , y , Directions(rand()%8));
						}
						catch (EmptyTileNotExistException&)
						{
							SAFE_DELETE(pMonster);
						}

						break;
					}
				}
			}
		}
	}

	if (g_pVariableManager->isActiveChiefMonster()
		&& m_pEventMonsterInfo!=NULL)
	{
		Timeval currentTime;
		getCurrentTime( currentTime );

		//cout << "regenCheck [" << m_pZone->getZoneID() <<"] EventMonsterNum = "
		//	<< m_pEventMonsterInfo->size() << " : "; 

		for (size_t i=0; i<m_pEventMonsterInfo->size(); i++)
		{
			EventMonsterInfo& info = (*m_pEventMonsterInfo)[i];

			if (!info.bExist
				&& info.bCanAppear
				&& currentTime >= info.regenTime)
			{
				//cout << i << " ";
				MonsterType_t monsterType = info.monsterType;

				// ���� �� ��ǥ�� ã�Ƴ���.
				ZoneCoord_t x, y;
				if ( info.x != -1 )
				{
					x = info.x;
					y = info.y;
				}
				else if (!findPosition(monsterType, x, y))
				{
					Assert(false);
					return;
				}

				// ���� ��ü�� �����ϰ� �ɷ�ġ ���� �ʱ�ȭ�Ѵ�.
				Monster* pMonster = new Monster(monsterType);
				Assert(pMonster != NULL);

				pMonster->setEventMonsterIndex( i );

				try
				{
					m_pZone->addCreature(pMonster , x , y , Directions(rand()%8));

					// �׷���Ʈ ���Ǿ�
/*					if ( monsterType == 764 )
					{
						static TPOINT pos[] = {
							{ 41, 52 },
							{ 72, 114 },
							{ 104, 35 } };
						// ��ġ�� 20����
						for ( int j=0; j<3; ++j )
						for ( int i=0; i<20; ++i )
						{
							pMonster = new Monster( 493 + (i%10) );
							m_pZone->addCreature(pMonster , pos[j].x , pos[j].y , Directions(rand()%8));
						}
					}*/
				}
				catch (EmptyTileNotExistException&)
				{
					//cerr << "MonsterManager::processCreatures() : �ڸ��� ����?" << endl;
					SAFE_DELETE(pMonster);
				}
			}

			/*
			else
			{
				if (!info.bExist)
					cout << "f ";
				else
					cout << "t ";
			}
			*/
		}

		//cout << endl;
	}

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
bool MonsterManager::findPosition(MonsterType_t monsterType, ZoneCoord_t& RX, ZoneCoord_t& RY) const
	throw()
{
	__BEGIN_TRY

	const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(monsterType);

	int count = 0;

/*	if ( monsterType == 722 )
	{
		// ���巹 ���� -_-;;
		RX = 94;
		RY = 172;
		return true;
	}*/

	// ���� �����ε�... Ȥ�ö� ������ ������?
	while (true)
	{
		const BPOINT& pt = m_pZone->getRandomMonsterRegenPosition();

		Tile& rTile = m_pZone->getTile(pt.x,pt.y);

		// 1. Ÿ���� ���ϵǾ� ���� �ʰ�
		// 2. Ÿ�Ͽ� ��Ż�� �������� ������,
		// 3. �������밡 �ƴ϶��
		if (!rTile.isBlocked(pMonsterInfo->getMoveMode()) && 
			!rTile.hasPortal() && 
			!(m_pZone->getZoneLevel(pt.x, pt.y) & SAFE_ZONE))
		{
			RX = pt.x;
			RY = pt.y;
			return true;
		}

		if (++count >= 300)
		{
			cerr << "MonsterManager::findPosition() : Max Count Exceeded" << endl;
			throw ("MonsterManager::findPosition() : Max Count Exceeded");
		}
	}

	// ������ ���� �����ϱ�, ������� �� ������?
	return false;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ���� ũ��ó�� ó���Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::killCreature (Creature* pDeadCreature)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	Assert(pDeadCreature->isDead());

	Zone* pZone = pDeadCreature->getZone();
	Assert(m_pZone == pZone);

	Monster* pDeadMonster = dynamic_cast<Monster*>(pDeadCreature);
	ZoneCoord_t cx = pDeadMonster->getX();
	ZoneCoord_t cy = pDeadMonster->getY();

	// �׾����ϱ� �켱���� ������ش�.
	PrecedenceTable* pTable = pDeadMonster->getPrecedenceTable();
	
	pTable->compute();

	if ( pTable->getHostName() == "" )
	{
		// �ƹ��� ���� ���� ���ٸ� �������� �� �ִ´�.
		pDeadMonster->setTreasure( false );
	}
	else
	{
		pDeadMonster->setHostName(pTable->getHostName());
		pDeadMonster->setHostPartyID(pTable->getHostPartyID());
	}

	// Eisen Dungeon B4F Astral crystals (BlackAstral 1077 / WhiteAstral 1078): every player in the lair gets
	// its chest in the inventory instead of a corpse drop, whether or not they fought it (user request
	// 2026-09-14; it used to need damage within 30 s of the kill). A full inventory drops the chest at the
	// player's feet, reserved for them, the same way GQuestGiveItemElement does.
	if ( pDeadMonster->getMonsterType() == 1077 || pDeadMonster->getMonsterType() == 1078 )
	{
		ItemType_t chestType = ( pDeadMonster->getMonsterType() == 1077 ) ? 42 : 43;	// Black / White Astral's Chest

		const hash_map<ObjectID_t, Creature*>& players = m_pZone->getPCManager()->getCreatures();
		hash_map<ObjectID_t, Creature*>::const_iterator itr = players.begin();

		for ( ; itr != players.end(); ++itr )
		{
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(itr->second);
			if ( pPC == NULL )
				continue;

			Item* pChest = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, chestType, list<OptionType_t>() );
			if ( pChest == NULL )
				continue;

			m_pZone->registerObject( pChest );

			TPOINT pt;
			if ( pPC->getInventory()->addItem( pChest, pt ) )
			{
				pChest->create( pPC->getName(), STORAGE_INVENTORY, 0, pt.x, pt.y );

				GCCreateItem gcCreateItem;
				makeGCCreateItem( &gcCreateItem, pChest, pt.x, pt.y );
				pPC->getPlayer()->sendPacket( &gcCreateItem );

				GCSystemMessage gcAdded;
				gcAdded.setMessage( chestType == 42 ? "Black Astral's Chest was added to your inventory." : "White Astral's Chest was added to your inventory." );
				pPC->getPlayer()->sendPacket( &gcAdded );
			}
			else
			{
				pt.x = -1;
				try
				{
					pt = m_pZone->addItem( pChest, pPC->getX(), pPC->getY() );
				}
				catch ( Throwable& )
				{
					pt.x = -1;
				}

				if ( pt.x == -1 )
				{
					SAFE_DELETE( pChest );
					continue;
				}

				EffectPrecedence* pEffectPrecedence = new EffectPrecedence( pChest );
				pEffectPrecedence->setDeadline( 999999 );
				pEffectPrecedence->setHostName( pPC->getName() );
				pEffectPrecedence->setHostPartyID( pPC->getPartyID() );
				pChest->getEffectManager().deleteEffect( Effect::EFFECT_CLASS_PRECEDENCE );
				pChest->getEffectManager().addEffect( pEffectPrecedence );
				pChest->setFlag( Effect::EFFECT_CLASS_PRECEDENCE );

				pChest->create( "", STORAGE_ZONE, m_pZone->getZoneID(), pt.x, pt.y );

				GCSystemMessage gcSM;
				gcSM.setMessage( "Your inventory is full, so the Astral chest was dropped at your feet." );
				pPC->getPlayer()->sendPacket( &gcSM );
			}
		}

		// The chests were handed out above; keep them out of the corpse (BlackAstral/WhiteAstral .bin).
		pDeadMonster->setTreasure( false );
	}


	// ���� �ٴڿ� �����߸����, ����Ʈ�� �Ѹ���.
	GCAddEffect gcAddEffect;
	gcAddEffect.setObjectID(pDeadCreature->getObjectID());
	gcAddEffect.setEffectID(Effect::EFFECT_CLASS_COMA);
	gcAddEffect.setDuration(0);
	pZone->broadcastPacket(cx, cy, &gcAddEffect);

	// ���� ����
	Tile & tile = m_pZone->getTile(cx , cy);
	tile.deleteCreature(pDeadMonster->getObjectID());
	
	if ( pZone != NULL )
	{
		pZone->NotifyKillCreature(NULL, pDeadCreature);
	}

	// DynamicZone �ϰ���� ó��
	if ( m_pZone->isDynamicZone() )
	{
		DynamicZone* pDynamicZone = m_pZone->getDynamicZone();
		Assert( pDynamicZone != NULL );

		if ( pDynamicZone->getTemplateZoneID() == 4001 )
		{
			// ������ �Ա��� ��� ó��
			DynamicZoneGateOfAlter* pGateOfAlter = dynamic_cast<DynamicZoneGateOfAlter*>(pDynamicZone);
			Assert( pGateOfAlter != NULL );

			pGateOfAlter->removeEffect( cx, cy );
		}
	}

	// �׶��� ������Ż�� ��ü�� ������
	if ( pDeadMonster->getMonsterType() == GROUND_ELEMENTAL_TYPE  ||
		// 2007 06 25 �ﰡ�� Ÿ�������� ���� ��ü�� �ٷ� ���� ������.
		 m_pZone->isHellGardenTower() )
	{
		GCDeleteObject* pGCDO = new GCDeleteObject;
		pGCDO->setObjectID( pDeadMonster->getObjectID() );

		EffectPacketSend* pEffectPacketSend = new EffectPacketSend( pDeadMonster->getZone(), pDeadMonster->getX(), pDeadMonster->getY() );
		pEffectPacketSend->setPacket( pGCDO );
		// 1�� �ڿ� ��Ŷ ��������~
		pEffectPacketSend->setDeadline(10);
		pDeadMonster->getZone()->registerObject( pEffectPacketSend );
		pDeadMonster->getZone()->addEffect( pEffectPacketSend );

		SAFE_DELETE( pDeadMonster );
		return;
	}
	else if ( pDeadMonster->getMonsterType() == 764 )
	{
		// �׷���Ʈ ���Ǿ�
		GCDeleteObject* pGCDO = new GCDeleteObject;
		pGCDO->setObjectID( pDeadMonster->getObjectID() );

		EffectPacketSend* pEffectPacketSend = new EffectPacketSend( pDeadMonster->getZone(), pDeadMonster->getX(), pDeadMonster->getY() );
		pEffectPacketSend->setPacket( pGCDO );
		// 1�� �ڿ� ��Ŷ ��������~
		pEffectPacketSend->setDeadline(10);
		pDeadMonster->getZone()->registerObject( pEffectPacketSend );
		pDeadMonster->getZone()->addEffect( pEffectPacketSend );

		Monster* pNewMonster = new Monster(765);
		pNewMonster->setClanType( pDeadMonster->getClanType() );
		pNewMonster->setEventMonsterIndex( pDeadMonster->getEventMonsterIndex() );
		pNewMonster->setName(pDeadMonster->getName());
		pDeadMonster->getZone()->addCreature(pNewMonster, pDeadMonster->getX(), pDeadMonster->getY(), pDeadMonster->getDir());

		SAFE_DELETE( pDeadMonster );
		return;
	}
	else if ( pDeadMonster->getMonsterType() == 793
			|| pDeadMonster->getMonsterType() == 794
			|| pDeadMonster->getMonsterType() == 795 )
	{
		// �����̾�, �����̾�, �ƿ콺���� ������ ��ü ����
		// �ٷ� ���� ������.
		GCDeleteObject gcDO;
		gcDO.setObjectID( pDeadMonster->getObjectID() );
		pDeadMonster->getZone()->broadcastPacket( pDeadMonster->getX(), pDeadMonster->getY(), &gcDO );

		SAFE_DELETE( pDeadMonster );
		return;
	}

	// ��ü ��ü�� �����ϰ�, OID �� �Ҵ�޴´�.
	MonsterCorpse* pMonsterCorpse = new MonsterCorpse(pDeadMonster);
	pMonsterCorpse->setHostName(pDeadMonster->getHostName());
	pMonsterCorpse->setHostPartyID(pDeadMonster->getHostPartyID());
	pMonsterCorpse->setQuestHostName( pTable->getQuestHostName() );
	pMonsterCorpse->setLevel( (int)(pDeadMonster->getLevel()) );
	pMonsterCorpse->setExp( (Exp_t)computeCreatureExp(pDeadMonster, 100) );
	pMonsterCorpse->setLastKiller( pDeadMonster->getLastKiller() );

	// ���� ���� ������ ���� ��ü�� �������� �߰��صд�.
	addItem(pDeadMonster, pMonsterCorpse);

	// by sigi. 2002.12.12
	addCorpseToZone( pMonsterCorpse, m_pZone, cx, cy );

	if ( pDeadMonster->isFlag( Effect::EFFECT_CLASS_HARPOON_BOMB ) )
	{
		EffectHarpoonBomb* pEffect = dynamic_cast<EffectHarpoonBomb*>(pDeadMonster->findEffect( Effect::EFFECT_CLASS_HARPOON_BOMB ));
		if ( pEffect != NULL )
		{
			// ���Ͱ� ������ Harpoon Bomb ����Ʈ�� �ɷ�������
			// ���� Harpoon Bomb ����Ʈ�� �ɾ��ش�. �̶� �ٷ� affect �� �ǵ��� �Ͽ� ���������Ѵ�.
			// affect �ȿ��� deadline �� 0 ���� ����� �ٷ� ���������� �Ѵ�.
			EffectHarpoonBomb* pZoneEffect = new EffectHarpoonBomb( m_pZone, pMonsterCorpse->getX(), pMonsterCorpse->getY() );
			pZoneEffect->setDamage( pEffect->getDamage() );
			pZoneEffect->setUserObjectID( pEffect->getUserObjectID() );
			pZoneEffect->setNextTime( 0 );
			pZoneEffect->setDeadline( 999999999 );
//			pDeadMonster->deleteEffect( Effect::EFFECT_CLASS_HARPOON_BOMB );
			pEffect->setDeadline(0);
			m_pZone->registerObject( pZoneEffect );
			m_pZone->getTile( pMonsterCorpse->getX(), pMonsterCorpse->getY() ).addEffect( pZoneEffect );
			m_pZone->addEffect( pZoneEffect );
		}
	}

	// ũ��ó�� �׾��ٰ� �ֺ��� �˷��ش�.
	GCCreatureDied gcCreatureDied;
	gcCreatureDied.setObjectID(pDeadMonster->getObjectID());
	m_pZone->broadcastPacket(cx , cy , &gcCreatureDied);

	// �������� ��쿡 �����鼭 �� ���� �ϴ°�.. by sigi. 2002.9.13
	if (pDeadMonster->isMaster())
	{
		//MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo( pDeadMonster->getMonsterType() );
		MasterLairInfo* pMasterLairInfo = g_pMasterLairInfoManager->getMasterLairInfo( pZone->getZoneID() );

		if (pMasterLairInfo!=NULL
			&& pMasterLairInfo->getMasterMonsterType()==pDeadMonster->getMonsterType())
		{
			GCSay gcSay;
			gcSay.setObjectID( pDeadMonster->getObjectID() );
			gcSay.setColor( MASTER_SAY_COLOR );

			if (pDeadMonster->getLastHitCreatureClass() == Creature::CREATURE_CLASS_SLAYER)
			{
				gcSay.setMessage( pMasterLairInfo->getRandomMasterDeadSlayerSay() );
			}
			else
			{
				gcSay.setMessage( pMasterLairInfo->getRandomMasterDeadVampireSay() );
			}

			if (!gcSay.getMessage().empty())
				pZone->broadcastPacket(cx, cy, &gcSay);
		}
	}

	if ( pDeadMonster->getMonsterType() == 717 )
	{
		GCSay gcSay;
		gcSay.setObjectID( pDeadMonster->getObjectID() );
		gcSay.setColor( MASTER_SAY_COLOR );

		gcSay.setMessage( g_pStringPool->getString(345) );
		cout << gcSay.getMessage() << endl;
		pZone->broadcastPacket(cx, cy, &gcSay);
	}
	else if ( pDeadMonster->getMonsterType() == 723 )
	{
		GCSay gcSay;
		gcSay.setObjectID( pDeadMonster->getObjectID() );
		gcSay.setColor( MASTER_SAY_COLOR );

		gcSay.setMessage( g_pStringPool->getString(360) );
		cout << gcSay.getMessage() << endl;
		pZone->broadcastPacket(cx, cy, &gcSay);
	}

	// ũ���ĸ� �����Ѵ�.
	SAFE_DELETE(pDeadMonster);

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// addCreature
//
// (x, y) ��ó�� 
// monsterType�� Monster�� num���� �߰��Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void
MonsterManager::addMonsters(ZoneCoord_t x, ZoneCoord_t y, MonsterType_t monsterType, int num, const SUMMON_INFO& summonInfo, list<Monster*>* pSummonedMonsters)
{
	TPOINT pt;

	ClanType_t clanType = CLAN_VAMPIRE_MONSTER;	// default

	// group ��ü�� ���� clan
	if (summonInfo.clanType==SUMMON_INFO::CLAN_TYPE_RANDOM_GROUP
		|| summonInfo.clanType==SUMMON_INFO::CLAN_TYPE_GROUP)
	{
		clanType = summonInfo.clanID;//rand()%90+2;
	}

	// ���� �� ��ǥ�� ã�Ƴ���.
	for (int i=0; i<num; i++)
	{
		int positionX = 0;
		int positionY = 0;
		if( monsterType == 809 )
		{
			positionX = rand()%17-8;
			positionY = rand()%17-8;
		}

		pt = findSuitablePosition(m_pZone, x+positionX, y+positionY, Creature::MOVE_MODE_WALKING);

		// ��ġ�� ã�� ���߰ų�, ���������� �߰��� �� ����.
		if (pt.x == -1 || (m_pZone->getZoneLevel(pt.x, pt.y) & SAFE_ZONE))
		{
			return;
		}

		Monster* pMonster = NULL;

		// ���� ��ü�� �����ϰ� �ɷ�ġ ���� �ʱ�ȭ�Ѵ�.
		try {

			pMonster = new Monster(monsterType);
			//cout << "���� �߰�" << endl;

			// ��ȯ�� ���Ͱ� �������� �����°�?
			pMonster->setTreasure( summonInfo.hasItem );

			////////////////////////////////////////////////////////////////////////////////
			// ���͸� �߰��ϴ� �������� �̺�Ʈ �������� �˻縦 �Ѵ�.
			//  7�� 1�� �̺�Ʈ ������ �౸�� ������ ����
			/*
			if(rand()%g_pVariableManager->getEventRatio()==0 && 
					g_pVariableManager->getEventActivate() == 1 )
			{		
				pMonster->setEventMonsterFlag(true);
				string MonsterName = g_pMonsterNameManager->getRandomName(pMonster, true);
				pMonster->setName(MonsterName);

				//cout << "�̺�Ʈ ���� �̸�: " << MonsterName;
			}
			*/
			///////////////////////////////////////////////////////////////////////////

			Assert(pMonster != NULL);

			if (summonInfo.regenType==REGENTYPE_PORTAL)
			{
				// Ȥ�� �̹� �������������� �𸣴� �͵��� �������ش�.
				if ( pMonster->isFlag( Effect::EFFECT_CLASS_HIDE ) )
				{
					pMonster->removeFlag( Effect::EFFECT_CLASS_HIDE );
					pMonster->getViewable()->removeViewEffect( Effect::EFFECT_CLASS_HIDE, 0 );
				}

				if ( pMonster->isFlag( Effect::EFFECT_CLASS_INVISIBILITY ) )
				{
					Effect* pEffect = pMonster->findEffect( Effect::EFFECT_CLASS_INVISIBILITY );
					if ( pEffect ) pEffect->setDeadline(0);
				}

				pMonster->removeFlag( Effect::EFFECT_CLASS_TRANSFORM_TO_BAT );

				pMonster->setFlag(Effect::EFFECT_CLASS_VAMPIRE_PORTAL);
				pMonster->setMoveMode( Creature::MOVE_MODE_WALKING );
			}

			if (summonInfo.initHPPercent!=0)
			{
				int currentHP = pMonster->getHP(ATTR_CURRENT);
				int MaxHP = currentHP * 100 / summonInfo.initHPPercent;
				pMonster->setHP(MaxHP, ATTR_MAX);
			}

		} catch (OutOfBoundException& t) {
			filelog("MonsterManagerBug.log", "addMonsters : %s", t.toString().c_str());
			SAFE_DELETE(pMonster);
			return;
		} catch (NoSuchElementException& t) {
			filelog("MonsterManagerBug.log", "addMonsters : %s", t.toString().c_str());
			SAFE_DELETE(pMonster);
			return;
		}


		try
		{
			m_pZone->addCreature(pMonster , pt.x , pt.y , Directions(rand()%8));


			// SUMMON_INFO
			if (summonInfo.clanType==SUMMON_INFO::CLAN_TYPE_RANDOM_EACH)
			{
				pMonster->setClanType( rand()%90+2 );
			}
			else
			{
				pMonster->setClanType( clanType );
			}

			//cout << "clanType=" << (int)pMonster->getClanType() << endl;

			// 
			if (summonInfo.canScanEnemy)
			{
				pMonster->setScanEnemy();

				m_pZone->monsterScan(pMonster, pt.x, pt.y, pMonster->getDir());
			}
			else if (summonInfo.scanEnemy)
			{
				m_pZone->monsterScan(pMonster, pt.x, pt.y, pMonster->getDir());
			}

			if (pSummonedMonsters!=NULL)
			{
				pSummonedMonsters->push_back( pMonster );
			}
	
		}
		catch (EmptyTileNotExistException&)
		{
			//cerr << "MonsterManager::processCreatures() : �ڸ��� ����?" << endl;
			SAFE_DELETE(pMonster);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
// ���� ���Ϳ��Լ� �������� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::addItem(Monster* pDeadMonster, MonsterCorpse* pMonsterCorpse)
	throw (Error)
{
	__BEGIN_TRY

	if ( pDeadMonster->getMonsterType() == 734 )
	{
		if ( pDeadMonster->getZoneID() >= 1500 && pDeadMonster->getZoneID() <= 1506 )
		{
			ItemType_t iType = pDeadMonster->getZoneID() - min((int)pDeadMonster->getZoneID(), 1501);
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_CASTLE_SYMBOL, iType, list<OptionType_t>() );
			pMonsterCorpse->setZone( pDeadMonster->getZone() );
			//pMonsterCorpse->addTreasure( pItem );

			// �ٴڿ� �ٷ� ���������� ����
			Zone* pZone = pDeadMonster->getZone();
			Assert( pZone != NULL );
			pZone->registerObject( pItem );
			TPOINT tp = pZone->addItem( pItem, pDeadMonster->getX(), pDeadMonster->getY() );

			pItem->create( "", STORAGE_ZONE, pZone->getZoneID(), tp.x, tp.y );

			dissectionRelicItem( pMonsterCorpse, pItem, tp );
		}
	}

	if ( pDeadMonster->getMonsterType() == 807 )
	{
		list<OptionType_t> nullOption;
		EventStar tmpItem( 6, nullOption, 1 );

		// EventItemCount ����. DB �� ������ �����.
		increaseEventItemCount( &tmpItem, 5 );
	}

	// 2009 �߼� �̺�Ʈ �޺� ���� - �ҿ��� ���غ� �̺�Ʈ
	int wishRatio = g_pVariableManager->getVariable( MOON_CRYSTAL_RATIO );
	//cout << "[AddItem] " << "wishRatio = " << wishRatio << endl;
	int userLevel, monsterLevel = pDeadMonster->getLevel();
	Creature* pCreature = pDeadMonster->getZone()->getCreature( pDeadMonster->getLastKiller() );
	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	if(pPC != NULL)
	{
		if(pPC->isAdvanced())
		{
			if(monsterLevel >= 140) // ���� ĳ���ʹ� 140���� �̻��� ���͸� ����� ��쿡�� ����
			{
				if ( wishRatio > 0 )
				{
					int value = rand() % 300;
					//cout << "[AddItem] " << "wishRatio = " << value << endl;
					if ( value < wishRatio )
					{
						// �޺� ���� ������ ����
						list<OptionType_t> optionType;
						Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_COMMON_QUEST_ITEM, 52, optionType ); //ITEM_CLASS_MOON_CARD �� ����
						// ���� ��ü�� �ִ´�.
						pMonsterCorpse->addTreasure( pItem );
						//cout << "[AddItem Suc!!] " << endl;
					}
				}
			}
		}
		else
		{
			if( pPC->isSlayer() )
			{
				Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
				Assert( pSlayer != NULL );
				userLevel = pSlayer->getLevel();
			}
			else if( pPC->isVampire() )
			{
				Vampire* pVampire= dynamic_cast<Vampire*>(pPC);
				Assert( pVampire != NULL );
				userLevel = pVampire->getLevel();
			}
			else if( pPC->isOusters() )
			{
				Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
				Assert( pOusters != NULL );
				userLevel = pOusters->getLevel();
			}
			int iResult = 0;
			if(monsterLevel > userLevel )
			{
				iResult = monsterLevel - userLevel;
			}
			else if((monsterLevel < userLevel ))
			{
				iResult = userLevel - monsterLevel;
			}

			if(iResult < 20)
			{
				if ( wishRatio > 0 )
				{
					int value = rand() % 300;
					//cout << "[AddItem] " << "wishRatio = " << value << endl;
					if ( value < wishRatio )
					{
						// �޺� ���� ������ ����
						list<OptionType_t> optionType;
						Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_COMMON_QUEST_ITEM, 52, optionType ); //ITEM_CLASS_MOON_CARD �� ����
						// ���� ��ü�� �ִ´�.
						pMonsterCorpse->addTreasure( pItem );
						//cout << "[AddItem Suc!!] " << endl;
					}
				}
			}

		}
	}

/*
	// 20080528 6�� 13���� �ݿ��� �̺�Ʈ ���� ������ �߰�
	if ( pDeadMonster->getMonsterType() == 1038 )
	{
		int value = rand()%1000;
		Item* pItem = NULL;
		if( value < 300 )
		{
			pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EFFECT_ITEM, 47, list<OptionType_t>() );		
		}
		else if( value < 305 )
		{
			pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_STAR, 54, list<OptionType_t>() );		
		}
		else if( value < 310 )
		{
			pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_STAR, 55, list<OptionType_t>() );		
		}
		else if( value < 450 )
		{
			pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_STAR, 56, list<OptionType_t>() );		
		}
		else if( value < 700 )
		{
			pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_RESURRECT_ITEM, 0, list<OptionType_t>() );		
		}
		else if( value < 1000 )
		{
			pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_ETC, 14, list<OptionType_t>() );		
		}

		pMonsterCorpse->addTreasure( pItem );
	}
*/
		
	// ����Ʈ ������ �߰�
	if ( pDeadMonster->getQuestItem() != NULL )
	{
		pMonsterCorpse->addTreasure( pDeadMonster->getQuestItem() );
		pDeadMonster->setQuestItem( NULL );
	}

	if ( g_pVariableManager->getVariable( PREMIUM_TRIAL_EVENT ) != 0 && pDeadMonster->getMonsterType() == 705 )
	{
		if ( rand()%100 < 30 )
		{
			int Num = 5 + (rand()%5); // 5~9
			for ( int i=0; i<Num; ++i )
			{
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_LUCKY_BAG, 3, list<OptionType_t>() );
				pMonsterCorpse->addTreasure( pItem );
			}
		}
	}

	// 2007 06 22 �ﰡ�� Ű ���
	ItemType_t keyType = 0;
	switch( pDeadMonster->getMonsterType() )
	{
		case 917:
			keyType = 11;
			break;
		case 918:
			keyType = 12;
			break;
		case 919:
			keyType = 13;
			break;
		case 920:
			keyType = 14;
			break;
		case 921:
			keyType = 15;
			break;
	}

	if( keyType != 0 )
	{
		Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_QUEST_ITEM, keyType, list<OptionType_t>() );
		pMonsterCorpse->addTreasure( pItem );
	}

	// �������� �� ������ ���� üũ(==������ ��ȯ ����)
	// by sigi. 2002.9.2
	if (!pDeadMonster->hasTreasure())
		return;

	MonsterType_t MonsterType = pDeadMonster->getMonsterType();
	const MonsterInfo* pMonsterInfo = g_pMonsterInfoManager->getMonsterInfo(MonsterType);
	TreasureList* pTreasureList = NULL;

	//----------------------------------------------------------------------
	// 2002�� �߼� �̺�Ʈ ������
	// ������ ���� Ȯ���� ���� �ڿ��� �ٸ� �������� ������ �ʾƾ� �Ѵ�. 
	//----------------------------------------------------------------------
	bool isHarvestFestivalItemAppeared = false;
	int  PartialSumOfCakeRatio = 0;
	int  itemBonusPercent = 0;

	if (g_pVariableManager->getHarvestFestivalItemRatio() > 0 &&  rand() % g_pVariableManager->getHarvestFestivalItemRatio() == 0) 
	{
		// �������� 5���� �߿��� ���� �� �ִ�.
		ITEM_TEMPLATE ricecake_template;
		ricecake_template.NextOptionRatio = 0;

		bool bOK = false;
		int EventSelector = rand() % m_SumOfCakeRatio;

		for (int i=0; i<5; i++)
		{
			PartialSumOfCakeRatio += m_RICE_CAKE_PROB_RATIO[i];

			// ���� Dice ������� ����ȴٸ�
			if ( EventSelector < PartialSumOfCakeRatio)
			{
				if ( i == 0 )
				{
					if (pDeadMonster->getLastHitCreatureClass() == Creature::CREATURE_CLASS_SLAYER)
					{
						ricecake_template.ItemClass = Item::ITEM_CLASS_POTION;
						ricecake_template.ItemType  = 11;
					}
					else
					{
						ricecake_template.ItemClass = Item::ITEM_CLASS_SERUM;
						ricecake_template.ItemType  = 5;
					}
				}
				else
				{
					// ��
					ricecake_template.ItemClass = Item::ITEM_CLASS_EVENT_STAR;
					ricecake_template.ItemType = i + 7;
				}
				bOK = true;
				break;
			}
		}

		//cout << "�̺�Ʈ ������ ����"  << "[" << i >> "," << EventSelector << "]" << m_SumOfCakeRatio << endl 
			 //<< "(" << ricecake_template.ItemClass << " " << ricecake_template.ItemType << ")" << endl;

		if (bOK)
		{
			Item* pItem = g_pItemFactoryManager->createItem(ricecake_template.ItemClass,ricecake_template.ItemType, ricecake_template.OptionType);

			Assert(pItem != NULL);

			pMonsterCorpse->addTreasure(pItem);

			isHarvestFestivalItemAppeared = true;
		}
	}
	
	if (g_pVariableManager->isMonsterDropItemRudolphPattern())
	{	
		unsigned int iRudolphPatternRatio = rand()%100;
		unsigned int iRudolphPatternCreateRatio = rand()%10000;
		int iMonsterLevel = 0;
		int iUserLevel = 0;
		int iSuccessResult = 0;
		bool bAdvanceResult = false;
		
		if ( m_pZone != NULL && pDeadMonster != NULL)
		{
			Creature* pCreature = pDeadMonster->getZone()->getCreature( pDeadMonster->getLastKiller() );
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
			
			if(pPC != NULL && pCreature != NULL)
			{		
				if( pPC->isSlayer() )
				{
					Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
					Assert( pSlayer != NULL );
					iUserLevel = pSlayer->getLevel();
				}
				else if( pPC->isVampire() )
				{
					Vampire* pVampire= dynamic_cast<Vampire*>(pPC);
					Assert( pVampire != NULL );
					iUserLevel = pVampire->getLevel();
				}
				else if( pPC->isOusters() )
				{
					Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
					Assert( pOusters != NULL );
					iUserLevel = pOusters->getLevel();
				}
				
				iMonsterLevel = pDeadMonster->getLevel();
			
				if(iMonsterLevel > iUserLevel)
				{
					iSuccessResult = iMonsterLevel - iUserLevel;
				}
				else if( iMonsterLevel < iUserLevel )
				{
					iSuccessResult = iUserLevel - iMonsterLevel;
				}
				
				if(pPC->isAdvanced())
				{
					if( iMonsterLevel >= 140 )
					{
						bAdvanceResult = true;
						
						cout << "���� ������ 140�� �Ѵ±���." << endl;
					}
				}
			}
		}
		
		cout << "bAdvanceResult : " << bAdvanceResult << endl;
			
		if((iSuccessResult <= 20 && iRudolphPatternRatio < 5) || (bAdvanceResult == true && iRudolphPatternRatio < 5))
		{
			cout << " ������ �༮�� ��Ƽ� ���� ��� " << endl;
			
			if(iRudolphPatternCreateRatio <= 1200)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 90, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 1201 && iRudolphPatternCreateRatio <= 2300)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 91, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 2301 && iRudolphPatternCreateRatio <= 3400)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 92, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 3401 && iRudolphPatternCreateRatio <= 4500)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 93, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 4501 && iRudolphPatternCreateRatio <= 5600)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 94, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 5601 && iRudolphPatternCreateRatio <= 6700)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 95, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 6701 && iRudolphPatternCreateRatio <= 7800)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 96, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 7801 && iRudolphPatternCreateRatio <= 8900)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 97, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
			else if(iRudolphPatternCreateRatio >= 8901 && iRudolphPatternCreateRatio <= 10000)
			{
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, 98, optionType );
				pMonsterCorpse->addTreasure( pItem );
			}
		}
	}

	//----------------------------------------------------------------------
	// ũ�������� ���� �߰�
	//----------------------------------------------------------------------
/*	int fireCrackerRatio = g_pVariableManager->getVariable( CHRISTMAS_FIRE_CRACKER_RATIO );
	if ( fireCrackerRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < fireCrackerRatio )
		{
			// �� ���� ������ ������ ���´�.
			ItemType_t fireCrackerType = value % 14;

			// �������� �����Ѵ�.
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_ETC, fireCrackerType, optionType );

			// ���� ��ü�� �ִ´�.
			pMonsterCorpse->addTreasure( pItem );
		}
	}*/ // SkillUtil.cpp �� �ű�
	
	//----------------------------------------------------------------------
	// ũ�������� Ʈ�� ���� �߰�
	//----------------------------------------------------------------------
	int treePartRatio = g_pVariableManager->getVariable( CHRISTMAS_TREE_PART_RATIO );
	if ( treePartRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < treePartRatio )
		{
			// 12���� Ʈ�� ������ �ִ�.
			ItemType_t treeItemType = rand() % 12;

			// �������� �����Ѵ�.
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, treeItemType, optionType );

			// ���� ��ü�� �ִ´�.
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	// 2006.12.6 ũ�������� �̺�Ʈ 
	int snowmanPartRatio = g_pVariableManager->getVariable( EVENT_SNOW_MAN_PART_RATIO );
	if ( snowmanPartRatio > 0 )
	{
		int value = rand() % 10000;

		int userLevel, monsterLevel = pDeadMonster->getLevel();
		Creature* pCreature = m_pZone->getCreature( pDeadMonster->getLastKiller() );
		if( pCreature != NULL && pCreature->isPC() )
		{
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
			if( pPC->isSlayer() )
			{
				Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
				Assert( pSlayer != NULL );
				userLevel = pSlayer->getLevel();
			}
			else if( pPC->isVampire() )
			{
				Vampire* pVampire= dynamic_cast<Vampire*>(pPC);
				Assert( pVampire != NULL );
				userLevel = pVampire->getLevel();
			}
			else if( pPC->isOusters() )
			{
				Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
				Assert( pOusters != NULL );
				userLevel = pOusters->getLevel();
			}

			userLevel = min( userLevel, 150 );

			if ( value < snowmanPartRatio && userLevel <= monsterLevel+30 )
			{
				ItemType_t snowmanItemType = (rand() % 12) + 42;

				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, snowmanItemType, optionType );

				pMonsterCorpse->addTreasure( pItem );
			}
		}
	}


	//----------------------------------------------------------------------
	// ��� ���� ���� �߰�
	//----------------------------------------------------------------------
	int giftBoxRatio = g_pVariableManager->getVariable( CHRISTMAS_GIFT_BOX_RATIO );
	if ( giftBoxRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < giftBoxRatio )
		{
			// ��� ���� ���ڸ� �����Ѵ�.
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 0, optionType );

			// ���� ��ü�� �ִ´�.
			pMonsterCorpse->addTreasure( pItem );
		}
	}

	//----------------------------------------------------------------------
	// ���� ���� �߰�
	//----------------------------------------------------------------------
	// ���ָӴϴ� affectKillCount ���⼭ ó��������
	// ���� ���ڴ� Monster �� m_pQuestItem �� ���� ���� �ƴϹǷ� ���⼭ ó���Ѵ�
	// (��� ���ָӴϵ� m_pQuestItem �� ���� �ʿ䰡 �����ϴٸ� ;;)
	//----------------------------------------------------------------------
	if ( g_pVariableManager->isEventGiftBox() )
	{
		if ( m_pZone != NULL )
		{
			Creature* pCreature = m_pZone->getCreature( pDeadMonster->getLastKiller() );

			if ( pCreature != NULL && pCreature->isPC() )
			{
				PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);

				if ( pPC != NULL )
				{
					Item* pItem = getGiftBoxItem( getGiftBoxKind( pPC, pDeadMonster ) );

					// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
					if ( pItem != NULL )
						pMonsterCorpse->addTreasure( pItem );
				}
			}
		}
	}

//1219 wlzzi - 2008 12�� �̺�Ʈ -- 
	if ( g_pVariableManager->getVariable( EVENT_2008CHRISTMAS ) && 
			(pDeadMonster->getMonsterType() == 360 || pDeadMonster->getMonsterType() == 361) )
	{
		Creature* pCreature = m_pZone->getCreature( pDeadMonster->getLastKiller() );
		if ( pCreature && pCreature->isPC() )
		{
			int userLevel = getCreatureLevel (pCreature);
			int monsterType = pDeadMonster->getMonsterType();
			if ( (userLevel > 59 && monsterType == 360) || (userLevel < 60 && monsterType == 361) ) 
			{
				// 9���� �縻���� ������ �ִ�.
				ItemType_t SocksItemType = 81 + rand() % 9;	//81 ~ 90

				// �������� �����Ѵ�.
				list<OptionType_t> optionType;
				Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, SocksItemType, optionType );

				// ���� ��ü�� �ִ´�.
				pMonsterCorpse->addTreasure( pItem );
			}
		}
	}
//-
	// 20080526 ���ָӴ� �̺�Ʈ, ����, ���� Ŭ�ι� ���� �����ϰ� ������.
	{
		Creature* pCreature = m_pZone->getCreature( pDeadMonster->getLastKiller() );

		if ( pCreature != NULL && pCreature->isPC() )
		{
			int userLevel, monsterLevel = pDeadMonster->getLevel();
			PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
			do{
				if(pPC == NULL)
					break;

				if(pPC->isAdvanced())
				{
					if(monsterLevel < 140) // 20070906 �߼��̺�Ʈ ���� ĳ���ʹ� 140���� �̻��� ���͸� ����� ��쿡�� ����
						break;
				}
				else
				{

					if( pPC->isSlayer() )
					{
						Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
						Assert( pSlayer != NULL );
						userLevel = pSlayer->getLevel();
					}
					else if( pPC->isVampire() )
					{
						Vampire* pVampire= dynamic_cast<Vampire*>(pPC);
						Assert( pVampire != NULL );
						userLevel = pVampire->getLevel();
					}
					else if( pPC->isOusters() )
					{
						Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
						Assert( pOusters != NULL );
						userLevel = pOusters->getLevel();
					}

					//				userLevel = min( userLevel, 150 );
					if((userLevel + 20 < monsterLevel) || (userLevel - 20 > monsterLevel)) // 20070906 �߼��̺�Ʈ ������� ���� ���� ���̰� +/- 20 �̻��� ��� ���õ��� ����
						break;
				}
				list<OptionType_t> optionType;
				if ( g_pVariableManager->isRiceCakeEvent() )
				{
					if ( m_pZone != NULL && rand() % g_pVariableManager->getRiceCakeItemRatio() == 0)
					{
						Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_STAR, 47, optionType ); // 20080123 ���� �߼��̺�Ʈ ��Ȱ��
						// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
						if ( pItem != NULL )
						{
							filelog("GiftBox.txt", "[%s]���� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
							pMonsterCorpse->addTreasure( pItem );
						}
					}
				}

				if ( g_pVariableManager->isThreeLeafEvent() ) // 20080425 ���� Ŭ�ι� �̺�Ʈ
				{
					if ( m_pZone != NULL && rand() % g_pVariableManager->getThreeLeafItemRatio() == 0)
					{
						Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 30, optionType ); 
						// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
						if ( pItem != NULL )
						{
							filelog("GiftBox.txt", "[%s]���� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
							pMonsterCorpse->addTreasure( pItem );
						}
					}
				}
				if ( g_pVariableManager->isFourLeafEvent() ) // 20080425 ���� Ŭ�ι� �̺�Ʈ
				{
					if ( m_pZone != NULL && rand() % g_pVariableManager->getFourLeafItemRatio() == 0)
					{
						Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 31, optionType ); 
						// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
						if ( pItem != NULL )
						{
							filelog("GiftBox.txt", "[%s]���� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
							pMonsterCorpse->addTreasure( pItem );
						}
					}
				}
				if ( g_pVariableManager->isBloodGiftBox() ) // 20080528 �ͺ� �������� �̺�Ʈ
				{
					if ( m_pZone != NULL && rand() % g_pVariableManager->getBloodGiftBoxRatio() == 0)
					{
						Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 32, optionType ); 
						// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
						if ( pItem != NULL )
						{
							filelog("GiftBox.txt", "[%s]���� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
							pMonsterCorpse->addTreasure( pItem );
						}
					}
				}
				//----------------------------------------------------------------------
				// 20080825 ���������� �����̺�Ʈ ���� �߰�
				//----------------------------------------------------------------------
				int blitzPartRatio = g_pVariableManager->getVariable( BLITZ_PART_RATIO );
				if ( blitzPartRatio > 0 )
				{
					int value = rand() % 10000;
					if ( value < blitzPartRatio )
					{
						// 12���� ������ �ִ�.
						ItemType_t blitzItemType = 55;
						int blitzItemRatio = rand() % 1000;
						int addRatio = 0;
						// EventTreeInfo here holds ItemTypes 0-41 only, so every lookup in
						// this range returns NULL and the original unchecked
						// pItemInfo->getRatio() dereferenced it, killing the whole
						// gameserver with SIGSEGV. Skip types with no info, and drop
						// nothing at all if none of them exist.
						// Dormant today: BLITZ_PART_RATIO is never assigned a default and
						// AttrInfo has no row for it, so it stays 0 and this never runs.
						bool bFoundBlitzInfo = false;
						for(int i = 55; i < 67; i++)
						{
							ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(Item::ITEM_CLASS_EVENT_TREE, i);
							if (pItemInfo == NULL) continue;

							addRatio += pItemInfo->getRatio();
							bFoundBlitzInfo = true;

							if(blitzItemRatio < addRatio)
							{
								blitzItemType = i;
								break;
							}
						}

						if ( bFoundBlitzInfo )
						{
							list<OptionType_t> optionType;
							Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, blitzItemType, optionType );

							if ( pItem != NULL )
								pMonsterCorpse->addTreasure( pItem );
						}
					}
				}
				//----------------------------------------------------------------------
				// 20080925 smallheart �����̺�Ʈ ���� �߰�
				//----------------------------------------------------------------------
				int fallenleavesPartRatio = g_pVariableManager->getVariable( FALLENLEAVES_PART_RATIO );
				if ( fallenleavesPartRatio > 0 )
				{
					int value = rand() % 10000;
					if ( value < fallenleavesPartRatio )
					{
						// 12���� ������ �ִ�.
						ItemType_t fallenleavesItemType = 68; // ~ 79
						int fallenleabesItemRatio = rand() % 1000;
						int addRatio = 0;
						// EventTreeInfo here holds ItemTypes 0-41 only, so every lookup in
						// this range returns NULL and the original unchecked
						// pItemInfo->getRatio() dereferenced it, killing the whole
						// gameserver with SIGSEGV. Skip types with no info, and drop
						// nothing at all if none of them exist.
						// This one was live: FALLENLEAVES_PART_RATIO defaults to 500 and
						// AttrInfo has no row to override it, so a 5% roll on EVERY
						// monster kill crashed the server -- seen as a random client DC.
						bool bFoundFallenLeavesInfo = false;
						for(int i = 68; i < 80; i++)
						{
							ItemInfo* pItemInfo = g_pItemInfoManager->getItemInfo(Item::ITEM_CLASS_EVENT_TREE, i);
							if (pItemInfo == NULL) continue;

							addRatio += pItemInfo->getRatio();
							bFoundFallenLeavesInfo = true;

							if(fallenleabesItemRatio < addRatio)
							{
								fallenleavesItemType = i;
								break;
							}
						}

						if ( bFoundFallenLeavesInfo )
						{
							list<OptionType_t> optionType;
							Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_TREE, fallenleavesItemType, optionType );

							if ( pItem != NULL )
								pMonsterCorpse->addTreasure( pItem );
						}
					}
				}	
				// �� ������ �̺�Ʈ (�ҷ���) kisoo
				if ( g_pVariableManager->isJackoLanternEvent() ) // �� ������ �̺�Ʈ
				{
					int wishRatio = g_pVariableManager->getJackoLanternItemRatio();//g_pVariableManager->getVariable( MOON_CRYSTAL_RATIO );
					cout << "������� [addItem] " << "wishRatio = " << wishRatio << endl;
					int userLevel, monsterLevel = pDeadMonster->getLevel();

					if ( m_pZone != NULL )//&& rand() % g_pVariableManager->getJackoLanternItemRatio() == 0)
					{

						PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
						if(pPC != NULL)
						{
							if(pPC->isAdvanced())
							{
								if(monsterLevel >= 140) // ���� ĳ���ʹ� 140���� �̻��� ���͸� ����� ��쿡�� ����
								{
									if ( wishRatio > 0 )
									{
										int value = rand() % 300;
										//cout << "[AddItem] " << "wishRatio = " << value << endl;
										if ( value < wishRatio )
										{
											list<OptionType_t> optionType;
											Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 35, optionType );
											// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
											if ( pItem != NULL )
											{
												filelog("GiftBox.txt", "[%s]���� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
												pMonsterCorpse->addTreasure( pItem );
											}
										}


									}
								}
							}
							else
							{
								if( pPC->isSlayer() )
								{
									Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
									Assert( pSlayer != NULL );
									userLevel = pSlayer->getLevel();
								}
								else if( pPC->isVampire() )
								{
									Vampire* pVampire= dynamic_cast<Vampire*>(pPC);
									Assert( pVampire != NULL );
									userLevel = pVampire->getLevel();
								}
								else if( pPC->isOusters() )
								{
									Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
									Assert( pOusters != NULL );
									userLevel = pOusters->getLevel();
								}
								int iResult = 0;
								if(monsterLevel > userLevel )
								{
									iResult = monsterLevel - userLevel;
								}
								else if((monsterLevel < userLevel ))
								{
									iResult = userLevel - monsterLevel;
								}

								if(iResult < 20)
								{
									if ( wishRatio > 0 )
									{
										int value = rand() % 300;
										//cout << "[AddItem] " << "wishRatio = " << value << endl;
										if ( value < wishRatio )
										{
											//
											list<OptionType_t> optionType;
											Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 35, optionType );
											// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
											if ( pItem != NULL )
											{
												filelog("GiftBox.txt", "[%s]���� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
												pMonsterCorpse->addTreasure( pItem );
											}
										}
									}
								}

							}
						}
					}
				}

			}while(false);
		}
	}

/*	if ( g_pVariableManager->isThreeLeafEvent() ) // 20080425 ���� Ŭ�ι� �̺�Ʈ
	{
		if ( m_pZone != NULL && rand() % g_pVariableManager->getThreeLeafItemRatio() == 0)
		{
			Creature* pCreature = m_pZone->getCreature( pDeadMonster->getLastKiller() );

			if ( pCreature != NULL && pCreature->isPC() )
			{
				int userLevel, monsterLevel = pDeadMonster->getLevel();
				PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
				do{
					if(pPC == NULL)
						break;
					
					if(pPC->isAdvanced())
					{
						if(monsterLevel < 140) // 20070906 �߼��̺�Ʈ ���� ĳ���ʹ� 140���� �̻��� ���͸� ����� ��쿡�� ����
							break;
					}
					else
					{
				
						if( pPC->isSlayer() )
						{
							Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
							Assert( pSlayer != NULL );
							userLevel = pSlayer->getLevel();
						}
						else if( pPC->isVampire() )
						{
							Vampire* pVampire= dynamic_cast<Vampire*>(pPC);
							Assert( pVampire != NULL );
							userLevel = pVampire->getLevel();
						}
						else if( pPC->isOusters() )
						{
							Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
							Assert( pOusters != NULL );
							userLevel = pOusters->getLevel();
						}

//				userLevel = min( userLevel, 150 );
						if((userLevel + 10 < monsterLevel) || (userLevel - 10 > monsterLevel))
							break;
					}
					
					list<OptionType_t> optionType;
					Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 30, optionType ); 


					// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
					if ( pItem != NULL )
					{
						filelog("GiftBox.txt", "[%s]���� ����Ŭ�ι� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
						pMonsterCorpse->addTreasure( pItem );
					}
					
				}while(false);
			}
		}
	}

	if ( g_pVariableManager->isFourLeafEvent() ) // 20080425 ���� Ŭ�ι� �̺�Ʈ
	{
		if ( m_pZone != NULL && rand() % g_pVariableManager->getFourLeafItemRatio() == 0)
		{
			Creature* pCreature = m_pZone->getCreature( pDeadMonster->getLastKiller() );

			if ( pCreature != NULL && pCreature->isPC() )
			{
				int userLevel, monsterLevel = pDeadMonster->getLevel();
				PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
				do{
					if(pPC == NULL)
						break;
					
					if(pPC->isAdvanced())
					{
						if(monsterLevel < 140) // 20070906 �߼��̺�Ʈ ���� ĳ���ʹ� 140���� �̻��� ���͸� ����� ��쿡�� ����
							break;
					}
					else
					{
				
						if( pPC->isSlayer() )
						{
							Slayer* pSlayer = dynamic_cast<Slayer*>(pPC);
							Assert( pSlayer != NULL );
							userLevel = pSlayer->getLevel();
						}
						else if( pPC->isVampire() )
						{
							Vampire* pVampire= dynamic_cast<Vampire*>(pPC);
							Assert( pVampire != NULL );
							userLevel = pVampire->getLevel();
						}
						else if( pPC->isOusters() )
						{
							Ousters* pOusters = dynamic_cast<Ousters*>(pPC);
							Assert( pOusters != NULL );
							userLevel = pOusters->getLevel();
						}

						if((userLevel + 10 < monsterLevel) || (userLevel - 10 > monsterLevel)) 
							break;
					}
					
					list<OptionType_t> optionType;
					Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_GIFT_BOX, 31, optionType ); 


					// GiftBox �������� �߰��ؾ� �ȴٸ� �߰��Ѵ�.
					if ( pItem != NULL )
					{
						filelog("GiftBox.txt", "[%s]���� ����Ŭ�ι� [%d] �� �޾ҽ��ϴ�.\n", pCreature->getName().c_str(), pItem->getItemType());
						pMonsterCorpse->addTreasure( pItem );
					}
					
				}while(false);
			}
		}
	}
*/
	// ������ �Ծ���� ĳ������ ������ ������.
	// ���� ���� �� ĳ���Ͱ� ���ٸ�, 
	// �� ĳ������ party�� ������.. ��Ƽ�� ���ٸ�
	// LastHit�� ������.
	// by sigi. 2002.10.14
	// ���������� �� ���͸� ���� ũ���İ� �����̾��� �����̾� �������� �����ϰ�,
	// �ƴ϶�� ����Ʈ�� �����̾� �������� �����Ѵ�.
	Creature* pItemOwnerCreature = m_pZone->getPCManager()->getCreature( pDeadMonster->getHostName() );
	bool bPremiumPlayer = false;
	//1223 wlzzi - �����̾� �� ���� ���� 
	bool bPremiumZoneBenefit = false;

	Creature::CreatureClass ownerCreatureClass;
	
	int luckLevel = 0;
	if (pItemOwnerCreature!=NULL)
	{
		ownerCreatureClass = pItemOwnerCreature->getCreatureClass();
		luckLevel = pItemOwnerCreature->getLuck();

		if ( g_pTimeChecker->isInPeriod( TIME_PERIOD_LUCK_UP ) ) luckLevel *= 2;

		GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(pItemOwnerCreature->getPlayer());

		if ( pGamePlayer != NULL)
		{
			itemBonusPercent = pGamePlayer->getItemRatioBonusPoint();
			bPremiumZoneBenefit = pGamePlayer->isAuthGameFeature(GamePlayer::GAME_FEATURE_APPLY_PREMIUMZONE, (void*)pDeadMonster->getZone());	//1223 wlzzi - �����̾� �� ���� 
		}

//		if ( pGamePlayer != NULL && pGamePlayer->isPayPlaying() )
		if ( pGamePlayer != NULL && pGamePlayer->isPremiumPlay() ) // 20080227 ������ Ƽ�� �߰��� ����
			bPremiumPlayer = true;
	}
	else if (pDeadMonster->getHostPartyID()!=0)
	{
		Party* pParty = m_pZone->getLocalPartyManager()->getParty( pDeadMonster->getHostPartyID() );

		if (pParty!=NULL)
		{
			ownerCreatureClass = pParty->getCreatureClass();
		}
		else
		{
			ownerCreatureClass = pDeadMonster->getLastHitCreatureClass();
		}
		//1223 wlzzi - �����̾� �� ���� .. // PremiumZoneType �� 2�� ���� ..
		bPremiumZoneBenefit = (pDeadMonster->getZone())->getPremiumZoneType() == 2? true : false;
	}
	else 
	{
		ownerCreatureClass = pDeadMonster->getLastHitCreatureClass();
	}

	// ������ �������� ������ ���� �������� ���� ���� 
	if (ownerCreatureClass == Creature::CREATURE_CLASS_SLAYER)
	{
		pTreasureList = pMonsterInfo->getSlayerTreasureList();
	}
	else if (ownerCreatureClass == Creature::CREATURE_CLASS_VAMPIRE)
	{
		pTreasureList = pMonsterInfo->getVampireTreasureList();
	}
	else if (ownerCreatureClass == Creature::CREATURE_CLASS_OUSTERS)
	{
		pTreasureList = pMonsterInfo->getOustersTreasureList();
	}

	// �� ���Ͱ� chief monster�ΰ�?  by sigi. 2002.10.23
	bool bChiefMonsterBonus = pDeadMonster->isChief()
								&& g_pVariableManager->isActiveChiefMonster();


	if ( pTreasureList != NULL )
	{
		const list<Treasure*>& treasures = pTreasureList->getTreasures();

		list<Treasure*>::const_iterator itr = treasures.begin();
		for (; itr != treasures.end(); itr++)
		{
			Treasure* pTreasure = (*itr);
			ITEM_TEMPLATE it;

			it.ItemClass  = Item::ITEM_CLASS_MAX;
			it.ItemType   = 0;
			//it.OptionType = 0;

			int itemRatioBonus = 0;

			if (bChiefMonsterBonus)
			{
				it.NextOptionRatio = g_pVariableManager->getChiefMonsterRareItemPercent();
				itemRatioBonus     = g_pVariableManager->getPremiumItemProbePercent();
			}
			else
			{
				it.NextOptionRatio = pDeadMonster->getMonsterNextRatio();
			}

			Item* pItem = NULL;

			// ����ȭ �������� ������ Ȯ���� �� ���.
			Zone* pZone = pDeadMonster->getZone();

			// ����̺�Ʈ�� ����Ǵ� ��. by sigi. 2003.1.17
			static bool isNetMarble = g_pConfig->getPropertyInt("IsNetMarble")!=0;
			bool isLottoZone = pZone->isPayPlay() || isNetMarble;

//1223 wlzzi - �����̾� �� ���� //����ȭ -- isPremiumZone���� �˻����� �ʰ�, GamePlayer::isAuthGameFeature �Լ���.. �����̾� �� ���� �ο� ���θ� �Ǵ��Ѵ�.
//							-- �� �Ǵ��� .. ������.. �ϵ��� �Ѵ�.
//			if ( pZone->isPayPlay() 
//				|| pZone->isPremiumZone())
			if (bPremiumZoneBenefit)
			{
//				cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
				if (pTreasure->getRandomItem(&it, itemRatioBonus + g_pVariableManager->getPremiumItemProbePercent() + itemBonusPercent, bPremiumPlayer ) )
				{
					// by sigi. 2002.10.21
					int upgradeLevel = upgradeItemTypeByLuck(luckLevel, ownerCreatureClass, it);
					if ( upgradeLevel != 0 )
					{
						GCAddEffectToTile gcAE;

						if ( upgradeLevel > 0 ) gcAE.setEffectID( Effect::EFFECT_CLASS_LUCKY );
						else gcAE.setEffectID( Effect::EFFECT_CLASS_MISFORTUNE );

						gcAE.setObjectID( 0 );
						gcAE.setDuration( 0 );
						gcAE.setXY( pDeadMonster->getX(), pDeadMonster->getY() );

						PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pItemOwnerCreature);
						if ( pPC != NULL )
						{
							if ( canGiveEventItem( pPC, pDeadMonster ) && !GDRLairManager::Instance().isGDRLairZone(pPC->getZoneID()) )
							{
								if ( upgradeLevel > 0 )
									addOlympicStat( pPC, 5 );
								else
									addOlympicStat( pPC, 6 );
							}
						}

	//					cout << "��ε�ĳ���� : " << pDeadMonster->getX() << ", " << pDeadMonster->getY() << endl;
						
						pZone->broadcastPacket( pDeadMonster->getX(), pDeadMonster->getY(), &gcAE );
					}

					if ( !it.OptionType.empty() )
					{
						upgradeOptionByLuck( luckLevel, ownerCreatureClass, it );
					}

					// ġ�� ���ʹ� ������ 1�ܰ� +
					// by sigi. 2002.10.23
					if (bChiefMonsterBonus
						// �ϴ� rare Ȯ���� ���� ���µ�..
						// ���߿� �̰͵� �ٸ� variable�� �и��ؾߵ� ���̴�.	 by sigi. 2002.10.23
						&& rand()%100 < g_pVariableManager->getChiefMonsterRareItemPercent()
						&& isPossibleUpgradeItemType(it.ItemClass))
					{
						// ItemType 1�ܰ� upgrade
						int upgradeCount = 1;
			
						it.ItemType = getUpgradeItemType(it.ItemClass, it.ItemType, upgradeCount);
					}

#if defined(__THAILAND_SERVER__) || defined(__CHINA_SERVER__)
					it.ItemType = getItemTypeByItemLimit( it.ItemClass, it.ItemType );
#endif

					pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
					Assert(pItem != NULL);
					if ( pItem->getItemClass() == Item::ITEM_CLASS_RESURRECT_ITEM ) countResurrectItem();

					if ( pItem->isUnique() ) pItem->setGrade(6);
					else if ( pItem->getItemClass() == Item::ITEM_CLASS_CUE_OF_ADAM )
						pItem->setGrade( ItemGradeManager::Instance().getRandomCueOfAdamGrade() );
					else
						pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
	//				cout << "���� ������ ��� : " << pItem->getGrade() << endl;

					pItem->setDurability( computeMaxDurability(pItem) );

					if (!isHarvestFestivalItemAppeared ||
							(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
						pMonsterCorpse->addTreasure(pItem);

					// ����̺�Ʈ: �ذ� 8�� �� �߰�
					if ( isLottoZone 
						&& pItem->getItemClass() == Item::ITEM_CLASS_SKULL )
					{
						int lottoSkullRatio = g_pVariableManager->getVariable( LOTTO_SKULL_RATIO );
						if ( lottoSkullRatio > 0 )
						{
							int value = rand() % 10000;
							if ( value < lottoSkullRatio )
							{
								// �ذ� 8�� �� ����� �ִ´�.
								for ( int i = 0; i < 8; i++ )
								{
									pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
									pMonsterCorpse->addTreasure( pItem );
									if ( pItem->getItemClass() == Item::ITEM_CLASS_RESURRECT_ITEM ) countResurrectItem();
								}
							}
						}
					}
				}
			}
			else
			{
				//cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
				if (pTreasure->getRandomItem(&it, g_pVariableManager->getItemProbRatio() + itemBonusPercent, bPremiumPlayer ))
				{
					// by sigi. 2002.10.21
					//upgradeItemTypeByLuck(luckLevel, it);
#if defined(__THAILAND_SERVER__) || defined(__CHINA_SERVER__)

					it.ItemType = getItemTypeByItemLimit( it.ItemClass, it.ItemType );
#endif
					pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
					Assert(pItem != NULL);
					if ( pItem->getItemClass() == Item::ITEM_CLASS_RESURRECT_ITEM ) countResurrectItem();

					if ( pItem->isUnique() ) pItem->setGrade(6);
					else if ( pItem->getItemClass() == Item::ITEM_CLASS_CUE_OF_ADAM )
						pItem->setGrade( ItemGradeManager::Instance().getRandomCueOfAdamGrade() );
					else
						pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
	//				pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
	//				cout << "���� ������ ��� : " << pItem->getGrade() << endl;

					pItem->setDurability( computeMaxDurability(pItem) );
		
					if (!isHarvestFestivalItemAppeared ||
							(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
						pMonsterCorpse->addTreasure(pItem);

				}
			}


			/////////////////////////////////////////////////////////////////////////
			// ������(�ذ񻩰�) ������ ��� Ȯ���� �����ٸ� �������� � �� �ִ´�. ��������.
			// ġ�� ���Ϳ� �߰� �������� �����Ǿ� �ִٸ� �� ��ġ��ŭ �������� �� �ִ´�.
			int nBonusItem = 0;

			if ( pItem != NULL
				&& pItem->getItemClass() != Item::ITEM_CLASS_SKULL
				)	
			{
				if ( bChiefMonsterBonus )
					nBonusItem = g_pVariableManager->getVariable( CHIEF_ITEM_BONUS_NUM );

				if ( isLottoZone && isLottoWinning() )
					nBonusItem = g_pVariableManager->getVariable( LOTTO_ITEM_BONUS_NUM );

				if ( pDeadMonster->getMonsterType() == 765 )
					nBonusItem = 8;

				if ( pDeadMonster->getMonsterType() == 814 )
				{
					// ����𸮴��� 6��
					nBonusItem = 5;
				}

				if ( pDeadMonster->getMonsterType() == 815 )
				{
					// ���۸������� 4��
					nBonusItem = 3;
				}

				if ( pDeadMonster->getMonsterType() == 816 || pDeadMonster->getMonsterType() == 817 )
				{
					// ���۴�Ʈ������ ����Ʈ������� 3��
					nBonusItem = 2;
				}
			}

			if ( nBonusItem > 0 )
			{
				int i = 0;
				int j = 0;
				static int MaxTry = 30;
				while ( i < nBonusItem && j < MaxTry )
				{
					Treasure* pTreasure = (*itr);
					ITEM_TEMPLATE it;

					it.ItemClass  = Item::ITEM_CLASS_MAX;
					it.ItemType   = 0;
					//it.OptionType = 0;

					int itemRatioBonus = 0;

					if (bChiefMonsterBonus || pDeadMonster->getMonsterType() == 765)
					{
						it.NextOptionRatio = g_pVariableManager->getChiefMonsterRareItemPercent();
						itemRatioBonus     = g_pVariableManager->getPremiumItemProbePercent();
					}
					else
					{
						it.NextOptionRatio = 0;
					}

					Item* pItem = NULL;

					// ����ȭ �������� ������ Ȯ���� �� ���.
					Zone* pZone = pDeadMonster->getZone();
//1223 wlzzi - �����̾� �� ���� //����ȭ -- isPremiumZone���� �˻����� �ʰ�, GamePlayer::isAuthGameFeature �Լ���.. �����̾� �� ���� �ο� ���θ� �Ǵ��Ѵ�.
//							-- �� �Ǵ��� .. ������.. �ϵ��� �Ѵ�.
//					if ( pZone->isPayPlay() 
//						|| pZone->isPremiumZone())
					if (bPremiumZoneBenefit)
					{
						//cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
						if (pTreasure->getRandomItem(&it, itemRatioBonus + g_pVariableManager->getPremiumItemProbePercent() + itemBonusPercent, bPremiumPlayer ) )
						{
							// by sigi. 2002.10.21
							int upgradeLevel = upgradeItemTypeByLuck(luckLevel, ownerCreatureClass, it);

							if ( upgradeLevel != 0 )
							{
								GCAddEffectToTile gcAE;

								if ( upgradeLevel > 0 ) gcAE.setEffectID( Effect::EFFECT_CLASS_LUCKY );
								else gcAE.setEffectID( Effect::EFFECT_CLASS_MISFORTUNE );

								gcAE.setObjectID( 0 );
								gcAE.setDuration( 0 );
								gcAE.setXY( pDeadMonster->getX(), pDeadMonster->getY() );

								PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pItemOwnerCreature);
								if ( pPC != NULL )
								{
									if ( canGiveEventItem( pPC, pDeadMonster ) && !GDRLairManager::Instance().isGDRLairZone(pPC->getZoneID()) )
									{
										if ( upgradeLevel > 0 )
											addOlympicStat( pPC, 5 );
										else
											addOlympicStat( pPC, 6 );
									}
								}

	//							cout << "��ε�ĳ���� : " << pDeadMonster->getX() << ", " << pDeadMonster->getY() << endl;
								
								pZone->broadcastPacket( pDeadMonster->getX(), pDeadMonster->getY(), &gcAE );
							}

							// ġ�� ���ʹ� ������ 1�ܰ� +
							// by sigi. 2002.10.23
							if (bChiefMonsterBonus
								// �ϴ� rare Ȯ���� ���� ���µ�..
								// ���߿� �̰͵� �ٸ� variable�� �и��ؾߵ� ���̴�.	 by sigi. 2002.10.23
								&& rand()%100 < g_pVariableManager->getChiefMonsterRareItemPercent()
								&& isPossibleUpgradeItemType(it.ItemClass))
							{
								// ItemType 1�ܰ� upgrade
								int upgradeCount = 1;
					
								it.ItemType = getUpgradeItemType(it.ItemClass, it.ItemType, upgradeCount);
							}

							if ( !it.OptionType.empty() )
							{
								upgradeOptionByLuck( luckLevel, ownerCreatureClass, it );
							}

#if defined(__THAILAND_SERVER__) || defined(__CHAINA_SERVER__)
							it.ItemType	= getItemTypeByItemLimit( it.ItemClass , it.ItemType );
#endif

							pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
							Assert(pItem != NULL);
							if ( pItem->getItemClass() == Item::ITEM_CLASS_RESURRECT_ITEM ) countResurrectItem();
							
							if ( pItem->isUnique() ) pItem->setGrade(6);
							else if ( pItem->getItemClass() == Item::ITEM_CLASS_CUE_OF_ADAM )
								pItem->setGrade( ItemGradeManager::Instance().getRandomCueOfAdamGrade() );
							else
								pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
							//pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
							//cout << "���� ������ ��� : " << pItem->getGrade() << endl;

							pItem->setDurability( computeMaxDurability(pItem) );
				
							if (!isHarvestFestivalItemAppeared ||
									(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
								pMonsterCorpse->addTreasure(pItem);
						}
					}
					else
					{
						//cout << "����Ȯ��!!!! : " << g_pVariableManager->getPremiumItemProbePercent() << endl;
						if (pTreasure->getRandomItem(&it, g_pVariableManager->getItemProbRatio() + itemBonusPercent, bPremiumPlayer ))
						{
							// by sigi. 2002.10.21
							//upgradeItemTypeByLuck(luckLevel, it);
#if defined(__CHAINA_SERVER__) || defined(__THAILAND_SERVER__)
							it.ItemType = getItemTypeByItemLimit ( it.ItemClass, it.ItemType );
#endif
							pItem = g_pItemFactoryManager->createItem(it.ItemClass, it.ItemType, it.OptionType);
							Assert(pItem != NULL);
							if ( pItem->getItemClass() == Item::ITEM_CLASS_RESURRECT_ITEM ) countResurrectItem();

							if ( pItem->isUnique() ) pItem->setGrade(6);
							else if ( pItem->getItemClass() == Item::ITEM_CLASS_CUE_OF_ADAM )
								pItem->setGrade( ItemGradeManager::Instance().getRandomCueOfAdamGrade() );
							else
								pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
							//pItem->setGrade( ItemGradeManager::Instance().getRandomGrade() );
	//						cout << "���� ������ ��� : " << pItem->getGrade() << endl;

							pItem->setDurability( computeMaxDurability(pItem) );
				
							if (!isHarvestFestivalItemAppeared ||
									(isHarvestFestivalItemAppeared && pItem->getItemClass() == Item::ITEM_CLASS_SKULL))
								pMonsterCorpse->addTreasure(pItem);
						}
					}

					if ( pItem != NULL )
						i++;

					j++;
				}
			}
			/////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////
		}
	}

	// �ذ� �־���� �Ǵ� ��Ÿ
	if ( pMonsterInfo->getSkullType() != 0 )
	{
		Item* pSkull = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_SKULL, pMonsterInfo->getSkullType(), list<OptionType_t>() );
		if ( pSkull != NULL )
		{
			pMonsterCorpse->addTreasure( pSkull );
		}
	}
	
	if (g_pVariableManager->isMonsterDropItem())
	{
		unsigned int iYellowDropRatio = rand()%100;
		
		if(iYellowDropRatio < 1)
		{
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_STAR, 69, optionType );
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	
	if (g_pVariableManager->isMonsterDropItemSkillBook())
	{
		unsigned int iSkillBook1Ratio = rand()%100;
		
		if(iSkillBook1Ratio < 1)
		{
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_SKILL_BOOK, 37, optionType );
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	
	if (g_pVariableManager->isMonsterDropItemSkillBook())
	{
		unsigned int iSkillBook2Ratio = rand()%500;
		
		if(iSkillBook2Ratio < 1)
		{
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_SKILL_BOOK, 38, optionType );
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	
	if (g_pVariableManager->isMonsterDropItemSkillBook())
	{
		unsigned int iSkillBook3Ratio = rand()%500;
		
		if(iSkillBook3Ratio < 1)
		{
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_SKILL_BOOK, 39, optionType );
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	
	if (g_pVariableManager->isMonsterDropItemSkillBook())
	{
		unsigned int iSkillBook4Ratio = rand()%500;
		
		if(iSkillBook4Ratio < 1)
		{
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_SKILL_BOOK, 40, optionType );
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	
	// Forbidden Blood (CommonQuestItem 56), the Dracula Castle entry item: 1 in 500 from level 150+ monsters
	if ( pMonsterInfo->getLevel() >= 150 && rand()%500 < 1 )
	{
		list<OptionType_t> optionType;
		Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_COMMON_QUEST_ITEM, 56, optionType );
		if ( pItem != NULL ) pMonsterCorpse->addTreasure( pItem );
	}
	
	if (g_pVariableManager->isMonsterDropItemEventStar())
	{
		unsigned int iBlueDropRatio = rand()%500;
		
		if(iBlueDropRatio < 1)
		{
			list<OptionType_t> optionType;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_EVENT_STAR, 78, optionType );
			pMonsterCorpse->addTreasure( pItem );
		}
	}
	
	//////////////////////////////////////////////////////////////////////
	// 2002�� 6�� ������ �̺�Ʈ
	//  �̺�Ʈ ���ͷ� ������ �� ���Ϳ��Լ��� �౸�� �������� ���´�.
	//  �౸���� ������ ITEM_TYPE�� ������ �ʰ�
	//  EVENT_STAR�� Type7������ �۵��Ѵ�.
	//  ���� EventStarInfo, EventStarObject�� EventItemInfo, EventItemObject
	//  �� ����Ǿ�� �� ���̴�.
	/////////////////////////////////////////////////////////////////////
	/*
	if(pDeadMonster->getEventMonsterFlag() == true)
	{
		ITEM_TEMPLATE ball_template;
		ball_template.ItemClass = Item::ITEM_CLASS_EVENT_STAR;
		ball_template.ItemType = 6;
		ball_template.OptionType=0;

		//if(g_pVariable->getDebugMode() == "COUT")
			//cout << "�౸�� ������ ����" << endl;

		Item *pItem = g_pItemFactoryManager->createItem(ball_template.ItemClass, ball_template.ItemType, ball_template.OptionType);
		Assert(pItem != NULL);
		pMonsterCorpse->addTreasure(pItem);
	}
	*/
	

	//////////////////////////////////////////////////////////////////////
	//   2002�� 5�� ������ �� �̺�Ʈ/
	//   ��� ���Ϳ��Լ� ���� ���� �� �����Ƿ�, ���⿡ �ϵ��ڵ��Ͽ���.
	//   1/1500 �� Ȯ���� �� �������� �߰��� �����Ѵ�.(�ɸ��� ���� �����)
	//////////////////////////////////////////////////////////////////////
	//cout << "Monster Manager: star -> " << g_pVariable->getStar() << endl;
	//int star_percentage = g_pVariable->getStar();
    /*
	if(rand()%500 == 0) {
		ITEM_TEMPLATE star_template;
		star_template.ItemClass = Item::ITEM_CLASS_EVENT_STAR;

		// ���� 1/10�� Ȯ���� ���캻 ����, �ɸ��� 1/6�� Ȯ���� �� ���� ������ �Ѵ�.
		// 9/10�� Ȯ���δ� �������� ������ ���� ������ �Ѵ�.
		if(rand() % 1500 == 0)
			star_template.ItemType = rand() % 6;
		else
			star_template.ItemType = (rand() % 5) + 1;
		star_template.OptionType = 0;

		cout << "�̺�Ʈ ������ ����" << star_template.ItemType << endl;
		Item* pItem = g_pItemFactoryManager->createItem(star_template.ItemClass,star_template.ItemType, star_template.OptionType);
		Assert(pItem != NULL);
		pMonsterCorpse->addTreasure(pItem);
	}
	*/
	__END_CATCH
}

int MonsterManager::upgradeItemTypeByLuck(int luckLevel, Creature::CreatureClass ownerCreatureClass, ITEM_TEMPLATE& it)
	throw (Error)
{
	__BEGIN_TRY

	if (luckLevel==0
		|| !isPossibleUpgradeItemType(it.ItemClass))
		return 0;

	luckLevel = luckLevel + (rand()%20) - 10;
	luckLevel = min(MAX_LUCK_LEVEL, luckLevel);
//	cout << "Apply luck : " << luckLevel << endl;

	int ratio;

	switch ( ownerCreatureClass )
	{
		case Creature::CREATURE_CLASS_SLAYER:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (4.254 + (1.0 + it.ItemType)/5.0) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (2.5 - (1.0 + it.ItemType)/20.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_VAMPIRE:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (6.03 + (1.0 + it.ItemType)/5.0) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (4.14 - (1.0 + it.ItemType)/20.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_OUSTERS:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (4.936 + (1.0 + it.ItemType)/5.0) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (3.05 - (1.0 + it.ItemType)/20.0) ) * 100);
				}
			}
			break;
		default:
			return 0;
	}

	int value = rand()%10000;
//	int value = 0;//rand()%10000;

//	cout << "ratio : " << ratio << endl;
//	cout << "value : " << value << endl;

/*	const LuckInfo& luckInfo = g_pLuckInfoManager->getLuckInfo(luckLevel);

	int upgradeCount = luckInfo.getUpgradeItemTypeCount();

	if (upgradeCount==0)
		return;*/

//	cout << "before : " << it.ItemClass << "/" << (int)it.ItemType << endl;
	if ( ratio > 0 && value < ratio )
	{
		it.ItemType = getUpgradeItemType(it.ItemClass, it.ItemType, 1);
//		cout << "after : " << it.ItemClass << "/" << (int)it.ItemType << endl;
		return 1;
	}
	else if ( ratio < 0 && value < (-ratio) )
	{
		it.ItemType = getDowngradeItemType(it.ItemClass, it.ItemType);
//		cout << "after : " << it.ItemClass << "/" << (int)it.ItemType << endl;
		return -1;
	}

	return 0;

	__END_CATCH
}

int MonsterManager::upgradeOptionByLuck(int luckLevel, Creature::CreatureClass ownerCreatureClass, ITEM_TEMPLATE& it) throw (Error)
{
	__BEGIN_TRY

	if ( it.OptionType.empty() ) return 0;

	OptionType_t optionType = it.OptionType.front();
	OptionInfo* pOptionInfo = g_pOptionInfoManager->getOptionInfo( optionType );
	if ( pOptionInfo == NULL ) return 0;

	luckLevel = luckLevel + (rand()%20) - 10;
	luckLevel = min(MAX_LUCK_LEVEL, luckLevel);
//	cout << "Apply luck to option : " << luckLevel << endl;

	int grade = pOptionInfo->getGrade() + 1;
//	cout << "Option Grade : " << grade << endl;

	int ratio;

	switch ( ownerCreatureClass )
	{
		case Creature::CREATURE_CLASS_SLAYER:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (grade*25.0 - 15.2) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (7.5 - grade/2.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_VAMPIRE:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (grade*25.0 - 11.3) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (10.3 - grade/2.0) ) * 100);
				}
			}
			break;
		case Creature::CREATURE_CLASS_OUSTERS:
			{
				if ( luckLevel >= 0 )
				{
					ratio = (int)(( (float)luckLevel / (grade/25.0 - 13.7) ) * 100);
				}
				else
				{
					ratio = (int)(( (float)luckLevel / (7.9 - grade/2.0) ) * 100);
				}
			}
			break;
		default:
			return 0;
	}

	int value = rand()%10000;
//	int value = 0;//rand()%10000;

//	cout << "ratio : " << ratio << endl;
//	cout << "value : " << value << endl;

//	cout << "before : " << pOptionInfo->getHName() << endl;

	if ( ratio > 0 && value < ratio && pOptionInfo->getUpgradeType() != optionType && pOptionInfo->isUpgradePossible() )
	{
		(*it.OptionType.begin()) = pOptionInfo->getUpgradeType();
//		cout << "after : " << g_pOptionInfoManager->getOptionInfo( it.OptionType.front() )->getHName() << endl;
		return 1;
	}
	else if ( ratio < 0 && value < (-ratio) && pOptionInfo->getPreviousType() != optionType )
	{
		if ( pOptionInfo->getPreviousType() != 0 )
			(*it.OptionType.begin()) = pOptionInfo->getPreviousType();
		else
			it.OptionType.pop_front();
//		if ( it.OptionType.front() == 0 ) it.OptionType.pop_front();
//		cout << "after : " << g_pOptionInfoManager->getOptionInfo( it.OptionType.front() )->getHName() << endl;
		return -1;
	}

	return 0;

	__END_CATCH
}

void MonsterManager::setAppearEventMonster( MonsterType_t monsterType )
	throw (Error )
{
	__BEGIN_TRY

	vector<EventMonsterInfo>::iterator itr = m_pEventMonsterInfo->begin();
	vector<EventMonsterInfo>::iterator endItr = m_pEventMonsterInfo->end();

	for ( ; itr != endItr; ++itr )
	{
		if ( (*itr).monsterType == monsterType )
		{
			(*itr).bCanAppear = true;
		}
	}

	__END_CATCH
}

bool MonsterManager::isAllEventMonsterNotExist()
	throw (Error)
{
	__BEGIN_TRY

	vector<EventMonsterInfo>::iterator itr = m_pEventMonsterInfo->begin();
	vector<EventMonsterInfo>::iterator endItr = m_pEventMonsterInfo->end();

	for ( ; itr != endItr; ++itr )
	{
		if ( ( (*itr).monsterType == 815 || (*itr).monsterType == 816 || (*itr).monsterType == 817 )
			&& (*itr).bExist
			)
		{
			return false;
		}
	}

	return true;

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��� ũ��ó�� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::deleteAllMonsters (bool bDeleteFromZone)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	hash_map< ObjectID_t , Creature* >::iterator current = m_Creatures.begin();

	while (current != m_Creatures.end()) 
	{
		Creature* pCreature = current->second;

		Assert(pCreature != NULL);

		if (bDeleteFromZone)
		{
			try {
				Zone* pZone = pCreature->getZone();
				Assert(m_pZone == pZone);

				//Monster* pMonster = dynamic_cast<Monster*>(pCreature);

				ZoneCoord_t cx = pCreature->getX();
				ZoneCoord_t cy = pCreature->getY();

				// Ÿ�Ͽ��� ����
				Tile & tile = m_pZone->getTile(cx , cy);
				tile.deleteCreature(pCreature->getObjectID());

				// �ֺ��� PC�鿡�� ũ��ó�� ������ٴ� ����� ��ε�ĳ��Ʈ�Ѵ�.
				GCDeleteObject gcDeleteObject(pCreature->getObjectID());
				pZone->broadcastPacket(cx, cy, &gcDeleteObject, pCreature);

			} catch (Throwable& t) {
				filelog("MonsterManagerBug.txt", "deleteAllCreatures: %s", t.toString().c_str());
			}
		}

		// ũ���ĸ� �����Ѵ�.
		SAFE_DELETE(pCreature);

		current ++;
	}

	// �� �����Ѵ�.
	m_Creatures.clear();
	m_Monsters.clear();



	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// ��� ũ��ó�� ���δ�.
////////////////////////////////////////////////////////////////////////////////
void MonsterManager::killAllMonsters (const hash_map<ObjectID_t, ObjectID_t>& exceptCreatures)
	throw (Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	hash_map< ObjectID_t , Creature* >::iterator current = m_Creatures.begin();

	while (current != m_Creatures.end()) 
	{
		Creature* pCreature = current->second;

		Assert(pCreature != NULL);

		if (pCreature->isAlive())
		{
			if (pCreature->isMonster())
			{
				hash_map<ObjectID_t, ObjectID_t>::const_iterator itr = exceptCreatures.find( pCreature->getObjectID() );

				if (itr==exceptCreatures.end())
				{
					Monster* pMonster = dynamic_cast<Monster*>(pCreature);
					pMonster->setHP(0, ATTR_CURRENT);
				}
			}
			else Assert(false);
		}
	}

	__END_DEBUG
	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// get debug string
////////////////////////////////////////////////////////////////////////////////
string MonsterManager::toString () const
       throw ()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "MonsterManager(" << CreatureManager::toString();

	hash_map< SpriteType_t , MonsterCounter* >::const_iterator itr = m_Monsters.begin();
	for (; itr != m_Monsters.end() ; itr ++) msg << itr->second->toString();

	msg << ")" ;
	return msg.toString();

	__END_CATCH
}



//////////////////////////////////////////////////////////////////////////////
// Ȳ�� �ذ� �ݱ� �̺�Ʈ�� ������ �ڵ��� �Ϻκ��̴�.
// �ϴ��� ���� �Ⱦ �����µ�, ���߿��� Ȥ�� �ٽ� �������� �ؼ�
// ���� �� ������ �Űܳ��´�.
//////////////////////////////////////////////////////////////////////////////

/*
////////////////////////////////////////////////////////////
// �̺�Ʈ ���� �ڵ� ����
////////////////////////////////////////////////////////////
SpriteType_t SpriteType = pMonsterInfo->getSpriteType();
uint         event_ratio = rand()%100;
uint         skull_ratio = rand()%100;

switch (SpriteType)
{
	case 5: // ����ٵ�
		if (event_ratio < 3) ItemType = 12;
		break;
	case 8: // �ʹ׵���
		if (event_ratio < 3) ItemType = 12;
		break;
	case 7: // �ʹ׼ҿ�
		if (event_ratio < 3)
		{
			if (skull_ratio < 98) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 6: // Ű��
		if (event_ratio < 3)
		{
			if (skull_ratio < 97) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 4: // ����
		if (event_ratio < 3)
		{
			if (skull_ratio < 96) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 9: // ĸƾ
		if (event_ratio < 3)
		{
			if (skull_ratio < 94) ItemType = 12;
			else ItemType = 15;
		}
		break;
	case 42: // ��ĭ
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 43: // �������
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 60: // ����Ʈ
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 64: // �𵥶�
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 41: // ��Ƽ��Ʈ���̴�
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 62: // ����Ʈ���̴�
		if (event_ratio < 4)
		{
			if (skull_ratio < 93) ItemType = 12;
			else if (93 <= skull_ratio && skull_ratio < 99) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 61: // ��������
		if (event_ratio < 4)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 48: // ȣ��
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 < skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 27: // ���������
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 40: // �񷹸�
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 57: // ��������
		if (event_ratio < 5)
		{
			if (skull_ratio < 91) ItemType = 12;
			else if (91 <= skull_ratio && skull_ratio < 98) ItemType = 15;
			else ItemType = 14;
		}
		break;
	case 47: // ī���������
		if (event_ratio < 6)
		{
			if (skull_ratio < 89) ItemType = 12;
			else if (89 <= skull_ratio && skull_ratio < 97) ItemType = 15;
			else ItemType = 14;
		}
		break;
	default:
		break;
}
////////////////////////////////////////////////////////////
// �̺�Ʈ ���� �ڵ� ��
////////////////////////////////////////////////////////////
*/

bool isLottoWinning()
{
	int lottoItemRatio = g_pVariableManager->getVariable( LOTTO_ITEM_RATIO );
	if ( lottoItemRatio > 0 )
	{
		int value = rand() % 10000;
		if ( value < lottoItemRatio )
		{
			return true;
		}
	}

	return false;
}
