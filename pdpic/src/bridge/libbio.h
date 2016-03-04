#include <sys/types.h>

typedef struct bio
{
	int		( *open )( struct bio*, const char* );
	ssize_t		( *read )( struct bio*, void*, size_t );
	ssize_t		( *write )( struct bio*, void*, size_t );
	int		( *close )( struct bio* );

	const char*	( *name )();
	size_t		( *sizeOf )();

	void		( *destruct )( struct bio* );
} bio_t;

extern bio_t*		bioNew( const char* );
extern void		bioDelete( bio_t** );

extern bio_t*		bioConstruct( void*, const char* );
extern void		bioDestruct( bio_t* );

extern size_t		bioSizeOf( const char* );

extern int		bioOpen( bio_t*, const char* );
extern ssize_t		bioRead( bio_t*, void*, size_t );
extern ssize_t		bioWrite( bio_t*, void*, size_t );
extern int		bioClose( bio_t* );

extern const char*	bioName( bio_t* );
extern size_t		biosizeof( bio_t* );
