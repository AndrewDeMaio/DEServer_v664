//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionBlitzReward.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_BLITZ_REWARD_H__
#define __ACTION_BLITZ_REWARD_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionBlitzRegister
//////////////////////////////////////////////////////////////////////////////

class ActionBlitzReward : public Action 
{
public:
	ActionBlitzReward();
	~ActionBlitzReward() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_BLITZ_REWARD; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();
private:
	int m_BlitzRewardCount;
};


//////////////////////////////////////////////////////////////////////////////
// class ActionBlitzRewardFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionBlitzRewardFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_BLITZ_REWARD; }
	virtual string getActionName() const throw() { return "BlitzReward"; }
	virtual Action* createAction() const throw() { return new ActionBlitzReward(); }
};

#endif
