//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveItem.h
// Written By  : excel96
// Description : 
// Creature가 PC에게 질문을 던진다. 이 대사는 NPC 대화창에 출력된다.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GIVE_ITEM_H__
#define __ACTION_GIVE_ITEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"
#include "Item.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveItem
//////////////////////////////////////////////////////////////////////////////

class ActionGiveItem : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_GIVE_ITEM; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

public:
private:
	Item::ItemClass m_ItemClass;
	ItemType_t		m_ItemType;
	
	int 			m_RequiredContribute;
	bool			m_bRequiredContribute;
	
	Item::ItemClass m_RequiredItemClass;
	ItemType_t		m_RequiredItemType;
	int				m_RequiredItemCount;
	
	Item::ItemClass m_RequiredItem2Class;
	ItemType_t		m_RequiredItem2Type;
	int				m_RequiredItem2Count;
	
	Item::ItemClass m_RequiredItem3Class;
	ItemType_t		m_RequiredItem3Type;
	int				m_RequiredItem3Count;
	
	Item::ItemClass m_RequiredItem4Class;
	ItemType_t		m_RequiredItem4Type;
	int				m_RequiredItem4Count;
	
	Item::ItemClass m_RequiredItem5Class;
	ItemType_t		m_RequiredItem5Type;
	int				m_RequiredItem5Count;
	
	Item::ItemClass m_RequiredItem6Class;
	ItemType_t		m_RequiredItem6Type;
	int				m_RequiredItem6Count;
	
	Item::ItemClass m_RequiredItem7Class;
	ItemType_t		m_RequiredItem7Type;
	int				m_RequiredItem7Count;
	
	Item::ItemClass m_RequiredItem8Class;
	ItemType_t		m_RequiredItem8Type;
	int				m_RequiredItem8Count;
	
	Item::ItemClass m_RequiredItem9Class;
	ItemType_t		m_RequiredItem9Type;
	int				m_RequiredItem9Count;
	
	int				m_ItemLimitTime;
	
	bool			m_bRequiredItem;
	bool			m_bRequiredItem2;
	bool			m_bRequiredItem3;
	bool			m_bRequiredItem4;
	bool			m_bRequiredItem5;
	bool			m_bRequiredItem6;
	bool			m_bRequiredItem7;
	bool			m_bRequiredItem8;
	bool			m_bRequiredItem9;
	
	Item::ItemClass m_EventItemClass;
	ItemType_t		m_EventItemType;
	
	int				m_EventItemLimitTime;
	bool			m_bEventItem;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveItemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionGiveItemFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_GIVE_ITEM; }
	virtual string getActionName() const throw() { return "GiveItem"; }
	virtual Action* createAction() const throw() { return new ActionGiveItem(); }
};
#endif
