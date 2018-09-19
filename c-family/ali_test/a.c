#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1,j = 1;
    int b = i++ + j++;
    int c = ++i + ++j;
    printf("%d,%d,%d\n", b,c,i++);
    return 0;
}
