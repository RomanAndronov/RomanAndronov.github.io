#include <stdio.h>
#include <stdlib.h>
#include "libbook.h"

typedef struct
{
	book_t		bookadt;

	str_t*		title;
	str_t*		authors;
} bookimpl_t;

static void		bookInfoImpl( book_t* );
static str_t*		bookSetTitleImpl( book_t*, str_t* );
static str_t*		bookSetAuthorsImpl( book_t*, str_t* );

static book_t	bookAdt = 
{ 
	bookInfoImpl,
	bookSetTitleImpl,
	bookSetAuthorsImpl
};

extern size_t
bookSizeOf()
{
	size_t		rv;

	rv = sizeof( bookimpl_t );

	return rv;
}

extern book_t*
bookNew()
{
	book_t*		book = ( book_t* )NULL;
	void*		mem = calloc( 1, bookSizeOf() );

	book = bookConstruct( mem );

	return book;
}

extern book_t*
bookConstruct( void* mem )
{
	bookimpl_t*		bimpl = ( bookimpl_t* )mem;

	bimpl->bookadt = bookAdt;

	bimpl->title = NULL;
	bimpl->authors = NULL;

	return &bimpl->bookadt;
}

extern void
bookDestruct( book_t* book )
{
	bookimpl_t*		bimpl = ( bookimpl_t* )book;

	bimpl->title = NULL;
	bimpl->authors = NULL;
}

extern void
bookDelete( book_t** book )
{
	if ( !book && !*book )
	{
		return;
	}

	bookDestruct( *book );

	free( *book );

	*book = ( book_t* )NULL;
}

extern void
bookInfo( book_t* book )
{
	book->info( book );
}

extern str_t*
bookSetTitle( book_t* book, str_t* title )
{
	str_t*		oldTitle;

	oldTitle = book->setTitle( book, title );

	return oldTitle;
}

extern str_t*
bookSetAuthors( book_t* book, str_t* authors )
{
	str_t*		oldAuthors;

	oldAuthors = book->setAuthors( book, authors );

	return oldAuthors;
}

static void
bookInfoImpl( book_t* book )
{
	bookimpl_t*	bimpl = ( bookimpl_t* )book;

	printf( "%s:%d: bookInfoImpl()\n", __FILE__, __LINE__ );

	printf( " bookSizeOf() = %zu\n", bookSizeOf() );
	printf( " sizeof( bookimpl_t ) = %zu\n", sizeof( bookimpl_t ) );
	printf( " sizeof( book_t ) = %zu\n", sizeof( book_t ) );
	printf( " sizeof( title ) = %zu\n", sizeof( str_t* ) );
	printf( " sizeof( authors ) = %zu\n", sizeof( str_t* ) );
	printf( "  &book = %p\n", ( void* )book );
	printf( "  &bookadt = %p\n", ( void* )( &bimpl->bookadt ) );
	printf( "  &title = %p\n", ( void* )( &bimpl->title ) );
	printf( "  &title - &book = %zu\n",
		( void* )( &bimpl->title ) - ( void* )book );
	printf( "  &authors = %p\n", ( void* )( &bimpl->authors ) );
	printf( "  &authors - &title = %zu\n",
		( void* )( &bimpl->authors ) - ( void* )( &bimpl->title ) );
}

extern str_t*
bookSetTitleImpl( book_t* book, str_t* title )
{
	str_t*		oldTitle;
	bookimpl_t*	bimpl = ( bookimpl_t* )book;

	oldTitle = bimpl->title;
	bimpl->title = title;

	return oldTitle;
}

extern str_t*
bookSetAuthorsImpl( book_t* book, str_t* authors )
{
	str_t*		oldAuthors;
	bookimpl_t*	bimpl = ( bookimpl_t* )book;

	oldAuthors = bimpl->authors;
	bimpl->authors = authors;

	return oldAuthors;
}
