#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libdoc.h"

typedef struct
{
	doc_t		docadt;

	char		buf[ 1024 + 1 ];
} docimpl_t;

static void		docSetContentImpl( doc_t*, const char* );
static void		docPrintImpl( doc_t* );

static doc_t	docAdt = 
{ 
	docSetContentImpl,
	docPrintImpl
};

extern size_t
docSizeOf()
{
	return sizeof( docimpl_t );
}

extern doc_t*
docNew()
{
	void*		docimpl = calloc( 1, docSizeOf() );

	doc_t*		doc = docConstruct( docimpl );

	return doc;
}

extern doc_t*
docConstruct( void* docmem )
{
	docimpl_t*	docimpl = ( docimpl_t* )docmem;

	docimpl->docadt = docAdt;

	docimpl->buf[ 0 ] = '\0';

	return &docimpl->docadt;
}

extern void
docDestruct( doc_t* doc )
{
	docimpl_t*	docimpl;

	if ( !doc )
	{
		return;
	}

	docimpl = ( docimpl_t* )doc;

	memset( docimpl, 0, sizeof( docimpl_t ) );
}

extern void
docDelete( doc_t** doc )
{
	if ( !doc && !*doc )
	{
		return;
	}

	docDestruct( *doc );

	free( *doc );

	*doc = ( doc_t* )NULL;
}

extern void
docSetContent( doc_t* doc, const char* cntnt )
{
	doc->setContent( doc, cntnt );
}

extern void
docPrint( doc_t* doc )
{
	doc->print( doc );
}

static void
docSetContentImpl( doc_t* doc, const char* cntnt )
{
	docimpl_t*	docimpl = ( docimpl_t* )doc;

	memset( docimpl->buf, 0, sizeof( docimpl->buf ) );

	if ( cntnt && *cntnt )
	{
		snprintf( docimpl->buf,
			sizeof( docimpl->buf ),
			"%s",
			cntnt );
	}
}

static void
docPrintImpl( doc_t* doc )
{
	docimpl_t*	docimpl = ( docimpl_t* )doc;

	printf( "%s", docimpl->buf );
}
