//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionMapleReward.h
// Written By  : smallheart
// Description : 2008년 가을(10월)이벤트 - 메이플 문양
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_MAPLE_REWARD_H__
#define __ACTION_MAPLE_REWARD_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionBlitzRegister
//////////////////////////////////////////////////////////////////////////////

class ActionMapleReward : public Action 
{
public:
	ActionMapleReward();
	~ActionMapleReward() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_MAPLE_REWARD; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();
private:
	int m_MapleRewardCount;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionMapleRewardFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionMapleRewardFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_MAPLE_REWARD; }
	virtual string getActionName() const throw() { return "MapleReward"; }
	virtual Action* createAction() const throw() { return new ActionMapleReward(); }
};

#endif