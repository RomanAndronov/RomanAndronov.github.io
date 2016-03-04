#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h> /* for dlsym(). Replace with your OS' equivalent header. */
#include "libbio.h"

extern size_t
bioSizeOf( const char* bionm )
{
	size_t		rv;
	size_t		( *biosizeof )();
	void*		handle = RTLD_DEFAULT;
	char		nm[ 1024 + 1 ] = { 0 };
	size_t		nmsz = sizeof( nm );

#ifdef IO_MLRTF
	snprintf( nm, nmsz, "libbio%s.so", bionm );
	handle = dlopen( nm, RTLD_LAZY | RTLD_GLOBAL );
#endif

	snprintf( nm, nmsz, "bioSizeOf%s", bionm );

	biosizeof = ( size_t ( * )() )dlsym( handle, nm );

	rv = biosizeof();

	return rv;
}

extern bio_t*
bioConstruct( void* mem, const char* bionm )
{
	bio_t*		bio;
	bio_t*		( *biocnstrct )( void* );
	char		fnm[ 1024 + 1 ] = { 0 };
	size_t		fnmsz = sizeof( fnm );

	snprintf( fnm, fnmsz, "bioConstruct%s", bionm );

	biocnstrct = ( bio_t* ( * )( void* ) )dlsym( RTLD_DEFAULT, fnm );

	bio = biocnstrct( mem );

	return bio;
}

extern bio_t*
bioNew( const char* bionm )
{
	bio_t*		bio;
	size_t		n = bioSizeOf( bionm );
	void*		mem = calloc( 1, n );

	bio = bioConstruct( mem, bionm );

	return bio;
}

extern void
bioDestruct( bio_t* bio )
{
	bio->destruct( bio );
}

extern void
bioDelete( bio_t** bio )
{
	if ( !bio || !*bio )
	{
		return;
	}

	bioDestruct( *bio );

	free( *bio );

	*bio = ( bio_t* )NULL;
}

extern int
bioOpen( bio_t* bio, const char* adrs )
{
	int		rv;

	rv = bio->open( bio, adrs );

	return rv;
}

extern ssize_t
bioRead( bio_t* bio, void* b, size_t bsz )
{
	ssize_t		rv;

	rv = bio->read( bio, b, bsz );

	return rv;
}

extern ssize_t
bioWrite( bio_t* bio, void* b, size_t bsz )
{
	ssize_t		rv;

	rv = bio->write( bio, b, bsz );

	return rv;
}

extern int
bioClose( bio_t* bio )
{
	int		rv;

	rv = bio->close( bio );

	return rv;
}

extern const char*
bioName( bio_t* bio )
{
	const char*	rv;

	rv = bio->name();

	return rv;
}

extern size_t
biosizeof( bio_t* bio )
{
	size_t		rv;

	rv = bio->sizeOf();

	return rv;
}

extern bio_t*
bioSetNextDecorator( bio_t* bio, bio_t* nextDecorator )
{
	bio_t*		rv;

	rv = bio->setNextDecorator( bio, nextDecorator );

	return rv;
}

extern bio_t*
bioGetNextDecorator( bio_t* bio )
{
	bio_t*		rv;

	rv = bio->getNextDecorator( bio );

	return rv;
}
