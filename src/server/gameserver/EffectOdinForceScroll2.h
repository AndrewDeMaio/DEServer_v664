//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectOdinForceScroll2.h
// Written by  : 
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_ODIN_FORCE_SCROLL_2__
#define __EFFECT_ODIN_FORCE_SCROLL_2__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectOdinForceScroll2
//////////////////////////////////////////////////////////////////////////////

class EffectOdinForceScroll2 : public Effect
{
public:
	EffectOdinForceScroll2(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_ODIN_FORCE_SCROLL_2; }

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
// class EffectOdinForceScroll2Loader
//////////////////////////////////////////////////////////////////////////////

class EffectOdinForceScroll2Loader : public EffectLoader
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_ODIN_FORCE_SCROLL_2; }
	virtual string getEffectClassName() const throw() { return "EffectOdinForceScroll2"; }

public:
	virtual void load( Creature* pCreature ) throw(Error);
};

extern EffectOdinForceScroll2Loader* g_pEffectOdinForceScroll2Loader;

#endif 

