#include <stdio.h>
#include "libframe.h"

typedef struct
{
	frame_t		frameadt;
} frameblue_t;

extern size_t		frameSizeOfblue();
extern frame_t*		frameConstructblue( void* );

static const char*	frameNameBlue();
static void		frameDestructBlue( frame_t* );

static frame_t	frameAdtBlue = 
{
	frameNameBlue,
	frameDestructBlue
};

extern size_t
frameSizeOfBlue()
{
	size_t		rv;

	printf( "  %s.%d: frameSizeOfblue()\n", __FILE__, __LINE__ );

	rv = sizeof( frameblue_t );

	return rv;
}

extern frame_t*
frameConstructBlue( void* mem )
{
	frame_t*	rv;
	frameblue_t*	frameblue = ( frameblue_t* )mem;

	printf( "  %s.%d: frameConstructblue()\n", __FILE__, __LINE__ );

	frameblue->frameadt = frameAdtBlue;

	rv = &frameblue->frameadt;

	return rv;
}

static void
frameDestructBlue( frame_t* frame )
{
	printf( "  %s.%d: frameDestructBlue()\n", __FILE__, __LINE__ );
}

static const char*
frameNameBlue()
{
	printf( "  %s.%d: frameNameBlue()\n", __FILE__, __LINE__ );

	return "blue";
}
