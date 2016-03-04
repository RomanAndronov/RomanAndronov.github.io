#include <sys/types.h>

typedef struct book
{
	void		( *info )( struct book* );
} book_t;

extern book_t*		bookNew( const char*, const char* );
extern void		bookDelete( book_t** );

extern book_t*		bookConstruct( void*, const char*, const char* );
extern void		bookDestruct( book_t* );

extern size_t		bookSizeOf();

extern void		bookInfo( book_t* );
