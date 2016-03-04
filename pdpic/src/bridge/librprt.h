#include <sys/types.h>
#include "libbio.h"

typedef struct rprt
{
	int		( *write )( struct rprt*, int [], size_t, bio_t* );

	const char*	( *name )();
	size_t		( *sizeOf )();

	void		( *destruct )( struct rprt* );
} rprt_t;

extern rprt_t*		rprtNew( const char* );
extern void		rprtDelete( rprt_t** );
extern rprt_t*		rprtConstruct( void*, const char* );
extern void		rprtDestruct( rprt_t* );
extern size_t		rprtSizeOf( const char* );

extern int		rprtWrite( rprt_t*, int [], size_t, bio_t* );

extern const char*	rprtName( rprt_t* );
extern size_t		rprtsizeof( rprt_t* );
