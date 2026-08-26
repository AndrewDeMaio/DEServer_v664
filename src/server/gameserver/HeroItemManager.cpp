///////////////////////////////////////////////////////////////////////////
// File : HeroItemManager.cpp
///////////////////////////////////////////////////////////////////////////

// include files
#include "HeroItemManager.h"
#include "ItemFactoryManager.h"
#include "ZoneUtil.h"
#include "Zone.h"
#include "GlobalItemPositionLoader.h"
#include "EffectVampireHeroItem.h"
#include "EffectSlayerHeroItem.h"
#include "EffectOustersHeroItem.h"
#include "ShrineInfoManager.h"

#include <stdio.h>

const int nHeroItems = 12;

///////////////////////////////////////////////////////////////////////////
// class HeroItemManager
///////////////////////////////////////////////////////////////////////////
HeroItemManager::HeroItemManager()
{
	__BEGIN_TRY

	m_SlayerHeroItems.reserve( nHeroItems );
	m_VampireHeroItems.reserve( nHeroItems );
	m_OustersHeroItems.reserve( nHeroItems );
	m_SlayerDefaultPositions.reserve( nHeroItems );
	m_VampireDefaultPositions.reserve( nHeroItems );
	m_OustersDefaultPositions.reserve( nHeroItems );

	initDefaultPositions();

	__END_CATCH
}

HeroItemManager::~HeroItemManager()
{
	__BEGIN_TRY
	__END_CATCH
}

void HeroItemManager::init()
throw(Error)
{
	__BEGIN_TRY

		createAllHeroItems();

	__END_CATCH
}

void HeroItemManager::initDefaultPositions()
throw(Error)
{
	__BEGIN_TRY

		// 전쟁 시작시 HeroItem 의 시작 위치 설정.
	m_SlayerDefaultPositions[0].set(   73,  38, 122 );		
	m_SlayerDefaultPositions[1].set(   73,  38, 124 );		// 슬레이어 / 아담서 / 28 / 124
	m_SlayerDefaultPositions[2].set(   73,  38, 126 );		// 슬레이어 / 아담서 / 20 / 124
	m_SlayerDefaultPositions[3].set(   73,  38, 128 );		// 슬레이어 / 아담서 / 24 / 118
	m_SlayerDefaultPositions[4].set( 1201,  60,  68 );		// 슬레이어 / 옥타부스 / 60 / 68
	m_SlayerDefaultPositions[5].set( 1201,  64,  68 );		// 슬레이어 / 옥타부스 / 64 / 68
	m_SlayerDefaultPositions[6].set( 1201,  62,  65 );		// 슬레이어 / 옥타부스 / 62 / 65
	m_SlayerDefaultPositions[7].set( 1201,  62,  71 );		// 슬레이어 / 옥타부스 / 62 / 71
	m_SlayerDefaultPositions[8].set( 1203,  83,  50 );		// 슬레이어 / 셉티무스 / 83 / 50
	m_SlayerDefaultPositions[9].set( 1203,  85,  47 );		// 슬레이어 / 셉티무스 / 85 / 47
	m_SlayerDefaultPositions[10].set( 1203,  85,  53 );		// 슬레이어 / 셉티무스 / 85 / 53
	m_SlayerDefaultPositions[11].set( 1203,  87,  50 );		// 슬레이어 / 셉티무스 / 87 / 50

	m_VampireDefaultPositions[0].set(   71, 97, 126 );		// 뱀파이어 / 아담동 / 111 / 133
	m_VampireDefaultPositions[1].set(   71, 97, 128 );		// 뱀파이어 / 아담동 / 111 / 136
	m_VampireDefaultPositions[2].set(   71, 97, 130 );		// 뱀파이어 / 아담동 / 106 / 128
	m_VampireDefaultPositions[3].set(   71, 97, 132 );		// 뱀파이어 / 아담동 / 115 / 128
	m_VampireDefaultPositions[4].set( 1204,  60,  69 );		// 뱀파이어 / 쿠아르투스 / 60 / 69
	m_VampireDefaultPositions[5].set( 1204,  62,  66 );		// 뱀파이어 / 쿠아르투스 / 62 / 66
	m_VampireDefaultPositions[6].set( 1204,  62,  72 );		// 뱀파이어 / 쿠아르투스 / 62 / 72
	m_VampireDefaultPositions[7].set( 1204,  64,  69 );		// 뱀파이어 / 쿠아르투스 / 64 / 69
	m_VampireDefaultPositions[8].set( 1202,  83,  52 );		// 뱀파이어 / 테르티우스 / 83 / 52
	m_VampireDefaultPositions[9].set( 1202,  79,  52 );		// 뱀파이어 / 테르티우스 / 79 / 52
	m_VampireDefaultPositions[10].set( 1202,  81,  49 );		// 뱀파이어 / 테르티우스 / 81 / 49
	m_VampireDefaultPositions[11].set( 1202,  81,  55 );		// 뱀파이어 / 테르티우스 / 81 / 55

	m_OustersDefaultPositions[0].set(   72,  65, 162 );		// 아우스터즈 / 아담 / 66 / 176
	m_OustersDefaultPositions[1].set(   72,  66, 162 );		// 아우스터즈 / 아담 / 62 / 172
	m_OustersDefaultPositions[2].set(   72,  67, 162 );		// 아우스터즈 / 아담 / 66 / 179
	m_OustersDefaultPositions[3].set(   72,  68, 162 );		// 아우스터즈 / 아담 / 70 / 172
	m_OustersDefaultPositions[4].set( 1205,  60,  69 );		// 아우스터즈 / 펜타누스 / 60 / 69
	m_OustersDefaultPositions[5].set( 1205,  62,  66 );		// 아우스터즈 / 펜타누스 / 62 / 66
	m_OustersDefaultPositions[6].set( 1205,  62,  71 );		// 아우스터즈 / 펜타누스 / 62 / 71
	m_OustersDefaultPositions[7].set( 1205,  64,  69 );		// 아우스터즈 / 펜타누스 / 64 / 69
	m_OustersDefaultPositions[8].set( 1206,  82,  54 );		// 아우스터즈 / 헥시리우스 / 82 / 54
	m_OustersDefaultPositions[9].set( 1206,  82,  55 );		// 아우스터즈 / 헥시리우스 / 82 / 55
	m_OustersDefaultPositions[10].set( 1206,  80,  52 );		// 아우스터즈 / 헥시리우스 / 80 / 52
	m_OustersDefaultPositions[11].set( 1206,  84,  52 );		// 아우스터즈 / 헥시리우스 / 84 / 52

	__END_CATCH
}

void HeroItemManager::createAllHeroItems()
throw(Error)
{
	__BEGIN_TRY

		// 일단 Hero Item 을 생성한다.
		for ( int i=0; i<nHeroItems; ++i )
		{
			list<OptionType_t> optionNull;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_WAR_ITEM, 1, optionNull );
			Assert( pItem != NULL );

			WarItem* pWarItem = dynamic_cast<WarItem*>(pItem);
			Assert( pWarItem != NULL );

			Zone* pZone = getZoneByZoneID( m_SlayerDefaultPositions[i].id );
			Assert( pZone != NULL );

			char strZoneID[10];
			sprintf( strZoneID, "%u", pZone->getZoneID() );

			pZone->registerObject( pWarItem );
			pWarItem->create( strZoneID, STORAGE_ZONE, pZone->getZoneID(), m_SlayerDefaultPositions[i].x, m_SlayerDefaultPositions[i].y );

			pWarItem->setIndex( i );

			m_SlayerHeroItems[i] = pWarItem;
		}

		// 일단 Hero Item 을 생성한다.
		for ( int i=0; i<nHeroItems; ++i )
		{
			list<OptionType_t> optionNull;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_WAR_ITEM, 2, optionNull );
			Assert( pItem != NULL );

			WarItem* pWarItem = dynamic_cast<WarItem*>(pItem);
			Assert( pWarItem != NULL );

			Zone* pZone = getZoneByZoneID( m_VampireDefaultPositions[i].id );
			Assert( pZone != NULL );

			char strZoneID[10];
			sprintf( strZoneID, "%u", pZone->getZoneID() );

			pZone->registerObject( pWarItem );
			pWarItem->create( strZoneID, STORAGE_ZONE, pZone->getZoneID(), m_VampireDefaultPositions[i].x, m_VampireDefaultPositions[i].y );

			pWarItem->setIndex( i );

			m_VampireHeroItems[i] = pWarItem;
		}

		// 일단 Hero Item 을 생성한다.
		for ( int i=0; i<nHeroItems; ++i )
		{
			list<OptionType_t> optionNull;
			Item* pItem = g_pItemFactoryManager->createItem( Item::ITEM_CLASS_WAR_ITEM, 3, optionNull );
			Assert( pItem != NULL );

			WarItem* pWarItem = dynamic_cast<WarItem*>(pItem);
			Assert( pWarItem != NULL );

			Zone* pZone = getZoneByZoneID( m_OustersDefaultPositions[i].id );
			Assert( pZone != NULL );

			char strZoneID[10];
			sprintf( strZoneID, "%u", pZone->getZoneID() );

			pZone->registerObject( pWarItem );
			pWarItem->create( strZoneID, STORAGE_ZONE, pZone->getZoneID(), m_OustersDefaultPositions[i].x, m_OustersDefaultPositions[i].y );

			pWarItem->setIndex( i );

			m_OustersHeroItems[i] = pWarItem;
		}
		__END_CATCH
}

void HeroItemManager::addAllHeroItemsToZone()
throw(Error)
{
	__BEGIN_TRY

		// 아이템을 각자의 초기 위치에 놓는다.
		int nSlayerHeroItem = 12 - g_pShrineInfoManager->getBloodBibleCount(RACE_SLAYER);
	cout << "nSlayerHeroItem : " << nSlayerHeroItem << endl;
		for ( int i=0; i<nSlayerHeroItem; ++i )
		{
			Zone* pZone = getZoneByZoneID( m_SlayerDefaultPositions[i].id );
			Assert( pZone != NULL );

			Item* pItem = m_SlayerHeroItems[i];
			Assert( pItem != NULL );

			// 존에 아이템 추가하기
			pZone->addItemDelayed( pItem, m_SlayerDefaultPositions[i].x, m_SlayerDefaultPositions[i].y );
			cout << "SlayerHeroItem Count : " << i << endl;
		}

		int nVampireHeroItem = 12 - g_pShrineInfoManager->getBloodBibleCount(RACE_VAMPIRE);
		cout << "nVampireHeroItem : " << nVampireHeroItem << endl;
		// 아이템을 각자의 초기 위치에 놓는다.
		for ( int i=0; i<nVampireHeroItem; ++i )
		{
			Zone* pZone = getZoneByZoneID( m_VampireDefaultPositions[i].id );
			Assert( pZone != NULL );

			Item* pItem = m_VampireHeroItems[i];
			Assert( pItem != NULL );

			// 존에 아이템 추가하기
			pZone->addItemDelayed( pItem, m_VampireDefaultPositions[i].x, m_VampireDefaultPositions[i].y );
			cout << "VampireHeroItem Count : " << i << endl;
		}

		int nOustersHeroItem = 12 - g_pShrineInfoManager->getBloodBibleCount(RACE_OUSTERS);
		cout << "nOustersHeroItem : " << nOustersHeroItem << endl;
		// 아이템을 각자의 초기 위치에 놓는다.
		for ( int i=0; i<nOustersHeroItem; ++i )
		{
			Zone* pZone = getZoneByZoneID( m_OustersDefaultPositions[i].id );
			Assert( pZone != NULL );

			Item* pItem = m_OustersHeroItems[i];
			Assert( pItem != NULL );

			// 존에 아이템 추가하기
			pZone->addItemDelayed( pItem, m_OustersDefaultPositions[i].x, m_OustersDefaultPositions[i].y );
			cout << "OustersHeroItem Count : " << i << endl;
		}

		__END_CATCH
}

void HeroItemManager::removeAllHeroItems()
throw(Error)
{
	__BEGIN_TRY

		// 존재하는 모든 드래곤 아이이를 볼 수 없도록 없앤다.
		for ( int i=0; i<nHeroItems; ++i )
		{
			Item::ItemClass ItemClass	= Item::ITEM_CLASS_WAR_ITEM;
			ItemID_t		ItemID		= m_SlayerHeroItems[i]->getItemID();

			GlobalItemPosition* pItemPosition = GlobalItemPositionLoader::getInstance()->load( ItemClass, ItemID );

			if ( pItemPosition == NULL )
				return;

			// War 쓰레드에서 호출 되므로 락 걸어야 된다.
			pItemPosition->popItem( true );
		}

		// 존재하는 모든 드래곤 아이이를 볼 수 없도록 없앤다.
		for ( int i=0; i<nHeroItems; ++i )
		{
			Item::ItemClass ItemClass	= Item::ITEM_CLASS_WAR_ITEM;
			ItemID_t		ItemID		= m_VampireHeroItems[i]->getItemID();

			GlobalItemPosition* pItemPosition = GlobalItemPositionLoader::getInstance()->load( ItemClass, ItemID );

			if ( pItemPosition == NULL )
				return;

			// War 쓰레드에서 호출 되므로 락 걸어야 된다.
			pItemPosition->popItem( true );
		}

		// 존재하는 모든 드래곤 아이이를 볼 수 없도록 없앤다.
		for ( int i=0; i<nHeroItems; ++i )
		{
			Item::ItemClass ItemClass	= Item::ITEM_CLASS_WAR_ITEM;
			ItemID_t		ItemID		= m_OustersHeroItems[i]->getItemID();

			GlobalItemPosition* pItemPosition = GlobalItemPositionLoader::getInstance()->load( ItemClass, ItemID );

			if ( pItemPosition == NULL )
				return;

			// War 쓰레드에서 호출 되므로 락 걸어야 된다.
			pItemPosition->popItem( true );
		}


		__END_CATCH
}

void HeroItemManager::warpToDefaultPosition( Creature* pCreature )
throw(Error)
{
	__BEGIN_TRY

		// pCreature 는 드래곤 아이를 가지고 있는 크리쳐이다.
		// 드래곤 아이를 가지고 있던 사용자가 죽거나 나가거나 할때 불린다.
		// 드래곤 아이를 원래 위치로 이동시키는 코드다.
		// GlobalItemPositionLoader 를 사용해서 아이템을 원래 위치에서 제거한다.
		// 원래 존의 포인터를 가져와서 아이템을 넣는다.
		// 이 함수는 사용자가 어떤 행동을 할때 불리는 코드이므로 ZoneGroup 에서 호출되는 코드이다.
		// 그래서 존의 포인터로 작업을 할 때 ZoneGroup 을 비교해보고 작업을 한다.
	if(pCreature->isSlayer())
	{
		EffectSlayerHeroItem* pEffect = dynamic_cast<EffectSlayerHeroItem*>(pCreature->getEffectManager()->findEffect( Effect::EFFECT_CLASS_SLAYER_HERO_ITEM ));
		Assert( pEffect != NULL );

		Item::ItemClass ItemClass	= Item::ITEM_CLASS_WAR_ITEM;
		ItemID_t		ItemID		= pEffect->getItemID();

		GlobalItemPosition* pItemPosition = GlobalItemPositionLoader::getInstance()->load( ItemClass, ItemID );

		if ( pItemPosition == NULL )
			return;

		Item* pItem = pItemPosition->popItem( false );

		if ( pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_WAR_ITEM && pItem->getItemType() == 1)
		{
			WarItem* pWarItem = dynamic_cast<WarItem*>(pItem);
			Assert( pWarItem != NULL );

			int index = pWarItem->getIndex();

			Zone* pZone = pCreature->getZone();
			Assert( pZone != NULL );

			Zone* pTargetZone = getZoneByZoneID( m_SlayerDefaultPositions[index].id );
			Assert( pTargetZone != NULL );

			if ( pZone->getZoneGroup() == pTargetZone->getZoneGroup() )
				pTargetZone->addItem( pItem, m_SlayerDefaultPositions[index].x, m_SlayerDefaultPositions[index].y );
			else
				pTargetZone->addItemDelayed( pItem, m_SlayerDefaultPositions[index].x, m_SlayerDefaultPositions[index].y );
		}
	}
	else if(pCreature->isVampire())
	{
		EffectVampireHeroItem* pEffect = dynamic_cast<EffectVampireHeroItem*>(pCreature->getEffectManager()->findEffect( Effect::EFFECT_CLASS_VAMPIRE_HERO_ITEM ));

		Assert( pEffect != NULL );

		Item::ItemClass ItemClass	= Item::ITEM_CLASS_WAR_ITEM;
		ItemID_t		ItemID		= pEffect->getItemID();

		GlobalItemPosition* pItemPosition = GlobalItemPositionLoader::getInstance()->load( ItemClass, ItemID );

		if ( pItemPosition == NULL )
			return;

		Item* pItem = pItemPosition->popItem( false );

		if ( pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_WAR_ITEM && pItem->getItemType() == 2)
		{
			WarItem* pWarItem = dynamic_cast<WarItem*>(pItem);
			Assert( pWarItem != NULL );

			int index = pWarItem->getIndex();

			Zone* pZone = pCreature->getZone();
			Assert( pZone != NULL );

			Zone* pTargetZone = getZoneByZoneID( m_VampireDefaultPositions[index].id );
			Assert( pTargetZone != NULL );

			if ( pZone->getZoneGroup() == pTargetZone->getZoneGroup() )
				pTargetZone->addItem( pItem, m_VampireDefaultPositions[index].x, m_VampireDefaultPositions[index].y );
			else
				pTargetZone->addItemDelayed( pItem, m_VampireDefaultPositions[index].x, m_VampireDefaultPositions[index].y );
		}
	}
	else if(pCreature->isOusters())
	{
		EffectOustersHeroItem* pEffect = dynamic_cast<EffectOustersHeroItem*>(pCreature->getEffectManager()->findEffect( Effect::EFFECT_CLASS_OUSTERS_HERO_ITEM ));

		Assert( pEffect != NULL );

		Item::ItemClass ItemClass	= Item::ITEM_CLASS_WAR_ITEM;
		ItemID_t		ItemID		= pEffect->getItemID();

		GlobalItemPosition* pItemPosition = GlobalItemPositionLoader::getInstance()->load( ItemClass, ItemID );

		if ( pItemPosition == NULL )
			return;

		Item* pItem = pItemPosition->popItem( false );

		if ( pItem != NULL && pItem->getItemClass() == Item::ITEM_CLASS_WAR_ITEM && pItem->getItemType() == 3)
		{
			WarItem* pWarItem = dynamic_cast<WarItem*>(pItem);
			Assert( pWarItem != NULL );

			int index = pWarItem->getIndex();

			Zone* pZone = pCreature->getZone();
			Assert( pZone != NULL );

			Zone* pTargetZone = getZoneByZoneID( m_OustersDefaultPositions[index].id );
			Assert( pTargetZone != NULL );

			if ( pZone->getZoneGroup() == pTargetZone->getZoneGroup() )
				pTargetZone->addItem( pItem, m_OustersDefaultPositions[index].x, m_OustersDefaultPositions[index].y );
			else
				pTargetZone->addItemDelayed( pItem, m_OustersDefaultPositions[index].x, m_OustersDefaultPositions[index].y );
		}
	}

	__END_CATCH
}

HeroItemManager* g_pHeroItemManager = NULL;
