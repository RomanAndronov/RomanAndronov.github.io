#include <stdio.h>
#include <stdlib.h>
#include "libstr.h"

extern int
main( int argc, char* argv[] )
{
	str_t*		s1;
	str_t*		s2;
	unsigned char*	b = NULL;
	size_t		nb = 0;
	str_t*		sfb = NULL;

	if ( argc != 3 )
	{
		return 1;
	}

	s1 = strNew( argv[ 1 ] );
	s2 = strNew( argv[ 2 ] );

	printf( "Strings s1 and s2 are %s equal.\n",
		strCmp( s1, s2, 1 ) ? "not" : "" );

	b = strToBytes( s1, &nb );
	sfb = strFromBytes( b, nb );
	printf( "Strings s1 and sfb are %s equal.\n",
		strCmp( s1, sfb, 1 ) ? "not" : "" );


	strDelete( &s1 );
	strDelete( &s2 );
	strDelete( &sfb );
	free( b );

	return 0;
}
