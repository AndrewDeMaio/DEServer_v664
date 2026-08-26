//--------------------------------------------------------------------------------
//
// Filename    : Timeval.h
// Written By  : Reiot
// Description : struct timeval �� ���õ� operator ���� ��Ƴ��� ����
//
//--------------------------------------------------------------------------------

#ifndef __TIMEVAL_H__
#define __TIMEVAL_H__

// include files
#include <sys/time.h>
#include <unistd.h>
#include "Types.h"		// Turn_t

// type redefinition
typedef struct timeval Timeval;

extern Timeval gCurrentTime;

#ifdef __GAME_SERVER__
	#define getCurrentTime(t) gettimeofday((&t),NULL)
	#define setCurrentTime() gettimeofday(&gCurrentTime,NULL)
#else
	#define getCurrentTime(t) gettimeofday((&t),NULL)
#endif

bool operator > ( const Timeval & left , const Timeval & right );
bool operator >= ( const Timeval & left , const Timeval & right );
bool operator == ( const Timeval & left , const Timeval & right );
bool operator <= ( const Timeval & left , const Timeval & right );
bool operator < ( const Timeval & left , const Timeval & right );

// timediff�� ��������� ���� ��쿡 ����Ѵ�.
// (��� ���� �ð����� ���Ѵٴ� ���� �콺�� ���̴�. - -; )
Timeval operator + ( const Timeval & left , const Timeval & right );

//
// �� Timeval ���� �ð����� ���Ѵ�. 
//
Timeval timediff ( const Timeval & left , const Timeval & right );

// every caller passes a Turn_t; spelling it `unsigned long` here only worked
// while DWORD was `unsigned long`.
void getCurrentYearTime ( Turn_t & currentYearTime );

#endif
