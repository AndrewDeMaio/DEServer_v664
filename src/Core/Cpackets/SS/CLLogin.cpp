//////////////////////////////////////////////////////////////////////////////
// Filename    : CLLogin.cpp 
// Written By  : reiot@ewestsoft.com
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "libcpsso.h"
#include "CLLogin.h"

#include "Properties.h"

#ifdef __XTEA__
#include "xtea.h"
#endif //__XTEA__

void CLLogin::read (SocketInputStream & iStream) 
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY

#ifdef __LOGIN_SERVER__
#ifdef __NETMARBLE_SERVER__
	if (g_pConfig->getPropertyInt("IsNetMarble")==1)
	{
		setNetmarble(true);

		int szCpsso;
		iStream.read(szCpsso);

		if ( szCpsso == 0 )
			throw InvalidProtocolException("szID == 0");

		if ( szCpsso > 2048 )
			throw InvalidProtocolException("too large ID length");

		iStream.read( m_Cpsso , szCpsso );

		char id[30];
		char pw[30];
		char age[10];

		bool bRet = false;

		bRet = GetCPCookieValue( m_Cpsso.c_str(), "UserID", id);

		if (!bRet)
			throw InvalidProtocolException("Name Does Not Exist");

		bRet = GetCPCookieValue( m_Cpsso.c_str(), "UniID", pw);

		if (!bRet)
			throw InvalidProtocolException("UniID Does Not Exist");

		bRet = GetCPCookieValue( m_Cpsso.c_str(), "Age", age);

		if (!bRet)
			throw InvalidProtocolException("Age Does Not Exist");

		m_ID = id;
		m_Password = pw;

		int realage = atoi(age);

		// 디버깅
		cout << "ID : " << m_ID << endl;
		cout << "PW : " << m_Password << endl;
		cout << "Age : " << realage << endl;

		// 20080226 넷마블 수정
		setAdult(false);
		setChildren(false);
		setUnderFifthteen(false);

		if ( realage >= 18 )
		{
			setAdult(true);
		}
		else if( realage < 15 && realage >= 12)
		{
			setUnderFifthteen(true);
		}
		else if( realage < 12)
		{
			setChildren(true);
		}

/*		if ( realage >= 12 )
			setChildren( false );
		else
			setChildren( true );

		if ( realage < 12 )
			setUnderFifthteen( true );
		else
			setUnderFifthteen( false ); */
	}
	else
#endif
#endif

	{
		setNetmarble(false);

		BYTE szID;

		iStream.read(szID);

		if (szID == 0)
			throw InvalidProtocolException("szID == 0");

		if (szID > 30)
			throw InvalidProtocolException("too large ID length");

		iStream.read(m_ID , szID);

		BYTE szPassword;

		iStream.read(szPassword);

		if (szPassword == 0)
			throw InvalidProtocolException("szPassword == 0");

		if (szPassword > 32)
			throw InvalidProtocolException("too large password length");

		iStream.read(m_Password , szPassword);

#ifdef __XTEA__
		/*
		 * FIXME
		 * @brief  해킹관련 접수가 계속 들어오기 때문에 긴급 패치로 Client->Server의 CLLogin 패킷에서 
		 * 	   ID와 Password만 암호화해서 전송한다
		 * 	   따라서, 서버는 read부분에서 ID와 Password만 복호화 해서 m_ID, m_Password에 저장하면 된다.
		 *         시간도 없고, 아직 정확한 해킹의 원인도 모르기때문에 작성한 땜빵코드다. 반드시 고쳐야 한다.
		 *
		 * @issue  #1
		 * @Author shyblue@darkeden.com 2010.01.06
		 * @Date   2010.01.06
		 *
		 */
		t_xor_key XorKey;

		xor_key_init( &XorKey, 64 );
		set_ctx_key( &XorKey, XTEA_KEY );
		get_xor_key( &XorKey );

		size_t szIDDecrypt = (size_t) szID;
		string IDDecrypt;

		IDDecrypt.resize( m_ID.size() );
		xor_key_encrypt( &XorKey, (const void*)(m_ID.c_str()),(size_t)szID, (void *)(IDDecrypt.c_str()), &szIDDecrypt );
		m_ID = IDDecrypt;
		
		size_t szPWDecrypt = (size_t) szPassword;
		string PWDecrypt;

		PWDecrypt.resize( m_Password.size() );
		xor_key_encrypt( &XorKey, (const void*)(m_Password.c_str()),(size_t)szPassword, (void *)(PWDecrypt.c_str()), &szPWDecrypt );
		m_Password = PWDecrypt;
#endif // __XTEA__

		iStream.read((char*)m_cMacAddress, 6 * szBYTE);

		iStream.read( m_LoginMode );

		/* convert hex -> str */
		
		char	tmpStr[20];
		sprintf(tmpStr, "%02x%02x%02x%02x%02x%02x", m_cMacAddress[0],m_cMacAddress[1],m_cMacAddress[2],m_cMacAddress[3],m_cMacAddress[4],m_cMacAddress[5]);

		m_strMacAddress	= tmpStr;
		
	}

	__END_CATCH
}

void CLLogin::write (SocketOutputStream & oStream) const 
     throw (ProtocolException , Error)
{
	__BEGIN_TRY

	// 넷마블의 Cpsso 관련된 코드는 서버의 Write 에서는 고치지 않는다  (쓰이지 않으므로 ;;)
	// Client 에서만 알아서 처리해서 보내주도록 한다.
	BYTE szID = m_ID.size();

	if (szID == 0)
		throw InvalidProtocolException("empty ID");
	if (szID > 30)
		throw InvalidProtocolException("too large ID length");

	oStream.write(szID);

	oStream.write(m_ID);

	BYTE szPassword = m_Password.size();

	if (szPassword == 0)
		throw InvalidProtocolException("szPassword == 0");
	if (szPassword > 32)
		throw InvalidProtocolException("too large password length");

	oStream.write(szPassword);

	oStream.write(m_Password);
	oStream.write((char*)m_cMacAddress, 6 * sizeof(BYTE));

	oStream.write( m_LoginMode );

	__END_CATCH
}

void CLLogin::execute (Player* pPlayer) 
	 throw (ProtocolException , Error)
{
	__BEGIN_TRY
		
	CLLoginHandler::execute (this , pPlayer);
		
	__END_CATCH
}

string CLLogin::toString () const
	throw ()
{
	StringStream msg;
	msg << "CLLogin("
		<< "ID:" << m_ID 
		<< ",Password:" << m_Password 
		<< ")";
	return msg.toString();
}

PacketSize_t CLLogin::getPacketSize() const 
	throw()
{ 
	if (g_pConfig->getPropertyInt("IsNetMarble")==1)
	{
		return szint + m_Cpsso.size();
	}
	else
	{
		return szBYTE + m_ID.size() + szBYTE + m_Password.size() + 6 + szBYTE; 
	}
}

bool CLLogin::checkMacAddress(string lastMac) const 
	throw() 
{
	bool retValue = false;

	if(m_strMacAddress	== lastMac)	retValue = true;
	
	return retValue;     
}
