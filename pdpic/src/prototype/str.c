#include <stdio.h>
#include "libstr.h"

extern int
main( int argc, char* argv[] )
{
	str_t*		s1;
	str_t*		s2;

	if ( argc != 2 )
	{
		return 1;
	}

	s1 = strNew( argv[ 1 ] );
	s2 = strClone( s1, NULL );

	printf( "Strings s1 and s2 are %s equal.\n",
		strCmp( s1, s2, 1 ) ? "not" : "" );

	printf( "strLength( s1 ) = %zu\n", strLength( s1 ) );
	printf( "strLength( s2 ) = %zu\n", strLength( s2 ) );

	strDelete( &s1 );
	strDelete( &s2 );

	return 0;
}
