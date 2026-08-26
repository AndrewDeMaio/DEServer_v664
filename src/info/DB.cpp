//////////////////////////////////////////////////////////////////////////////
// Filename    : DB.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include <stdio.h>
#include <stdarg.h>
#include <sys/time.h>
#include <mysql/mysql.h>
#include <assert.h>

//////////////////////////////////////////////////////////////////////////////
// global varibles
//////////////////////////////////////////////////////////////////////////////
Connection* g_pConnection = NULL;
Connection* g_pTransilConnection = NULL;
Connection* g_pWalaConnection = NULL;
Connection* g_pMoldaConnection = NULL;

//////////////////////////////////////////////////////////////////////////////
// class Connection
//////////////////////////////////////////////////////////////////////////////

Connection::Connection ()
{
	m_bConnected = false;
	
	// MYSQL  .
	if ( mysql_init(&m_Mysql) == NULL ) 
	{
		cout << mysql_error(&m_Mysql);
		return;
	}
}

Connection::Connection (string host, string db, string user, string password, uint port)
{
	m_bConnected = false;
 	m_Host       = host;
	m_Port       = port;
	m_Database   = db;
	m_User       = user;
	m_Password   = password;

	// MYSQL  .
	if (mysql_init(&m_Mysql) == NULL)
	{
		cout << mysql_error(&m_Mysql);
		return;
	}

	//   .
	connect(m_Host, m_Database, m_User, m_Password, m_Port);
}

Connection::~Connection() 
{
	if (m_bConnected) 
	{
		close();
	}
}

void Connection::connect(string host, string db, string user, string password, uint port)
{
	m_Host     = host;
	m_Port     = port;
	m_Database = db;
	m_User     = user;
	m_Password = password;

	connect();
}
	
void Connection::connect ()
{
	//       .
	if ( m_bConnected ) 
	{
		//  ,       .
		close();
		cout << "Already Connected"; 
		return;
	}

	//    ...
	m_bConnected = (mysql_real_connect(&m_Mysql, m_Host.c_str(), m_User.c_str(), m_Password.c_str(), m_Database.c_str(), m_Port, 0, 0) != NULL);
	
	//   .
	if(!m_bConnected) 
	{
		cout << mysql_error(&m_Mysql);
		return;
	}
}

void Connection::close () 
{
	if( ! m_bConnected ) 
	{
		cout << "Not Connected" << endl;
		return;
	}
	mysql_close(&m_Mysql);
	m_bConnected = false;
}

Statement* Connection::createStatement ()
{
	//  Statement  .
	Statement* pStatement = new Statement();
	
	//        ..
	pStatement->setConnection(this);
	
	// .
	return pStatement;
}

//////////////////////////////////////////////////////////////////////////////
// class Statement
//////////////////////////////////////////////////////////////////////////////

Statement::Statement() 
{
	m_pConnection   = NULL;
	m_pResult       = NULL;
	m_nAffectedRows = 0;
}

Statement::Statement ( char * fmt , ... ) 
{
	// variable argument list
	va_list valist;
	
	va_start( valist , fmt );
	
	char buffer[2048];
	
	int nchars = vsnprintf( buffer, 2048, fmt, valist );

	//     ,      .
	if ( nchars == -1 || nchars > 2048 )
	{
		cout << "more buffer size needed for SQL statement buffer...";
		return;
	}
	
	va_end(valist);
	
	// string   . 
	//  char * , local variable   .
	m_Statement = buffer;
}

Statement::~Statement() 
{
	if ( m_pResult != NULL ) 
	{
		delete m_pResult;
		m_pResult = NULL;
	}
}

Result* Statement::executeQuery()
{
	assert( m_pConnection != NULL );

	//  Result    ,
	if ( m_pResult != NULL ) 
	{
		delete m_pResult;
		m_pResult = NULL;
	}

	if (mysql_real_query(m_pConnection->getMYSQL(), m_Statement.c_str(), m_Statement.size()) != 0)
	{
		cout << getError() << endl;
		return NULL;
	}
	
	MYSQL_RES* pResult = mysql_store_result( m_pConnection->getMYSQL() );
	
	//   NULL  update .
	if ( pResult )
	{
		m_pResult = new Result( pResult );
	}
	else 
	{
		//if ( mysql_num_fields( m_pConnection->getMYSQL() ) != 0 )
		if ( mysql_field_count ( m_pConnection->getMYSQL() ) != 0 )
		{
			cout << getError() << endl;
			return NULL;
		}
		else
		{
			m_nAffectedRows = mysql_affected_rows( m_pConnection->getMYSQL() );
		}
	}

	return m_pResult;
}

Result* Statement::executeQuery ( string sqlStatement )
{
	m_Statement = sqlStatement;
	return executeQuery();
}	
	
Result* Statement::executeQuery(char* fmt, ... ) 
{
	// SQL Statement  .
	va_list valist;

	va_start(valist, fmt);

	char buffer[2048+1];

	int nchars = vsnprintf( buffer, 2048, fmt, valist );

	//     ,     .
	if ( nchars == -1 || nchars > 2048 )
	{
		cout << "more buffer size needed for SQL statement buffer...";
		return NULL;
	}

	va_end(valist);

	m_Statement = buffer;

	return executeQuery();
}	
	
void Statement::setStatement (char* fmt, ... ) 
{
	// variable argument list
	va_list valist;
	
	va_start( valist, fmt );
	
	// buffer size = 1kb..Too big??
	char buffer[2048+1];
	
	int nchars = vsnprintf( buffer, 2048 , fmt, valist );
	
	//     ,     .
	if ( nchars == -1 || nchars > 2048 )
	{
		cout << "more buffer size needed for SQL statement buffer...";
		return;
	}

	va_end(valist);
	
	m_Statement = buffer;
}


//////////////////////////////////////////////////////////////////////////////
// class Result
//////////////////////////////////////////////////////////////////////////////

Result::Result ( T_RESULT * pResult ) 
{
	m_pResult = pResult;
	m_pRow    = NULL;

	assert( m_pResult != NULL );

	// #rows  .
	m_RowCount = mysql_num_rows( m_pResult );
	m_FieldCount = mysql_num_fields(m_pResult);
}

Result::~Result () 
{
	if ( m_pResult != NULL ) 
	{
		mysql_free_result( m_pResult );
		m_pResult = NULL;
	}
}

bool Result::next () 
{
	assert( m_pResult != NULL );
	return ( m_pRow = mysql_fetch_row(m_pResult) ) != NULL;
}

char * Result::getField ( uint index ) 
{
	if ( m_pRow == NULL )
	{
		cout << "please call Result::next()" << endl;
		return NULL;
	}

	if ( index == 0 || index > m_FieldCount )
	{
		cout << "Out of Bound!" << endl;
		return NULL;
	}
	
	return m_pRow[index-1];
}

