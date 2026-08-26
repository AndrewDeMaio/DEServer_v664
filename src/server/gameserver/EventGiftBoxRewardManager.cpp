////////////////////////////////////////////////////////////////////////////////
// Filename    : EventGiftBoxRewardManager.cpp
// Written By  : 
// Description :
////////////////////////////////////////////////////////////////////////////////
#include "EventGiftBoxRewardManager.h"
#include "Item.h"
#include "GamePlayer.h"
#include "Slayer.h"
#include "Vampire.h"
#include "NPC.h"
#include "Player.h"
#include "Inventory.h"
#include "ItemFactoryManager.h"
#include "ItemUtil.h"
#include "ItemInfoManager.h"
#include "OptionInfo.h"
#include "Zone.h"
#include "VariableManager.h"
#include "FlagSet.h"
#include "DB.h"
#include "Gpackets/GCNPCResponse.h"
#include "Gpackets/GCNPCAsk.h"
#include "Gpackets/GCUseOK.h"
#include "item/SlayerPortalItem.h"
#include "item/VampirePortalItem.h"
#include "item/OustersSummonItem.h"

#include <list>

////////////////////////////////////////////////////////////////////////////////
// EventGiftBoxRewardManager
////////////////////////////////////////////////////////////////////////////////
void EventGiftBoxRewardManager::Load()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;
	Result*    pResult = NULL;

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		pResult = pStmt->executeQuery(
			"SELECT `Groups`, Orders, ItemClass, ItemType, OptionType, LimitTime, Ratio, Race"
			" FROM EventGiftBoxRewardItemInfo"
			" ORDER BY Race, `Groups`, Orders"
		);			
		
		EVENT_ITEM_TEMPLATE EventItemTemplate;

		int i = 0;
		int iGroup;
		int order;
		Item::ItemClass itemClass;
		int itemType;
		string option;
		int LimitTime;
		int ratio;
		int Race;
		
		while(pResult->next())
		{
			i = 0;
			
			iGroup = pResult->getInt(++i);
			order = pResult->getInt(++i);
			itemClass = (Item::ItemClass)pResult->getInt(++i);
			itemType = pResult->getInt(++i);
			option = pResult->getString(++i);
			LimitTime = pResult->getInt(++i);
			ratio = pResult->getInt(++i);
			Race =  pResult->getInt(++i);

			EventItemTemplate.ItemClass = itemClass;
			EventItemTemplate.ItemType = itemType;
			EventItemTemplate.ItemOption = option;
			EventItemTemplate.LimitTime = LimitTime;
			EventItemTemplate.Ratio = ratio;
			
			switch(Race)
			{
					case RACE_SLAYER :
					{
						m_SlayerEventGiftBoxRewardItemInfo[iGroup].push_back(EventItemTemplate);
						m_SlayerTotalRatio[iGroup] += ratio;
						
						cout << "Slayer EventGiftBoxRewardItemInfo "
							<< "Group : " << iGroup 
							<< ", order : " << order 
							<< ", itemClass : " << itemClass 
							<< ", itemType : " << itemType 
							<< ", option : " << option 
							<< ", Ratio : " << ratio 
							<< endl;
					}
					break;
				
				case RACE_VAMPIRE :
					{
						m_VampireEventGiftBoxRewardItemInfo[iGroup].push_back(EventItemTemplate);
						m_VampireTotalRatio[iGroup] += ratio;
						
						cout << "Vampire EventGiftBoxRewardItemInfo "
							<< "Group : " << iGroup 
							<< ", order : " << order 
							<< ", itemClass : " << itemClass 
							<< ", itemType : " << itemType 
							<< ", option : " << option 
							<< ", Ratio : " << ratio 
							<< endl;
					}
					break;
				
				case RACE_OUSTERS :
					{
						m_OustersEventGiftBoxRewardItemInfo[iGroup].push_back(EventItemTemplate);
						m_OustersTotalRatio[iGroup] += ratio;
						
						cout << "Ousters EventGiftBoxRewardItemInfo "
							<< "Group : " << iGroup
							<< ", order : " << order
							<< ", itemClass : " << itemClass 
							<< ", itemType : " << itemType 
							<< ", option : " << option 
							<< ", Ratio : " << ratio 
							<< endl;
					}
					break;
				
				default :
					break;
			}
		}

		TRewardItemInfoList::iterator iter;
		
		iter = m_SlayerEventGiftBoxRewardItemInfo.begin();
		for( ; iter != m_SlayerEventGiftBoxRewardItemInfo.end() ; ++iter )
		{
			iGroup = iter->first;
			
			cout << "Group " << iGroup 
				<< " m_SlayerTotalRatio : " << m_SlayerTotalRatio[iGroup] 
				<< " m_SlayerEventGiftBoxRewardItemInfo[" << iGroup 
				<< "].size(): " << m_SlayerEventGiftBoxRewardItemInfo[iGroup].size() << endl;
		}
		
		iter = m_VampireEventGiftBoxRewardItemInfo.begin();
		for( ; iter != m_VampireEventGiftBoxRewardItemInfo.end() ; ++iter )
		{
			iGroup = iter->first;
			
			cout << "Group " << iGroup 
				<< " m_VampireTotalRatio : " << m_VampireTotalRatio[iGroup]
				<< " m_VampireEventGiftBoxRewardItemInfo[" << iGroup 
				<< "].size() : " << m_VampireEventGiftBoxRewardItemInfo[iGroup].size() << endl;
		}
		
		iter = m_OustersEventGiftBoxRewardItemInfo.begin();
		for( ; iter != m_OustersEventGiftBoxRewardItemInfo.end() ; ++iter )
		{
			iGroup = iter->first;

			cout << "Group " << iGroup 
				<< " m_OustersTotalRatio : " << m_OustersTotalRatio[iGroup]
				<< " m_OustersEventGiftBoxRewardItemInfo[" << iGroup 
				<< "].size() : " << m_OustersEventGiftBoxRewardItemInfo[iGroup].size() << endl;			
		}		

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt);

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
EventGiftBoxRewardManager::~EventGiftBoxRewardManager()
throw(Error)
{
}

////////////////////////////////////////////////////////////////////////////////
// 액션을 실행한다.
////////////////////////////////////////////////////////////////////////////////
Item* EventGiftBoxRewardManager::getEventGiftBoxReward(Creature * pCreature, int Group, int& limitTime) 
	throw (Error)
{
	__BEGIN_TRY
	
	Assert(pCreature != NULL);
	Assert(pCreature->isPC());

	PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
	Assert(pPC != NULL);

	Player* pPlayer = pPC->getPlayer();
	Assert(pPlayer != NULL);

	GamePlayer* pGamePlayer  = dynamic_cast<GamePlayer*>(pPlayer);
	Assert(pGamePlayer != NULL);

	Inventory* pInventory = pPC->getInventory();
	Assert( pInventory != NULL );

	Zone* pZone = pPC->getZone();
	Assert( pZone != NULL );
	
	TEventItemTemplateList *pRewardItemInfoList = NULL;
	int GroupTotalRatio;
	
	if(pPC->isSlayer())
	{
		pRewardItemInfoList = &m_SlayerEventGiftBoxRewardItemInfo[Group]; 
		GroupTotalRatio = m_SlayerTotalRatio[Group];
	}
	else if(pPC->isVampire())
	{
		pRewardItemInfoList = &m_VampireEventGiftBoxRewardItemInfo[Group];
		GroupTotalRatio = m_VampireTotalRatio[Group];
	}
	else if(pPC->isOusters())
	{
		pRewardItemInfoList = &m_OustersEventGiftBoxRewardItemInfo[Group];
		GroupTotalRatio = m_OustersTotalRatio[Group];
	}
	else
	{
		return NULL;
	}
	
	if ( pRewardItemInfoList == NULL || GroupTotalRatio == 0 )
	{
		return NULL;
	}
	
	int Sum = 0;
	int Ratio = 0;
	int array = 0;
	
	Ratio = rand() % GroupTotalRatio + 1;

	for( int i = 0; i < (*pRewardItemInfoList).size(); ++i )
	{
		Sum += (*pRewardItemInfoList)[i].Ratio;
		if( Sum >= Ratio )
		{
			array = i; 
			
			break;
		}
	}
	
	cout << "EventRewardItem array=" << array 
		<< " ItemClass=" << (*pRewardItemInfoList)[array].ItemClass
		<< " ItemType=" << (*pRewardItemInfoList)[array].ItemType
		<< endl;
	
	ItemInfo* pItemInfo = NULL;
	pItemInfo = g_pItemInfoManager->getItemInfo( 
		(*pRewardItemInfoList)[array].ItemClass,
		(*pRewardItemInfoList)[array].ItemType
	);
	Assert( pItemInfo != NULL );

	Item* pItem = NULL;
	list<OptionType_t> options;
	
	// 인벤토리에 넣을 수 있는지에 대한 검사는 호출한 부분에서 해야 한다.
	if((*pRewardItemInfoList)[array].ItemOption.size() > 0)
	{
		makeOptionList( (*pRewardItemInfoList)[array].ItemOption, options );
	}
	
	pItem = g_pItemFactoryManager->createItem( pItemInfo->getItemClass(), pItemInfo->getItemType(), options );
	Assert( pItem != NULL );
	
	limitTime = (*pRewardItemInfoList)[array].LimitTime;
	
	if ( pItem->getItemClass() == Item::ITEM_CLASS_SLAYER_PORTAL_ITEM ) 
	{
		SlayerPortalItem* pSlayerPortalItem = dynamic_cast<SlayerPortalItem*>(pItem);
		pSlayerPortalItem->setCharge( pSlayerPortalItem->getMaxCharge() );
	}
	else if ( pItem->getItemClass() == Item::ITEM_CLASS_VAMPIRE_PORTAL_ITEM )
	{
		VampirePortalItem* pVampirePortalItem = dynamic_cast<VampirePortalItem*>(pItem);
		pVampirePortalItem->setCharge( pVampirePortalItem->getMaxCharge() );
	}
	else if ( pItem->getItemClass() == Item::ITEM_CLASS_OUSTERS_SUMMON_ITEM )
	{
		OustersSummonItem* pOustersSummonItem = dynamic_cast<OustersSummonItem*>(pItem);
		pOustersSummonItem->setCharge( pOustersSummonItem->getMaxCharge() );
	}
	
	return pItem;
	
	__END_CATCH
}


// global variable declaration
EventGiftBoxRewardManager* g_pEventGiftBoxRewardManager = NULL;


