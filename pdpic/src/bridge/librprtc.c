#include <stdio.h>
#include <string.h>
#include "librprt.h"

typedef struct
{
	rprt_t		rprtadt;
} rprtc_t;

extern size_t		rprtSizeOfc();
extern rprt_t*		rprtConstructc( void* );

static int		rprtWriteC( rprt_t*, int [], size_t, bio_t* );
static void		rprtDestructC( rprt_t* );
static const char*	rprtNameC();

static rprt_t	rprtAdtC = 
{ 
	rprtWriteC,
	rprtNameC,
	rprtSizeOfc,
	rprtDestructC
};

extern size_t
rprtSizeOfc()
{
	size_t		rv;

	rv = sizeof( rprtc_t );

	return rv;
}

extern rprt_t*
rprtConstructc( void* mem )
{
	rprt_t*		rv;
	rprtc_t*	rprtc = ( rprtc_t* )mem;

	rprtc->rprtadt = rprtAdtC;

	rv = &rprtc->rprtadt;

	return rv;
}

static void
rprtDestructC( rprt_t* rprt )
{
}

static int
rprtWriteC( rprt_t* rprt, int input[], size_t inputsz, bio_t* dst )
{
	size_t		i;
	char		b[ 512 + 1 ];
	rprtc_t*	rprtc = ( rprtc_t* )rprt;

	for ( i = 0; i < inputsz; i++ )
	{
		snprintf( b, sizeof( b ), "%d\n", input[ i ] );
		bioWrite( dst, b, strlen( b ) );
	}

	return 1;
}

static const char*
rprtNameC()
{
	return "c";
}
