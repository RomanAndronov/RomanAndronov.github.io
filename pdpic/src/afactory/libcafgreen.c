#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libcaf.h"

typedef struct
{
	caf_t		cafadt;
} cafgreen_t;

extern size_t		cafSizeOfgreen();
extern caf_t*		cafConstructgreen( void* );

static const char*	cafNameGreen();
static void		cafDestructGreen( caf_t* );

extern frame_t*		frameConstructGreen( void* );
extern size_t		frameSizeOfGreen();

static caf_t	cafAdtGreen = 
{ 
	cafNameGreen,
	cafDestructGreen,

	frameConstructGreen,
	frameSizeOfGreen
};

extern size_t
cafSizeOfgreen()
{
	size_t		rv;

	printf( " %s.%d: cafSizeOfgreen()\n", __FILE__, __LINE__ );

	rv = sizeof( cafgreen_t );

	return rv;
}

extern caf_t*
cafConstructgreen( void* mem )
{
	cafgreen_t*	cafgreen = ( cafgreen_t* )mem;

	printf( " %s.%d: cafConstructgreen()\n", __FILE__, __LINE__ );

	cafgreen->cafadt = cafAdtGreen;

	return &cafgreen->cafadt;
}

extern void
cafDestructGreen( caf_t* caf )
{
	cafgreen_t*	cafgreen;

	printf( " %s.%d: cafDestructGreen()\n", __FILE__, __LINE__ );

	if ( !caf )
	{
		return;
	}

	cafgreen = ( cafgreen_t* )caf;

	memset( cafgreen, 0, sizeof( cafgreen_t ) );
}

static const char*
cafNameGreen()
{
	printf( " %s.%d: cafNameGreen()\n", __FILE__, __LINE__ );

	return "green";
}
