#include <stdio.h>
#include "libtypeb.h"
#include "libtypea.h"

extern void
typeA( void )
{
	typeB();

	printf( "%s.%d: typeA()\n", __FILE__, __LINE__ );
}
