#include <sys/types.h>
#include "libdoc.h"

typedef struct docbldr
{
	void		( *addHdr )( struct docbldr*, const char* );
	void		( *rmHdr )( struct docbldr* );
	void		( *addBody )( struct docbldr*, const char* );
	void		( *rmBody )( struct docbldr* );

	void		( *attachDoc )( struct docbldr*, doc_t* );
	doc_t*		( *detachDoc )( struct docbldr* );

	void		( *destruct )( struct docbldr* );
} docbldr_t;

extern docbldr_t*	docbldrNew( const char* );
extern void		docbldrDelete( docbldr_t** );
extern docbldr_t*	docbldrConstruct( void*, const char* );
extern void		docbldrDestruct( docbldr_t* );
extern size_t		docbldrSizeOf( const char* );

extern void		docbldrAddHdr( docbldr_t*, const char* );
extern void		docbldrRmHdr( docbldr_t* );
extern void		docbldrAddBody( docbldr_t*, const char* );
extern void		docbldrRmBody( docbldr_t* );
extern void		docbldrAttachDoc( docbldr_t*, doc_t* );
extern doc_t*		docbldrDetachDoc( docbldr_t* );
