//--------------------------------------------------------------------------------
//
// Filename   : DB.h
// Written By : Reiot
//
//--------------------------------------------------------------------------------

#ifndef __DB_H__
#define __DB_H__

#include "DatabaseManager.h"
#include "Connection.h"
#include "Statement.h"
#include "Result.h"

#define BEGIN_DB try 
#define BEGIN_DB_EX try 

// NOTE: these used to end in throw(msg.c_str()), which threw a const char*
// that nothing catches (every handler expects Throwable&), so any SQL error
// unwound past all of them into terminate() and killed the server. It also
// threw a pointer into a local string that was destroyed while unwinding.
// Error derives from Throwable and copies the message. These two macros are
// used at 1324 call sites across 497 files.
#define END_DB(STMT)         catch(SQLQueryException& sqe) { delete STMT; string msg; msg += string(__PRETTY_FUNCTION__); msg += " : "; msg += string(sqe.toString()); filelog("DBError.log", "%s", msg.c_str()); throw Error(msg); } 
#define END_DB_EX(STMT, MSG) catch(SQLQueryException& sqe) { delete STMT; string msg; msg += string(__PRETTY_FUNCTION__); msg += string(" : "); msg += string(sqe.toString()); msg += string(" : "); msg += string(MSG); filelog("DBError.log", "%s", msg.c_str()); throw Error(msg); } 

#define NEW_STMT g_pDatabaseManager->getConnection("DARKEDEN")->createStatement()

#endif
