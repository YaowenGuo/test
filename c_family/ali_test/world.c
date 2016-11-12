#include <stdio.h>

//输入字符，放到temp缓冲区中，并且将字符川长度返回
#define STRLENGTH 10000
#define TEMPLENGTH 100

int getString( char * str )
{
    char t;
    int i = 0;
    for(; t = getchar() && t != '\0' && i < (STRLENGTH-1); ++i )
    {
        str[i] = t;
    }
    str[i] = '\0';
    return i;
}
//输出固定长度的字符串，少的补空格
void printStr(char * start, int length, int  allLength)
{
    for( int i = 0; i < allLength; ++i )
    {
        if( i < length ) putchar( start[i] );
        else putchar( ' ' );
    }
    printf("\n");
    return;
}
//将字符串打包成最大长度的字符串，以空格分割，多余补空格

void split(char * str, int length, int retLength)
{
    char temp[100] = "";
    int start = 0;
    int i = retLength;
    for( ; i < length  ; start = i,i += retLength)
    {

        if(str[i] == ' ')
        {
            printStr( &str[start], retLength, retLength );
            ++i;
        }
        else
        {
            int j = 1;
            for(; str[i-j] !=' ' && i <= retLength; ++j);
            if( j == retLength )
                printStr( &str[start], retLength, retLength );
            else
            {
                printStr( &str[start],retLength-j,retLength );
                i = i - j + 1;
            }

        }

    }
}



int main()
{
    char str[STRLENGTH] = "";
    int strLeg;
    strLeg = getString( str );
    int spiLeg;
    scanf("%d", &spiLeg);
    split( str,  strLeg, spiLeg );
    return 0;

}
