#include <stdio.h>
#include "libbio.h"

typedef struct
{
	bio_t		bioadt;

	int		sockd;
	bio_t*		nextDecorator;
} biotcpipv4_t;

/*
   The names of these functions must
   adhere to the chosen naming convention.
   Their linkage specification is "extern".
 */
extern size_t		bioSizeOftcpipv4();
extern bio_t*		bioConstructtcpipv4( void* );

/*
   The names of these functions are arbitrary but their
   prototypes must conform to the ones announced in
   libbio.h public header file. The linkage specification
   of these functions may be "static".
 */
static int		bioOpenTcpipv4( bio_t*, const char* );
static ssize_t		bioReadTcpipv4( bio_t*, void*, size_t );
static ssize_t		bioWriteTcpipv4( bio_t*, void*, size_t );
static int		bioCloseTcpipv4( bio_t* );
static void		bioDestructTcpipv4( bio_t* );
static const char*	bioNameTcpipv4();
static bio_t*		bioSetNextDecoratorTcpipv4( bio_t*, bio_t* );
static bio_t*		bioGetNextDecoratorTcpipv4( bio_t* );

static bio_t	bioAdtTcpipv4 = 
{ 
	bioOpenTcpipv4,
	bioReadTcpipv4,
	bioWriteTcpipv4,
	bioCloseTcpipv4,
	bioNameTcpipv4,
	bioSizeOftcpipv4,
	bioSetNextDecoratorTcpipv4,
	bioGetNextDecoratorTcpipv4,
	bioDestructTcpipv4
};

extern size_t
bioSizeOftcpipv4()
{
	size_t		rv;

	rv = sizeof( biotcpipv4_t );

	return rv;
}

extern bio_t*
bioConstructtcpipv4( void* mem )
{
	bio_t*		rv;
	biotcpipv4_t*	tcpipv4 = ( biotcpipv4_t* )mem;

	tcpipv4->bioadt = bioAdtTcpipv4;

	printf( "%s.%d: bioConstructtcpipv4()\n", __FILE__, __LINE__ );

	rv = &tcpipv4->bioadt;

	return rv;
}

static void
bioDestructTcpipv4( bio_t* bio )
{
	bioCloseTcpipv4( bio );
}

static int
bioOpenTcpipv4( bio_t* bio, const char* adrs )
{
	int		rv;
	biotcpipv4_t*	tcpipv4 = ( biotcpipv4_t* )bio;

	printf( "%s.%d: bioOpenTcpipv4()\n", __FILE__, __LINE__ );

	rv = 1;

	return rv;
}

static ssize_t
bioReadTcpipv4( bio_t* bio, void* b, size_t bsz )
{
	size_t		n;
	biotcpipv4_t*	tcpipv4 = ( biotcpipv4_t* )bio;

	printf( "%s.%d: bioReadTcpipv4()\n", __FILE__, __LINE__ );

	n = bsz;

	return n;
}

static ssize_t
bioWriteTcpipv4( bio_t* bio, void* b, size_t bsz )
{
	size_t		n;
	biotcpipv4_t*	tcpipv4 = ( biotcpipv4_t* )bio;

	printf( "%s.%d: bioWriteTcpipv4()\n", __FILE__, __LINE__ );

	n = bsz;

	return n;
}

static int
bioCloseTcpipv4( bio_t* bio )
{
	biotcpipv4_t*	tcpipv4 = ( biotcpipv4_t* )bio;

	printf( "%s.%d: bioCloseTcpipv4()\n", __FILE__, __LINE__ );

	return 0;
}

static const char*
bioNameTcpipv4()
{
	return "tcpipv4";
}

static bio_t*
bioSetNextDecoratorTcpipv4( bio_t* bio, bio_t* nextDecorator )
{
	bio_t*		rv;
	biotcpipv4_t*	tcpipv4 = ( biotcpipv4_t* )bio;

	rv = tcpipv4->nextDecorator;

	tcpipv4->nextDecorator = nextDecorator;

	return rv;
}

static bio_t*
bioGetNextDecoratorTcpipv4( bio_t* bio )
{
	biotcpipv4_t*	tcpipv4 = ( biotcpipv4_t* )bio;
	bio_t*		rv = tcpipv4->nextDecorator;

	return rv;
}
