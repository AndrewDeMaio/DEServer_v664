//////////////////////////////////////////////////////////////////////////////
// Filename    : ActionChangePlayerColor.h
// Written By  : 
// Description :
// 플레이어 케릭터의 색을 변경 하는 액션
//////////////////////////////////////////////////////////////////////////////

#ifndef __ACTION_CHANGE_PLAYER_COLOR_H__
#define __ACTION_CHANGE_PLAYER_COLOR_H__

#include "Types.h"
#include "Exception.h"
#include "Action.h"
#include "ActionFactory.h"
#include "Creature.h"

//////////////////////////////////////////////////////////////////////////////
// class ActionChangePlayerColor;
//////////////////////////////////////////////////////////////////////////////

class ActionChangePlayerColor : public Action 
{
public:
	virtual ActionType_t getActionType() const throw() { return ACTION_CHANGE_PLAYER_COLOR; }
	virtual void read(PropertyBuffer & propertyBuffer) throw(Error);
	virtual void execute(Creature* pCreature1, Creature* pCreature2 = NULL) throw(Error);
	virtual string toString() const throw();

private:
	BYTE	m_Flag;
	int		m_ColorValue;
};

////////////////////////////////////////////////////////////////////////////////
// class ActionChangePlayerColorFactory;
////////////////////////////////////////////////////////////////////////////////

class ActionChangePlayerColorFactory : public ActionFactory 
{
public:
    virtual ActionType_t getActionType() const throw() { return Action::ACTION_CHANGE_PLAYER_COLOR; }
    virtual string getActionName() const throw() { return "ChangePlayerColor"; }
    virtual Action* createAction() const throw() { return new ActionChangePlayerColor(); }
};

#endif
