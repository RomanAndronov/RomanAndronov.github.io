#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libTYPE.h"

typedef struct
{
	/*
	   State variables go here.
	 */
} TYPEimpl_t;

extern size_t
TYPESizeOf()
{
	return sizeof( TYPEimpl_t );
}

extern TYPE_t*
TYPENew()
{
	void*		impl = calloc( 1, TYPESizeOf() );

	TYPE_t*		v = TYPEConstruct( impl );

	return v;
}

extern TYPE_t*
TYPEConstruct( void* mem )
{
	TYPEimpl_t*	t = ( TYPEimpl_t* )mem;

	/*
	   Construction code goes here.
	 */

	return ( TYPE_t* )t;
}

extern void
TYPEDestruct( TYPE_t* t )
{
	TYPEimpl_t*	timpl;

	if ( !t )
	{
		return;
	}

	/*
	   Destruction code goes here.
	 */
	timpl = ( TYPEimpl_t* )t;
}

extern void
TYPEDelete( TYPE_t** t )
{
	if ( !t && !*t )
	{
		return;
	}

	TYPEDestruct( *t );

	free( *t );

	*t = ( TYPE_t* )NULL;
}

extern int
TYPEFunc( TYPE_t* t )
{
	TYPEimpl_t*	timpl = ( TYPEimpl_t* )t;

	return 0;
}
