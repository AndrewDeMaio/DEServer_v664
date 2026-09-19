//////////////////////////////////////////////////////////////////////////////
// Filename    : RareBookSkill.h
// Description : The level 171/181 skill-book skills (books 41-73) never level up: Slayer ones gain no skill
//               exp (SkillInfo level >= 150) and Ousters ones have no LevelUpPoint. They are created and
//               loaded already mastered, so every skill-level term in their formulas is at full value.
//////////////////////////////////////////////////////////////////////////////

#ifndef __RARE_BOOK_SKILL_H__
#define __RARE_BOOK_SKILL_H__

#include "Types.h"
#include "Skill.h"

const int RARE_BOOK_SLAYER_SKILL_LEVEL  = 100;
const int RARE_BOOK_OUSTERS_SKILL_LEVEL = 30;
const int RARE_BOOK_ADVANCEMENT_LEVEL   = 100;	// max advancement class level (AdvancementClassEXPInfo), for
												// formulas copied from skills that grow with it

inline bool isRareBookSkill(SkillType_t SkillType)
{
	switch (SkillType)
	{
		// Slayer
		case SKILL_BLAZE_WALK_2:
		case SKILL_GLADIATOR:
		case SKILL_CRUSHING_STORM:
		case SKILL_SATELLITE_BOMB_2:
		case SKILL_INTIMATE_GRAIL_2:
		case SKILL_HOLY_ARMOR_2:
		case SKILL_STRIKING_2:
		case SKILL_BLESS_2:
		case SKILL_GLORY_GROUND:
		case SKILL_PASSING_HEAL_2:
		case SKILL_GREAT_HEAL_2:
		case SKILL_DRAGON_HURRICANE:
		case SKILL_LAR_STROKE:
		case SKILL_GAE_BULGA:
		case SKILL_VICIOUS_GUIDANCE:
		case SKILL_SPECTOR_INVERSE:
		case SKILL_DRAGON_HURRICANE_2:
		// Vampire (no skill levels, listed for completeness)
		case SKILL_CHAIN_OF_DEMON:
		case SKILL_BLOODY_SKULL:
		case SKILL_RAGE_OF_BLOOD:
		case SKILL_BAT_BREAKER:
		case SKILL_SHADY_DOUPLE:
		// Ousters
		case SKILL_ALLYSTER_WIND:
		case SKILL_FLAME_SIGHT:
		case SKILL_SPIRAL_MEGALITH:
		case SKILL_RADCHIA:
		case SKILL_BREATH_OF_DRYAD:
		case SKILL_CHAKRAM_HAIL:
		case SKILL_FLAME_SPIKE:
		case SKILL_BLIZZARD:
		case SKILL_DEMOLISHER:
		case SKILL_BLIZZARD_2:
		case SKILL_CHAKRAM_HAIL_2:
			return true;
		default:
			return false;
	}
}

#endif
