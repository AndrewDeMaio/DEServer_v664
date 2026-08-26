//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionCheckGlutinousRiceKneading.h
// Written By  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_CHECK_GLUTINOUS_RICE_KNEADING_H__
#define __ACTION_CHECK_GLUTINOUS_RICE_KNEADING_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionCheckGlutinousRiceKneading
//////////////////////////////////////////////////////////////////////////////

class ActionCheckGlutinousRiceKneading : public Action 
{
public:
	ActionCheckGlutinousRiceKneading();
	~ActionCheckGlutinousRiceKneading() throw();

	virtual ActionType_t getActionType() const throw() { return ACTION_CHECK_GLUTINOUS_RICE_KNEADING; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private :
	int							m_QuestItemNum;
	int							m_TotalRatio; //20070911 ¿Ã∫•∆Æ æ∆¿Ã≈€¿« √— »Æ∑¸
};


//////////////////////////////////////////////////////////////////////////////
// class ActionCheckGlutinousRiceKneadingFactory;
//////////////////////////////////////////////////////////////////////////////

class ActionCheckGlutinousRiceKneadingFactory : public ActionFactory 
{
public:
	virtual ActionType_t getActionType() const throw() { return Action::ACTION_CHECK_GLUTINOUS_RICE_KNEADING; }
	virtual string getActionName() const throw() { return "CheckGlutinousRiceKneading"; }
	virtual Action* createAction() const throw() { return new ActionCheckGlutinousRiceKneading(); }
};

#endif
