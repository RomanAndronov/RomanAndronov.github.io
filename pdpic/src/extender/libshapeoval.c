#include <stdio.h>
#include "libshape.h"

typedef struct
{
	shape_t		shapeadt;
} shapeoval_t;

static void		shapeDescribeOval( shape_t* );
static void		shapeDestructOval( shape_t* );

static shape_t	ovalAdt = 
{ 
	shapeDescribeOval,
	shapeDestructOval
};

extern size_t
shapeSizeOfoval()
{
	return sizeof( shapeoval_t );
}

extern shape_t*
shapeConstructoval( void* mem )
{
	shapeoval_t*	oval = ( shapeoval_t* )mem;

	oval->shapeadt = ovalAdt;

	return &oval->shapeadt;
}

static void
shapeDescribeOval( shape_t* shape )
{
	shapeoval_t*	oval = ( shapeoval_t* )shape;

	printf( " %s.%d: shapeDescribeOval(): I am an oval.\n",
		__FILE__, __LINE__ );
}

extern void
shapeDestructOval( shape_t* shape )
{
	shapeoval_t*	oval = ( shapeoval_t* )shape;

	printf( " %s.%d: shapeDestructOval()\n",
		__FILE__, __LINE__ );
}
