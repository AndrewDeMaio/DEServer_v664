//////////////////////////////////////////////////////////////////////

// 

// SocketOutputStream.h 

// 

// by Reiot

// 

//////////////////////////////////////////////////////////////////////



#ifndef __SOCKET_OUTPUT_STREAM_H__

#define __SOCKET_OUTPUT_STREAM_H__



// include files

#include <cstring>

#include "Types.h"

#include "Exception.h"

#include "Socket.h"



// constant definitions

const unsigned int DefaultSocketOutputBufferSize = 81920;



// forward declaration

class Packet;



//////////////////////////////////////////////////////////////////////

//

// class SocketOutputStream

//

//////////////////////////////////////////////////////////////////////



class SocketOutputStream {



//////////////////////////////////////////////////

// constructor/destructor

//////////////////////////////////////////////////

public :

	

	// constructor

	SocketOutputStream (Socket* sock, uint BufferSize = DefaultSocketOutputBufferSize) throw (Error);

	

	// destructor

	virtual ~SocketOutputStream () throw (Error);



	

//////////////////////////////////////////////////

// methods

//////////////////////////////////////////////////

public :

	

	// write data to stream (output buffer)

	// *CAUTION*

	// string �� ���ۿ� writing �� ��, �ڵ����� size �� �տ� ���� ���� �ִ�.

	// �׷���, string �� ũ�⸦ BYTE/WORD �� ��� ������ �� ������ �ǹ��̴�.

	// ��Ŷ�� ũ��� ���� ���� ���ٴ� ��å�Ͽ��� �ʿ信 ���� string size ����

	// BYTE �Ǵ� WORD �� �������� ����ϵ��� �Ѵ�.

	uint write (const char* buf, uint len) throw (Error);

	uint write (const string & buf) throw (Error) { return write(buf.c_str(),buf.size()); }

	void writePacket (const Packet* pPacket) throw (ProtocolException, Error);

	

	template<typename T>

		uint write( T buf ) throw (Error);

/*	uint write (bool   buf) throw (ProtocolException, Error) { return write((const char*)&buf, szbool  ); }

	uint write (char   buf) throw (ProtocolException, Error) { return write((const char*)&buf, szchar  ); }

	uint write (uchar  buf) throw (ProtocolException, Error) { return write((const char*)&buf, szuchar ); }

	uint write (short  buf) throw (ProtocolException, Error) { return write((const char*)&buf, szshort ); }

	uint write (ushort buf) throw (ProtocolException, Error) { return write((const char*)&buf, szushort); }

	uint write (int    buf) throw (ProtocolException, Error) { return write((const char*)&buf, szint   ); }

	uint write (uint   buf) throw (ProtocolException, Error) { return write((const char*)&buf, szuint  ); }

	uint write (long   buf) throw (ProtocolException, Error) { return write((const char*)&buf, szlong  ); }

	uint write (ulong  buf) throw (ProtocolException, Error) { return write((const char*)&buf, szulong ); }

*/

	// flush stream (output buffer) to socket

	uint flush () throw (IOException, ProtocolException, InvalidProtocolException, Error);



	// resize buffer 

	void resize (int size) throw (IOException, Error);



	// get buffer length

	int capacity () const throw () { return m_BufferLen; }

 

    // get data length in buffer

    uint length () const throw ();

    uint size () const throw () { return length(); }



	// get data in buffer

	char* getBuffer() const { return m_Buffer; }

 

    // check if buffer is empty

    bool isEmpty () const throw () { return m_Head == m_Tail; }



    // get debug string

    string toString () const throw ()

    {

        StringStream msg;

        msg << "SocketOutputStream(m_BufferLen:"<<m_BufferLen<<",m_Head:"<<m_Head<<",m_Tail:"<<m_Tail

<<")";

        return msg.toString();

    }



//////////////////////////////////////////////////

// attributes

//////////////////////////////////////////////////

private :

	

	// socket

	Socket* m_Socket;

	

	// output buffer

	char* m_Buffer;

	

	// buffer length

	uint m_BufferLen;

	

	// buffer head/tail

	uint m_Head;

	uint m_Tail;



	// Total bytes handed to write() since this stream was created.
	// writePacket() uses it to verify a packet body really is as long as its
	// getPacketSize() claims. m_Tail cannot be used for that, because
	// resize() repacks the ring buffer and moves it.

	uint m_WriteCounter;



};





//////////////////////////////////////////////////////////////////////

//

// write data to stream (output buffer)

//

// *Notes*

//

// ( ( m_Head = m_Tail + 1 ) ||  

//   ( ( m_Head == 0 ) && ( m_Tail == m_BufferLen - 1 ) )

//

// �� �� ���� full �� �����Ѵٴ� ���� ���� ����. ����, ������ ��

// ������ ũ��� �׻� 1 �� ����� �Ѵٴ� ���!

//

//////////////////////////////////////////////////////////////////////

template<typename T>

uint SocketOutputStream::write ( T buf ) 

     throw ( Error )

{

	__BEGIN_TRY



	uint len = sizeof(T);

		

	// ���� ������ �� ������ ����Ѵ�.

	// (!) m_Head > m_Tail�� ��쿡 m_Head - m_Tail - 1 �� �����ߴ�. by sigi. 2002.9.16

	// �ٵ� buffer_resize�� �� ���� �Ͼ��. �ٸ��� ������ �ִµ� �ϴ� �� ã�����Ƿ�.. back. by sigi. 2002.9.23

	// �׽�Ʈ �غ��ϱ�.. �������̾���. ������ buffer resize�� ����� �Ͼ�� ������ ����? �ٽ� ����. by sigi. 2002.9.27

	uint nFree = ( ( m_Head <= m_Tail ) ?  m_BufferLen - m_Tail + m_Head - 1 : m_Head - m_Tail - 1 );

					//m_Tail - m_Head - 1 );



	// ������ �ϴ� ����Ÿ�� ũ�Ⱑ �� ������ ũ�⸦ �ʰ��� ��� ���۸� ������Ų��.

	if ( len >= nFree )

		resize( len - nFree + 1 );

		

	if ( m_Head <= m_Tail )		// normal order

	{

		//

		//    H   T

		// 0123456789

		// ...abcd...

		//

		

		if ( m_Head == 0 )

		{

			nFree = m_BufferLen - m_Tail - 1;

			*((T*)(m_Buffer+m_Tail)) = buf;

		}

		else

		{

			nFree = m_BufferLen - m_Tail;

			if ( len <= nFree )

			{

				*((T*)(m_Buffer+m_Tail)) = buf;

			}

			else

			{

				memcpy( &m_Buffer[m_Tail] , (char *)&buf , nFree );

				memcpy( m_Buffer , (((char*)&buf)+nFree), len - nFree );

			}

		}

	} 

	else						// reversed order

	{

		//

		//     T  H

		// 0123456789

		// abcd...efg

		//

		*((T*)(m_Buffer+m_Tail)) = buf;

	}



	// advance m_Tail

	m_Tail = ( m_Tail + len ) % m_BufferLen;

	m_WriteCounter += len;



	return len;

	

	__END_CATCH

}



#endif

