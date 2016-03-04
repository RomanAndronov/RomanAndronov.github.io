#include <sys/types.h>
#include "libstr.h"

typedef struct book
{
	void		( *info )( struct book* );
	str_t*		( *setTitle )( struct book*, str_t* );
	str_t*		( *setAuthors )( struct book*, str_t* );
} book_t;

extern book_t*		bookNew();
extern void		bookDelete( book_t** );

extern book_t*		bookConstruct( void* );
extern void		bookDestruct( book_t* );

extern size_t		bookSizeOf();

extern void		bookInfo( book_t* );
extern str_t*		bookSetTitle( book_t*, str_t* );
extern str_t*		bookSetAuthors( book_t*, str_t* );
