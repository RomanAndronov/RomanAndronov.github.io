#include <sys/types.h>

typedef struct frame
{
	const char*	( *name )();
	void		( *destruct )( struct frame* );
} frame_t;

extern void		frameDelete( frame_t** );
extern const char*	frameName( frame_t* );
extern void		frameDestruct( frame_t* );
