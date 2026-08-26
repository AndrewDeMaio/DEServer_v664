//////////////////////////////////////////////////////////////////////////////
// Filename    : Shape.cpp
// Written by  : excel96
// Description : 
// 로그인 화면에서 슬레이어의 외양을 보여주는 데 필요한 함수들.
// 아이템 타입에 따른 겉모습 상수를 리턴하는 함수들이다.
//////////////////////////////////////////////////////////////////////////////

#include "Shape.h"

BYTE getShoulderType(ItemType_t IType)
	throw()
{
	return 1;
}

PantsType getPantsType(ItemType_t IType)
	throw()
{
	PantsType rValue	= PANTS_BASIC;
	switch (IType)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			rValue	= PANTS1;
			break;

		case 4:
		case 5:
		case 6:
		case 7:
		case 30: case 31:	//발키리 레깅즈 외형
			rValue	= PANTS2;
			break;

		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 28: case 29:	//칼리가드 외형
			rValue	= PANTS3;
			break;

		case 22:
		case 23:
		default:
//			throw ("getPantsType() : unknown pants type");
			rValue	= PANTS4;
			break;
	}

	if(IType == 34 || IType == 35)
		rValue	= PANTS_OSIRIS;			//오시리스 아이템일 경우 외형 변화

	return rValue;
}

JacketType getJacketType(ItemType_t IType)
	throw()
{
	JacketType rValue	= JACKET_BASIC;
	switch (IType)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			rValue	= JACKET1;
			break;

		case 4:
		case 5:
		case 6:
		case 7:
		case 30: case 31:	//발키리 배틀슈트 외형
			rValue	= JACKET2;
			break;

		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 28: case 29:	//칼리 아머 외형
			rValue	= JACKET3;
			break;

		case 22:
		case 23:
		default:
//			throw ("getJacketType() : unknown jacket type");
			rValue	= JACKET4;
			break;
	}

	if(IType == 34 || IType == 35)
		rValue	= JACKET_OSIRIS;

	return rValue;
}

HelmetType getHelmetType(ItemType_t IType)
	throw()
{
	HelmetType rValue	= HELMET_NONE;
	switch (IType)
	{
		case 0:
		case 1:
		case 2:
			rValue	= HELMET1;
			break;

		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 15:	//칼리헬맷 외형
//			throw ("getHelmetType() : unknown helmet type");
			rValue	= HELMET2;
			break;

		case 12:
		default:
			rValue	= HELMET3;
			break;
	}

	if(IType == 17)
		rValue	= HELMET_OSIRIS;

	return rValue;
}

ShieldType getShieldType(ItemType_t IType)
	throw()
{
	ShieldType rValue	= SHIELD_NONE;
	switch (IType)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
			rValue	= SHIELD1;
			break;

		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 15:	//칼릴헬맷
		default:
//			throw ("getShieldType() : unknown shield type");
			rValue	= SHIELD2;
			break;
	}

	if(IType == 17)
		rValue	= SHIELD_OSIRIS;

	return rValue;
}

VampireCoatType getVampireCoatType(ItemType_t IType)
	throw()
{
	VampireCoatType rValue = VAMPIRE_COAT_BASIC;
	switch (IType)
	{
		case 0:
		case 1:
		case 2:
		case 3:
			rValue	=  VAMPIRE_COAT1;
			break;

		case 4:
		case 5:
		case 6:
		case 7:
		case 26: case 27:	//릴리스 슬리퍼리 로브/플룸 클록 외형
			rValue = VAMPIRE_COAT2;
			break;

		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 24: case 25:
			rValue = VAMPIRE_COAT3;
			break;

		case 18:
		case 19:
		default:
//			throw ("getVampireCoatType() : unknown VampireCoat type");
			rValue = VAMPIRE_COAT4;
			break;
	}

	if(IType == 31 || IType == 30)	//오시리스 폴/콥 외형
		rValue	= VAMPIRE_OSIRIS_COAT;

	return rValue;
}

MotorcycleType getMotorcycleType(ItemType_t IType)
	throw()
{
	switch (IType)
	{
		case 9 :
		case 8 :
			return MOTORCYCLE_WING;
		case 7:
			return MOTORCYCLE3;
		case 6:
			return MOTORCYCLE2;
		case 0:
		case 5:
		default:
			return MOTORCYCLE1;
			break;
	}

	return MOTORCYCLE_NONE;
}

OustersCoatType getOustersCoatType(ItemType_t IType)
	throw()
{
	OustersCoatType rValue = OUSTERS_COAT_BASIC;
	switch ( IType )
	{
		case 0:
		case 1:
		case 2:
		case 15:	//네이쳐스 스프라이트 코드 외형
			rValue	= OUSTERS_COAT1;
			break;

		case 3:
		case 4:
		case 5:
			rValue	= OUSTERS_COAT2;
			break;

		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 14: 	//리르코트 외형 
			rValue	= OUSTERS_COAT3;
			break;

		case 11:
		default:
			rValue	= OUSTERS_COAT4;
			break;
	}

	if(IType == 17)
		rValue	= OUSTERS_OSIRIS_COAT;

	return rValue;
}

OustersArmType getOustersArmType(ItemType_t IType)
	throw()
{
	switch ( IType )
	{
		case 0:
			return OUSTERS_ARM_GAUNTLET;
	}

	return OUSTERS_ARM_GAUNTLET;
}

