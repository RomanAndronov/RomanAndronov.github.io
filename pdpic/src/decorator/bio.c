#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libbio.h"

static void	enumChain( bio_t* );

extern int
main( int argc, char* argv[] )
{
	int		w;
	char*		instr;
	size_t		n;

	const char*	componentnm;
	const char*	adrs;

	bio_t*		bio;
	bio_t*		component;

	int		i;
	int		ndecs = 0;
	bio_t*		decs[ 3 ] = { 0 };

	char		b[ 1024 + 1 ] = { 0 };


	if ( argc < 5 )
	{
		return -1;
	}

	w =  *argv[ 1 ] == 'w' ? 1 : 0;

	if ( w )
	{
		instr = argv[ 2 ];
		n = strlen( instr );
	}
	else
	{
		n = atoi( argv[ 2 ] );
	}

	componentnm = argv[ 3 ];
	adrs = argv[ 4 ];
	component = bioNew( componentnm );
	bio = component;

	if ( argc > 5 )
	{
		for ( i = 0; i < ( argc - 5 ) && ndecs < 4; i++ )
		{
			decs[ i ] = bioNew( argv[ 5 + i ] );
			ndecs++;
		}

		for ( i = 0; i < ndecs; i++ )
		{
			bioSetNextDecorator( decs[ ndecs - i - 1 ], bio );
			bio = decs[ ndecs - i - 1 ];
		}
	}

	enumChain( bio );

	bioOpen( bio, adrs );

	if ( w )
	{
		bioWrite( bio, instr, n );
	}
	else
	{
		bioRead( bio, b, n );
		printf( "%s\n", b );
	}

	bioDelete( &component );

	for ( i = 0; i < ndecs; i++ )
	{
		bioDelete( &decs[ i ] );
	}

	return 0;
}

static void
enumChain( bio_t* bio )
{
	printf( "Chain's members (name and address):\n" );

	while ( bio )
	{
		printf( "\"%s\"\t%p\n",
			bioName( bio ),
			( void* )bio );

		bio = bioGetNextDecorator( bio );
	}
}
