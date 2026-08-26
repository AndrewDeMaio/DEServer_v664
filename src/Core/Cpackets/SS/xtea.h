#ifndef QOOM_XTEA_DEFINED
#define QOOM_XTEA_DEFINED

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define XTEA_KEY 		"oi-0sd8-fv0-sdup"
#define XTEA_KEY_SIZE		16
#define XTEA_DELTA		0x9e3779b9
#define XTEA_ROUNDS		32
#define CTR_NOUNCE_64BIT	0x9BDC06A714292967LL
#define BLOCK_SIZE 		8

typedef struct _block_buffer
{
	unsigned char 	v[BLOCK_SIZE];
} t_block_buffer, *pt_block_buffer;

typedef struct _context
{
	unsigned long	key[4];
} t_ctx, *pt_ctx;

typedef struct _xor_key
{
	int		round;
	int		used;
	pt_block_buffer	key;
	t_ctx		ctx;
} t_xor_key, *pt_xor_key, XOR_KEY;


int xor_key_init( pt_xor_key p, int counter );
int set_ctx_key( pt_xor_key a, const char *key);
void key_encrypt( pt_ctx ctx, const void* input , void* output );
int get_xor_key( pt_xor_key a );
void block_xor( void* dst, const void* src );
int xor_key_encrypt( pt_xor_key a, const void* src, size_t src_size, void* dst, size_t* dst_size );
#endif
