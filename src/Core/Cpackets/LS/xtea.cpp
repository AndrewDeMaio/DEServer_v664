#include "xtea.h"
//#include "portab.h"

#define min( a, b)	( a < b ? a:b)

typedef unsigned char BYTE;

int xor_key_init( pt_xor_key p, int counter )
{
	assert( p );
	assert( counter> 0 );
	assert( counter> 63 );

	p->key = (t_block_buffer *)malloc( sizeof(t_block_buffer) * counter );

	if( !p->key )
		return -1;
	
	p->round = counter;
	p->used=0;

	return 1;
}

int set_ctx_key( pt_xor_key a, const char *key)
{
	assert( a );
	assert( key );

	memset( &a->ctx, 0x00,sizeof(a->ctx) );
	memcpy( &a->ctx, key, sizeof(a->ctx) );
	return 0;
}

void key_encrypt( pt_ctx ctx, const void* input , void* output )
{
	const unsigned int *v = (const unsigned int*)input;
	unsigned int* w = (unsigned int*)output;

	register unsigned int y = v[0], z = v[1], sum = 0, n = XTEA_ROUNDS;
	register const unsigned int delta = XTEA_DELTA;

	while ( n-->0 )
	{
		y += (z << 4 ^ z >> 5) + z ^ sum + ctx->key[sum&3];
		sum += delta;
		z += (y << 4 ^ y >> 5) + y ^ sum + ctx->key[sum>>11 & 3];
	}

	w[0] = y; w[1] = z;
}

int get_xor_key( pt_xor_key a )
{
	int i;
	int iv[2];


	assert( a );
	assert( a->key );

	if ( a->used >= a->round )
		return 1;
	for ( i=0; i< a->round; i++ )
	{
		iv[0] = (int)(CTR_NOUNCE_64BIT & 0x00000000ffffffff);
		iv[1] = (int)(CTR_NOUNCE_64BIT >> 32);
		iv[0] *= (i+1);
		iv[1] *= (i+1);
		key_encrypt( &a->ctx, (const void*)iv, (void *)&a->key[i].v );
	}

	return 0;
}

void block_xor( void* dst, const void* src ) // BLOCK_SIZE supposed to be multiplier of 8 in bytes
{
	size_t i;

	for ( i = 0; i < BLOCK_SIZE/sizeof(long long); ++i )
	{
		((long long*)dst)[i] ^= ((const long long*)src)[i];
	}
}

int xor_key_encrypt( pt_xor_key a, const void* src, size_t src_size, void *dst, size_t* dst_size )
{
	unsigned char  out[BLOCK_SIZE];

	int p = (int)src_size;
	int round = 0;

	assert( src_size <= *dst_size );

	while ( p > 0 )
	{
		size_t src_block = src_size - (BLOCK_SIZE*round);
		size_t dst_block = *dst_size - (BLOCK_SIZE*round);
		memset( &out, 0x00, sizeof(out) );
		memcpy( &out, ((const unsigned char*)src)+(BLOCK_SIZE*round), min(BLOCK_SIZE, src_block) );

		block_xor( (void *)&out, (const void*)&a->key[round].v );

		memcpy( (BYTE *)dst+(BLOCK_SIZE*round), &out,  min(BLOCK_SIZE,dst_block) );

		//////////////////////////////////////////////////////////////////////////
		p -= BLOCK_SIZE;
		++round;
	}

#ifdef DEBUG_X
	{
		int i;
		for( i=0;i<src_size;i++)
			printf("%d ", (unsigned char ) *src+i);
		printf("\n");

		for( i=0;i<src_size;i++)
			printf("%d ", (unsigned char ) *dst+i);
		printf("\n");

	}
#endif

	*dst_size = src_size;
	return (int)*dst_size;
}
#ifdef DEBUG_XTEA
int main(void)
{
	t_xor_key xor_key;
	char b[2046];
	char d[2046];
	const char user[] = "nick shyblue\r\n";
	int c;

	xor_key_init( &xor_key, 64 );
	set_ctx_key( &xor_key, XTEA_KEY ); 
	get_xor_key( &xor_key );

	printf ("Original buf[%d] : [%s]\n",strlen(user), user );
	c = 2046;
	xor_key_encrypt( &xor_key, (const void *)user, strlen(user), (void *)b, (size_t *)&c );
	printf ("Encrypt buf[%d] : [%s]\n",c, b);
	c = 2046;
	xor_key_encrypt( &xor_key, (const void *)b, strlen(user), (void *)d, (size_t *)&c );
	d[c]='\0';
	printf ("Decrupt buf[%d] : [%s]\n",c, d);
	return 1;	
}
#endif
