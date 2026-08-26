//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveCommonQuestItem.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GIVE_COMMON_QUEST_ITEM_H__
#define __ACTION_GIVE_COMMON_QUEST_ITEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveCommonQuestItem
//////////////////////////////////////////////////////////////////////////////

class ActionGiveCommonQuestItem : public Action 
{
public:
	ActionGiveCommonQuestItem();
	~ActionGiveCommonQuestItem() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_GIVE_COMMON_QUEST_ITEM; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
	ItemNum_t					m_RequestItemNum;
	int							m_QuestItemNum;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveCommonQuestItemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionGiveCommonQuestItemFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_GIVE_COMMON_QUEST_ITEM; }
	virtual string getActionName() const throw() { return "GiveCommonQuestItem"; }
	virtual Action* createAction() const throw() { return new ActionGiveCommonQuestItem(); }
};

#endif
