#include <stdio.h>
#include "libdocbldr.h"

typedef struct
{
	docbldr_t	docbldradt;

	doc_t*		doc;
	char		hdr[ 1024 + 1 ];
	char		body[ 1024 + 1 ];
} docbldrplain_t;

extern size_t		docbldrSizeOfplain();
extern docbldr_t*	docbldrConstructplain( void* );

static void		docbldrAddHdrPlain( docbldr_t*, const char* );
static void		docbldrRmHdrPlain( docbldr_t* );
static void		docbldrAddBodyPlain( docbldr_t*, const char* );
static void		docbldrRmBodyPlain( docbldr_t* );
static void		docbldrAttachDocPlain( docbldr_t*, doc_t* );
static doc_t*		docbldrDetachDocPlain( docbldr_t* );
static void		docbldrDestructPlain( docbldr_t* );

static docbldr_t	docbldrAdtPlain = 
{ 
	docbldrAddHdrPlain,
	docbldrRmHdrPlain,
	docbldrAddBodyPlain,
	docbldrRmBodyPlain,
	docbldrAttachDocPlain,
	docbldrDetachDocPlain,
	docbldrDestructPlain 
};

extern size_t
docbldrSizeOfplain()
{
	size_t		rv;

	rv = sizeof( docbldrplain_t );

	return rv;
}

extern docbldr_t*
docbldrConstructplain( void* mem )
{
	docbldr_t*		rv;
	docbldrplain_t*		plain = ( docbldrplain_t* )mem;

	plain->docbldradt = docbldrAdtPlain;

	plain->doc = ( doc_t* )NULL;

	rv = &plain->docbldradt;

	return rv;
}

static void
docbldrDestructPlain( docbldr_t* docbldr )
{
	docbldrplain_t*		plain = ( docbldrplain_t* )docbldr;

	plain->doc = ( doc_t* )NULL;
	plain->hdr[ 0 ] = '\0';
	plain->body[ 0 ] = '\0';
}

static void
docbldrAddHdrPlain( docbldr_t* docbldr, const char* txt )
{
	docbldrplain_t*		plain = ( docbldrplain_t* )docbldr;

	snprintf( plain->hdr,
		sizeof( plain->hdr ),
		"[%s]", txt );
}

static void
docbldrRmHdrPlain( docbldr_t* docbldr )
{
	docbldrplain_t*		plain = ( docbldrplain_t* )docbldr;

	plain->hdr[ 0 ] = '\0';
}

static void
docbldrAddBodyPlain( docbldr_t* docbldr, const char* txt )
{
	docbldrplain_t*		plain = ( docbldrplain_t* )docbldr;

	snprintf( plain->body,
		sizeof( plain->body ),
		"[%s]", txt );
}

static void
docbldrRmBodyPlain( docbldr_t* docbldr )
{
	docbldrplain_t*		plain = ( docbldrplain_t* )docbldr;

	plain->body[ 0 ] = '\0';
}

static void
docbldrAttachDocPlain( docbldr_t* docbldr, doc_t* doc )
{
	docbldrplain_t*		plain = ( docbldrplain_t* )docbldr;

	plain->doc = doc;
}

static doc_t*
docbldrDetachDocPlain( docbldr_t* docbldr )
{
	doc_t*			rv;
	char			cntnt[ 1024 + 1 ] = { 0 };
	docbldrplain_t*		plain = ( docbldrplain_t* )docbldr;

	rv = plain->doc;

	snprintf( cntnt,
		sizeof( cntnt ),
		"%s\n%s\n",
		plain->hdr,
		plain->body );

	docSetContent( rv, cntnt );

	plain->doc = ( doc_t* )NULL;

	return rv;
}
