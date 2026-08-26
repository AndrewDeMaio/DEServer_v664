//////////////////////////////////////////////////////////////////////
//
// Filename    : Timeval.cpp
// Written By  : Reiot
// Description : struct timeval �� ���õ� operator ���� ��Ƴ��� ����
//
//////////////////////////////////////////////////////////////////////

// include files
#include "Timeval.h"
#include "stdlib.h"
#include "StringStream.h"

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
bool operator > ( const Timeval & left , const Timeval & right )
{
	return left.tv_sec > right.tv_sec || 
		( left.tv_sec == right.tv_sec && left.tv_usec > right.tv_usec );
}


//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
bool operator >= ( const Timeval & left , const Timeval & right )
{
	return left.tv_sec > right.tv_sec || 
		( left.tv_sec == right.tv_sec && left.tv_usec > right.tv_usec ) ||
		( left.tv_sec == right.tv_sec && left.tv_usec == right.tv_usec );
}


//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
bool operator == ( const Timeval & left , const Timeval & right )
{
	return left.tv_sec == right.tv_sec && left.tv_usec == right.tv_usec;
}


//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
bool operator <= ( const Timeval & left , const Timeval & right )
{
	return left.tv_sec < right.tv_sec || 
		( left.tv_sec == right.tv_sec && left.tv_usec < right.tv_usec ) ||
		( left.tv_sec == right.tv_sec && left.tv_usec == right.tv_usec );
}


//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
bool operator < ( const Timeval & left , const Timeval & right )
{
	return left.tv_sec < right.tv_sec || 
		( left.tv_sec == right.tv_sec && left.tv_usec < right.tv_usec );
}


//--------------------------------------------------------------------------------
// timediff�� ��������� ���� ��쿡 ����Ѵ�.
// (��� ���� �ð����� ���Ѵٴ� ���� �콺�� ���̴�. - -; )
//--------------------------------------------------------------------------------
Timeval operator + ( const Timeval & left , const Timeval & right )
{
	Timeval result;

	result.tv_sec  = left.tv_sec  + right.tv_sec;
	result.tv_usec = left.tv_usec + right.tv_usec;

	if ( result.tv_usec > 1000000 ) {
		result.tv_sec ++;
		result.tv_usec -= 1000000;
	}

	return result;
}


//--------------------------------------------------------------------------------
// �� Timeval ���� �ð����� ���Ѵ�. 
//--------------------------------------------------------------------------------
Timeval timediff ( const Timeval & left , const Timeval & right )
{
	Timeval result;
 
	if ( left.tv_sec > right.tv_sec ) {
		result.tv_sec  = left.tv_sec  - right.tv_sec;
		result.tv_usec = left.tv_usec - right.tv_usec;
		if ( result.tv_usec < 0 ) {
			result.tv_sec --;
			result.tv_usec = 1000000 + result.tv_usec;
		}
	} else if ( left.tv_sec == right.tv_sec ) {
		result.tv_sec = 0;
		result.tv_usec = left.tv_usec - right.tv_usec;
		if ( result.tv_usec < 0 ) {
			result.tv_usec = - result.tv_usec;
		}
	} else {	// left.tv_sec < right.tv_sec
		result.tv_sec  = right.tv_sec  - left.tv_sec;
		result.tv_usec = right.tv_usec - left.tv_usec;
		if ( result.tv_usec < 0 ) {
			result.tv_sec --;
			result.tv_usec = 1000000 + result.tv_usec;
		}
	}

    return result;
}

void getCurrentYearTime ( Turn_t & currentYearTime )
{
	time_t daytime = time(0);

	tm Timem;
	localtime_r( &daytime, &Timem );
//	tm * Timem = localtime( &daytime );

	StringStream stime;

	stime << Timem.tm_year << Timem.tm_mon << Timem.tm_mday;

	currentYearTime = atoi(stime.toString().c_str());

}

Timeval gCurrentTime = Timeval();

