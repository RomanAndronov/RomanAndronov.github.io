#include <stdio.h>
#include "libbook.h"

int
main( int argc, char* argv[] )
{
	book_t*		book = bookNew( "The C Programming Language", "K & R" );

	bookInfo( book );

	bookDelete( &book );

	return 0;
}
