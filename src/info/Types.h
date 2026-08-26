#ifndef __SYSTEM_TYPES_H__
#define __SYSTEM_TYPES_H__

#include <sys/types.h>
 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long  DWORD;

typedef unsigned long long ulonglong;
//typedef unsigned __int64 ulonglong;

const unsigned int szbool   = sizeof(bool);
const unsigned int szchar   = sizeof(char);
const unsigned int szshort  = sizeof(short);
const unsigned int szint    = sizeof(int);
const unsigned int szlong   = sizeof(long);
const unsigned int szuchar  = sizeof(unsigned char);
const unsigned int szushort = sizeof(unsigned short);
const unsigned int szuint   = sizeof(unsigned int);
const unsigned int szulong  = sizeof(unsigned long);
const unsigned int szBYTE   = sizeof(BYTE);
const unsigned int szWORD   = sizeof(WORD);
const unsigned int szDWORD  = sizeof(DWORD);

//by kim
const unsigned int szlonglong = sizeof(long long);
const unsigned int szulonglong = sizeof(unsigned long long);

#define SAFE_DELETE(P)       { if (P != NULL) { delete P; P = NULL; } }
#define SAFE_DELETE_ARRAY(P) { if (P != NULL) { delete [] P; P = NULL; } }

#endif
