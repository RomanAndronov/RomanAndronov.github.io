#include <stdio.h>
#include "libbio.h"

typedef struct
{
	bio_t		bioadt;

	int		sockd;
	bio_t*		nextDecorator;
} biotcpipv6_t;

/*
   The names of these functions must
   adhere to the chosen naming convention.
   Their linkage specification is "extern".
 */
extern size_t		bioSizeOftcpipv6();
extern bio_t*		bioConstructtcpipv6( void* );

/*
   The names of these functions are arbitrary but their
   prototypes must conform to the ones announced in
   libbio.h public header file. The linkage specification
   of these functions may be "static".
 */
static int		bioOpenTcpipv6( bio_t*, const char* );
static ssize_t		bioReadTcpipv6( bio_t*, void*, size_t );
static ssize_t		bioWriteTcpipv6( bio_t*, void*, size_t );
static int		bioCloseTcpipv6( bio_t* );
static void		bioDestructTcpipv6( bio_t* );
static const char*	bioNameTcpipv6();
static bio_t*		bioSetNextDecoratorTcpipv6( bio_t*, bio_t* );
static bio_t*		bioGetNextDecoratorTcpipv6( bio_t* );

static bio_t	bioAdtTcpipv6 = 
{ 
	bioOpenTcpipv6,
	bioReadTcpipv6,
	bioWriteTcpipv6,
	bioCloseTcpipv6,
	bioNameTcpipv6,
	bioSizeOftcpipv6,
	bioSetNextDecoratorTcpipv6,
	bioGetNextDecoratorTcpipv6,
	bioDestructTcpipv6
};

extern size_t
bioSizeOftcpipv6()
{
	size_t		rv;

	rv = sizeof( biotcpipv6_t );

	return rv;
}

extern bio_t*
bioConstructtcpipv6( void* mem )
{
	bio_t*		rv;
	biotcpipv6_t*	tcpipv6 = ( biotcpipv6_t* )mem;

	tcpipv6->bioadt = bioAdtTcpipv6;

	printf( "%s.%d: bioConstructtcpipv6()\n", __FILE__, __LINE__ );

	rv = &tcpipv6->bioadt;

	return rv;
}

static void
bioDestructTcpipv6( bio_t* bio )
{
	bioCloseTcpipv6( bio );
}

static int
bioOpenTcpipv6( bio_t* bio, const char* adrs )
{
	int		rv;
	biotcpipv6_t*	tcpipv6 = ( biotcpipv6_t* )bio;

	printf( "%s.%d: bioOpenTcpipv6()\n", __FILE__, __LINE__ );

	rv = 1;

	return rv;
}

static ssize_t
bioReadTcpipv6( bio_t* bio, void* b, size_t bsz )
{
	size_t		n;
	biotcpipv6_t*	tcpipv6 = ( biotcpipv6_t* )bio;

	printf( "%s.%d: bioReadTcpipv6()\n", __FILE__, __LINE__ );

	n = bsz;

	return n;
}

static ssize_t
bioWriteTcpipv6( bio_t* bio, void* b, size_t bsz )
{
	size_t		n;
	biotcpipv6_t*	tcpipv6 = ( biotcpipv6_t* )bio;

	printf( "%s.%d: bioWriteTcpipv6()\n", __FILE__, __LINE__ );

	n = bsz;

	return n;
}

static int
bioCloseTcpipv6( bio_t* bio )
{
	biotcpipv6_t*	tcpipv6 = ( biotcpipv6_t* )bio;

	printf( "%s.%d: bioCloseTcpipv6()\n", __FILE__, __LINE__ );

	return 0;
}

static const char*
bioNameTcpipv6()
{
	return "tcpipv6";
}

static bio_t*
bioSetNextDecoratorTcpipv6( bio_t* bio, bio_t* nextDecorator )
{
	bio_t*		rv;
	biotcpipv6_t*	tcpipv6 = ( biotcpipv6_t* )bio;

	rv = tcpipv6->nextDecorator;

	tcpipv6->nextDecorator = nextDecorator;

	return rv;
}

static bio_t*
bioGetNextDecoratorTcpipv6( bio_t* bio )
{
	biotcpipv6_t*	tcpipv6 = ( biotcpipv6_t* )bio;
	bio_t*		rv = tcpipv6->nextDecorator;

	return rv;
}
