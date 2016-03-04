#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "libshape.h"

extern size_t
shapeSizeOf( const char* shapenm )
{
	size_t		rv;
	size_t		( *shapesizeof )();
	void*		handle = RTLD_DEFAULT;
	char		nm[ 1024 + 1 ] = { 0 };
	size_t		nmsz = sizeof( nm );

#ifdef GSE_MLRTF
	snprintf( nm, nmsz, "libshape%s.so", shapenm );
	handle = dlopen( nm, RTLD_LAZY | RTLD_GLOBAL );
#endif

	snprintf( nm, nmsz, "shapeSizeOf%s", shapenm );

	shapesizeof = ( size_t ( * )() )dlsym( handle, nm );

	rv = shapesizeof();

	return rv;
}

extern shape_t*
shapeConstruct( void* mem, const char* shapenm )
{
	shape_t*	shape;
	shape_t*	( *shapecnstrct )( void* );
	char		fnm[ 1024 + 1 ] = { 0 };
	size_t		fnmsz = sizeof( fnm );

	snprintf( fnm, fnmsz, "shapeConstruct%s", shapenm );

	shapecnstrct = ( shape_t* ( * )( void* ) )dlsym( RTLD_DEFAULT, fnm );

	shape = shapecnstrct( mem );

	return shape;
}

extern shape_t*
shapeNew( const char* shapenm )
{
	shape_t*	shape;
	size_t		n = shapeSizeOf( shapenm );
	void*		mem = calloc( 1, n );

	shape = shapeConstruct( mem, shapenm );

	return shape;
}

extern void
shapeDestruct( shape_t* shape )
{
	shape->destruct( shape );
}

extern void
shapeDelete( shape_t** shape )
{
	if ( !shape || !*shape )
	{
		return;
	}

	shapeDestruct( *shape );

	free( *shape );

	*shape = ( shape_t* )NULL;
}

extern void
shapeDescribe( shape_t* shape )
{
	printf( "%s.%d: shapeDescribe(): I am a geometric shape.\n",
		__FILE__, __LINE__ );

	shape->describe( shape );
}

extern size_t
logicalSize( size_t currsz, size_t nextsz )
{
	size_t		adjstdsz = ( ( currsz - 1 ) / nextsz ) * nextsz + nextsz;

	return adjstdsz;
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
	size_t		logicalsz = logicalSize( currsz, nextsz );

	void*		na = ( unsigned char* )curradrs + logicalsz;

	return na;
}
