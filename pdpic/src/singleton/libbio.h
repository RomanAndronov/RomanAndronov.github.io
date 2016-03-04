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
extern void		bioDelete();

extern size_t		bioSizeOf( const char* );

extern int		bioOpen( const char* );
extern ssize_t		bioRead( void*, size_t );
extern ssize_t		bioWrite( void*, size_t );
extern int		bioClose();

extern const char*	bioName();
extern size_t		biosizeof();
