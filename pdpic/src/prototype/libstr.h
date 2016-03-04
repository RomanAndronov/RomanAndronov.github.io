#include <sys/types.h>

typedef struct str
{
	int		( *cmp )( struct str*, struct str*, int );
	size_t		( *length )( struct str* );
	struct str*	( *clone )( struct str*, void* );
} str_t;

extern str_t*		strNew( const char* );
extern void		strDelete( str_t** );
extern str_t*		strConstruct( void*, const char* );
extern void		strDestruct( str_t* );
extern size_t		strSizeOf();

extern int		strCmp( str_t*, str_t*, int );
extern size_t		strLength( str_t* );

extern str_t*		strClone( str_t*, void* );
