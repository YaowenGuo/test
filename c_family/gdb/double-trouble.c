#include <stdio.h>
#include <errno.h>
#include <math.h>

int main( void ){
    double trouble = exp( 1000.0 );
    if( errno ){
        printf( "trouble: %f (errno: %d )", trouble, errno );
        return -1;
    }

    return 0;
}