//////////////////////////////////////////////////////////////////////////////
// Filename    : DB.h
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __DB_H__
#define __DB_H__

#include "Types.h"
#include <mysql/mysql.h>

//////////////////////////////////////////////////////////////////////////////
// forward declaration
//////////////////////////////////////////////////////////////////////////////

class Connection;
class Statement;
class Result;

//////////////////////////////////////////////////////////////////////////////
// class Connection
//////////////////////////////////////////////////////////////////////////////

class Connection 
{

///// Member methods /////

public: // Constructor & destructor

	Connection();
	Connection(string host, string db, string user, string password, uint port=0);
	~Connection();

public: // Public methods

	// connect & close
	void connect();
	void connect(string host, string db, string user, string password, uint port=0 );
	void close();
	
	// check connected
	bool isConnected() const { return m_bConnected; }
	bool operator ! () const { return m_bConnected == false; }
	
	// get the statement
	Statement* createStatement ();	

	// identity
	MYSQL* getMYSQL()             { return &m_Mysql; }
	string getHost() const        { return m_Host; }
	uint   getPort() const        { return m_Port; }
	string getDatabase() const    { return m_Database; }
	string getUser() const        { return m_User; }
	string getPassword() const    { return m_Password; }
	string getName() const        { return m_Name; }
	void   setName( string name ) { m_Name = name; }
	string getError()             { return mysql_error(&m_Mysql); }

	
///// Member data /////
	
private:

	MYSQL   m_Mysql;
	bool    m_bConnected;
	string  m_Host;
	uint    m_Port;
	string  m_Database;
	string  m_User;
	string  m_Password;
	string  m_Name;

};

extern Connection* g_pConnection;
extern Connection* g_pTransilConnection;
extern Connection* g_pWalaConnection;
extern Connection* g_pMoldaConnection;

//////////////////////////////////////////////////////////////////////////////
// class Statement
//////////////////////////////////////////////////////////////////////////////

class Statement 
{

///// Member data /////

public: // Constructor & destructor

	Statement(); 
	Statement(char* fmt, ... );
	~Statement() ;

public: // Public methods
	
	//   SQL   .
	Result* executeQuery();
	
	// SQL   .
	Result* executeQuery(char* fmt, ...);
	Result* executeQuery(string sqlStatement);
	
	// get SQL statement
	string getStatement() const { return m_Statement; }

	// SQL  .
	void setStatement(char* fmt, ...);

	// get connection object
	Connection* getConnection() const { return m_pConnection; }

	// set connection object
	void setConnection(Connection* pConnection) { m_pConnection = pConnection; }

	// get warning/error string
	string getError() const { return ( m_pConnection == NULL ) ? ("Not Associated with Connection Object") :( m_pConnection->getError() ); }

	// get affected rows
	uint getAffectedRowCount() const { return m_nAffectedRows; }


///// Member data /////
	
private:

	Connection* m_pConnection;   // Connection
	string      m_Statement;     // SQL Statement
	Result*     m_pResult;       // Query Result 
	uint        m_nAffectedRows; //   row  

};


//////////////////////////////////////////////////////////////////////////////
// class Result;
//////////////////////////////////////////////////////////////////////////////

#define T_RESULT MYSQL_RES

class Result 
{
	
///// Member methods /////
	
public: // Constructor & destructor

	Result(T_RESULT*);
	~Result();

public: // Public methods

	// iteration methods
	bool next();

	// get specific field
	char*  getField(uint index); 
	char   getChar(uint index)   { return (getField(index))[0]; }
	int    getInt(uint index)    { return atoi(getField(index)); }
	//long long    getLongLong(uint index)    { return atoi(getField(index)); }
	//long long    getLongLong(ulonglong index)    { return atoll(getField(index)); }
	long long    getLongLong(uint index)    { return atoll(getField(index)); }
	uint   getUInt(uint index)   { return (uint)atoi(getField(index)); }
	BYTE   getBYTE(uint index)   { return (BYTE)atoi(getField(index)); }
	WORD   getWORD(uint index)   { return (WORD)atoi(getField(index)); }
	DWORD  getDWORD(uint index)  { return (DWORD)atoi(getField(index)); }
	string getString(uint index) 
	{ 
		if ( getField(index) == NULL )
			return "";
		return string(getField(index)); 
	}

	// get count
	uint getRowCount() const { return m_RowCount; }
	uint getFieldCount() const { return m_FieldCount; }


///// Member data /////
	
private:

	T_RESULT*  m_pResult;    //   MYSQL structure
	MYSQL_ROW  m_pRow;       //    row
	uint       m_RowCount;   //    row 
	uint       m_FieldCount;

};

#endif // __DB_H__
