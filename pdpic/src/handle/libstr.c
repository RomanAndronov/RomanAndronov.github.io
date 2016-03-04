#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "libstr.h"

/*
   Complete (implementation) string data type.
   Only visible inside this (private) file.
 */
typedef struct
{
	size_t		bufsz;
	char*		buf;
	size_t		slen;
} strimpl_t;


extern size_t
strSizeOf()
{
	return sizeof( strimpl_t );
}

extern str_t*
strNew( const char* istr )
{
	void*		simpl = calloc( 1, strSizeOf() );

	str_t*		s = strConstruct( simpl, istr );

	return s;
}

extern str_t*
strConstruct( void* smem, const char* istr )
{
	strimpl_t*	s = ( strimpl_t* )smem;

	if ( istr && *istr )
	{
		s->bufsz = strlen( istr );
	}
	else
	{
		s->bufsz = 32;
	}
	s->bufsz += sizeof( char );

	s->buf = calloc( s->bufsz, sizeof( char ) );

	if ( istr && *istr )
	{
		memcpy( s->buf, istr, s->bufsz );
		s->slen = s->bufsz - sizeof( char );
	}
	else
	{
		s->buf[ 0 ] = '\0';
		s->slen = 0;
	}

	return ( str_t* )s;
}

extern void
strDestruct( str_t* s )
{
	strimpl_t*	str;

	if ( !s )
	{
		return;
	}

	str = ( strimpl_t* )s;

	if ( str->buf )
	{
		/*
		   Balances calloc() in strConstruct().
		 */
		free( str->buf );
	}

	memset( str, 0, sizeof( strimpl_t ) );
}

extern void
strDelete( str_t** s )
{
	if ( !s && !*s )
	{
		return;
	}

	strDestruct( *s );

	/*
	   Balances calloc() in strNew().
	 */
	free( *s );

	*s = ( str_t* )NULL;
}

extern int
strCmp( str_t* s1, str_t* s2, int caseSensitive )
{
	int		rv;
	int		( *scmp )( const char*, const char*, size_t );
	strimpl_t*	str1 = ( strimpl_t* )s1;
	strimpl_t*	str2 = ( strimpl_t* )s2;

	printf( "%s:%d: strCmp( \"%s\", \"%s\", %d )\n",
		__FILE__, __LINE__, str1->buf, str2->buf, caseSensitive );

	scmp = caseSensitive ? strncmp : strncasecmp;

	rv = scmp( str1->buf, str2->buf, strlen( str1->buf ) );

	return rv;
}

extern size_t
strLength( str_t* s )
{
	strimpl_t*	str = ( strimpl_t* )s;

	return str->slen;
}

extern unsigned char*
strToBytes( str_t* str, size_t* nb )
{
	unsigned char*		bytes;
	strimpl_t*		simpl = ( strimpl_t* )str;
	size_t			ntslen = simpl->slen + sizeof( char );

	*nb = sizeof( *nb ) + ntslen;

	bytes = malloc( *nb );

	memcpy( bytes, nb, sizeof( *nb ) );

	memcpy( bytes + sizeof( *nb ), simpl->buf, ntslen );

	return bytes;
}

extern str_t*
strFromBytes( unsigned char* bytes, size_t nb )
{
	const char*	nts = ( const char* )( bytes + sizeof( nb ) );
	str_t*		s = strNew( nts );

	return s;
}
