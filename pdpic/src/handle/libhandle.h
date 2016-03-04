#include <sys/types.h>

typedef void TYPE_t;

extern TYPE_t*		TYPENew();
extern void		TYPEDelete( TYPE_t** );

extern TYPE_t*		TYPEConstruct( void* );
extern void		TYPEDestruct( TYPE_t* );

extern size_t		TYPESizeOf();

extern int		TYPEFunc( TYPE_t* );
