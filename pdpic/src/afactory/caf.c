#include <stdio.h>
#include "libcaf.h"

extern int
main( int argc, char* argv[] )
{
	const char*		familynm;
	caf_t*			caf;
	frame_t*		frame;

	if ( argc < 2 )
	{
		return -1;
	}

	familynm = ( const char* )argv[ 1 ];

	caf = cafNew( familynm );

	frame = frameNew( caf );

	printf( "Family name: \"%s\"\n", cafName( caf ) );

	printf( "Frame from \"%s\" family.\n", frameName( frame ) );
	printf( "frameSizeOf() = %zu\n", frameSizeOf( caf ) );

	frameDelete( &frame );
	cafDelete( &caf );

	return 0;
}
