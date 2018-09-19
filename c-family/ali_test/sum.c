#include <stdio.h>
#define TEMPLEN 1000
#define MAPLEN 100
int main()
{
    char str[TEMPLEN] = "";
    int map[MAPLEN];
    int sum = 0;
    int max = 0,tempMax = 0;
    while(scanf("%s", str) != 0)
    {
        for( int i = 0; i < MAPLEN; ++i ) map[i] = 0;

        for( int i = 0; str[i] != '\0'; ++i )
        {
            sum = 0;
            while( '0' <= str[i]  && str[i] <= '9')
            {
                sum = sum*10+(str[i]-'0');
                ++i;
            }
            map[sum]++;
        }
        for(int i = 0; i < MAPLEN; ++i )
        {
            tempMax = i * map[i];
            if(tempMax > max) max = tempMax;
        }
        printf("%d\n", max);

    }
}
