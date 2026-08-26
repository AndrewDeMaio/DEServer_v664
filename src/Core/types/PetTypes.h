#ifndef __PET_TYPES_H__
#define __PET_TYPES_H__

#include "SystemTypes.h"

enum PetType
{
	PET_NONE 				= 0,
	PET_COMMON 				= 1,
	PET_PACKAGE 			= 2,
	PET_CENTAURO 			= 3,
	PET_STIRGE 				= 4,
	PET_PIXIE 				= 5,			
	PET_LUPENG 				= 6,			//±«µµ·çÆØ(Æë±Ï)
	//2007.11.20 kim sung yong
	PET_MILITARY_BEAR 		= 7,    
	//2007.11.20 kim sung yong
	PET_GARGOYLE 			= 8,	
	PET_FIRE_ELEMENTAL 		= 9,
	PET_SUCCUBUS 			= 10,
	PET_INCUBUS 			= 11,	//2008.12.01 wlzzi
	PET_MASHIMARO 			= 12,
	PET_TABBY 				= 13,
	PET_WEALTHY 			= 14,
	PET_SIAMING 			= 15,
	
	PET_MINOTAURS_TABBY 	= 16,
	PET_PTHA_TABBY 			= 17,
	PET_ROC_WEALTHY 		= 18,
	PET_PTHA_WEALTHY		= 19,
	PET_GENIUS_SIAMING 		= 20,
	PET_PTHA_SIAMING 		= 21,
	PET_DESTROY_TABBY 		= 22,
	PET_VARUNA_TABBY 		= 23,
	PET_NECROMANCY_WEALTHY 	= 24,
	PET_VARUNA_WEALTHY 		= 25,
	PET_DRACULA_SIAMING 	= 26,
	PET_VARUNA_SIAMING 		= 27,
	
	PET_MINOTAURS_INCUBUS 	= 28,
	PET_PTHA_INCUBUS 		= 29,
	PET_ROC_SUCCUBUS 		= 30,
	PET_PTHA_SUCCUBUS 		= 31,
	PET_GENIUS_GARGOYLE 	= 32,
	PET_PTHA_GARGOYLE 		= 33,
	PET_DESTROY_INCUBUS 	= 34,
	PET_VARUNA_INCUBUS 		= 35,
	PET_NECROMANCY_SUCCUBUS = 36,
	PET_VARUNA_SUCCUBUS 	= 37,
	PET_DRACULA_GARGOYLE 	= 38,
	PET_VARUNA_GARGOYLE 	= 39,
	PET_MINI_WOLFDOG		= 40,
	PET_VARUNA_LUPENG		= 41,
	PET_DRACULA_LUPENG		= 42,
	PET_PTHA_LUPENG			= 43,
	PET_DECATON_LUPENG		= 44,
	PET_VARUNA_BEAR			= 45,
	PET_DRACULA_BEAR		= 46,
	PET_PTHA_BEAR			= 47,
	PET_PHEONIX_BEAR		= 48,
	PET_DESTORY_BEAR		= 49,
	PET_NECROMANCY_BEAR		= 50,
	PET_PAINFUL_BEAR		= 51,
	PET_CORUNDUM_BEAR		= 52,
	
};

//20090109 wlzzi - Çª´õ±â´ÉÅ¸ÀÔ
enum PetFoodFunctionType
{
	FOOD_FUNCTION_NONE = 0,
	FOOD_FUNCTION_LUCKY = 1,
	FOOD_FUNCTION_INTERPRETER = 2,
	FOOD_FUNCTION_SMART = 3,	//20090410 ksym555 ½º¸¶Æ® Çªµå
};
//-
typedef BYTE PetType_t;
const uint szPetType = szBYTE;

typedef BYTE PetLevel_t;
const uint szPetLevel = szBYTE;

typedef DWORD PetExp_t;
const uint szPetExp = szDWORD;

typedef WORD PetHP_t;
const uint szPetHP = szWORD;

typedef BYTE PetAttr_t;
const uint szPetAttr = szBYTE;

typedef BYTE PetAttrLevel_t;
const uint szPetAttrLevel = szBYTE;

#endif
