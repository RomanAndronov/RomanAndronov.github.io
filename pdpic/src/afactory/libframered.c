#include <stdio.h>
#include "libframe.h"

typedef struct
{
	frame_t		frameadt;
} framered_t;

extern size_t		frameSizeOfred();
extern frame_t*		frameConstructred( void* );

static const char*	frameNameRed();
static void		frameDestructRed( frame_t* );

static frame_t	frameAdtRed = 
{
	frameNameRed,
	frameDestructRed
};

extern size_t
frameSizeOfRed()
{
	size_t		rv;

	printf( "  %s.%d: frameSizeOfred()\n", __FILE__, __LINE__ );

	rv = sizeof( framered_t );

	return rv;
}

extern frame_t*
frameConstructRed( void* mem )
{
	frame_t*	rv;
	framered_t*	framered = ( framered_t* )mem;

	printf( "  %s.%d: frameConstructred()\n", __FILE__, __LINE__ );

	framered->frameadt = frameAdtRed;

	rv = &framered->frameadt;

	return rv;
}

static void
frameDestructRed( frame_t* frame )
{
	printf( "  %s.%d: frameDestructRed()\n", __FILE__, __LINE__ );
}

static const char*
frameNameRed()
{
	printf( "  %s.%d: frameNameRed()\n", __FILE__, __LINE__ );

	return "red";
}
