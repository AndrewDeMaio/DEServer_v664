//////////////////////////////////////////////////////////////////////
// 
// Filename    : LCLoginOK.cpp
// Written By  : Reiot
// Description : 
// 
//////////////////////////////////////////////////////////////////////

// include files
#include "LCLoginOK.h"

//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
void LCLoginOK::read ( SocketInputStream & iStream )
	throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	// ���� �׷� �̸��� �д´�.
	iStream.read( m_isAdult );
	iStream.read( m_bUnderFifthteen );
	iStream.read( m_bFamily );
	iStream.read( m_Stat );
	iStream.read( m_LastDays );
	// m_PayType �� ���� �ʴ´�. getPacketSize() �� ���� ����.

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
void LCLoginOK::write ( SocketOutputStream & oStream ) const
	throw ( ProtocolException , Error )
{
	__BEGIN_TRY

	// �׷� �̸��� ����.
	oStream.write( m_isAdult );
	oStream.write( m_bUnderFifthteen );
	oStream.write( m_bFamily );
	oStream.write( m_Stat );
	oStream.write( m_LastDays );
	// m_PayType �� ���� �ʴ´� -- Ŭ���̾�Ʈ�� __PAYZONE_PASS_TICKET __OFF ��
	// �о��� �ʰ�, ���� 7����Ʈ�� ������ "too large PacketSize ID)117 7/6" ��
	// �޴´�. �ʵ��� accessor �� DB �� Player.PayType �� �����ϹǷ� �����д�.

	cout << "**************" << m_LastDays << " �� ���ҽ��ϴ�." << endl;

	__END_CATCH
}


//////////////////////////////////////////////////////////////////////
// execute packet's handler
//////////////////////////////////////////////////////////////////////
void LCLoginOK::execute ( Player * pPlayer ) 
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY
		
	LCLoginOKHandler::execute( this , pPlayer );
		
	__END_CATCH
}


