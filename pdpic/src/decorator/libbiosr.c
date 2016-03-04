#include <stdio.h>
#include "libbio.h"

typedef struct
{
	bio_t		bioadt;

	bio_t*		nextDecorator;
} biosr_t;

/*
   The names of these functions must
   adhere to the chosen naming convention.
   Their linkage specification is "extern".
 */
extern size_t		bioSizeOfsr();
extern bio_t*		bioConstructsr( void* );

/*
   The names of these functions are arbitrary but their
   prototypes must conform to the ones announced in
   libbio.h public header file. The linkage specification
   of these functions may be "static".
 */
static int		bioOpenSR( bio_t*, const char* );
static ssize_t		bioReadSR( bio_t*, void*, size_t );
static ssize_t		bioWriteSR( bio_t*, void*, size_t );
static int		bioCloseSR( bio_t* );
static void		bioDestructSR( bio_t* );
static const char*	bioNameSR();
static bio_t*		bioSetNextDecoratorSR( bio_t*, bio_t* );
static bio_t*		bioGetNextDecoratorSR( bio_t* );

static bio_t	bioAdtSR = 
{ 
	bioOpenSR,
	bioReadSR,
	bioWriteSR,
	bioCloseSR,
	bioNameSR,
	bioSizeOfsr,
	bioSetNextDecoratorSR,
	bioGetNextDecoratorSR,
	bioDestructSR
};

static void		rotateString( char*, size_t );

extern size_t
bioSizeOfsr()
{
	size_t		rv;

	rv = sizeof( biosr_t );

	return rv;
}

extern bio_t*
bioConstructsr( void* mem )
{
	bio_t*		rv;
	biosr_t*	sr = ( biosr_t* )mem;

	sr->bioadt = bioAdtSR;

	rv = &sr->bioadt;

	return rv;
}

static void
bioDestructSR( bio_t* bio )
{
}

static int
bioOpenSR( bio_t* bio, const char* adrs )
{
	int		rv = 0;
	biosr_t*	sr = ( biosr_t* )bio;

	if ( sr->nextDecorator )
	{
		rv = bioOpen( sr->nextDecorator, adrs );
	}

	return rv;
}

static ssize_t
bioReadSR( bio_t* bio, void* b, size_t bsz )
{
	size_t		n = 0;
	biosr_t*	sr = ( biosr_t* )bio;

	if ( sr->nextDecorator )
	{
		n = bioRead( sr->nextDecorator, b, bsz );
		rotateString( ( char* )b, n );
	}

	return n;
}

static ssize_t
bioWriteSR( bio_t* bio, void* b, size_t bsz )
{
	size_t		n = 0;
	biosr_t*	sr = ( biosr_t* )bio;

	if ( sr->nextDecorator )
	{
		rotateString( ( char* )b, bsz );
		n = bioWrite( sr->nextDecorator, b, bsz );
	}

	return n;
}

static int
bioCloseSR( bio_t* bio )
{
	int		rv = 0;
	biosr_t*	sr = ( biosr_t* )bio;

	if ( sr->nextDecorator )
	{
		rv = bioClose( sr->nextDecorator );
	}

	return rv;
}

static const char*
bioNameSR()
{
	return "sr";
}

static bio_t*
bioSetNextDecoratorSR( bio_t* bio, bio_t* nextDecorator )
{
	bio_t*		rv;
	biosr_t*	sr = ( biosr_t* )bio;

	rv = sr->nextDecorator;

	sr->nextDecorator = nextDecorator;

	return rv;
}

static bio_t*
bioGetNextDecoratorSR( bio_t* bio )
{
	biosr_t*	sr = ( biosr_t* )bio;
	bio_t*		rv = sr->nextDecorator;

	return rv;
}

static void
rotateString( char* s, size_t n )
{
	char		ch;
	size_t		i;

	for ( i = 0; i < ( n / 2 ); i++ )
	{
		ch = s[ i ];
		s[ i ] = s[ n - i - 1 ];
		s[ n - i - 1 ] = ch;
	}
}
