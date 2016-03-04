#include <stdio.h>
#include "libbio.h"

typedef struct
{
	bio_t		bioadt;

	bio_t*		nextDecorator;
} biocf_t;

/*
   The names of these functions must
   adhere to the chosen naming convention.
   Their linkage specification is "extern".
 */
extern size_t		bioSizeOfcf();
extern bio_t*		bioConstructcf( void* );

/*
   The names of these functions are arbitrary but their
   prototypes must conform to the ones announced in
   libbio.h public header file. The linkage specification
   of these functions may be "static".
 */
static int		bioOpenCF( bio_t*, const char* );
static ssize_t		bioReadCF( bio_t*, void*, size_t );
static ssize_t		bioWriteCF( bio_t*, void*, size_t );
static int		bioCloseCF( bio_t* );
static void		bioDestructCF( bio_t* );
static const char*	bioNameCF();
static bio_t*		bioSetNextDecoratorCF( bio_t*, bio_t* );
static bio_t*		bioGetNextDecoratorCF( bio_t* );

static bio_t	bioAdtCF = 
{ 
	bioOpenCF,
	bioReadCF,
	bioWriteCF,
	bioCloseCF,
	bioNameCF,
	bioSizeOfcf,
	bioSetNextDecoratorCF,
	bioGetNextDecoratorCF,
	bioDestructCF
};

static void		flipCase( char*, size_t );

extern size_t
bioSizeOfcf()
{
	size_t		rv;

	rv = sizeof( biocf_t );

	return rv;
}

extern bio_t*
bioConstructcf( void* mem )
{
	bio_t*		rv;
	biocf_t*	cf = ( biocf_t* )mem;

	cf->bioadt = bioAdtCF;

	rv = &cf->bioadt;

	return rv;
}

static void
bioDestructCF( bio_t* bio )
{
}

static int
bioOpenCF( bio_t* bio, const char* adrs )
{
	int		rv = 0;
	biocf_t*	cf = ( biocf_t* )bio;

	if ( cf->nextDecorator )
	{
		rv = bioOpen( cf->nextDecorator, adrs );
	}

	return rv;
}

static ssize_t
bioReadCF( bio_t* bio, void* b, size_t bsz )
{
	size_t		n = 0;
	biocf_t*	cf = ( biocf_t* )bio;

	if ( cf->nextDecorator )
	{
		n = bioRead( cf->nextDecorator, b, bsz );
		flipCase( ( char* )b, n );
	}

	return n;
}

static ssize_t
bioWriteCF( bio_t* bio, void* b, size_t bsz )
{
	size_t		n = 0;
	biocf_t*	cf = ( biocf_t* )bio;

	if ( cf->nextDecorator )
	{
		flipCase( ( char* )b, bsz );
		n = bioWrite( cf->nextDecorator, b, bsz );
	}

	return n;
}

static int
bioCloseCF( bio_t* bio )
{
	int		rv = 0;
	biocf_t*	cf = ( biocf_t* )bio;

	if ( cf->nextDecorator )
	{
		rv = bioClose( cf->nextDecorator );
	}

	return rv;
}

static const char*
bioNameCF()
{
	return "cf";
}

static bio_t*
bioSetNextDecoratorCF( bio_t* bio, bio_t* nextDecorator )
{
	bio_t*		rv;
	biocf_t*	cf = ( biocf_t* )bio;

	rv = cf->nextDecorator;

	cf->nextDecorator = nextDecorator;

	return rv;
}

static bio_t*
bioGetNextDecoratorCF( bio_t* bio )
{
	biocf_t*	cf = ( biocf_t* )bio;
	bio_t*		rv = cf->nextDecorator;

	return rv;
}

static const int	D = 'a' - 'A';

static void
flipCase( char* s, size_t n )
{
	int		d;
	size_t		i;

	for ( i = 0; i < n; i++ )
	{
		if ( !isalpha( s[ i ] ) )
		{
			continue;
		}

		d = isupper( s[ i ] ) ? D : -D;
		s[ i ] += d;
	}
}
