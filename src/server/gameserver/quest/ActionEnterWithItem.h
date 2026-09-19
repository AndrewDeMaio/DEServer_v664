//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionEnterWithItem.h
// Description : Hand one item to an NPC and be transported (Marcus, the gatekeeper
//               outside Dracula Castle, lets players in for a Forbidden Blood).
//
//   ActionType : EnterWithItem          (every field required, in this order -
//     ItemClass : class of the item taken  PropertyBuffer is sequential)
//     ItemType  : type of the item taken
//     ItemName  : name used in the messages
//     ZoneID    : where the player is sent
//     X / Y
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_ENTER_WITH_ITEM_H__
#define __ACTION_ENTER_WITH_ITEM_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionEnterWithItem;
//////////////////////////////////////////////////////////////////////////////

class ActionEnterWithItem : public Action
{
public:
	ActionEnterWithItem() throw(Error);
	virtual ~ActionEnterWithItem() throw(Error) {}

	virtual ActionType_t getActionType() const throw() { return ACTION_ENTER_WITH_ITEM; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private:
	int         m_ItemClass;
	ItemType_t  m_ItemType;
	string      m_ItemName;
	ZoneID_t    m_ZoneID;
	ZoneCoord_t m_X;
	ZoneCoord_t m_Y;
};

////////////////////////////////////////////////////////////////////////////////
// class ActionEnterWithItemFactory;
////////////////////////////////////////////////////////////////////////////////

class ActionEnterWithItemFactory : public ActionFactory
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_ENTER_WITH_ITEM; }
	virtual string getActionName() const throw() { return "EnterWithItem"; }
	virtual Action* createAction() const throw() { return new ActionEnterWithItem(); }
};

#endif
