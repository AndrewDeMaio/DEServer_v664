#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Types.h"
#include <stdio.h>
#include <stdlib.h>

// ,  
string itos(int value);

// get line from big-string
// pos  \n   .
string getline ( const string & str , size_t & pos );

// strip whitespace from the beginning and end of a string
string trim ( const string & str );

#endif
