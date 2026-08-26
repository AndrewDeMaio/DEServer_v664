//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveEventBoxItem.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_GIVE_EVENT_BOX_ITEM_H__
#define __ACTION_GIVE_EVENT_BOX_ITEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveEventBoxItem
//////////////////////////////////////////////////////////////////////////////

class ActionGiveEventBoxItem : public Action 
{
public:
	ActionGiveEventBoxItem();
	~ActionGiveEventBoxItem() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_GIVE_EVENT_BOX_ITEM; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
};


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveEventBoxItemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionGiveEventBoxItemFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_GIVE_EVENT_BOX_ITEM; }
	virtual string getActionName() const throw() { return "GiveEventBoxItem"; }
	virtual Action* createAction() const throw() { return new ActionGiveEventBoxItem(); }
};

#endif
