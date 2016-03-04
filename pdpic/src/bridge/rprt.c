#include <stdio.h>
#include <stdlib.h>
#include "librprt.h"

extern int
main( int argc, char* argv[] )
{
	int		i;
	const char*	rprtnm;
	const char*	dstnm;
	const char*	dstadrs;
	bio_t*		dst;
	rprt_t*		rprt;
	int		input[ 100 ] = { 0 };
	size_t		inputsz = 0;

	if ( argc < 5 )
	{
		return -1;
	}

	rprtnm = argv[ 1 ];
	dstnm = argv[ 2 ];
	dstadrs = argv[ 3 ];
	
	rprt = rprtNew( rprtnm );
	dst = bioNew( dstnm );

	for ( i = 0; i < ( argc - 4 ) && i < 100; i++ )
	{
		input[ i ] = atoi( argv[ i + 4 ] );
		inputsz++;
	}

	bioOpen( dst, dstadrs );

	rprtWrite( rprt, input, inputsz, dst );

	rprtDelete( &rprt );
	bioDelete( &dst );

	return 0;
}
