#include<stdio.h>

int main()
{
    char *str[] = {"Welcome","to","our","company"};
    char **p[] = {str+1,str+3,str+2,str};
    char ***pp = p;
    printf("%s",*--*++pp+1);
    //printf("%s\n",str);
    return 0;
}
