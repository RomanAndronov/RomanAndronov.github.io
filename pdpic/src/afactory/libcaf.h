#include <sys/types.h>
#include "libframe.h"

typedef struct caf
{
	/*
	   Abstract Factory Proper, family.
	 */
	const char*	( *name )();
	void		( *destruct )( struct caf* );

	/*
	   Family Members' Factories.

	   Frame.
	 */
	frame_t*	( *frameConstruct )( void* );
	size_t		( *frameSizeOf )();
} caf_t;

/*
   Abstract Factory Proper.
 */
extern caf_t*		cafNew( const char* );
extern void		cafDelete( caf_t** );
extern caf_t*		cafConstruct( void*, const char* );
extern void		cafDestruct( caf_t* );
extern size_t		cafSizeOf( const char* );
extern const char*	cafName( caf_t* );

/*
   Frame's Factory.
 */
extern frame_t*		frameNew( caf_t* );
extern frame_t*		frameConstruct( caf_t*, void* );
extern size_t		frameSizeOf( caf_t* );
