//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionTradeSealingStone.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_TRADE_SEALING_STONE_H__
#define __ACTION_TRADE_SEALING_STONE_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionTradeSealingStone
//////////////////////////////////////////////////////////////////////////////

class ActionTradeSealingStone : public Action 
{
public:
	ActionTradeSealingStone();
	~ActionTradeSealingStone() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_TRADE_SEALING_STONE; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
};


//////////////////////////////////////////////////////////////////////////////
// class ActionTradeSealingStoneFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionTradeSealingStoneFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_TRADE_SEALING_STONE; }
	virtual string getActionName() const throw() { return "TradeSealingStone"; }
	virtual Action* createAction() const throw() { return new ActionTradeSealingStone(); }
};

#endif
