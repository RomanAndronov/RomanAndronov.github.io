#include <stdio.h>
#include "libdoc.h"
#include "libdocbldr.h"

extern int
main( int argc, char* argv[] )
{
	doc_t*		doc;
	docbldr_t*	db;

	if ( argc < 2 )
	{
		return -1;
	}

	db = docbldrNew( argv[ 1 ] );

	doc = docNew();

	docbldrAttachDoc( db, doc );

	docbldrAddHdr( db, "Hello" );

	docbldrAddBody( db, "world." );

	doc = docbldrDetachDoc( db );

	docPrint( doc );

	docbldrDelete( &db );
	docDelete( &doc );

	return 0;
}
