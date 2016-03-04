#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libTYPE.h"

typedef struct
{
	TYPE_t		TYPEadt;


	/*
	   State variables go here.
	 */
} TYPEimpl_t;

extern int	TYPEFunc( TYPE_t* );

static TYPE_t	TYPEAdt = 
{ 
	TYPEFunc 
};

extern size_t
TYPESizeOf()
{
	return sizeof( TYPEimpl_t );
}

extern TYPE_t*
TYPENew()
{
	void*	impl = calloc( 1, sizeof( TYPEimpl_t ) );

	return TYPEConstruct( impl );
}

extern TYPE_t*
TYPEConstruct( void* mem )
{
	TYPEimpl_t*	impl = ( TYPEimpl_t* )mem;

	impl->TYPEadt = TYPEAdt;

	/*
	   Construction code goes here.
	 */

	return &impl->TYPEadt;
}

extern void
TYPEDestruct( TYPE_t* TYPE )
{
	TYPEimpl_t*	impl;

	if ( !TYPE )
	{
		return;
	}


	impl = ( TYPEimpl_t* )TYPE;

	/*
	   Destruction code goes here.
	 */

}

extern void
TYPEDelete( TYPE_t** TYPE )
{
	if ( !TYPE && !*TYPE )
	{
		return;
	}

	TYPEDestruct( *TYPE );

	free( *TYPE );

	*TYPE = ( TYPE_t* )NULL;
}

extern int
TYPEFunc( TYPE_t* TYPE )
{
	TYPEimpl_t*	impl = ( TYPEimpl_t* )TYPE;

	return 0;
}
