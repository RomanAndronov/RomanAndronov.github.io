#include <sys/types.h>

typedef struct shape
{
	void		( *describe )( struct shape* );

	void		( *destruct )( struct shape* );
} shape_t;

extern shape_t*		shapeNew( const char* );
extern void		shapeDelete( shape_t** );
extern shape_t*		shapeConstruct( void*, const char* );
extern void		shapeDestruct( shape_t* );
extern size_t		shapeSizeOf( const char* );

extern void		shapeDescribe( shape_t* );

extern size_t		logicalSize( size_t, size_t );
extern size_t		paddingAmount( size_t, size_t );
extern void*		nextAddress( void*, size_t, size_t );
