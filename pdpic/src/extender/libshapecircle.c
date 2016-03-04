#include <stdio.h>
#include "libshape.h"

typedef struct
{
	shape_t		shapeadt;

	/*
	   An ellipse is an integral
	   part of a circle.
	 */
	shape_t*	ellipse;
} shapecircle_t;

static void		shapeDescribeCircle( shape_t* );
static void		shapeDestructCircle( shape_t* );

static shape_t	circleAdt = 
{ 
	shapeDescribeCircle,
	shapeDestructCircle 
};

extern size_t
shapeSizeOfcircle()
{
	size_t		rv;

	rv = sizeof( shapecircle_t ) +

		paddingAmount( sizeof( shapecircle_t ), shapeSizeOf( "ellipse" ) ) +

		shapeSizeOf( "ellipse" );

	return rv;
}

extern shape_t*
shapeConstructcircle( void* mem )
{
	void*			adrs;
	shapecircle_t*		circle = ( shapecircle_t* )mem;

	circle->shapeadt = circleAdt;

	adrs = nextAddress( mem, sizeof( shapecircle_t ), shapeSizeOf( "ellipse" ) );

	circle->ellipse = shapeConstruct( adrs, "ellipse" );

	return &circle->shapeadt;
}

static void
shapeDescribeCircle( shape_t* shape )
{
	shapecircle_t*		circle = ( shapecircle_t* )shape;

	circle->ellipse->describe( circle->ellipse );

	printf( "   %s.%d: shapeDescribeCircle(): I am a circle.\n",
		__FILE__, __LINE__ );
}

static void
shapeDestructCircle( shape_t* shape )
{
	shapecircle_t*		circle = ( shapecircle_t* )shape;

	circle->ellipse->destruct( circle->ellipse );

	printf( "   %s.%d: shapeDestructCircle()\n",
		__FILE__, __LINE__ );
}
