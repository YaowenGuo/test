#include <stdio.h>
#include <string.h>
int getline(char **strP, int *lenP, FILE *stream)
{
    char temp[1024];
    memset(temp,'\0',1024);
    int i = 0;
    temp[0] = getchat(stream);
    for(int i = 0; i < 1024 && temp[i] != EOF; i++,temp[i] = getchar(stream) );
    *strP = (char *)mallco(sizeof(char));
    strcpy(*strP, temp, i);
    *lenP = i;
    return i;
}


char *str;

int length = 0;

length = getline( strss, length, )
