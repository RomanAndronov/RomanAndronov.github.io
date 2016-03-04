#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "libcaf.h"

/*
   Abstract Factory Proper.
 */
extern size_t
cafSizeOf( const char* cafnm )
{
	size_t		rv;
	size_t		( *cafsizeof )();
	void*		handle = RTLD_DEFAULT;
	char		nm[ 1024 + 1 ] = { 0 };
	size_t		nmsz = sizeof( nm );

	printf( "%s.%d: cafSizeOf()\n", __FILE__, __LINE__ );

#ifdef CAR_MLRTAF
	snprintf( nm, nmsz, "libcaf%s.so", cafnm );
	handle = dlopen( nm, RTLD_LAZY | RTLD_GLOBAL );
#endif

	snprintf( nm, nmsz, "cafSizeOf%s", cafnm );

	cafsizeof = ( size_t ( * )() )dlsym( handle, nm );

	rv = cafsizeof();

	return rv;
}

extern caf_t*
cafConstruct( void* mem, const char* cafnm )
{
	caf_t*		caf;
	caf_t*		( *cafcnstrct )( void* );
	char		fnm[ 1024 + 1 ] = { 0 };
	size_t		fnmsz = sizeof( fnm );

	printf( "%s.%d: cafConstruct()\n", __FILE__, __LINE__ );

	snprintf( fnm, fnmsz, "cafConstruct%s", cafnm );

	cafcnstrct = ( caf_t* ( * )( void* ) )dlsym( RTLD_DEFAULT, fnm );

	caf = cafcnstrct( mem );

	return caf;
}

extern caf_t*
cafNew( const char* cafnm )
{
	caf_t*		caf;
	size_t		n = cafSizeOf( cafnm );
	void*		mem = calloc( 1, n );

	printf( "%s.%d: cafNew()\n", __FILE__, __LINE__ );

	caf = cafConstruct( mem, cafnm );

	return caf;
}

extern void
cafDestruct( caf_t* caf )
{
	printf( "%s.%d: cafDestruct()\n", __FILE__, __LINE__ );

	caf->destruct( caf );
}

extern void
cafDelete( caf_t** caf )
{
	printf( "%s.%d: cafDelete()\n", __FILE__, __LINE__ );

	if ( !caf || !*caf )
	{
		return;
	}

	cafDestruct( *caf );

	free( *caf );

	*caf = ( caf_t* )NULL;
}

extern const char*
cafName( caf_t* caf )
{
	const char*	rv;

	printf( "%s.%d: cafName()\n", __FILE__, __LINE__ );

	rv = caf->name( caf );

	return rv;
}

/*
   Family Members' Factories.

   Frame.
 */
extern frame_t*
frameNew( caf_t* caf )
{
	frame_t*	frm;
	size_t		n = caf->frameSizeOf();
	void*		mem = calloc( 1, n );

	printf( "%s.%d: frameNew()\n", __FILE__, __LINE__ );

	frm = caf->frameConstruct( mem );

	return frm;
}

extern frame_t*
frameConstruct( caf_t* caf, void* mem )
{
	frame_t*	frm;

	printf( "%s.%d: frameConstruct()\n", __FILE__, __LINE__ );

	frm = caf->frameConstruct( mem );

	return frm;
}

extern size_t
frameSizeOf( caf_t* caf )
{
	size_t		frmsz;

	printf( "%s.%d: frameSizeOf()\n", __FILE__, __LINE__ );

	frmsz = caf->frameSizeOf();

	return frmsz;
}
