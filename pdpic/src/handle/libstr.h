#include <sys/types.h>

typedef void str_t;

/*
   Public interface.

   Life cycle routines.
 */
extern str_t*		strNew( const char* );
extern void		strDelete( str_t** );

extern str_t*		strConstruct( void*, const char* );
extern void		strDestruct( str_t* );

extern size_t		strSizeOf();

extern int		strCmp( str_t*, str_t*, int );
extern size_t		strLength( str_t* );

extern unsigned char*	strToBytes( str_t*, size_t* );
extern str_t*		strFromBytes( unsigned char*, size_t );
