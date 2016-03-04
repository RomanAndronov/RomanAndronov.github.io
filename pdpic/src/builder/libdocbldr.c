#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "libdocbldr.h"

extern size_t
docbldrSizeOf( const char* docbldrnm )
{
	size_t		rv;
	size_t		( *docbldrsizeof )();
	void*		handle = RTLD_DEFAULT;
	char		nm[ 1024 + 1 ] = { 0 };
	size_t		nmsz = sizeof( nm );

#ifdef DOC_MLRTB
	snprintf( nm, nmsz, "libdocbldr%s.so", docbldrnm );
	handle = dlopen( nm, RTLD_LAZY | RTLD_GLOBAL );
#endif

	snprintf( nm, nmsz, "docbldrSizeOf%s", docbldrnm );

	docbldrsizeof = ( size_t ( * )() )dlsym( handle, nm );

	rv = docbldrsizeof();

	return rv;
}

extern docbldr_t*
docbldrConstruct( void* mem, const char* docbldrnm )
{
	docbldr_t*	docbldr;
	docbldr_t*	( *docbldrcnstrct )( void* );
	char		fnm[ 1024 + 1 ] = { 0 };
	size_t		fnmsz = sizeof( fnm );

	snprintf( fnm, fnmsz, "docbldrConstruct%s", docbldrnm );

	docbldrcnstrct = ( docbldr_t* ( * )( void* ) )dlsym( RTLD_DEFAULT, fnm );

	docbldr = docbldrcnstrct( mem );

	return docbldr;
}

extern docbldr_t*
docbldrNew( const char* docbldrnm )
{
	docbldr_t*	docbldr;
	size_t		n = docbldrSizeOf( docbldrnm );
	void*		mem = calloc( 1, n );

	docbldr = docbldrConstruct( mem, docbldrnm );

	return docbldr;
}

extern void
docbldrDestruct( docbldr_t* docbldr )
{
	docbldr->destruct( docbldr );
}

extern void
docbldrDelete( docbldr_t** docbldr )
{
	if ( !docbldr || !*docbldr )
	{
		return;
	}

	docbldrDestruct( *docbldr );

	free( *docbldr );

	*docbldr = ( docbldr_t* )NULL;
}

extern void
docbldrAddHdr( docbldr_t* docbldr, const char* txt )
{
	docbldr->addHdr( docbldr, txt );
}

extern void
docbldrRmHdr( docbldr_t* docbldr )
{
	docbldr->rmHdr( docbldr );
}

extern void
docbldrAddBody( docbldr_t* docbldr, const char* txt )
{
	docbldr->addBody( docbldr, txt );
}

extern void
docbldrRmBody( docbldr_t* docbldr )
{
	docbldr->rmBody( docbldr );
}

extern void
docbldrAttachDoc( docbldr_t* docbldr, doc_t* doc )
{
	docSetContent( doc, NULL );

	docbldr->attachDoc( docbldr, doc );
}

extern doc_t*
docbldrDetachDoc( docbldr_t* docbldr )
{
	doc_t*		doc;

	doc = docbldr->detachDoc( docbldr );

	return doc;
}
