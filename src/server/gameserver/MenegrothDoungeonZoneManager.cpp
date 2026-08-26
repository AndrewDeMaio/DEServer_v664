#include "Types.h"

#ifdef __MENEGROTH_DOUNGEON_SYSTEM__

#include "Utility.h"
#include "Monster.h"
#include "Zone.h"
#include "MonsterManager.h"

#include "MenegrothDoungeonZoneManager.h"
#include "EffectMenegrothTrap1.h"
#include "EffectMenegrothTrap2.h"
#include "EffectSummonCabracam.h"
#include "StringPool.h"
#include "Player.h"
#include "PlayerCreature.h"
#include "ItemFactoryManager.h"
#include "Inventory.h"
#include "ItemUtil.h"
#include "PacketUtil.h"
#include "VariableManager.h"

#include "Gpackets/GCSystemMessage.h"
#include "Gpackets/GCAddEffect.h"
#include "Gpackets/GCAddEffectToTile.h"
#include "Gpackets/GCCreateItem.h"


MenegrothDoungeonZoneManager::MenegrothDoungeonZoneManager(Zone *pZone)
{
	m_pZone = pZone;

	m_bReadyToSummon = false;
	m_bSummonCabracam = false;
	m_CabracamObjectID = 0;

	ResetCabracamHeartToAltar();

	g_MenegrothDoungeonManager.getTrap1Pos(m_pZone, m_Trap1PosList);
	g_MenegrothDoungeonManager.getTrap2Pos(m_pZone, m_Trap2PosList);
	m_Trap2InstallTimeList.reserve(m_Trap2PosList.size());

	{
		TTrapPosList::iterator iter;
		iter = m_Trap1PosList.begin();
		for( ; iter != m_Trap1PosList.end() ; ++iter)
		{
			InstallTrap1((*iter).x, (*iter).y);
		}
	}

	{
		TTrapInstallTimeList::iterator iter;
		iter = m_Trap2InstallTimeList.begin();
		for(; iter != m_Trap2InstallTimeList.end(); ++iter)
		{
			getCurrentTime((*iter));
		}
	}

	getCurrentTime(m_PrevTrapCheckTime);

	g_MenegrothDoungeonManager.getBossMonster(m_pZone->getZoneID(), m_summonMonsterType, m_summonX, m_summonY);

	calcNextCabracamRegenTime();

}

void MenegrothDoungeonZoneManager::calcNextCabracamRegenTime()
{
	// 17시기준으로 3시간마다 보스몹 리젠

	getCurrentTime(m_nextCabracamRegenTime);

	int iRegenPeriod;

	// per 3 hours 
	iRegenPeriod = 60 * 60 * 3;
	// 0시 기준으로 3시간 마다 계산
	m_nextCabracamRegenTime.tv_sec = ((m_nextCabracamRegenTime.tv_sec / iRegenPeriod) + 1) * iRegenPeriod; 
	// 0시 기준으로 계산된 결과에 2시간을 더함 -> 17시(2시) 기준으로 3시간마다 됨
	m_nextCabracamRegenTime.tv_sec += (60*60*2); 

	/*
	// to test, per 10 minutes
	iRegenPeriod = 60 * 10;
	m_nextCabracamRegenTime.tv_sec = ((m_nextCabracamRegenTime.tv_sec / iRegenPeriod) + 1) * iRegenPeriod; 
	*/
}

bool MenegrothDoungeonZoneManager::IsAlreadySummonCabracam()
{
	bool bSummonCabracam = false;

	if ( m_CabracamObjectID == 0 )
	{
		return false;
	}

	// 이미 카브라캄 나와 있는지 체크
	Creature *pCreature = m_pZone->getCreature(m_CabracamObjectID);
	if ( pCreature != NULL && m_CabracamObjectID == pCreature->getObjectID() )
	{
		if ( pCreature->isDead() )
		{
			bSummonCabracam = false;
		}
		else
		{
			// 이미 카브라캄 나와 있다 
		    bSummonCabracam = true;
		}
    }

	return bSummonCabracam;

}

void MenegrothDoungeonZoneManager::giveRewardItemToAllPCInZone()
{
	cout << "giveRewardItemToAllPCInZone()" << endl;

	PCManager* pPM = (PCManager*)m_pZone->getPCManager();

	hash_map< ObjectID_t, Creature* > & pcs = pPM->getCreatures();
	hash_map< ObjectID_t, Creature* >::iterator itr = pcs.begin();

	for( ; itr != pcs.end() ; itr++)
	{
		Creature* pCreature = itr->second;
		PlayerCreature* pPlayerCreature = dynamic_cast<PlayerCreature*>(pCreature);
		Inventory* pInventory = pPlayerCreature->getInventory();

		cout << "MenegrothDoungeon, giveRewardItemToAllPCInZone() " 
			<< "ZoneID = " << m_pZone->getZoneID() 
			<< "PlayerName = " << pPlayerCreature->getName() 
			<< endl;

		if ( pInventory == NULL )
		{
			continue;
		}

		// 보상할 증표를 검색 
		Item::ItemClass ItemClass;
		ItemType_t ItemType;
		ItemNum_t ItemNum = 1;

		if ( !g_MenegrothDoungeonManager.getRewardMenegrothVoucher(pCreature, ItemClass, ItemType) )
		{
			continue;
		}
		
		if ( m_pZone->getZoneLevel( pPlayerCreature->getX(), pPlayerCreature->getY() ) & SAFE_ZONE )
		{
			ItemNum = 1;
		}
		else
		{
			ItemNum = g_pVariableManager->getMenegroVoucherCount();
		}

		list<OptionType_t> nullList;
		Item* pItem = g_pItemFactoryManager->createItem(ItemClass, ItemType, nullList);
		pItem->setNum(ItemNum);

		(m_pZone->getObjectRegistry()).registerObject(pItem);


		// 인벤토리의 빈 곳을 찾는다.
		_TPOINT p;
		if (pInventory->getEmptySlot(pItem, p))
		{
			// 인벤토리에 추가한다.
			pInventory->addItem(p.x, p.y, pItem);
			pItem->create(pCreature->getName(), STORAGE_INVENTORY, 0, p.x, p.y);

			// ItemTrace 에 Log 를 남긴다
			if ( pItem != NULL && pItem->isTraceItem() )
			{
				remainTraceLog( pItem, "MenegrothDoungeon", pCreature->getName(), ITEM_LOG_CREATE, DETAIL_EVENTNPC);
				remainTraceLogNew( pItem, pCreature->getName(), ITL_GET, ITLD_EVENTNPC, m_pZone->getZoneID() );
			}

			// 인벤토리에 아이템 생성 패킷을 보내준다.
			GCCreateItem gcCreateItem;
			makeGCCreateItem( &gcCreateItem, pItem, p.x, p.y );
			pCreature->getPlayer()->sendPacket(&gcCreateItem);
		}
	}
}

void MenegrothDoungeonZoneManager::SummonCabracam()
{
	Monster *pMonster;

	try
	{
		if ( IsAlreadySummonCabracam() )
		{
			// 카브라캄이 존재하고 있다.

			return;
		}


		pMonster = new Monster(m_summonMonsterType);
		Assert( pMonster != NULL );

		pMonster->setDir(DOWN);
		m_pZone->addCreature( pMonster, m_summonX, m_summonY, pMonster->getDir() );

		calcNextCabracamRegenTime();

		m_bSummonCabracam = true;
		m_bReadyToSummon = false;
		m_CabracamObjectID = pMonster->getObjectID();

	}
	catch ( EmptyTileNotExistException& )
	{
		SAFE_DELETE( pMonster );
	}

}

bool MenegrothDoungeonZoneManager::BeReadyToSummonCabracam()
{
	if ( IsAlreadySummonCabracam() )
	{
		// 카브라캄이 존재하고 있다.

		return false;

	}

	if ( m_bReadyToSummon )
	{
		return false;
	}

	cout << "CurrentTime = " << getCurrentTimeStringEx()
		<< " ZoneID=" << m_pZone->getZoneID() 
		<< " Cabracam MonsterType = " << m_summonMonsterType 
		<< " X = " << m_summonX 
		<< " Y = " << m_summonY << endl; 

	try
	{
		
		EffectSummonCabracam *pEffectSummonCabracam;
		pEffectSummonCabracam = new EffectSummonCabracam(m_pZone, m_summonX, m_summonY);
		pEffectSummonCabracam->setNextTime(5);

		Tile& tile = m_pZone->getTile(m_summonX, m_summonY);

		ObjectRegistry & objectregister = m_pZone->getObjectRegistry();
		objectregister.registerObject(pEffectSummonCabracam);

		m_pZone->addEffect(pEffectSummonCabracam);	
		tile.addEffect(pEffectSummonCabracam);

		/*
		GCAddEffectToTile gcAddEffectToTile;
		gcAddEffectToTile.setObjectID( pEffectSummonCabracam->getObjectID() );
		gcAddEffectToTile.setEffectID( Effect::EFFECT_CLASS_MENEGROTH_SUMMON_CABRACAM );
		gcAddEffectToTile.setXY(m_summonX, m_summonY);

		m_pZone->broadcastPacket(m_summonX, m_summonY, &gcAddEffectToTile);
		*/

		m_bReadyToSummon = true;

		SummonCabracam();

		GCSystemMessage gcSystemMessage;

		gcSystemMessage.setMessage( g_pStringPool->getString(STRID_SHOWUP_CABRACAM_MONSTER) );
		m_pZone->broadcastPacket(&gcSystemMessage);
	}
	catch ( Throwable& )
	{
	}

	return true;

}

void MenegrothDoungeonZoneManager::ResetCabracamHeartToAltar()
{
	list<ObjectID_t>::iterator iter;

	iter = m_AltarToInsertCabracamHeartList.begin();
	for( ; iter != m_AltarToInsertCabracamHeartList.end() ; ++iter)
	{
		ObjectID_t ObjectID = (*iter);

		Creature* pCreature = m_pZone->getCreature(ObjectID);
		if ( pCreature != NULL && pCreature->isNPC() )
		{
			if ( pCreature->isFlag(Effect::EFFECT_CLASS_MENEGROTH_CABRACAM_ALTAR) )
			{
				Effect* pEffect = pCreature->findEffect(Effect::EFFECT_CLASS_MENEGROTH_CABRACAM_ALTAR);
				if ( pEffect != NULL )
				{
					pEffect->unaffect();
				}
			}
		}
	}

	m_AltarToInsertCabracamHeartList.clear();
}

void MenegrothDoungeonZoneManager::AddCabracamHeartToAltar(ObjectID_t ObjectID)
{
	m_AltarToInsertCabracamHeartList.push_back(ObjectID);
}

int MenegrothDoungeonZoneManager::GetCabracamHeartCountToAltar()
{
	return m_AltarToInsertCabracamHeartList.size();
}

void MenegrothDoungeonZoneManager::InstallTrap1(ZoneCoord_t trapX, ZoneCoord_t trapY)
{
	// 영구적인 트랩
	//cout << "Install EffectMenegrothTrap1" << endl;

	int iMinDamage, iMaxDamage;

	g_MenegrothDoungeonManager.getTrap1Damage(m_pZone, iMinDamage, iMaxDamage);

	EffectMenegrothTrap1 *pEffectMenegrothTrap1;
	pEffectMenegrothTrap1 = new EffectMenegrothTrap1(m_pZone, trapX, trapY);
	pEffectMenegrothTrap1->setNextTime(0);
	pEffectMenegrothTrap1->setDeadline(99999999);
	pEffectMenegrothTrap1->setDamage(iMinDamage, iMaxDamage);

	m_pZone->registerObject(pEffectMenegrothTrap1);
	m_pZone->addEffect(pEffectMenegrothTrap1);
}

void MenegrothDoungeonZoneManager::InstallTrap2(ZoneCoord_t trapX, ZoneCoord_t trapY)
{
	// 일시적인 트랩
	//cout << "Install EffectMenegrothTrap2" << endl;

	int iMinDamage, iMaxDamage;

	g_MenegrothDoungeonManager.getTrap2Damage(m_pZone, iMinDamage, iMaxDamage);

	EffectMenegrothTrap2 *pEffectMenegrothTrap2;
	pEffectMenegrothTrap2 = new EffectMenegrothTrap2(m_pZone, trapX, trapY);
	pEffectMenegrothTrap2->setNextTime(0);
	pEffectMenegrothTrap2->setDeadline(20);		// 2 seconds
	pEffectMenegrothTrap2->setDamage(iMinDamage, iMaxDamage);

	m_pZone->registerObject(pEffectMenegrothTrap2);
	m_pZone->addEffect(pEffectMenegrothTrap2);

	/*
	GCAddEffectToTile gcAE;
	gcAE.setEffectID(pEffectMenegrothTrap2->getEffectClass());
	gcAE.setObjectID(pEffectMenegrothTrap2->getObjectID());
	gcAE.setXY(trapX, trapY);
	gcAE.setDuration(20);
	m_pZone->broadcastPacket(trapX, trapY, &gcAE);
	*/
}

void MenegrothDoungeonZoneManager::heartbeat()
{
	Timeval curTime;
	Timeval diffTime;

	getCurrentTime(curTime);

	diffTime = timediff(curTime, m_PrevTrapCheckTime);

	if ( diffTime.tv_sec >= 1 )
	{
		// 1초 마다 트랩 체크

		for(int iIndex = 0 ; iIndex < m_Trap2PosList.size() ; ++iIndex)
		{
			ZONE_COORD TrapPos;

			diffTime = timediff(curTime, m_Trap2InstallTimeList[iIndex]);

			if ( diffTime.tv_sec >= 4 + ( rand() % 4) )
			{
				TrapPos = m_Trap2PosList[iIndex];
				InstallTrap2(TrapPos.x, TrapPos.y);

				getCurrentTime(m_Trap2InstallTimeList[iIndex]);
			}

		}

		getCurrentTime(m_PrevTrapCheckTime);
	}

	if ( m_bSummonCabracam )
	{
		if ( !IsAlreadySummonCabracam() )
		{
			// 소환되어 있고, 현재 존재하지 않는다면 죽은 경우이다.
			// 현재 존의 모든 플레이어에게 증표를 지급한다.

			giveRewardItemToAllPCInZone();

			m_bSummonCabracam = false;
		}
	}

	if ( curTime >= m_nextCabracamRegenTime )
	{
		BeReadyToSummonCabracam();
	}
}

#endif /* __MENEGROTH_DOUNGEON_SYSTEM__ */
