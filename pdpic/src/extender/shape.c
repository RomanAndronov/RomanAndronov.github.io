#include <stdio.h>
#include "libshape.h"

extern int
main( int argc, char* argv[] )
{
	shape_t*	shape;

	if ( argc < 2 )
	{
		return -1;
	}

	shape = shapeNew( argv[ 1 ] );

	shapeDescribe( shape );

	shapeDelete( &shape );

	return 0;
}
