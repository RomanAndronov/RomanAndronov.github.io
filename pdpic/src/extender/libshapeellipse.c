#include <stdio.h>
#include "libshape.h"

typedef struct
{
	shape_t		shapeadt;

	/*
	   An oval is an integral
	   part of an ellipse.
	 */
	shape_t*	oval;
} shapeellipse_t;

static void		shapeDescribeEllipse( shape_t* );
static void		shapeDestructEllipse( shape_t* );

static shape_t	ellipseAdt = 
{ 
	shapeDescribeEllipse,
	shapeDestructEllipse 
};

extern size_t
shapeSizeOfellipse()
{
	size_t		rv;

	rv = sizeof( shapeellipse_t ) +

		paddingAmount( sizeof( shapeellipse_t ), shapeSizeOf( "oval" ) ) +

		shapeSizeOf( "oval" );

	return rv;
}

extern shape_t*
shapeConstructellipse( void* mem )
{
	void*			adrs;
	shapeellipse_t*		ellipse = ( shapeellipse_t* )mem;

	ellipse->shapeadt = ellipseAdt;

	adrs = nextAddress( mem, sizeof( shapeellipse_t ), shapeSizeOf( "oval" ) );

	ellipse->oval = shapeConstruct( adrs, "oval" );

	return &ellipse->shapeadt;
}

static void
shapeDescribeEllipse( shape_t* shape )
{
	shapeellipse_t*		ellipse = ( shapeellipse_t* )shape;

	ellipse->oval->describe( ellipse->oval );

	printf( "  %s.%d: shapeDescribeEllipse(): I am an ellipse.\n",
		__FILE__, __LINE__ );
}

static void
shapeDestructEllipse( shape_t* shape )
{
	shapeellipse_t*		ellipse = ( shapeellipse_t* )shape;

	ellipse->oval->destruct( ellipse->oval );

	printf( "  %s.%d: shapeDestructEllipse()\n",
		__FILE__, __LINE__ );
}
