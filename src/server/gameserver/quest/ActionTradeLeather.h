//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionTradeLeather.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_TRADE_LEATHER_H__
#define __ACTION_TRADE_LEATHER_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionTradeLeather
//////////////////////////////////////////////////////////////////////////////

class ActionTradeLeather : public Action 
{
public:
	ActionTradeLeather();
	~ActionTradeLeather() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_TRADE_LEATHER; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
};


//////////////////////////////////////////////////////////////////////////////
// class ActionTradeLeatherFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionTradeLeatherFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_TRADE_LEATHER; }
	virtual string getActionName() const throw() { return "TradeLeather"; }
	virtual Action* createAction() const throw() { return new ActionTradeLeather(); }
};

#endif
