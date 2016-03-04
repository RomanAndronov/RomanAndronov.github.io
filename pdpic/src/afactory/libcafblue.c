#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libcaf.h"

typedef struct
{
	caf_t		cafadt;
} cafblue_t;

extern size_t		cafSizeOfblue();
extern caf_t*		cafConstructblue( void* );

static const char*	cafNameBlue();
static void		cafDestructBlue( caf_t* );

extern frame_t*		frameConstructBlue( void* );
extern size_t		frameSizeOfBlue();

static caf_t	cafAdtBlue = 
{ 
	cafNameBlue,
	cafDestructBlue,

	frameConstructBlue,
	frameSizeOfBlue
};

extern size_t
cafSizeOfblue()
{
	size_t		rv;

	printf( " %s.%d: cafSizeOfblue()\n", __FILE__, __LINE__ );

	rv = sizeof( cafblue_t );

	return rv;
}

extern caf_t*
cafConstructblue( void* mem )
{
	cafblue_t*	cafblue = ( cafblue_t* )mem;

	printf( " %s.%d: cafConstructblue()\n", __FILE__, __LINE__ );

	cafblue->cafadt = cafAdtBlue;

	return &cafblue->cafadt;
}

extern void
cafDestructBlue( caf_t* caf )
{
	cafblue_t*	cafblue;

	printf( " %s.%d: cafDestructBlue()\n", __FILE__, __LINE__ );

	if ( !caf )
	{
		return;
	}

	cafblue = ( cafblue_t* )caf;

	memset( cafblue, 0, sizeof( cafblue_t ) );
}

static const char*
cafNameBlue()
{
	printf( " %s.%d: cafNameBlue()\n", __FILE__, __LINE__ );

	return "blue";
}
