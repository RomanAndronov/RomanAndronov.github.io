#include <stdio.h>
#include "libframe.h"

typedef struct
{
	frame_t		frameadt;
} framegreen_t;

extern size_t		frameSizeOfgreen();
extern frame_t*		frameConstructgreen( void* );

static const char*	frameNameGreen();
static void		frameDestructGreen( frame_t* );

static frame_t	frameAdtGreen = 
{
	frameNameGreen,
	frameDestructGreen
};

extern size_t
frameSizeOfGreen()
{
	size_t		rv;

	printf( "  %s.%d: frameSizeOfgreen()\n", __FILE__, __LINE__ );

	rv = sizeof( framegreen_t );

	return rv;
}

extern frame_t*
frameConstructGreen( void* mem )
{
	frame_t*	rv;
	framegreen_t*	framegreen = ( framegreen_t* )mem;

	printf( "  %s.%d: frameConstructgreen()\n", __FILE__, __LINE__ );

	framegreen->frameadt = frameAdtGreen;

	rv = &framegreen->frameadt;

	return rv;
}

static void
frameDestructGreen( frame_t* frame )
{
	printf( "  %s.%d: frameDestructGreen()\n", __FILE__, __LINE__ );
}

static const char*
frameNameGreen()
{
	printf( "  %s.%d: frameNameGreen()\n", __FILE__, __LINE__ );

	return "green";
}
