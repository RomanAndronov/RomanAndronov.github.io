#include <stdio.h>
#include <stdlib.h>
#include "libbook.h"
#include "libstr.h"

typedef struct
{
	book_t		bookadt;

	str_t*		title;
	str_t*		authors;
} bookimpl_t;

static void		bookInfoImpl( book_t* );

static book_t	bookAdt = 
{ 
	bookInfoImpl
};

extern size_t
logicalSize( size_t currsz, size_t nextsz )
{
	size_t		logicalsz = ( ( currsz - 1 ) / nextsz ) * nextsz + nextsz;

	return logicalsz;
}

extern size_t
paddingAmount( size_t currsz, size_t nextsz )
{
	size_t		logicalsz = logicalSize( currsz, nextsz );

	size_t		pad = logicalsz - currsz;

	return pad;
}

extern void*
nextAddress( void* curradrs, size_t currsz, size_t nextsz )
{
	size_t			logicalsz = logicalSize( currsz, nextsz );

	void*			na = ( unsigned char* )curradrs + logicalsz;

	return na;
}

extern size_t
bookSizeOf()
{
	size_t		rv;

	rv = sizeof( bookimpl_t ) +
	
		paddingAmount( sizeof( bookimpl_t ), strSizeOf() ) +

		strSizeOf() +

		paddingAmount( strSizeOf(), strSizeOf() ) +

		strSizeOf();

	return rv;
}

extern book_t*
bookNew( const char* title, const char* authors )
{
	book_t*		book = ( book_t* )NULL;
	void*		mem = calloc( 1, bookSizeOf() );

	book = bookConstruct( mem, title, authors );

	return book;
}

extern book_t*
bookConstruct( void* mem, const char* title, const char* authors )
{
	void*			adrs;
	bookimpl_t*		bimpl = ( bookimpl_t* )mem;

	bimpl->bookadt = bookAdt;

	adrs = nextAddress( mem, sizeof( bookimpl_t ), strSizeOf() );

	/*
	   Construct the integral part. It is possible because
	   str_t's construction is a public interface.
	 */
	bimpl->title = strConstruct( adrs, title );

	adrs = nextAddress( bimpl->title, strSizeOf(), strSizeOf() );

	bimpl->authors = strConstruct( adrs, authors );

	/*
	   Construct the whole and return it.
	 */
	return &bimpl->bookadt;
}

extern void
bookDestruct( book_t* book )
{
	bookimpl_t*		bimpl = ( bookimpl_t* )book;

	/*
	   Destruct the integral part first. It is possible
	   because str_t's destruction interface is public.
	 */
	strDestruct( bimpl->title );

	strDestruct( bimpl->authors );

	/*
	   Then - destruct the whole.
	 */
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
	printf( " logical size of bookimpl_t = %zu\n",
		logicalSize( sizeof( bookimpl_t ), strSizeOf() ) );
	printf( " strSizeOf() = %zu\n", strSizeOf() );
	printf( "  &book = %p\n", ( void* )book );
	printf( "  &bookadt = %p\n", ( void* )( &bimpl->bookadt ) );
	printf( "  padding amount = %zu\n",
		paddingAmount( sizeof( bookimpl_t ), strSizeOf() ) );
	printf( "  &title = %p\n", ( void* )( bimpl->title ) );
	printf( "  &title - &book = %zu\n",
		( void* )( bimpl->title ) - ( void* )book );
	printf( "  &authors = %p\n", ( void* )( bimpl->authors ) );
	printf( "  &authors - &title = %zu\n",
		( void* )( bimpl->authors ) - ( void* )( bimpl->title ) );
}
