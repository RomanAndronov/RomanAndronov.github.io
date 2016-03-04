#include <stdio.h>
#include <string.h>
#include "librprt.h"

typedef struct
{
	rprt_t		rprtadt;
} rprtl_t;

extern size_t		rprtSizeOfl();
extern rprt_t*		rprtConstructl( void* );

static int		rprtWriteL( rprt_t*, int [], size_t, bio_t* );
static void		rprtDestructL( rprt_t* );
static const char*	rprtNameL();

static rprt_t	rprtAdtL = 
{ 
	rprtWriteL,
	rprtNameL,
	rprtSizeOfl,
	rprtDestructL
};

extern size_t
rprtSizeOfl()
{
	size_t		rv;

	rv = sizeof( rprtl_t );

	return rv;
}

extern rprt_t*
rprtConstructl( void* mem )
{
	rprt_t*		rv;
	rprtl_t*	rprtl = ( rprtl_t* )mem;

	rprtl->rprtadt = rprtAdtL;

	rv = &rprtl->rprtadt;

	return rv;
}

static void
rprtDestructL( rprt_t* rprt )
{
}

static int
rprtWriteL( rprt_t* rprt, int input[], size_t inputsz, bio_t* dst )
{
	size_t		i;
	char*		sp;
	char*		nl;
	char		b[ 512 + 1 ];
	rprtl_t*	rprtl = ( rprtl_t* )rprt;

	for ( i = 0; i < inputsz; i++ )
	{
		sp = " ";
		nl = "";
		if ( i == 0 )
		{
			sp = "";
		}
		if ( i == ( inputsz - 1 ) )
		{
			nl = "\n";
		}
		snprintf( b, sizeof( b ), "%s%d%s", sp, input[ i ], nl );
		bioWrite( dst, b, strlen( b ) );
	}

	return 1;
}

static const char*
rprtNameL()
{
	return "l";
}
