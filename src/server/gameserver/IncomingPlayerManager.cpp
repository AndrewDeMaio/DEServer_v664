//////////////////////////////////////////////////////////////////////////////
// Filename    : IncomingPlayerManager.cpp
// Written by  : reiot@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "IncomingPlayerManager.h"
#include "Assert.h"
#include "SocketAPI.h"
#include "Socket.h"
#include "Player.h"
#include <algorithm>
#include "Properties.h"
#include "GamePlayer.h"
#include "LoginServerManager.h"
#include "PacketUtil.h"
#include "ZoneInfoManager.h"
#include "ZoneGroup.h"
#include "ZonePlayerManager.h"
#include "DB.h"
#include "LogClient.h"
#include "PaySystem.h"
#include "MasterLairManager.h"
#include "MikllizzLairManager.h"
//// �ﰡ�� �߰�
#include "HellGardenTowerManager.h"

#include "EventSurvivalZoneManager.h"
#include "Encrypter.h"
#include "LogDef.h"
#include "PlayerCreature.h"
#include "PKZoneInfoManager.h"
#include "CreatureUtil.h"

#include "Gpackets/GCUpdateInfo.h"
#include "Gpackets/GLIncomingConnection.h"
#include "Gpackets/GLKickVerify.h"

//#include "UserGateway.h"
#include "SystemAvailabilitiesManager.h"


//////////////////////////////////////////////////////////////////////////////
// constructor
// ���� �Ŵ��� �� ����Ÿ ������� �����Ѵ�.
//////////////////////////////////////////////////////////////////////////////

IncomingPlayerManager::IncomingPlayerManager () 
	throw (Error)
: m_pServerSocket(NULL), m_SocketID(INVALID_SOCKET), m_MinFD(-1), m_MaxFD(-1)
{
	__BEGIN_TRY

	m_Mutex.setName("IncomingPlayerManager");
	m_MutexOut.setName("IncomingPlayerManagerOut");
	m_PlayerListQueue.clear();

	try 
	{
		// create  server socket
		while ( 1 )
		{
			try
			{
				m_pServerSocket = new ServerSocket(g_pConfig->getPropertyInt("TCPPort"));
				break;
			}
			catch ( BindException& b )
			{
				SAFE_DELETE( m_pServerSocket );
				cout << "IncomingPlayerManager(" << g_pConfig->getPropertyInt("TCPPort") << ") : " << b.toString() << endl;
				sleep( 1);
			}
		}

		m_pServerSocket->setNonBlocking();

		// ���� ���� ��ũ���͸� �����Ѵ�.
		m_SocketID = m_pServerSocket->getSOCKET();
	} 
	catch (NoSuchElementException & nsee) 
	{
		// ȯ�� ���Ͽ� �׷� element�� ���� ���
		throw Error(nsee.toString());
	}

	g_pConnectionInfoManager = new ConnectionInfoManager();

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// destructor
//////////////////////////////////////////////////////////////////////////////

IncomingPlayerManager::~IncomingPlayerManager () 
	throw ()
{
	__BEGIN_TRY

	SAFE_DELETE(g_pConnectionInfoManager);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// ���� �Ŵ��� �� ������ ����� �ʱ�ȭ�Ѵ�.
//////////////////////////////////////////////////////////////////////////////

void IncomingPlayerManager::init ()
	throw (Error)
{
	__BEGIN_TRY

	// fd_set ���� 0 ���� �ʱ�ȭ�Ѵ�.
	FD_ZERO(&m_ReadFDs[0]);
	FD_ZERO(&m_WriteFDs[0]);
	FD_ZERO(&m_ExceptFDs[0]);

	//  ���� ������ ��Ʈ�� �Ҵ�. (write �� üũ�� �ʿ䰡 ����.)
	FD_SET(m_SocketID , &m_ReadFDs[0]);
	FD_SET(m_SocketID , &m_ExceptFDs[0]);

	// set min/max fd
	m_MinFD = m_MaxFD = m_SocketID;

	// m_Timeout �� �ʱ�ȭ�Ѵ�.
	// ���߿��� �� �ֱ� ���� �ɼ����� ó���ϵ��� ����.
	// ZonePlayerManager�� ���ؼ� �� �����ϴ�.....
	m_Timeout[0].tv_sec = 0;
	m_Timeout[0].tv_usec = 0;

	/*
	// connection info manager �� �ʱ�ȭ�Ѵ�.
	// ������ �α��μ����κ��� �޾ƾ� ������..
	// �ϴ� 210.220.188.161 ~ 180 ���� ����صд�.
	char buf[20];
	for (int i = 0 ; i < 20 ; i ++) 
	{
		sprintf(buf,"210.220.188.%d",161+i);
		ConnectionInfo* pConnectionInfo = new ConnectionInfo();
		pConnectionInfo->setClientIP(buf);
		g_pConnectionInfoManager.addConnectionInfo(pConnectionInfo);
	}
	*/

	string dist_host     = g_pConfig->getProperty("UI_DB_HOST");
	string dist_db       = "DARKEDEN";
	string dist_user     = g_pConfig->getProperty("UI_DB_USER");
	string dist_password = g_pConfig->getProperty("UI_DB_PASSWORD");
	uint dist_port		= 0;
	if ( g_pConfig->hasKey("UI_DB_PORT") )
		dist_port = g_pConfig->getPropertyInt("UI_DB_PORT");

	Connection* pDistConnection = new Connection(dist_host, dist_db, dist_user, dist_password, dist_port);
	g_pDatabaseManager->addDistConnection(((int)Thread::self()), pDistConnection);
	cout << "******************************************************" << endl;
	cout << " THREAD CONNECT UIIRIBUTION DB " << endl;
	cout << " TID Number = " << (int)Thread::self()<< endl;
	cout << "******************************************************" << endl;

	/*
    // Login DB �� PCRoomDBInfo Table �о Connection �����
    pStmt = pDistConnection->createStatement();
    Result * pResult = NULL;

    pResult = pStmt->executeQuery("SELECT ID, Host, DB, User, Password FROM PCRoomDBInfo");

    if (pResult->next())
    {
        WorldID_t ID = pResult->getInt(1);
        string host = pResult->getString(2);
        string db = pResult->getString(3);
        string user = pResult->getString(4);
        string password = pResult->getString(5);

        cout << "Connection: "
             << "  ID=" << (int)ID
             << ", HOST=" << host.c_str()
             << ", DB=" << db.c_str()
             << ", User=" << user.c_str() << endl;

        Connection * pConnection = new Connection(host, db, user, password);
        Assert(pConnection!=NULL);

        g_pDatabaseManager->addPCRoomConnection((int)(Thread::self()) , pConnection );
    }
	*/

	// Player.LogOn �� �������ش�.
    Statement * pStmt = NULL;
	Statement* pStmt2 = NULL;
	BEGIN_DB
	{
		//pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		//pStmt = g_pDatabaseManager->getDistConnection( (int)Thread::self() )->createStatement();
		//pStmt2 = g_pDatabaseManager->getDistConnection( (int)Thread::self() )->createStatement();

		pStmt = g_pDatabaseManager->getDistConnection( "PLAYER_DB" )->createStatement();
		pStmt2 = g_pDatabaseManager->getDistConnection( "PLAYER_DB" )->createStatement();

		Result* pResult = pStmt->executeQuery("SELECT PlayerID from Player WHERE LogOn='GAME' AND CurrentWorldID=%d AND CurrentServerGroupID=%d",
													g_pConfig->getPropertyInt("WorldID"), g_pConfig->getPropertyInt("ServerID") );

		// �׹濡�� ����ֵ� �������ش�.
		// ����~ by sigi 2002.5.31 
		while (pResult->next())
		{
			string playerID = pResult->getString(1);

			pStmt2->executeQuery( "DELETE FROM PCRoomUserInfo WHERE PlayerID='%s'",
						                    playerID.c_str());
		}

		pStmt->executeQuery("UPDATE Player SET LogOn = 'LOGOFF' WHERE LogOn = 'GAME' AND CurrentWorldID=%d AND CurrentServerGroupID=%d",
			g_pConfig->getPropertyInt("WorldID"), g_pConfig->getPropertyInt("ServerID") );

		/*
		// �ι� �ϴ°� ����. by sigi. 2002.5.9
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("DELETE FROM UserIPInfo WHERE ServerID = %d", g_pConfig->getPropertyInt("ServerID") );
		*/
		SAFE_DELETE(pStmt);
		SAFE_DELETE(pStmt2);
	}
	END_DB(pStmt)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		pStmt->executeQuery("DELETE FROM UserIPInfo WHERE ServerID = %d", g_pConfig->getPropertyInt("ServerID") );
		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::copyPlayers()
	    throw()
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	PlayerManager::copyPlayers();

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::broadcast (Packet* pPacket)
	throw (Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	for (int i = m_MinFD ; i <= m_MaxFD ; i ++) {
		if (i != m_SocketID && m_pPlayers[i] != NULL)
			m_pPlayers[i]->sendPacket(pPacket);
	}

    __LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// call select() system call
// �������� TimeoutException �� ������ �÷��̾�� ó������ �ʾƵ� �ȴ�.
//////////////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::select ()
	throw (TimeoutException , InterruptedException , Error)
{
	__BEGIN_TRY

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	// m_Timeout[0] �� m_Timeout[1] ���� �����Ѵ�.
	m_Timeout[1].tv_sec  = m_Timeout[0].tv_sec;
	m_Timeout[1].tv_usec = m_Timeout[0].tv_usec;

	// m_XXXFDs[0] �� m_XXXFDs[1] ���� �����Ѵ�.
	m_ReadFDs[1]   = m_ReadFDs[0];
	m_WriteFDs[1]  = m_WriteFDs[0];
	m_ExceptFDs[1] = m_ExceptFDs[0];

	try 
	{
		// ���� m_XXXFDs[1] �� ������ select() �� ȣ���Ѵ�.
		SocketAPI::select_ex(m_MaxFD + 1 , &m_ReadFDs[1] , &m_WriteFDs[1] , &m_ExceptFDs[1] , &m_Timeout[1]);
	} 
	/*
	// �ּ�ó�� by sigi. 2002.5.14
	catch (TimeoutException&) 
	{
		// do nothing
	} 
	*/
	catch (InterruptedException & ie) 
	{
		// �ñ׳��� �� ���� ����~~
		log(LOG_GAMESERVER_ERROR, "", "", ie.toString());
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)
	
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// process all players' inputs
// ���� ������ read flag�� ������ ���, ���ο� ������ �������Ƿ�
// �̸� ó���ϰ�, �ٸ� ������ read flag�� ������ ���, ���ο� ��Ŷ��
// �������Ƿ� �� �÷��̾��� processInput()�� ȣ���ϸ� �ȴ�.
//////////////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::processInputs () 
	throw (IOException , Error)
{
	__BEGIN_TRY

	//__ENTER_CRITICAL_SECTION(m_Mutex)

    if (m_MinFD == -1 && m_MaxFD == -1) // no player exist
	{ 
		//m_Mutex.unlock();
		return;
	}

	//copyPlayers();

	for (int i = m_MinFD ; i <= m_MaxFD ; i ++) 
	{
		if (FD_ISSET(i , &m_ReadFDs[1])) 
		{
			if (i == m_SocketID) 
			{
				//  ���� ������ ��� ���ο� ������ �����ߴٴ� ���̴�.
				// by sigi. 2002.12.8
				for (int i=0; i<50; i++)	// 50���� ���� - -;
				{
					if (!acceptNewConnection())
						break;
				}
			} 
			else 
			{
				if (m_pPlayers[i] != NULL) 
				{
					GamePlayer* pTempPlayer = dynamic_cast<GamePlayer*>(m_pPlayers[i]);
					Assert(pTempPlayer != NULL);
					Assert(m_pPlayers[i] != NULL);

					if (pTempPlayer->getSocket()->getSockError()) 
					{
						FILELOG_INCOMING_CONNECTION( "ICMPISocketErr.log", "[Input] PlayerID : %s, PlayerStatus : %d", pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );

						try 
						{
							// �̹� ������ ����Ǿ����Ƿ�, ��� ���۸� �÷����ؼ��� �ȵȴ�.
							pTempPlayer->disconnect(DISCONNECTED);
						} 
						catch (Throwable & t) 
						{
							cerr << t.toString() << endl;
						}


						// by sigi. 2002.12.30
//						UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_INPUT_ERROR );

						// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
						// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
						// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
						// ProcessCommand���� ������ٴ� ���̴�.
						deletePlayer(i);
						deleteQueuePlayer(pTempPlayer);

						Creature* pCreature = pTempPlayer->getCreature();
						if ( pCreature != NULL )
							pCreature->setValue(1);
						filelog( "ICMPDelete.txt", "Type[1] : %s", pTempPlayer->getID().c_str() );
						SAFE_DELETE(pTempPlayer);
					} 
					else 
					{
						try 
						{
							pTempPlayer->processInput();
						} 
						catch (ConnectException & ce) 
						{
							FILELOG_INCOMING_CONNECTION( "ICMPIConectionErr.log", "[Input] %s, PlayerID : %s, PlayerStatus : %d", ce.toString().c_str(), pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );
							// Blocking �����̹Ƿ�, ConnectException�� Error�� ������ � ���ܵ� �߻����� �ʴ´�.
							// ������ ������ ���, �α��ϰ� �÷��̾� ������ ������ �Ŀ� (�ε�Ǿ��ٸ�)
							// �÷��̾� ��ü�� �����Ѵ�.
							try 
							{
								pTempPlayer->disconnect();
							} 
							catch (Throwable & t) 
							{
								cerr << t.toString() << endl;
							}

							// by sigi. 2002.12.30
//							UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_INPUT_DISCONNECT );

							// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
							// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
							// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
							// ProcessCommand���� ������ٴ� ���̴�.
							deletePlayer(i);
							deleteQueuePlayer(pTempPlayer);

							Creature* pCreature = pTempPlayer->getCreature();
							if ( pCreature != NULL )
								pCreature->setValue(2);
							filelog( "ICMPDelete.txt", "Type[2] : %s", pTempPlayer->getID().c_str() );
							SAFE_DELETE(pTempPlayer);
						}
					} // else
				} // else
			} // if
		}
	}

//	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// process all players' commands
//////////////////////////////////////////////////////////////////////////////

void IncomingPlayerManager::processCommands() 
	throw (IOException , Error)
{
	__BEGIN_TRY
	__BEGIN_DEBUG

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	if (m_MinFD == -1 && m_MaxFD == -1) // no player exist
	{ 
		//m_Mutex.unlock();
		return;
	}

	//copyPlayers();

	for (int i = m_MinFD ; i <= m_MaxFD ; i ++) 
	{
		if (i != m_SocketID && m_pPlayers[i] != NULL) 
		{
			GamePlayer* pTempPlayer = dynamic_cast<GamePlayer*>(m_pPlayers[i]);
			Assert(pTempPlayer != NULL);
			Assert(m_pPlayers[i] != NULL);

			if (pTempPlayer->getSocket()->getSockError()) 
			{
				FILELOG_INCOMING_CONNECTION( "ICMPCSocketErr.log", "[Command] PlayerID : %s, PlayerStatus : %d", pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );
				try 
				{
					// �̹� ������ ����Ǿ����Ƿ�, ��� ���۸� �÷����ؼ��� �ȵȴ�.
					pTempPlayer->disconnect();
				} 
				catch (Throwable & t) 
				{
					cerr << t.toString() << endl;
				}

				// by sigi. 2002.12.30
//				UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_COMMAND_ERROR );

				// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
				// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
				// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
				// ProcessCommand���� ������ٴ� ���̴�.
				deletePlayer(i);
				deleteQueuePlayer(pTempPlayer);

				Creature* pCreature = pTempPlayer->getCreature();
				if ( pCreature != NULL )
					pCreature->setValue(3);
				try
				{
					filelog( "ICMPDelete.txt", "Type[3] : %s", pTempPlayer->getID().c_str() );
					SAFE_DELETE(pTempPlayer);
				}
				catch (Throwable& t)
				{
					cerr << t.toString() << endl;
					filelog( "Destructer.log", "IncommingPlayerManager.cpp +509 : %s" , t.toString().c_str() );
				}
			} 
			else 
			{
				try 
				{
					pTempPlayer->processCommand(false);
				} 
				catch (ProtocolException & pe) 
				{
					try 
					{
						FILELOG_INCOMING_CONNECTION( "ICMPCProtocolExcpt.log", "[Command] %s, PlayerID : %s, PlayerStatus : %d", pe.toString().c_str(), pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );
						pTempPlayer->disconnect();
					} 
					catch (Throwable & t) 
					{
						cerr << t.toString() << endl;
					}

					// by sigi. 2002.12.30
//					UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_COMMAND_DISCONNECT );

					// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
					// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
					// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
					// ProcessCommand���� ������ٴ� ���̴�.
					// 20080318 ���� ���� ������  ����ó�� �߰�
					try
					{
						deletePlayer(i);
						deleteQueuePlayer(pTempPlayer);
					}
					catch (NoSuchElementException & ne)
					{
						filelog( "deleteError.txt", "Error ID : %s", pTempPlayer->getID().c_str() );
					}

					Creature* pCreature = pTempPlayer->getCreature();
					if ( pCreature != NULL )
						pCreature->setValue(4);
					try
					{
						filelog( "ICMPDelete.txt", "Type[4] : %s", pTempPlayer->getID().c_str() );
						SAFE_DELETE(pTempPlayer);
					}
					catch (Throwable& t)
					{
						cerr << t.toString() << endl;
						filelog( "Destructer.log", "IncommingPlayerManager.cpp +509 : %s" , t.toString().c_str() );
					}
				}
				//--------------------------------------------------------------
				// Anything else that escapes processCommand().
				//
				// Only ProtocolException was caught above, so a plain Error --
				// which is what END_DB now throws for any SQL failure -- walked
				// all the way out to "UNHANDLED EXCEPTION" and killed the whole
				// gameserver because one player's row was unreadable. Several
				// missing columns during character load did exactly that.
				//
				// Drop that player, keep the server up, and record why.
				//--------------------------------------------------------------
				catch (Throwable & t)
				{
					filelog( "ICMPCThrowable.log", "[Command] %s, PlayerID : %s, PlayerStatus : %d",
						t.toString().c_str(),
						pTempPlayer->getID().c_str(),
						(int)pTempPlayer->getPlayerStatus() );

					try
					{
						pTempPlayer->disconnect();
					}
					catch (Throwable & t2)
					{
						filelog( "ICMPCThrowable.log", "[Disconnect] %s", t2.toString().c_str() );
					}

					deletePlayer(i);
					deleteQueuePlayer(pTempPlayer);

					try
					{
						filelog( "ICMPDelete.txt", "Type[9] : %s", pTempPlayer->getID().c_str() );
						SAFE_DELETE(pTempPlayer);
					}
					catch (Throwable & t3)
					{
						filelog( "Destructer.log", "IPM catch-all : %s", t3.toString().c_str() );
					}
				}
			}
		}
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_DEBUG
	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// process all players' outputs
//////////////////////////////////////////////////////////////////////////////

void IncomingPlayerManager::processOutputs () 
	throw (IOException , Error)
{
	__BEGIN_TRY

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	if (m_MinFD == -1 && m_MaxFD == -1) // no player exist
	{ 
		//m_Mutex.unlock();
		return;
	}

	//copyPlayers();

	for (int i = m_MinFD ; i <= m_MaxFD ; i ++) 
	{
		if (FD_ISSET(i , &m_WriteFDs[1])) 
		{
			if (i == m_SocketID)
			{
				FILELOG_INCOMING_CONNECTION( "ICMFD.txt", "[ i == m_SocketID ] FD : %d, ServerSocket : %d, MinFD : %d, MaxFD : %d, nPlayers : %d:", i, m_SocketID, m_MinFD, m_MaxFD, m_nPlayers );
				throw IOException("server socket's write bit is selected.");	
			}

			if (m_pPlayers[i] != NULL) 
			{
				GamePlayer* pTempPlayer = dynamic_cast<GamePlayer*>(m_pPlayers[i]);

				Assert( pTempPlayer != NULL );
				Assert(m_pPlayers[i] != NULL);

				if (pTempPlayer->getSocket()->getSockError()) 
				{
					FILELOG_INCOMING_CONNECTION( "ICMPOSocketErr.log", "[Output] PlayerID : %s, PlayerStatus : %d", pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );
					try 
					{
						// �̹� ������ ����Ǿ����Ƿ�, ��� ���۸� �÷����ؼ��� �ȵȴ�.
						pTempPlayer->disconnect(DISCONNECTED);
					} 
					catch (Throwable & t) 
					{
						cerr << t.toString() << endl;
					}

					// by sigi. 2002.12.30
//					UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_OUTPUT_ERROR );

					// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
					// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
					// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
					// ProcessCommand���� ������ٴ� ���̴�.
					deletePlayer(i);
					deleteQueuePlayer(pTempPlayer);

					Creature* pCreature = pTempPlayer->getCreature();
					if ( pCreature != NULL )
						pCreature->setValue(5);
					filelog( "ICMPDelete.txt", "Type[5] : %s", pTempPlayer->getID().c_str() );
					SAFE_DELETE(pTempPlayer);
				} 
				else 
				{
					try 
					{
						pTempPlayer->processOutput();
					} 
					catch (ConnectException & ce) 
					{
						FILELOG_INCOMING_CONNECTION( "ICMPOConnectExcept.log", "[Output] %s, PlayerID : %s, PlayerStatus : %d", ce.toString().c_str(), pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );
						StringStream msg;
						msg << "DISCONNECT " << pTempPlayer->getID() 
							<< "(" << ce.toString() << ")";
						log(LOG_GAMESERVER_ERROR, "", "", msg.toString());

						try 
						{
							// �̹� ������ ����Ǿ����Ƿ�, ��� ���۸� �÷����ؼ��� �ȵȴ�.
							pTempPlayer->disconnect(DISCONNECTED);
						} 
						catch (Throwable & t) 
						{
							cerr << t.toString() << endl;
						}

						// by sigi. 2002.12.30
//						UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_OUTPUT_DISCONNECT );

						// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
						// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
						// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
						// ProcessCommand���� ������ٴ� ���̴�.
						deletePlayer(i);
						deleteQueuePlayer(pTempPlayer);

						Creature* pCreature = pTempPlayer->getCreature();
						if ( pCreature != NULL )
							pCreature->setValue(6);
						filelog( "ICMPDelete.txt", "Type[6] : %s", pTempPlayer->getID().c_str() );
						SAFE_DELETE(pTempPlayer);
					} 
					catch (ProtocolException & cp) 
					{
						FILELOG_INCOMING_CONNECTION( "ICMPOProtocolExcept.log", "[Output] %s, PlayerID : %s, PlayerStatus : %d", cp.toString().c_str(), pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );
						StringStream msg;
						msg << "DISCONNECT " << pTempPlayer->getID() 
							<< "(" << cp.toString() << ")";
						log(LOG_GAMESERVER_ERROR, "", "", cp.toString());

						// �̹� ������ ����Ǿ����Ƿ�, ��� ���۸� �÷����ؼ��� �ȵȴ�.

						try 
						{
							pTempPlayer->disconnect(DISCONNECTED);
						} 
						catch (Throwable & t) 
						{
							cerr << t.toString() << endl;
						}

						// by sigi. 2002.12.30
//						UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_OUTPUT_DISCONNECT2 );

						// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
						// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
						// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
						// ProcessCommand���� ������ٴ� ���̴�.
						deletePlayer(i);
						deleteQueuePlayer(pTempPlayer);

						Creature* pCreature = pTempPlayer->getCreature();
						if ( pCreature != NULL )
							pCreature->setValue(7);
						filelog( "ICMPDelete.txt", "Type[7] : %s", pTempPlayer->getID().c_str() );
						SAFE_DELETE(pTempPlayer);
					}
				}
			}

			//pTempPlayer->processOutput();
		}
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////////////
// process all players' exceptions
// ��������� OOB ����Ÿ�� ������ ��ȹ�� ����.
// ����, ���� OOB�� ���� �ִٸ� ������ �����ϰ� ������ Ȯ ©�� ������.
//////////////////////////////////////////////////////////////////////////////

void IncomingPlayerManager::processExceptions () 
	throw (IOException , Error)
{
	__BEGIN_TRY

	//__ENTER_CRITICAL_SECTION(m_Mutex)

	if (m_MinFD == -1 && m_MaxFD == -1) // no player exist
	{ 
		//m_Mutex.unlock();
		return;
	}

	//copyPlayers();

	for (int i = m_MinFD ; i <= m_MaxFD ; i ++) 
	{
		if (FD_ISSET(i , &m_ExceptFDs[1])) 
		{
			if (i != m_SocketID) 
			{
				if (m_pPlayers[i] != NULL) 
				{
					GamePlayer* pTempPlayer = dynamic_cast<GamePlayer*>(m_pPlayers[i]);
					Assert(pTempPlayer != NULL );
					Assert(i != m_SocketID);
					Assert(m_pPlayers[i] != NULL);
					StringStream msg;
					msg << "OOB from " << pTempPlayer->toString();
					
					FILELOG_INCOMING_CONNECTION( "ICMPEOOB.log", "PlayerID : %s, PlayerStatus : %d", pTempPlayer->getID().c_str(), (int)pTempPlayer->getPlayerStatus() );
					try 
					{
						pTempPlayer->disconnect();
					} 
					catch (Throwable & t) 
					{
						//cerr << t.toString() << endl;
					} 

					// by sigi. 2002.12.30
//					UserGateway::getInstance()->passUser( UserGateway::USER_OUT_INCOMING_EXCEPTION );

					// �÷��̾ ���ٴ� ����? �ٸ� ������ ���� ���ų�,
					// �ٸ� ������ deletePlayer�� �ϴ� ���� ����.
					// ������ �� PlayerManager������ Player�� ���� �� �ִ�.
					// ProcessCommand���� ������ٴ� ���̴�.
					deletePlayer(i);
					deleteQueuePlayer(pTempPlayer);

					Creature* pCreature = pTempPlayer->getCreature();
					if ( pCreature != NULL )
						pCreature->setValue(8);
					filelog( "ICMPDelete.txt", "Type[8] : %s", pTempPlayer->getID().c_str() );
					SAFE_DELETE(pTempPlayer);
				}
			} 
			else 
			{
				//cerr << "Exception in Loginserver to Gameserver" << endl;
			}
		}
	}

	//__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}
	

//////////////////////////////////////////////////////////////////////////////
// select ��ݿ����� nonblocking ������ ������� �ʴ´�.
//////////////////////////////////////////////////////////////////////////////
bool IncomingPlayerManager::acceptNewConnection ()
	throw (Error)
{
	__BEGIN_TRY

	m_CheckValue = 0;
	
	int fd = -9999;
	int MinFD = (int)m_MinFD;
	int MaxFD = (int)m_MaxFD;

	// ����ŷ ������� connection�� ��ٸ� ���
	// ���ϵǴ� ���� ���� NULL�� �� �� ����.
	// ���� NonBlockingIOException�� �߻��� �� ����.
	Socket* client = NULL;

	try {
		m_CheckValue = 1;
		client = m_pServerSocket->accept();
		m_CheckValue = 2;
	} catch ( Throwable & t ) {
		m_CheckValue += 10000;
	}

	if (client == NULL) 
	{
		m_CheckValue = 50;
		return false;
	}

	try 
	{

		fd = (int)client->getSOCKET();
		FILELOG_INCOMING_CONNECTION("acceptNewConnection.log", "Accept FD : %d ( MinFD : %d , MaxFD : %d ) %s", fd, MinFD, MaxFD, client->getHost().c_str() );

		if (fd<=0 || fd>=nMaxPlayers)
		{
			FILELOG_INCOMING_CONNECTION("acceptNewConnectionError.log", "Accept FD : %d ( MinFD : %d , MaxFD : %d ) %s", fd, MinFD, MaxFD, client->getHost().c_str() );

			throw Error();
		}

		// ���� ó���� ���Ͽ� �־� �ξ��µ� ������ �� ������ �Ѵ�..
		// �Ƹ��� Thread�� ���� ���� �κп��� ������ ������ ������ ���� �Ѵ�
		// Thread ���� ó���� ������ ������ �ӽ÷� ����.
		if( client->getSockError() ) 
		{
			m_CheckValue = 4;
			throw Error();
		}

		m_CheckValue = 5;
		client->setNonBlocking();
		m_CheckValue = 6;

		// ���� ó���� ���Ͽ� �־� �ξ��µ� ������ �� ������ �Ѵ�..
		// �Ƹ��� Thread�� ���� ���� �κп��� ������ ������ ������ ���� �Ѵ�
		// Thread ���� ó���� ������ ������ �ӽ÷� ����.
		if( client->getSockError() ) 
		{
			m_CheckValue = 7;
			throw Error();
		}
		// set socket option (!NonBlocking, NoLinger)
		m_CheckValue = 8;
		client->setLinger(0);
		m_CheckValue = 9;

		StringStream msg;
		msg << "NEW CONNECTION FROM " << client->getHost() << ":" << client->getPort();
		log(LOG_GAMESERVER, "", "", msg.toString());
		m_CheckValue = 10;
		
		//----------------------------------------------------------------------
		// Incoming List �� �ִ��� �����Ѵ�.
		//----------------------------------------------------------------------
		// toString()���� CI == NULL �� �߻��ϱ⵵ �Ѵ�. -_-; ���� ���..

		// �� �ȿ��� ���ܰ� �߻��ϸ� ¥����.
		g_pConnectionInfoManager->getConnectionInfo(client->getHost());
		m_CheckValue = 11;

		// Ŭ���̾�Ʈ ������ �Ķ���ͷ� ����ؼ� �÷��̾� ��ü�� �����Ѵ�.
		GamePlayer* pGamePlayer = new GamePlayer(client);
		m_CheckValue = 12;

		// set player status to GPS_BEGIN_SESSION
		pGamePlayer->setPlayerStatus(GPS_BEGIN_SESSION);
		m_CheckValue = 13;
		
		// IPM �� ����Ѵ�.
		//addPlayer_NOBLOCKED(pGamePlayer);
		try 
		{
			m_CheckValue = 14;
			addPlayer(pGamePlayer);
			m_CheckValue = 15;

			// by sigi. 2002.12.30
//			UserGateway::getInstance()->passUser( UserGateway::USER_IN_NORMAL );
		}
		catch ( DuplicatedException & de) 
		{
			FILELOG_INCOMING_CONNECTION( "ancDupExcept.log", "[Output] %s, FD : %d ( MinFD : %d , MaxFD : %d ) %s", de.toString().c_str(), fd, MinFD, MaxFD, client->getHost().c_str() );

			m_CheckValue += 1000;
			client->close();
			m_CheckValue += 1000;
			SAFE_DELETE(client);
			m_CheckValue += 1000;
			SAFE_DELETE(pGamePlayer);
			m_CheckValue += 1000;
			//return true;
		}
	} 
	catch (NoSuchElementException&) 
	{
		FILELOG_INCOMING_CONNECTION( "ancNoSuch.log", "FD : %d ( MinFD : %d , MaxFD : %d ) %s", fd, MinFD, MaxFD, client->getHost().c_str() );

		m_CheckValue += 20000;
		m_CheckValue += 1000;
		StringStream msg2;
		msg2 << "ILLEGAL ACCESS FROM " << client->getHost() << ":" <<  client->getPort();
		log(LOG_GAMESERVER, "", "", msg2.toString());

		m_CheckValue += 1000;

		//----------------------------------------acceptNewConnection core!!!
		// �������� ���� �����̹Ƿ� ¥����. -_-;
		//client->send("Error : Unauthorized access",27);

		m_CheckValue += 1000;
		client->close();
		m_CheckValue += 1000;
		SAFE_DELETE(client);
		m_CheckValue += 1000;
	}
	catch (Throwable & t)
	{
		FILELOG_INCOMING_CONNECTION( "ancThrowable.log", "FD : %d ( MinFD : %d , MaxFD : %d ) %s checkValue : %d", fd, MinFD, MaxFD, client->getHost().c_str(), m_CheckValue );
		m_CheckValue += 30000;
		try
		{
			m_CheckValue = 25;
			if( client != NULL ) 
			{
				client->close();
				m_CheckValue = 26;
				SAFE_DELETE(client);
				m_CheckValue = 27;
			}
			m_CheckValue = 28;
		}
		catch (Throwable & t)
		{
			m_CheckValue += 1000;
		}
		catch (...)
		{
			m_CheckValue += 2000;
		}
	}
	catch (exception& e)
	{
		m_CheckValue += 40000;
		FILELOG_INCOMING_CONNECTION( "ancException.log", "FD : %d ( MinFD : %d , MaxFD : %d ) %s checkValue : %d", fd, MinFD, MaxFD, client->getHost().c_str(), m_CheckValue );
	}
	catch (...)
	{
		m_CheckValue += 50000;
		FILELOG_INCOMING_CONNECTION( "ancEtc.log", "FD : %d ( MinFD : %d , MaxFD : %d ) %s checkValue : %d", fd, MinFD, MaxFD, client->getHost().c_str(), m_CheckValue );
	}
	m_CheckValue = 33;

	return true;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// ���ο� ���ῡ ���õ� �÷��̾� ��ü�� IPM�� �߰��Ѵ�.
//
//////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::addPlayer (Player* pGamePlayer) 
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// call base class's method
	PlayerManager::addPlayer(pGamePlayer);

	SOCKET fd = pGamePlayer->getSocket()->getSOCKET();

	// m_MinFD , m_MaxFD �� �������Ѵ�.
	m_MinFD = min(fd , m_MinFD);
	m_MaxFD = max(fd , m_MaxFD);

	// ��� fd_set �� fd ��Ʈ�� on ��Ų��.
	// m_XXXFDs[1] �� �������� ó�����ָ� �ȴ�.
	FD_SET(fd , &m_ReadFDs[0]);
	FD_SET(fd , &m_WriteFDs[0]);
	FD_SET(fd , &m_ExceptFDs[0]);

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////
//
// ���ο� ���ῡ ���õ� �÷��̾� ��ü�� IPM�� �߰��Ѵ�.
//
//////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::addPlayer_NOBLOCKED (Player* pGamePlayer) 
	throw (DuplicatedException , Error)
{
	__BEGIN_TRY

	// call base class's method
	PlayerManager::addPlayer(pGamePlayer);

	SOCKET fd = pGamePlayer->getSocket()->getSOCKET();

	// m_MinFD , m_MaxFD �� �������Ѵ�.
	m_MinFD = min(fd , m_MinFD);
	m_MaxFD = max(fd , m_MaxFD);

	// ��� fd_set �� fd ��Ʈ�� on ��Ų��.
	// m_XXXFDs[1] �� �������� ó�����ָ� �ȴ�.
	FD_SET(fd , &m_ReadFDs[0]);
	FD_SET(fd , &m_WriteFDs[0]);
	FD_SET(fd , &m_ExceptFDs[0]);

	__END_CATCH
}

void IncomingPlayerManager::deletePlayer_NOBLOCKED (SOCKET fd) 
	throw (OutOfBoundException , NoSuchElementException , Error)
{
	__BEGIN_TRY

	// call base class's method
	PlayerManager::deletePlayer(fd);

	Assert(m_pPlayers[fd] == NULL);

	// m_MinFD , m_MaxFD �� �������Ѵ�.
	// fd == m_MinFD && fd == m_MaxFD �� ���� ù��° if ���� ó���ȴ�.
	if (fd == m_MinFD) 
	{
		// �տ������� ���� ���� fd �� ã�´�.
		// m_MinFD �ڸ��� ���� NULL �� �Ǿ� ������ �����϶�.
		int i = m_MinFD;
		for (i = m_MinFD ; i <= m_MaxFD ; i ++) {
			if (m_pPlayers[i] != NULL || i == m_SocketID) {
				m_MinFD = i;	
				break;
			}
		}

		// ������ m_MinFD�� ã�� ������ ���,
		// �̶����� m_MinFD == m_MaxFD �� ����̴�.
		// �̶����� �� �� -1 �� ����������.
		if (i > m_MaxFD)
			m_MinFD = m_MaxFD = -1;
	} 
	else if (fd == m_MaxFD) 
	{
		// �ڿ������� ���� ū fd �� ã�´�.
		// SocketID �� ������ ��! (SocketID �� ��� Player �����ʹ� NULL �̴�.)
		int i = m_MaxFD;
		for (i = m_MaxFD ; i >= m_MinFD ; i --) {
			if (m_pPlayers[i] != NULL || i == m_SocketID) {
				m_MaxFD = i;
				break;
			}
		}

		// ������ m_MinFD�� ã�� ������ ���,
		if (i < m_MinFD) {
			FILELOG_INCOMING_CONNECTION( "ICMFD.txt", "[ i < m_MinFD nbl] nPlayers : %d, MinFD : %d, MaxFD : %d, ServerSocket : %d", m_nPlayers, (int)m_MinFD, (int)m_MaxFD, (int)m_SocketID );
			throw UnknownError("m_MinFD & m_MaxFD problem.");
		}
	}

	// ��� fd_set �� fd ��Ʈ�� off ��Ų��.
	// m_XXXFDs[1]�� ���ľ� �ϴ� ������, ���� ó������ ��ü�� �������µ���
	// ó������ Ȯ���� �ֱ� �����̴�.
	FD_CLR(fd , &m_ReadFDs[0]);
	FD_CLR(fd , &m_ReadFDs[1]);
	FD_CLR(fd , &m_WriteFDs[0]);
	FD_CLR(fd , &m_WriteFDs[1]);
	FD_CLR(fd , &m_ExceptFDs[0]);
	FD_CLR(fd , &m_ExceptFDs[1]);

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
// Ư�� �÷��̾ IPM ���� �����Ѵ�.
//
// �÷��̾ IPM���� �����Ǵ� ������ ������ ����.
//
//  (1) ZPM���� ��ü�� �ű� --> �÷��̾� ��ü�� �����ϸ� �ȵȴ�.
//  (2) ���ӿ� ���� ���� ������ �����. --> �÷��̾� ��ü�� �����ؾ� �Ѵ�.
//
// ����, �÷��̾� ������ �ܺο��� �̷������ �Ѵ�.
//
//////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::deletePlayer (SOCKET fd) 
	throw (OutOfBoundException , NoSuchElementException , Error)
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	// call base class's method
	PlayerManager::deletePlayer(fd);

	Assert(m_pPlayers[fd] == NULL);

	// m_MinFD , m_MaxFD �� �������Ѵ�.
	// fd == m_MinFD && fd == m_MaxFD �� ���� ù��° if ���� ó���ȴ�.
	if (fd == m_MinFD) 
	{
		// �տ������� ���� ���� fd �� ã�´�.
		// m_MinFD �ڸ��� ���� NULL �� �Ǿ� ������ �����϶�.
		int i = m_MinFD;
		for (i = m_MinFD ; i <= m_MaxFD ; i ++) 
		{
			if (m_pPlayers[i] != NULL || i == m_SocketID) 
			{
				m_MinFD = i;	
				break;
			}
		}

		// ������ m_MinFD�� ã�� ������ ���,
		// �̶����� m_MinFD == m_MaxFD �� ����̴�.
		// �̶����� �� �� -1 �� ����������.
		if (i > m_MaxFD) m_MinFD = m_MaxFD = -1;
	} 
	else if (fd == m_MaxFD) 
	{
		// �ڿ������� ���� ū fd �� ã�´�.
		// SocketID �� ������ ��! (SocketID �� ��� Player �����ʹ� NULL �̴�.)
		int i = m_MaxFD;
		for (i = m_MaxFD ; i >= m_MinFD ; i --) {
			if (m_pPlayers[i] != NULL || i == m_SocketID) {
				m_MaxFD = i;
				break;
			}
		}

		// ������ m_MinFD�� ã�� ������ ���,
		if (i < m_MinFD) {
			FILELOG_INCOMING_CONNECTION( "ICMFD.txt", "[ i < m_MinFD ] nPlayers : %d, MinFD : %d, MaxFD : %d, ServerSocket : %d", m_nPlayers, (int)m_MinFD, (int)m_MaxFD, (int)m_SocketID );
			throw UnknownError("m_MinFD & m_MaxFD problem.");
		}
	}

	// ��� fd_set �� fd ��Ʈ�� off ��Ų��.
	// m_XXXFDs[1]�� ���ľ� �ϴ� ������, ���� ó������ ��ü�� �������µ���
	// ó������ Ȯ���� �ֱ� �����̴�.
	FD_CLR(fd , &m_ReadFDs[0]);
	FD_CLR(fd , &m_ReadFDs[1]);
	FD_CLR(fd , &m_WriteFDs[0]);
	FD_CLR(fd , &m_WriteFDs[1]);
	FD_CLR(fd , &m_ExceptFDs[0]);
	FD_CLR(fd , &m_ExceptFDs[1]);

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

GamePlayer* IncomingPlayerManager::getPlayer_NOBLOCKED (const string & id)
    throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	GamePlayer* pGamePlayer = NULL;

	for (int i = m_MinFD ; i <= m_MaxFD ; i ++) 
	{
		if (m_pPlayers[i] != NULL) 
		{
			if (m_pPlayers[i]->getID() == id) 
			{
				pGamePlayer = dynamic_cast<GamePlayer*>(m_pPlayers[i]);
				break;
			}
		}
	}

	if (pGamePlayer == NULL) 
		throw NoSuchElementException("�׷� ���̵� ���� �÷��̾�� �������� �ʽ��ϴ�.");

	return pGamePlayer;

	__END_CATCH

}

GamePlayer* IncomingPlayerManager::getPlayer (const string & id)
    throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	GamePlayer* pGamePlayer = NULL;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	pGamePlayer = getPlayer_NOBLOCKED(id);

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return pGamePlayer;

	__END_CATCH
}

GamePlayer* IncomingPlayerManager::getReadyPlayer (const string & id)
    throw (NoSuchElementException , Error)
{
	__BEGIN_TRY

	GamePlayer* pGamePlayer = NULL;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	list<GamePlayer *>::iterator itr = find_if (m_PlayerListQueue.begin(), m_PlayerListQueue.end(), isSamePlayerbyID(id));

	if (itr == m_PlayerListQueue.end()) 
	{
		throw NoSuchElementException();
	} 
	else 
	{
		pGamePlayer = (*itr);
		Assert(pGamePlayer != NULL);
	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	return pGamePlayer;

	__END_CATCH
}

void IncomingPlayerManager::pushPlayer(GamePlayer* pGamePlayer)
	throw(Error)
{
	__BEGIN_TRY

    __ENTER_CRITICAL_SECTION(m_Mutex)

    m_PlayerListQueue.push_back(pGamePlayer);

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	__END_CATCH
}

void IncomingPlayerManager::pushOutPlayer(GamePlayer* pGamePlayer)
	throw(Error)
{
	__BEGIN_TRY

    __ENTER_CRITICAL_SECTION(m_MutexOut)

    m_PlayerOutListQueue.push_back(pGamePlayer);

    __LEAVE_CRITICAL_SECTION(m_MutexOut)

	__END_CATCH
}

void IncomingPlayerManager::heartbeat()
	throw(Error) 
{
	__BEGIN_TRY

	__ENTER_CRITICAL_SECTION(m_Mutex)

	//--------------------------------------------------
	// PlayerQueue�� Player�� �޴����� �߰��Ѵ�.    
	//--------------------------------------------------

	// ZPM���� IPM���� ���� ���� Status�� ���� ó���ϴ� ����� �޶�����.
	// ZPM���� IPM���� ���� �������� �ΰ����� �ִ�.
	// 1. ���̵��� �� ��� GPS_WAITING_FOR_CG_READY ����.
	// 2. �α׾ƿ��� �� ��� GPS_AFTER_SENDING_GL_INCOMING_CONNECTION
	while(! m_PlayerListQueue.empty())
	{
		GamePlayer* pGamePlayer = m_PlayerListQueue.front();

		m_PlayerListQueue.pop_front();
		
		if (pGamePlayer == NULL)
		{
			filelog("ZoneBug.txt", "%s : %s", "IncomingPlayerManager::heartbeat(1)", "pGamePlayer�� NULL�Դϴ�.");
			continue;
		}

		//-----------------------------------------------------------------------------
		// * elcastle 's Note
		//-----------------------------------------------------------------------------
		// �Ѿ���� �������� KICKED �÷��װ� �ɷ� �ִٴ� ���� ������ ������ ���̴�.
		// �� ���� �׳� Disconnect ���ָ� �Ǵ� ���̴�.
		// �α׾ƿ��� �ϴ� ���� �� �ܰ迡�� KICKED�� �ɷ� ���� �ʴ�.
		// LGIncomingConnectionOK �ܰ迡�� KICKED �÷��װ� �ɷ� �����Ƿ� �򰥸��� ����.
		// �������� �α׾ƿ��� ��� �� üũ���� �ɸ��� ���� ���������� ���ϴ�.
		// ������ ����, ������ ���� ������ ��� ���⼭ ������ ���� ������ �ȴ�.
		// ���⼭ ���� ���� �ϰ��� �� �ϴ� ������ ������ Using �ڿ��� ���� Ŀ�η�����
		// �Ҿ����� ������ �������� �𸣴� ��츦 ����ؼ� �̴�.
		// ���������ε� �Ҿ����� ������ ��Ÿ���� �ִ�.
		//-----------------------------------------------------------------------------
		if( pGamePlayer->isPenaltyFlag(PENALTY_TYPE_KICKED) ) {
			// �̹� ������ ����Ǿ����Ƿ�, ��� ���۸� �÷����ؼ��� �ȵȴ�.
			int fd = -1;
			Socket* pSocket = pGamePlayer->getSocket();
			if (pSocket!=NULL)
				fd = (int)pSocket->getSOCKET();

			FILELOG_INCOMING_CONNECTION("incomingDisconnect.log", "FD : %d, %s", 
					fd, (pSocket==NULL? "NULL" : pSocket->getHost().c_str()) );

			// by sigi. 2002.12.30
			if (pGamePlayer->getReconnectPacket()!=NULL)
			{
//				UserGateway::getInstance()->passUser( UserGateway::USER_OUT_NORMAL );
			}
			else
			{
//				UserGateway::getInstance()->passUser( UserGateway::USER_OUT_KICKED );
			}

			try 
			{ 
				

				Creature* pCreature = pGamePlayer->getCreature();
				if ( pCreature != NULL )
				{
					//pCreature->setValue(9);
					filelog("LogoutBug.txt", "%s : %s", "���� ����", "pCreature ������ �־� ��� ���ϴ�.");
					//cout << "���� ���� �ɶ� Ŭ���� �ִ�." << endl;
					//g_GameDBExecuteManager.ForceLogoutSave(pCreature->getObjectID());
					
				//filelog( "ICMPDelete.txt", "Type[9] : %s, SecondParameter[%d], LastPacketID[%d]", pGamePlayer->getID().c_str(), pGamePlayer->getItemRatioBonusPoint(), pGamePlayer->getOldPacket((uint)0)->getPacketID() );
				}
				
				
				

				// Login�� �ϱ� ���ؼ� ������ �ִ� ĳ���͸� �����ϴ� ����̴�.
				// �� ����.. LoginServer�� ��� packet�� ������� �Ѵ�.
				// by sigi. 2002.5.4
				if (pGamePlayer->isKickForLogin())
				{
					// send GLKickVerify to LoginServer. 2002.5.6
					GLKickVerify glKickVerify;
					glKickVerify.setKicked(true);
					glKickVerify.setID( pGamePlayer->getSocket()->getSOCKET() );
					glKickVerify.setPCName( pGamePlayer->getCreature()->getName() );

					g_pLoginServerManager->sendPacket( pGamePlayer->getKickRequestHost(), 
														pGamePlayer->getKickRequestPort(), 
														&glKickVerify );

					cout << "LGKickVerify Send Packet to ServerIP : " << pGamePlayer->getKickRequestHost() << endl;
					cout << "LGKickVerify Send Packet to ServerPort : " << pGamePlayer->getKickRequestPort() << endl;
				}
				pGamePlayer->disconnect(DISCONNECTED);

			} 
			catch (Throwable & t) 
			{
				cerr << t.toString() << endl;
			}

			
			
			SAFE_DELETE(pGamePlayer);

			continue;
		}


		addPlayer_NOBLOCKED(pGamePlayer);

		//filelog("ZoneHeartbeatTrace.txt", "Added Player[%s]", pGamePlayer->getID().c_str());
	
		// �Ϻ��� Adding�� ���� ���� ������ ���� ó���� ���ش�. Status�� ����.
		// ZPM���� IPM���� �Ϻ��� �Ѿ�� ��쿡 �׿� ���� ��Ŷ�� ������.

		// ���̵��� �ϴ� ����̴�.
		if (pGamePlayer->getPlayerStatus() == GPS_WAITING_FOR_CG_READY) 
		{
			Creature * pCreature = pGamePlayer->getCreature();
			Assert(pCreature != NULL);

			Zone* pOldZone = pCreature->getZone();

			// by sigi. 2002.5.15
			Zone* pZone = pCreature->getNewZone();
			//Assert(pZone != NULL);

			if (pOldZone!=NULL)
			{
				// ������ ����� �÷��̾ ������ ���
				if (pOldZone->isMasterLair())
				{
					MasterLairManager* pMasterLairManager = pOldZone->getMasterLairManager();
					Assert(pMasterLairManager!=NULL);
					pMasterLairManager->leaveCreature( pCreature );
				}

				// ��Ŭ���� ����� �÷��̾ ������ ���
				if (pOldZone->isMikllizzLair())
				{
					MikllizzLairManager* pMikllizzLairManager = pOldZone->getMikllizzLairManager();
					Assert(pMikllizzLairManager != NULL );
					pMikllizzLairManager->leaveCreature( pCreature );
				}
				
				// �����̹� ������ �÷��̾ ������ ���
				if (pOldZone->isSurvivalZone())
				{
					EventSurvivalZoneManager* pEventSurvivalZoneManager = pOldZone->getEventSurvivalZoneManager();
					Assert(pEventSurvivalZoneManager != NULL);
					pEventSurvivalZoneManager->leaveCreature( pCreature );
				}

				// 2007 06 23
				if (pOldZone->isHellGardenTower())
				{
					HellGardenTowerManager* pHellGardenTowerManager = pOldZone->getHellGardenTowerManager();
 					Assert(pHellGardenTowerManager != NULL);
					pHellGardenTowerManager->leaveCreature( pCreature );
				}

				// PK ������ �÷��̾ ������ ���
				if (pCreature->isPLAYER() && pZone != NULL && pOldZone->getZoneID() != pZone->getZoneID())
				{
					if(g_pPKZoneInfoManager->isPKZone( pOldZone->getZoneID() )) g_pPKZoneInfoManager->leavePKZone( pOldZone->getZoneID() );
				}
			}

			if (pZone==NULL)
			{
				pZone = pCreature->getZone();
				Assert(pZone != NULL);
			}
			else
			{
				pCreature->setZone( pZone );
				pCreature->setNewZone( NULL );

				pCreature->setXY( pCreature->getNewX(), pCreature->getNewY() );

				// �� Zone�� ���� �Ǵ� ���
				pCreature->registerObject();
			}

			// ��ȣȭ �ڵ� ���. ������ objectID�� �ϱ� ������.. by sigi. 2002.11.27
#ifdef __USE_ENCRYPTER__
			pGamePlayer->setEncryptCode();
#endif

			#if defined(__PAY_SYSTEM_ZONE__) || defined(__PAY_SYSTEM_FREE_LIMIT__)
				// ����
				// ������ --> ���������� �� ��� 30���� ������ �������� ���� ���̴�.
				if ( ( pGamePlayer->isPayPlaying() || pGamePlayer->isPremiumPlay() )
					&& pGamePlayer->getPayType() == PAY_TYPE_TIME )
				{
					Assert( pCreature->isPC() );
					PlayerCreature* pPC = dynamic_cast<PlayerCreature*>(pCreature);
					Assert( pPC != NULL );

					if ( pPC->canPlayFree() && !pZone->isPayPlay() && !pZone->isPremiumZone() )
					{
						cout << "\\LogoutPayPlay:[" << (int)pZone->getZoneID() << "] "
								<< (int)pZone->isPayPlay() << " , "
								<< (int)pZone->isPremiumZone() << endl;
						pGamePlayer->logoutPayPlay( pGamePlayer->getID() );
					}
				}
			#endif

			// System Availabilities ������ �����ش�.
			SEND_SYSTEM_AVAILABILITIES(pGamePlayer);

			//--------------------------------------------------------------------------------
			// GCUpdateInfo ��Ŷ�� ����� ������.
			//--------------------------------------------------------------------------------
			GCUpdateInfo gcUpdateInfo;
			
			makeGCUpdateInfo(&gcUpdateInfo, pCreature);
			
			pGamePlayer->sendPacket(&gcUpdateInfo);

		// �α׾ƿ��� �ϴ� ����̴�.
		} else if (pGamePlayer->getPlayerStatus() == GPS_AFTER_SENDING_GL_INCOMING_CONNECTION) {

//			cout << "Logout..." << pGamePlayer->getID() << endl;

/*			Creature * pCreature = pGamePlayer->getCreature();

			// PK ������ �÷��̾ ������ ���
			if ( pCreature != NULL && g_pPKZoneInfoManager->isPKZone( pCreature->getZoneID() ))
			{
				g_pPKZoneInfoManager->leavePKZone( pCreature->getZoneID() );
			}
*/
   			// �α��� ������ GLIncomingConnection�� ������.
			// PlayerName�� ClientIP�� ���� �Ǿ ������.
			GLIncomingConnection glIncomingConnection;
			glIncomingConnection.setPlayerID(pGamePlayer->getID());
			glIncomingConnection.setClientIP(pGamePlayer->getSocket()->getHost());

			static int portNum = g_pConfig->getPropertyInt("LoginServerUDPPortNum");

			int port;
			
			if (portNum > 1)
			{
				port = g_pConfig->getPropertyInt("LoginServerBaseUDPPort") 
						+ rand()%portNum;
			}
			else
			{
				port = g_pConfig->getPropertyInt("LoginServerUDPPort");
			}
	
			//cout << "ReconnectAddress = " << g_pConfig->getProperty("LoginServerIP").c_str() << ":" << port << endl;

			/*
			if (g_pConfig->getProperty("User") == "excel96")
				g_pLoginServerManager->sendPacket(g_pConfig->getProperty("LoginServerIP") , port, &glIncomingConnection);
			else if (g_pConfig->getProperty("User") == "elcastle")
				g_pLoginServerManager->sendPacket(g_pConfig->getProperty("LoginServerIP") , port, &glIncomingConnection);
			else if (g_pConfig->getProperty("User") == "elca")
				g_pLoginServerManager->sendPacket(g_pConfig->getProperty("LoginServerIP") , port, &glIncomingConnection);
			*/

			// �׳� ������. by sigi. 2002.11.26
			g_pLoginServerManager->sendPacket(g_pConfig->getProperty("LoginServerIP") , port, &glIncomingConnection);
		}
	
		//filelog("ZoneHeartbeatTrace.txt", "After pop front");

	}

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	// ���� ��⿭�� �ִ� ����� ó�� �� �ش�.
	// ZPM���� ���� ������� ó���ϴ� �κ��̴�. ��� �߰� �ϸ� �� ���̴�.
	// ��� ������ ������ �˾Ʊ� ���ؼ� Creatue�� Zone�� �����ϹǷ� �̸� Zone�� ã�Ƽ� ������ �ξ�� �� ��.

	// by sigi. 2002.12.10
    __ENTER_CRITICAL_SECTION(m_MutexOut)

	while(!m_PlayerOutListQueue.empty()) {

		GamePlayer* pGamePlayer = m_PlayerOutListQueue.front();

		m_PlayerOutListQueue.pop_front();

		Assert(pGamePlayer != NULL);

		Creature * pCreature = pGamePlayer->getCreature();
//		Assert(pCreature != NULL); // 20080318 ���� ���� �������� �����Ѵ�.
		if(pCreature == NULL)
			continue;

		// getNewZone()�� ���� �� Zone�̴�.	 by sigi. 2002.5.11
		//Zone * pZone = pCreature->getZone();
		//Assert(pZone != NULL);
		Zone * pZone = pCreature->getNewZone();
		//Assert(pZone != NULL);

		// newZone�� ���� �ȵ����� ���� ������.. -_-;
		// load()�Ҷ��� NewZone������ ���Ѵ�.
		if (pZone==NULL)
		{
			pZone = pCreature->getZone();
			Assert(pZone != NULL);
		}

		// �� ���� PlayerManager�� ã�´�.
		ZoneGroup * pZoneGroup = pZone->getZoneGroup();
		Assert(pZoneGroup != NULL);
		ZonePlayerManager * pZonePlayerManager = pZoneGroup->getZonePlayerManager();
		Assert(pZonePlayerManager != NULL);

		// Push �Ѵ�.
		pZonePlayerManager->pushPlayer(pGamePlayer);


	}

    __LEAVE_CRITICAL_SECTION(m_MutexOut)

	__END_CATCH
}

void IncomingPlayerManager::deleteQueuePlayer(GamePlayer* pGamePlayer)
    throw(NoSuchElementException , Error)
{
	__BEGIN_TRY


	// �ʿ���� lock�ΰ� ����.
	// by sigi. 2002.5.9
	// �ٸ� lock���. 2002.12.10
	__ENTER_CRITICAL_SECTION(m_MutexOut)

	Assert(pGamePlayer != NULL);

	list<GamePlayer *>::iterator itr = find_if (m_PlayerOutListQueue.begin(), m_PlayerOutListQueue.end(), isSamePlayer(pGamePlayer));

	if (itr != m_PlayerOutListQueue.end()) {

		m_PlayerOutListQueue.erase(itr);

	}

	__LEAVE_CRITICAL_SECTION(m_MutexOut)

	__END_CATCH
}

////////////////////////////////////////////////////////////////////////
// IncomingPlayerManager �� �ִ� ��� ����ڸ� �����Ѵ�.
////////////////////////////////////////////////////////////////////////
void IncomingPlayerManager::clearPlayers()
	throw (Error)
{
	__BEGIN_TRY

	// PlayerListQueue �� �ִ� �ֵ��� �����Ѵ�.
	while ( !m_PlayerListQueue.empty() )
	{
		GamePlayer* pGamePlayer = m_PlayerListQueue.front();

		m_PlayerListQueue.pop_front();

		if ( pGamePlayer != NULL )
		{
			try
			{
				pGamePlayer->disconnect();
			}
			catch ( Throwable& t )
			{
				// ����
			}

			SAFE_DELETE( pGamePlayer );
		}
	}

	// PlayerOutListQueue �� �ִ� �ֵ��� �����Ѵ�.
	while ( !m_PlayerOutListQueue.empty() )
	{
		GamePlayer* pGamePlayer = m_PlayerOutListQueue.front();

		m_PlayerOutListQueue.pop_front();

		if ( pGamePlayer != NULL )
		{
			try
			{
				pGamePlayer->disconnect();
			}
			catch ( Throwable& t )
			{
				// ����
			}

			SAFE_DELETE( pGamePlayer );
		}
	}


	if ( m_MinFD == -1 && m_MaxFD == -1 )
		return;

	// �÷��̾ �����Ѵ�.
	for ( int i = m_MinFD; i <= m_MaxFD; i++ )
	{
		if ( i != m_SocketID && m_pPlayers[i] != NULL )
		{
			GamePlayer* pGamePlayer = dynamic_cast<GamePlayer*>(m_pPlayers[i]);

			if ( pGamePlayer != NULL )
			{
				try
				{
					pGamePlayer->disconnect();
				}
				catch ( Throwable& t )
				{
					// ����
				}

				SAFE_DELETE( pGamePlayer );
			}
		}
	}

	__END_CATCH
}


// external variable definition
IncomingPlayerManager* g_pIncomingPlayerManager = NULL;
