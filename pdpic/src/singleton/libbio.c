#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dlfcn.h>
#include "libbio.h"

static bio_t*			bioConstruct( void*, const char* );
static void			bioDestruct( bio_t* );

typedef struct
{
	bio_t*			bios;
	size_t			biosusers;
	pthread_mutex_t		bioslock;
} biosingleton_t;

static biosingleton_t		BIOS = 
{
	( bio_t* )NULL,
	0,
	PTHREAD_MUTEX_INITIALIZER
};

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
bioNew( const char* bionm )
{
	bio_t*		rv = ( bio_t* )NULL;

	pthread_mutex_lock( &BIOS.bioslock );

		if ( BIOS.biosusers == 0 )
		{
			size_t		n = bioSizeOf( bionm );
			void*		mem = calloc( 1, n );

			BIOS.bios = bioConstruct( mem, bionm );
		}
		else if ( strcmp( bionm, bioName() ) )
		{
			printf( "%s.%d: bioNew(): %s != %s\n",
				__FILE__, __LINE__,
				bionm, bioName() );
			goto unlock;
		}

		BIOS.biosusers++;
		rv = BIOS.bios;
		printf( "%s.%d: bioNew(): %zu BIO Singleton user(s) attached.\n",
			__FILE__, __LINE__,
			BIOS.biosusers );

unlock:
	pthread_mutex_unlock( &BIOS.bioslock );

	return rv;
}

extern void
bioDelete()
{
	pthread_mutex_lock( &BIOS.bioslock );

		if ( BIOS.biosusers == 0 )
		{
			goto unlock;
		}

		if ( BIOS.biosusers == 1 )
		{
			bioDestruct( BIOS.bios );
			free( BIOS.bios );
			BIOS.bios = ( bio_t* )NULL;
			printf( "%s.%d: bioDelete(): "
				"last BIO Singleton user detaching: "
				"deleting single instance.\n",
				__FILE__, __LINE__ );
		}

		BIOS.biosusers--;
		printf( "%s.%d: bioDelete(): %zu BIO Singleton user(s) attached.\n",
			__FILE__, __LINE__,
			BIOS.biosusers );

unlock:
	pthread_mutex_unlock( &BIOS.bioslock );
}

extern int
bioOpen( const char* adrs )
{
	int		rv;

	rv = BIOS.bios->open( BIOS.bios, adrs );

	return rv;
}

extern ssize_t
bioRead( void* b, size_t bsz )
{
	ssize_t		rv;

	rv = BIOS.bios->read( BIOS.bios, b, bsz );

	return rv;
}

extern ssize_t
bioWrite( void* b, size_t bsz )
{
	ssize_t		rv;

	rv = BIOS.bios->write( BIOS.bios, b, bsz );

	return rv;
}

extern int
bioClose()
{
	int		rv;

	rv = BIOS.bios->close( BIOS.bios );

	return rv;
}

extern const char*
bioName()
{
	const char*	rv;

	rv = BIOS.bios->name();

	return rv;
}

extern size_t
biosizeof()
{
	size_t		rv;

	rv = BIOS.bios->sizeOf();

	return rv;
}

static bio_t*
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

static void
bioDestruct( bio_t* bio )
{
	bio->destruct( bio );
}
