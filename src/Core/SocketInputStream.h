//////////////////////////////////////////////////////////////////////

// 

// Filename    : SocketInputStream.h 

// Written by  : reiot@ewestsoft.com

// Description :

// 

//////////////////////////////////////////////////////////////////////

//

// *Reiot's Notes*

//

// �ý��ۿ��� ���� ����ϰ� ���Ǵ� Ŭ�������� �ϳ��̴�.

// �ӵ��� ���������� ������ ��ġ�Ƿ�, ���� ���� �ӵ��� �����ϰ�

// �ʹٸ�, exception�� ���� re-write �϶�. 

//

// ���� nonblocking �� ������-�����-���� ���� �߻��Ѵٰ� ������,

// �̰��� NonBlockingIOException���� wrapping�ɶ� overhead�� �߻���

// Ȯ���� ���ٰ� �����ȴ�.

//

//////////////////////////////////////////////////////////////////////



#ifndef __SOCKET_INPUT_STREAM_H__

#define __SOCKET_INPUT_STREAM_H__



// include files

#include <cstring>

#include "Types.h"

#include "Exception.h"

#include "Socket.h"



// constant definitions

const uint DefaultSocketInputBufferSize = 81920;



// forward declaration

class Packet;



//////////////////////////////////////////////////////////////////////

//

// class SocketInputStream

//

//////////////////////////////////////////////////////////////////////



class SocketInputStream {



//////////////////////////////////////////////////

// constructor/destructor

//////////////////////////////////////////////////

public :

	

	// constructor

	SocketInputStream (Socket* sock, uint BufferSize = DefaultSocketInputBufferSize) throw (Error);

	

	// destructor

	virtual ~SocketInputStream () throw (Error);



	

//////////////////////////////////////////////////

// methods

//////////////////////////////////////////////////

public :

	

	// read data from stream (input buffer)

	uint read (char* buf, uint len) throw (ProtocolException, Error);

	uint read (string & str, uint len) throw (ProtocolException, Error);

	void readPacket (Packet* p, bool bSkipHeader = true) throw (ProtocolException, Error);



	template<typename T>

		uint read( T& buf ) throw (ProtocolException, Error);



/*	uint read (bool   & buf) throw (ProtocolException, Error) { return read((char*)&buf, szbool  ); }

	uint read (char   & buf) throw (ProtocolException, Error) { return read((char*)&buf, szchar  ); }

	uint read (uchar  & buf) throw (ProtocolException, Error) { return read((char*)&buf, szuchar ); }

	uint read (short  & buf) throw (ProtocolException, Error) { return read((char*)&buf, szshort ); }

	uint read (ushort & buf) throw (ProtocolException, Error) { return read((char*)&buf, szushort); }

	uint read (int    & buf) throw (ProtocolException, Error) { return read((char*)&buf, szint   ); }

	uint read (uint   & buf) throw (ProtocolException, Error) { return read((char*)&buf, szuint  ); }

	uint read (long   & buf) throw (ProtocolException, Error) { return read((char*)&buf, szlong  ); }

	uint read (ulong  & buf) throw (ProtocolException, Error) { return read((char*)&buf, szulong ); }

*/

	// peek data from stream (input buffer)

	bool peek (char* buf, uint len) throw (ProtocolException, Error);

	

	// skip data from stream (input buffer)

	void skip (uint len) throw (ProtocolException, Error);

	

	// fill stream (input buffer) from socket

	uint fill () throw (IOException, Error);

	uint fill_RAW () throw (IOException, Error);



	// resize buffer

	void resize (int size) throw (IOException, Error);

	

	// get buffer length

	uint capacity () const throw () { return m_BufferLen; }

	

	// get data length in buffer

	uint length () const throw ();

	uint size () const throw () { return length(); }



	// check if buffer is empty

	bool isEmpty () const throw () { return m_Head == m_Tail; }



	// get debug string

	string toString () const throw ();





//////////////////////////////////////////////////

// attributes

//////////////////////////////////////////////////

private :

	

	// socket

	Socket* m_pSocket;

	

	// buffer

	char* m_Buffer;

	

	// buffer length

	uint m_BufferLen;

	

	// buffer head/tail

	uint m_Head;

	uint m_Tail;



};





//////////////////////////////////////////////////////////////////////

//

// read data from input buffer

//

//////////////////////////////////////////////////////////////////////

template<typename T>

uint SocketInputStream::read ( T& buf ) 

	throw ( ProtocolException , Error )

{

	uint len = (uint)sizeof(T);



	// ��û�� ��ŭ�� ����Ÿ�� ���۳��� �������� ���� ��� ���ܸ� ������.

	// ���� ��� read �� peek() �� üũ�� �� ȣ��ȴٸ�, �Ʒ� if-throw �� 

	// �ߺ��� ���� �ִ�. ����, �ڸ�Ʈ�� ó���ص� �����ϴ�.

	// �� �Ʒ� �ڵ带 �ڸ�Ʈó���ϸ�, �ٷ� �Ʒ��� if-else �� 'if'-'else if'-'else'

	// �� ��������� �Ѵ�.

	if ( len > length() )

		throw InsufficientDataException( len - length() );

	

	if ( m_Head < m_Tail )	// normal order

	{

		//

        //    H   T

        // 0123456789

        // ...abcd...

        //

		buf = *(T*)(m_Buffer+m_Head);



	}

	else					// reversed order ( m_Head > m_Tail )

	{

		

        //

        //     T  H

        // 0123456789

        // abcd...efg

        //

		uint rightLen = m_BufferLen - m_Head;

		if ( len <= rightLen )

		{

			buf = *(T*)(m_Buffer+m_Head);

		}

		else

		{

			memcpy( (char*)&buf , &m_Buffer[m_Head] , rightLen );

			memcpy( ((char*)(&buf)+rightLen), m_Buffer, len - rightLen );

		}

	}



	m_Head = ( m_Head + len ) % m_BufferLen;

	

	return len;

		

//	__END_CATCH

}



#endif

