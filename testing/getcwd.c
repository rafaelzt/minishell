#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#ifndef PATH_MAX
# define PATH_MAX 1024
#endif

int main( void )
{
    char* cwd;
    char buff[PATH_MAX];

    cwd = getcwd( buff, PATH_MAX );
    if( cwd != NULL ) {
        printf( "My working directory is %s.\n", cwd );
    }

    return EXIT_SUCCESS;
}

// https://www.qnx.com/developers/docs/7.1/#com.qnx.doc.neutrino.lib_ref/topic/g/getcwd.html