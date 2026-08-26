//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionTradeMysteryPotion.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_TRADE_MYSTERY_POTION_H__
#define __ACTION_TRADE_MYSTERY_POTION_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionTradeMysteryPotion
//////////////////////////////////////////////////////////////////////////////

class ActionTradeMysteryPotion : public Action 
{
public:
	ActionTradeMysteryPotion();
	~ActionTradeMysteryPotion() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_TRADE_MYSTERY_POTION; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
};


//////////////////////////////////////////////////////////////////////////////
// class ActionTradeMysteryPotionFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionTradeMysteryPotionFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_TRADE_MYSTERY_POTION; }
	virtual string getActionName() const throw() { return "TradeMysteryPotion"; }
	virtual Action* createAction() const throw() { return new ActionTradeMysteryPotion(); }
};

#endif
