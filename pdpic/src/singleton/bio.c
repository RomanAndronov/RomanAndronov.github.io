#include <stdio.h>
#include <stdlib.h>
#include "libbio.h"

extern int
main( int argc, char* argv[] )
{
	size_t		i;
	const char*	bionm;
	const char*	adrs;
	bio_t*		bio;
	char		b[ 59 ] = { 0 };
	size_t		bsz = sizeof( b ) - 1;
	bio_t*		vars[ 8 ] = { 0 };
	size_t		nvars = sizeof( vars ) / sizeof( vars[ 0 ] );

	if ( argc != 3 )
	{
		return -1;
	}

	bionm = argv[ 1 ];
	adrs = argv[ 2 ];
	
	bio = bioNew( bionm );

	printf( "I/O Singleton address: %p\n", ( void* )bio );

	for ( i = 0; i < nvars; i++ )
	{
		vars[ i ] = bioNew( bionm );
		printf( "&vars[ %zu ] = %p\n", i, ( void* )vars[ i ] );
	}

	bioNew( "elif" );

	bioOpen( adrs );

	bioRead( b, bsz );

	printf( "First %zu bytes:\n%s\n", bsz, b );

	for ( i = 0; i < nvars; i++ )
	{
		bioDelete();
	}

	bioDelete();

	return 0;
}
