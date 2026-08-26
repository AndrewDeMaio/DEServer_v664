//////////////////////////////////////////////////////////////////////////////
// Filename    : StringStream.h
// Written By  : 
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __STRINGSTREAM_H__
#define __STRINGSTREAM_H__

#include "Types.h"
#include <list>

//////////////////////////////////////////////////////////////////////////////
// end of stream
//////////////////////////////////////////////////////////////////////////////
const char eos = '\n';

//////////////////////////////////////////////////////////////////////////////
//
// class StringStream
//
//////////////////////////////////////////////////////////////////////////////

class StringStream 
{

///// Member methods /////

public:
	StringStream();
	~StringStream();
	
public:
	StringStream & operator << (bool T);
	StringStream & operator << (char T);
	StringStream & operator << (uchar T);
	StringStream & operator << (short T);
	StringStream & operator << (ushort T);
	StringStream & operator << (int T);
	StringStream & operator << (uint T);
	StringStream & operator << (long T);
	StringStream & operator << (ulong T);
	StringStream & operator << (float T);
	StringStream & operator << (double T);
	StringStream & operator << (const char * str);
	StringStream & operator << (const string & str);

	// make string
	string toString();
	const char* toCString() { return toString().c_str(); }
	
	// true if stream is empty
	bool isEmpty() const { return m_Size == 0; }

	// empty string
	void flush(void);


///// Member data /////

private:
	list<string> m_Strings;   // list of string
	ushort       m_Size;      // size of string which will be generated
	bool         m_bInserted; // inserted flag 
	string       m_Buffer;    // buffer for string will be generated
};

#endif
