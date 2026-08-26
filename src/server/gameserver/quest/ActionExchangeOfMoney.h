//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionExchangeOfMoney.h
// Written By  : 
// Description :
// Creature가 주어진 대사를 말한다. 이 대사는 크리처의 머리 위의 말풍선으로
// 출력된다.
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_EXCHANGE_OF_MONEY_H__
#define __ACTION_EXCHANGE_OF_MONEY_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionExchangeOfMoney;
//////////////////////////////////////////////////////////////////////////////

class ActionExchangeOfMoney : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_EXCHANGE_OF_MONEY; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private:
	int 	m_ExchangeType;
	Gold_t	m_CheckMoney;

};

//////////////////////////////////////////////////////////////////////////////
// class ActionExchangeOfMoney;
//////////////////////////////////////////////////////////////////////////////

class ActionExchangeOfMoneyFactory : public ActionFactory 
{
public:
    virtual ActionType_t getActionType() const throw() { return Action::ACTION_EXCHANGE_OF_MONEY; }
	virtual string getActionName() const throw() { return "ExchangeOfMoney"; }
    virtual Action* createAction() const throw() { return new ActionExchangeOfMoney(); }
};

#endif
