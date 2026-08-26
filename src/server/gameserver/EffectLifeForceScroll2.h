//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectLifeForceScroll2.h
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_LIFE_FORCE_SCROLL_2__
#define __EFFECT_LIFE_FORCE_SCROLL_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectLifeForceScroll2
//////////////////////////////////////////////////////////////////////////////

class EffectLifeForceScroll2 : public Effect
{
public:
	EffectLifeForceScroll2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_LIFE_FORCE_SCROLL_2; }

	void affect() throw(Error);
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error); 
	void unaffect(Creature* pCreature) throw(Error);

	virtual void create( const string& ownerID ) throw(Error);
	virtual void destroy( const string& ownerID ) throw(Error);
	virtual void save( const string& ownerID ) throw(Error);

	bool isPossibleAffect () throw(Error); 
	string toString() const throw();

private:
};

//////////////////////////////////////////////////////////////////////////////
// class EffectLifeForceScroll2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectLifeForceScroll2Loader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_LIFE_FORCE_SCROLL_2; }
	virtual string getEffectClassName() const throw() { return "EffectLifeForceScroll2"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectLifeForceScroll2Loader* g_pEffectLifeForceScroll2Loader;

#endif 
