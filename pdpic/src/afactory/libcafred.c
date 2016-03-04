#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libcaf.h"

typedef struct
{
	caf_t		cafadt;
} cafred_t;

extern size_t		cafSizeOfred();
extern caf_t*		cafConstructred( void* );

static const char*	cafNameRed();
static void		cafDestructRed( caf_t* );

extern frame_t*		frameConstructRed( void* );
extern size_t		frameSizeOfRed();

static caf_t	cafAdtRed = 
{ 
	cafNameRed,
	cafDestructRed,

	frameConstructRed,
	frameSizeOfRed
};

extern size_t
cafSizeOfred()
{
	size_t		rv;

	printf( " %s.%d: cafSizeOfred()\n", __FILE__, __LINE__ );

	rv = sizeof( cafred_t );

	return rv;
}

extern caf_t*
cafConstructred( void* mem )
{
	cafred_t*	cafred = ( cafred_t* )mem;

	printf( " %s.%d: cafConstructred()\n", __FILE__, __LINE__ );

	cafred->cafadt = cafAdtRed;

	return &cafred->cafadt;
}

extern void
cafDestructRed( caf_t* caf )
{
	cafred_t*	cafred;

	printf( " %s.%d: cafDestructRed()\n", __FILE__, __LINE__ );

	if ( !caf )
	{
		return;
	}

	cafred = ( cafred_t* )caf;

	memset( cafred, 0, sizeof( cafred_t ) );
}

static const char*
cafNameRed()
{
	printf( " %s.%d: cafNameRed()\n", __FILE__, __LINE__ );

	return "red";
}
