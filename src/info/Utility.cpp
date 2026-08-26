#include "Utility.h"

// ,  
string itos(int value)
{
	char buf[100] = {0, };
	sprintf(buf, "%d", value);
	return string(buf);
}

// get line from big-string
// pos  \n   .
string getline ( const string & str , size_t & pos )
{
	if (pos > str.size()) return "";

	size_t oldpos = pos;
	pos = str.find_first_of('\n',oldpos);

	if (pos == string::npos) pos = str.size()+1;
	else                     pos = pos+1;

	return str.substr( oldpos , ( pos - 1 ) - oldpos );
}

// strip whitespace from the beginning and end of a string
string trim ( const string & str )
{
	if (str.size() == 0) return "";

	static const char * WhiteSpaces = " \t\n\r";
	size_t begin = str.find_first_not_of( WhiteSpaces );
	size_t end = str.find_last_not_of( WhiteSpaces );

	if (begin == string::npos) begin = 0;
	if (end   == string::npos) end   = str.size();

	return str.substr( begin , end - begin + 1 );
}
