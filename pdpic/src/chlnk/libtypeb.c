#include <stdio.h>
#include "libtypec.h"
#include "libtypeb.h"

extern void
typeB( void )
{
	typeC();

	printf( "%s.%d: typeB()\n", __FILE__, __LINE__ );
}
