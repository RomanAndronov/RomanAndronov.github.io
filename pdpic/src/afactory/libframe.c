#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "libframe.h"

extern void
frameDestruct( frame_t* frame )
{
	printf( " %s.%d: frameDestruct()\n", __FILE__, __LINE__ );

	frame->destruct( frame );
}

extern void
frameDelete( frame_t** frame )
{
	printf( " %s.%d: frameDelete()\n", __FILE__, __LINE__ );

	if ( !frame || !*frame )
	{
		return;
	}

	frameDestruct( *frame );

	free( *frame );

	*frame = ( frame_t* )NULL;
}

extern const char*
frameName( frame_t* frame )
{
	const char*	fnm;

	printf( " %s.%d: frameName()\n", __FILE__, __LINE__ );

	fnm = frame->name();

	return fnm;
}
