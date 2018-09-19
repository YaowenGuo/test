#include <stdio.h>

struct st
{
    int * p;
    int i;
    char a;
};



int main()
{
    printf("%ld\n",sizeof( struct st ));
    printf("%ld\n",sizeof( int * ));
    printf("%ld\n",sizeof( int ));
    printf("%ld\n",sizeof( long long ));
    return 0;
}
