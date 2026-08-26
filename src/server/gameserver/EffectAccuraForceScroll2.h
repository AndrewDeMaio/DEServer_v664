//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectAccuraForceScroll2.h
// Written by  : ksym555
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_ACCURA_FORCE_SCROLL_2__
#define __EFFECT_ACCURA_FORCE_SCROLL_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectAccuraForceScroll2
//////////////////////////////////////////////////////////////////////////////

class EffectAccuraForceScroll2 : public Effect
{
public:
	EffectAccuraForceScroll2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_ACCURA_FORCE_SCROLL_2; }

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
// class EffectAccuraForceScroll2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectAccuraForceScroll2Loader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_ACCURA_FORCE_SCROLL_2; }
	virtual string getEffectClassName() const throw() { return "EffectAccuraForceScroll2"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectAccuraForceScroll2Loader* g_pEffectAccuraForceScroll2Loader;

#endif 
