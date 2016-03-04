#include <stdio.h>
#include <stdlib.h>
#include "libbio.h"

extern int
main( int argc, char* argv[] )
{
	const char*	bionm;
	const char*	adrs;
	bio_t*		bio;
	char		b[ 59 ] = { 0 };
	size_t		bsz = sizeof( b ) - 1;

	if ( argc != 3 )
	{
		return -1;
	}

	bionm = argv[ 1 ];
	adrs = argv[ 2 ];
	
	bio = bioNew( bionm );

	bioOpen( bio, adrs );

	bioRead( bio, b, bsz );

	printf( "First %zu bytes:\n%s\n", bsz, b );

	bioDelete( &bio );

	return 0;
}
