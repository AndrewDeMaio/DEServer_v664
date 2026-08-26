//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBonusExpSecond.h
// Written by  : elca@ewestsoft.com
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_BONUS_EXP_SECOND__
#define __EFFECT_BONUS_EXP_SECOND__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectBonusExpSecond
//////////////////////////////////////////////////////////////////////////////

class EffectBonusExpSecond : public Effect 
{
public:
	EffectBonusExpSecond(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_BONUS_EXP_SECOND; }

	void affect() throw(Error) { }
	void affect(Creature* pCreature) throw(Error);

	void unaffect() throw(Error);
	void unaffect(Creature* pCreature) throw(Error);

	virtual void create(const string & name) throw(Error);
	virtual void destroy(const string & name) throw(Error);
	virtual void save(const string & name) throw(Error);

	string toString() const throw();
	
	void SetBonusRate(float fRate) { m_fBonusRate = fRate; }
	float GetBonusRate() { return m_fBonusRate; }
	
protected :
	float m_fBonusRate;
};

//////////////////////////////////////////////////////////////////////////////
// class EffectBonusExpSecondLoader
//////////////////////////////////////////////////////////////////////////////

class EffectBonusExpSecondLoader : public EffectLoader 
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_BONUS_EXP_SECOND; }
	virtual string getEffectClassName() const throw() { return "EffectBonusExpSecond"; }

public:
	virtual void load(Creature* pCreature) throw(Error);

};

extern EffectBonusExpSecondLoader* g_pEffectBonusExpSecondLoader;

#endif // __EFFECT_CLASS_BONUS_EXP_SECOND__
