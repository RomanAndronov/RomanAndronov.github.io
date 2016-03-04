#include <stdio.h>
#include "libbio.h"

typedef struct
{
	bio_t		bioadt;

	bio_t*		nextDecorator;
} bioxc_t;

/*
   The names of these functions must
   adhere to the chosen naming convention.
   Their linkage specification is "extern".
 */
extern size_t		bioSizeOfxc();
extern bio_t*		bioConstructxc( void* );

/*
   The names of these functions are arbitrary but their
   prototypes must conform to the ones announced in
   libbio.h public header file. The linkage specification
   of these functions may be "static".
 */
static int		bioOpenXC( bio_t*, const char* );
static ssize_t		bioReadXC( bio_t*, void*, size_t );
static ssize_t		bioWriteXC( bio_t*, void*, size_t );
static int		bioCloseXC( bio_t* );
static void		bioDestructXC( bio_t* );
static const char*	bioNameXC();
static bio_t*		bioSetNextDecoratorXC( bio_t*, bio_t* );
static bio_t*		bioGetNextDecoratorXC( bio_t* );

static bio_t	bioAdtXC = 
{ 
	bioOpenXC,
	bioReadXC,
	bioWriteXC,
	bioCloseXC,
	bioNameXC,
	bioSizeOfxc,
	bioSetNextDecoratorXC,
	bioGetNextDecoratorXC,
	bioDestructXC
};

static void		xcipher( char*, size_t, char );

extern size_t
bioSizeOfxc()
{
	size_t		rv;

	rv = sizeof( bioxc_t );

	return rv;
}

extern bio_t*
bioConstructxc( void* mem )
{
	bio_t*		rv;
	bioxc_t*	xc = ( bioxc_t* )mem;

	xc->bioadt = bioAdtXC;

	rv = &xc->bioadt;

	return rv;
}

static void
bioDestructXC( bio_t* bio )
{
}

static int
bioOpenXC( bio_t* bio, const char* adrs )
{
	int		rv = 0;
	bioxc_t*	xc = ( bioxc_t* )bio;

	if ( xc->nextDecorator )
	{
		rv = bioOpen( xc->nextDecorator, adrs );
	}

	return rv;
}

static ssize_t
bioReadXC( bio_t* bio, void* b, size_t bsz )
{
	size_t		n = 0;
	bioxc_t*	xc = ( bioxc_t* )bio;

	if ( xc->nextDecorator )
	{
		n = bioRead( xc->nextDecorator, b, bsz );
		xcipher( ( char* )b, n, 'd' );
	}

	return n;
}

static ssize_t
bioWriteXC( bio_t* bio, void* b, size_t bsz )
{
	size_t		n = 0;
	bioxc_t*	xc = ( bioxc_t* )bio;

	if ( xc->nextDecorator )
	{
		xcipher( ( char* )b, bsz, 'e' );
		n = bioWrite( xc->nextDecorator, b, bsz );
	}

	return n;
}

static int
bioCloseXC( bio_t* bio )
{
	int		rv = 0;
	bioxc_t*	xc = ( bioxc_t* )bio;

	if ( xc->nextDecorator )
	{
		rv = bioClose( xc->nextDecorator );
	}

	return rv;
}

static const char*
bioNameXC()
{
	return "xc";
}

static bio_t*
bioSetNextDecoratorXC( bio_t* bio, bio_t* nextDecorator )
{
	bio_t*		rv;
	bioxc_t*	xc = ( bioxc_t* )bio;

	rv = xc->nextDecorator;

	xc->nextDecorator = nextDecorator;

	return rv;
}

static bio_t*
bioGetNextDecoratorXC( bio_t* bio )
{
	bioxc_t*	xc = ( bioxc_t* )bio;
	bio_t*		rv = xc->nextDecorator;

	return rv;
}

static const int	K = 7;
static const int	PERIOD = 26;

static void
xcipher( char* str, size_t n, char what )
{
	char		ch;
	size_t		i;
	int		a;

	for ( i = 0; i < n; i++ )
	{
		if ( !isalpha( str[ i ] ) )
		{
			continue;
		}

		a = isupper( str[ i ] ) ? 'A' : 'a';

		ch = str[ i ] - a;

		if ( what == 'e' )
		{
			ch = ( ch + K ) % PERIOD;
		}
		else
		{
			ch = ( ch - K + PERIOD ) % PERIOD;
		}

		str[ i ] = ch + a;
	}
}
