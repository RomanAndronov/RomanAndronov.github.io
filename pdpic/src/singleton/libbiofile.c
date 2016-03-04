#include <stdio.h>
#include "libbio.h"

typedef struct
{
	bio_t		bioadt;

	FILE*		f;
} biofile_t;

/*
   The names of these functions must
   adhere to the chosen naming convention.
   Their linkage specification is "extern".
 */
extern size_t		bioSizeOffile();
extern bio_t*		bioConstructfile( void* );

/*
   The names of these functions are arbitrary but their
   prototypes must conform to the ones announced in
   libbio.h public header file. The linkage specification
   of these functions may be "static".
 */
static int		bioOpenFile( bio_t*, const char* );
static ssize_t		bioReadFile( bio_t*, void*, size_t );
static ssize_t		bioWriteFile( bio_t*, void*, size_t );
static int		bioCloseFile( bio_t* );
static void		bioDestructFile( bio_t* );
static const char*	bioNameFile();

static bio_t	bioAdtFile = 
{ 
	bioOpenFile,
	bioReadFile,
	bioWriteFile,
	bioCloseFile,
	bioNameFile,
	bioSizeOffile,
	bioDestructFile
};

extern size_t
bioSizeOffile()
{
	size_t		rv;

	rv = sizeof( biofile_t );

	return rv;
}

extern bio_t*
bioConstructfile( void* mem )
{
	bio_t*		rv;
	biofile_t*	file = ( biofile_t* )mem;

	file->bioadt = bioAdtFile;

	file->f = ( FILE* )NULL;

	rv = &file->bioadt;

	return rv;
}

static void
bioDestructFile( bio_t* bio )
{
	bioCloseFile( bio );
}

static int
bioOpenFile( bio_t* bio, const char* adrs )
{
	int		rv;
	biofile_t*	file = ( biofile_t* )bio;

	file->f = fopen( adrs, "r+" );

	rv = file->f ? 0 : -1;

	return rv;
}

static ssize_t
bioReadFile( bio_t* bio, void* b, size_t bsz )
{
	size_t		n;
	biofile_t*	file = ( biofile_t* )bio;

	n = fread( b, 1, bsz, file->f );
	if ( n != bsz && ferror( file->f ) )
	{
		return -1;
	}

	return n;
}

static ssize_t
bioWriteFile( bio_t* bio, void* b, size_t bsz )
{
	size_t		n;
	biofile_t*	file = ( biofile_t* )bio;

	n = fwrite( b, 1, bsz, file->f );
	if ( n != bsz && ferror( file->f ) )
	{
		return -1;
	}

	return n;
}

static int
bioCloseFile( bio_t* bio )
{
	biofile_t*	file = ( biofile_t* )bio;

	if ( !file->f )
	{
		return 0;
	}

	fclose( file->f );
	file->f = ( FILE* )NULL;

	return 0;
}

static const char*
bioNameFile()
{
	return "file";
}
