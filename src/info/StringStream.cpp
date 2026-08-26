//////////////////////////////////////////////////////////////////////////////
// Filename    : StringStream.cc
// Written By  : 
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "StringStream.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////
// class StringStream member methods
//////////////////////////////////////////////////////////////////////////////

StringStream::StringStream () 
{
	m_Size      = 0;
	m_bInserted = false;
	m_Buffer    = "";
}
	
StringStream::~StringStream () 
{
}
	
StringStream & StringStream::operator << ( bool T ) 
{
	string buf;

	if (T == true) buf = "true";
	else           buf = "false";

	m_Strings.push_back( buf );

	m_Size += buf.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( char T ) 
{
	char temp[2];
	temp[0] = T;
	temp[1] = '\0';

	string buf(temp);

	m_Strings.push_back( buf );

	m_Size += buf.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( uchar T )
{
	char temp[2];
	temp[0] = T;
	temp[1] = '\0';

	string buf(temp);

	m_Strings.push_back( buf );

	m_Size += buf.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( short T )
{
	char buf[7];
	sprintf( buf , "%d" , T );

	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( ushort T )
{
	char buf[7];
	sprintf( buf , "%d" , T );

	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( int T )
{
	char buf[12];
	sprintf( buf , "%d" , T );
	
	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( uint T )
{	
	char buf[12];
	sprintf( buf , "%d" , T );
	
	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( long T )
{
	char buf[12];
	sprintf( buf , "%ld" , T );
	
	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( ulong T )
{	
	char buf[12];
	sprintf( buf , "%ld" , T );
	
	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( float T )
{
	char buf[12];
	sprintf( buf , "%f" , T );
	
	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( double T )
{
	char buf[22];
	sprintf( buf , "%f" , T );
	
	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( const char * buf )
{
	string str(buf);

	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

StringStream & StringStream::operator << ( const string & str )
{
	m_Strings.push_back( str );

	m_Size += str.size();
	m_bInserted = true;

	return *this;
}

string StringStream::toString()
{
	//    , 
	//        .
	if ( m_bInserted ) 
	{
		m_bInserted = false;

		//          .
		m_Buffer.reserve( m_Size );

		//   .
		list<string>::const_iterator itr = m_Strings.begin ();
		for (; itr != m_Strings.end(); itr ++ ) 
		{
			m_Buffer += *itr;
			//m_Buffer.append( *itr );
		}
	}

	return m_Buffer;
}

void StringStream::flush(void)
{
	m_Size      = 0;
	m_bInserted = false;
	m_Buffer    = "";

	m_Strings.clear();
}
