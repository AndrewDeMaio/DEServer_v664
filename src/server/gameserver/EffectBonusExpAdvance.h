//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectBonusExpAdvance.h
// Written by  : ksym555
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __EFFECT_BONUS_EXP_ADVANCE__
#define __EFFECT_BONUS_EXP_ADVANCE__

#include "Effect.h"
#include "EffectLoader.h"

//////////////////////////////////////////////////////////////////////////////
// class EffectBonusExpAdvance
//////////////////////////////////////////////////////////////////////////////

class EffectBonusExpAdvance : public Effect 
{
public:
	EffectBonusExpAdvance(Creature* pCreature) throw(Error);

public:
    EffectClass getEffectClass() const throw() { return EFFECT_CLASS_BONUS_EXP_ADVANCE; }

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
// class EffectBonusExpAdvanceLoader
//////////////////////////////////////////////////////////////////////////////

class EffectBonusExpAdvanceLoader : public EffectLoader 
{
public:
	virtual Effect::EffectClass getEffectClass() const throw() { return Effect::EFFECT_CLASS_BONUS_EXP_ADVANCE; }
	virtual string getEffectClassName() const throw() { return "EffectBonusExpAdvance"; }

public:
	virtual void load(Creature* pCreature) throw(Error);

};

extern EffectBonusExpAdvanceLoader* g_pEffectBonusExpAdvanceLoader;

#endif // __EFFECT_CLASS_BONUS_EXP_ADVANCE__
