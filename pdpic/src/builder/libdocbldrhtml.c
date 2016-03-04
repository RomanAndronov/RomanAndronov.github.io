#include <stdio.h>
#include "libdocbldr.h"

typedef struct
{
	docbldr_t	docbldradt;

	doc_t*		doc;
	char		hdr[ 1024 + 1 ];
	char		body[ 1024 + 1 ];
} docbldrhtml_t;

extern size_t		docbldrSizeOfhtml();
extern docbldr_t*	docbldrConstructhtml( void* );

static void		docbldrAddHdrHtml( docbldr_t*, const char* );
static void		docbldrRmHdrHtml( docbldr_t* );
static void		docbldrAddBodyHtml( docbldr_t*, const char* );
static void		docbldrRmBodyHtml( docbldr_t* );
static void		docbldrAttachDocHtml( docbldr_t*, doc_t* );
static doc_t*		docbldrDetachDocHtml( docbldr_t* );
static void		docbldrDestructHtml( docbldr_t* );

static docbldr_t	docbldrAdtHtml = 
{ 
	docbldrAddHdrHtml,
	docbldrRmHdrHtml,
	docbldrAddBodyHtml,
	docbldrRmBodyHtml,
	docbldrAttachDocHtml,
	docbldrDetachDocHtml,
	docbldrDestructHtml 
};

extern size_t
docbldrSizeOfhtml()
{
	size_t		rv;

	rv = sizeof( docbldrhtml_t );

	return rv;
}

extern docbldr_t*
docbldrConstructhtml( void* mem )
{
	docbldr_t*		rv;
	docbldrhtml_t*		html = ( docbldrhtml_t* )mem;

	html->docbldradt = docbldrAdtHtml;

	html->doc = ( doc_t* )NULL;

	rv = &html->docbldradt;

	return rv;
}

static void
docbldrDestructHtml( docbldr_t* docbldr )
{
	docbldrhtml_t*		html = ( docbldrhtml_t* )docbldr;

	html->doc = ( doc_t* )NULL;
	html->hdr[ 0 ] = '\0';
	html->body[ 0 ] = '\0';
}

static void
docbldrAddHdrHtml( docbldr_t* docbldr, const char* txt )
{
	docbldrhtml_t*		html = ( docbldrhtml_t* )docbldr;

	snprintf( html->hdr,
		sizeof( html->hdr ),
		"<html>\n <head>\n  <title>%s</title>\n </head>\n", txt );
}

static void
docbldrRmHdrHtml( docbldr_t* docbldr )
{
	docbldrhtml_t*		html = ( docbldrhtml_t* )docbldr;

	html->hdr[ 0 ] = '\0';
}

static void
docbldrAddBodyHtml( docbldr_t* docbldr, const char* txt )
{
	docbldrhtml_t*		html = ( docbldrhtml_t* )docbldr;

	snprintf( html->body,
		sizeof( html->body ),
		" <body>\n  <p>%s</p>\n </body>\n</html>\n", txt );
}

static void
docbldrRmBodyHtml( docbldr_t* docbldr )
{
	docbldrhtml_t*		html = ( docbldrhtml_t* )docbldr;

	html->body[ 0 ] = '\0';
}

static void
docbldrAttachDocHtml( docbldr_t* docbldr, doc_t* doc )
{
	docbldrhtml_t*		html = ( docbldrhtml_t* )docbldr;

	html->doc = doc;
}

static doc_t*
docbldrDetachDocHtml( docbldr_t* docbldr )
{
	doc_t*			rv;
	char			cntnt[ 1024 + 1 ] = { 0 };
	docbldrhtml_t*		html = ( docbldrhtml_t* )docbldr;

	rv = html->doc;

	snprintf( cntnt,
		sizeof( cntnt ),
		"%s%s",
		html->hdr,
		html->body );

	docSetContent( rv, cntnt );

	html->doc = ( doc_t* )NULL;

	return rv;
}
