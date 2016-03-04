#ifndef __DOC_HEADER__
#define __DOC_HEADER__

#include <sys/types.h>

typedef struct doc
{
	void		( *setContent )( struct doc*, const char* );
	void		( *print )( struct doc* );
} doc_t;

extern doc_t*		docNew();
extern void		docDelete( doc_t** );
extern doc_t*		docConstruct( void* );
extern void		docDestruct( doc_t* );
extern size_t		docSizeOf();

extern void		docSetContent( doc_t*, const char* );
extern void		docPrint( doc_t* );

#endif
