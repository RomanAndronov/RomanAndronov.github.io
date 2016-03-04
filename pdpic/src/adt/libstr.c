#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libstr.h"

typedef struct
{
	/*
	   String's ADT - not a pointer, full structure.
	   Make it the very first member.
	   This passes the ANSI C Standard muster.
	   Public: users only see this member's address (which
	   happens to be the entire structure's address also).
	 */
	str_t		stradt;

	/*
	   Implementation details.
	   Private: users will not see this.
	 */
	size_t		bufsz;
	char*		buf;
	size_t		slen;
} strimpl_t;

static int		strCmpImpl( str_t*, str_t*, int );
static size_t		strLengthImpl( str_t* );

/* 
   This structure is used to initialize many
   functions at once.
   Add more routines here as string library is developed.
   Used by strConstruct(), see below.
 */
static str_t	strAdt = 
{ 
	strCmpImpl,
	strLengthImpl
};

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
	strimpl_t*	simpl = ( strimpl_t* )smem;

	/*
	   This initializes string's public interface.
	 */
	simpl->stradt = strAdt;


	/*
	   This initializes string's private state (implementation).
	 */
	if ( istr && *istr )
	{
		simpl->bufsz = strlen( istr );
	}
	else
	{
		simpl->bufsz = 32;
	}
	simpl->bufsz += sizeof( char );

	simpl->buf = calloc( simpl->bufsz, sizeof( char ) );

	if ( istr && *istr )
	{
		memcpy( simpl->buf, istr, simpl->bufsz );
		simpl->slen = simpl->bufsz - sizeof( char );
	}
	else
	{
		simpl->buf[ 0 ] = '\0';
		simpl->slen = 0;
	}


	/*
	   This is what users see - the public portion
	   of the bound IDT + ADT whole - ADT only.
	 */
	return &simpl->stradt;
}

extern void
strDestruct( str_t* str )
{
	strimpl_t*	simpl;

	if ( !str )
	{
		return;
	}


	/*
	   This is what ADT's authors see - public and
	   private portions - interface and implementation.
	 */
	simpl = ( strimpl_t* )str;

	if ( simpl->buf )
	{
		/*
		   Balances calloc() in strConstruct().
		 */
		free( simpl->buf );
	}

	memset( simpl, 0, sizeof( strimpl_t ) );
}

extern void
strDelete( str_t** str )
{
	if ( !str && !*str )
	{
		return;
	}

	strDestruct( *str );

	/*
	   Balances calloc() in strNew().
	 */
	free( *str );

	*str = ( str_t* )NULL;
}

/*
   Public convenience routines.
*/
extern int
strCmp( str_t* s1, str_t* s2, int caseSensitive )
{
	int		rv;

	rv = s1->cmp( s1, s2, caseSensitive );

	return rv;
}

extern size_t
strLength( str_t* s )
{
	size_t		sl;

	sl = s->length( s );

	return sl;
}

/*
   Private implementations of public routine names.
*/
static int
strCmpImpl( str_t* s1, str_t* s2, int caseSensitive )
{
	int		rv;
	int		( *scmp )( const char*, const char*, size_t );

	/*
	   ANSI C Standard rule makes this possible.
	 */
	strimpl_t*	simpl1 = ( strimpl_t* )s1;
	strimpl_t*	simpl2 = ( strimpl_t* )s2;

	printf( "%s:%d: strCmpImpl( \"%s\", \"%s\", %d )\n",
		__FILE__, __LINE__, simpl1->buf, simpl2->buf, caseSensitive );

	scmp = caseSensitive ? strncmp : strncasecmp;

	rv = scmp( simpl1->buf, simpl2->buf, simpl1->slen );

	return rv;
}

static size_t
strLengthImpl( str_t* s )
{
	strimpl_t*	simpl = ( strimpl_t* )s;

	return simpl->slen;
}
