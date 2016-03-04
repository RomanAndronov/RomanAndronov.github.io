#include <stdio.h>
#include <string.h>
#include "librprt.h"

typedef struct
{
	rprt_t		rprtadt;
} rprtnwd_t;

extern size_t		rprtSizeOfnwd();
extern rprt_t*		rprtConstructnwd( void* );

static int		rprtWriteNWD( rprt_t*, int [], size_t, bio_t* );
static void		rprtDestructNWD( rprt_t* );
static const char*	rprtNameNWD();

static rprt_t	rprtAdtNWD = 
{ 
	rprtWriteNWD,
	rprtNameNWD,
	rprtSizeOfnwd,
	rprtDestructNWD
};

extern size_t
rprtSizeOfnwd()
{
	size_t		rv;

	rv = sizeof( rprtnwd_t );

	return rv;
}

extern rprt_t*
rprtConstructnwd( void* mem )
{
	rprt_t*		rv;
	rprtnwd_t*	rprtnwd = ( rprtnwd_t* )mem;

	rprtnwd->rprtadt = rprtAdtNWD;

	rv = &rprtnwd->rprtadt;

	return rv;
}

static void
rprtDestructNWD( rprt_t* rprt )
{
}

static int
rprtWriteNWD( rprt_t* rprt, int input[], size_t inputsz, bio_t* dst )
{
	size_t		i;
	size_t		j;
	char		b[ 512 + 1 ];
	size_t		bsz = sizeof( b ) - 1;
	rprtnwd_t*	rprtnwd = ( rprtnwd_t* )rprt;

	for ( i = 0; i < inputsz; i++ )
	{
		for ( j = 0; j < i && j < bsz; j++ )
		{
			b[ j ] = ' ';
		}
		snprintf( b + j,
			sizeof( b ) - strlen( b ),
			"%d\n",
			input[ i ] );
		bioWrite( dst, b, strlen( b ) );
	}

	return 1;
}

static const char*
rprtNameNWD()
{
	return "nwd";
}
