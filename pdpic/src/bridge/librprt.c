#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "librprt.h"

extern size_t
rprtSizeOf( const char* rprtnm )
{
	size_t		rv;
	size_t		( *rprtsizeof )();
	void*		handle = RTLD_DEFAULT;
	char		nm[ 1024 + 1 ] = { 0 };
	size_t		nmsz = sizeof( nm );

#ifdef RPRT_MLRTF
	snprintf( nm, nmsz, "librprt%s.so", rprtnm );
	handle = dlopen( nm, RTLD_LAZY | RTLD_GLOBAL );
#endif

	snprintf( nm, nmsz, "rprtSizeOf%s", rprtnm );

	rprtsizeof = ( size_t ( * )() )dlsym( handle, nm );

	rv = rprtsizeof();

	return rv;
}

extern rprt_t*
rprtConstruct( void* mem, const char* rprtnm )
{
	rprt_t*		rprt;
	rprt_t*		( *rprtcnstrct )( void* );
	char		fnm[ 1024 + 1 ] = { 0 };
	size_t		fnmsz = sizeof( fnm );

	snprintf( fnm, fnmsz, "rprtConstruct%s", rprtnm );

	rprtcnstrct = ( rprt_t* ( * )( void* ) )dlsym( RTLD_DEFAULT, fnm );

	rprt = rprtcnstrct( mem );

	return rprt;
}

extern rprt_t*
rprtNew( const char* rprtnm )
{
	rprt_t*		rprt;
	size_t		n = rprtSizeOf( rprtnm );
	void*		mem = calloc( 1, n );

	rprt = rprtConstruct( mem, rprtnm );

	return rprt;
}

extern void
rprtDestruct( rprt_t* rprt )
{
	rprt->destruct( rprt );
}

extern void
rprtDelete( rprt_t** rprt )
{
	if ( !rprt || !*rprt )
	{
		return;
	}

	rprtDestruct( *rprt );

	free( *rprt );

	*rprt = ( rprt_t* )NULL;
}

extern int
rprtWrite( rprt_t* rprt, int input[], size_t inputsz, bio_t *dst )
{
	int		rv;

	rv = rprt->write( rprt, input, inputsz, dst );

	return rv;
}

extern const char*
rprtName( rprt_t* rprt )
{
	const char*	rv;

	rv = rprt->name();

	return rv;
}

extern size_t
rprtsizeof( rprt_t* rprt )
{
	size_t		rv;

	rv = rprt->sizeOf();

	return rv;
}
