#include <stdio.h>
#include "libbook.h"

int
main( int argc, char* argv[] )
{
	book_t*		book = bookNew();
	str_t*		title = strNew( "The C Programming Language" );
	str_t*		authors = strNew( "K & R" );

	bookInfo( book );

	bookSetTitle( book, title );
	bookSetAuthors( book, authors );

	bookDelete( &book );
	strDelete( &title );
	strDelete( &authors );

	return 0;
}
