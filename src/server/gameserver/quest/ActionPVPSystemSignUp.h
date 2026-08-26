//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionGiveHellGardenSeedItem.h
// Written By  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_PVP_SYSTEM_SIGN_UP_H__
#define __ACTION_PVP_SYSTEM_SIGN_UP_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionGiveDraculaCastleItem
//////////////////////////////////////////////////////////////////////////////

class ActionPVPSystemSignUp : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_PVP_SYSTEM_SIGN_UP; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();
public:
	int getType(void) const { return m_Type; }
	void setType(int type) { m_Type = type; }

private:
	ItemType_t m_Type; 
}
;


//////////////////////////////////////////////////////////////////////////////
// class ActionGiveDraculaCastleItemFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionPVPSystemSignUpFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_PVP_SYSTEM_SIGN_UP; }
	virtual string getActionName() const throw() { return "PVPSystemSignUp"; }
	virtual Action* createAction() const throw() { return new ActionPVPSystemSignUp(); }
};

#endif
