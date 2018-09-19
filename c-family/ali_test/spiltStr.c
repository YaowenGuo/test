#include <stdio.h>
#include <stdlib.h>
#define TEMP_LEN 1000
int main(){
    char str[TEMP_LEN] = "";
    char endstr[TEMP_LEN] = "";
    int len = 0;
    int subindex = 0;
    while( gets(str) != NULL ){
        while(str[len] != '\0' && len < TEMP_LEN) ++len;

        int i = len-1;
        subindex = len-1;
        int j = 0;
        while(i >= 0){
            while( i >= 0 && str[i] != ' ' ) --i;
            if( subindex != len-1){
                endstr[j] = ' ';
                j++;
            }
            for(int start = 0; (i+start) <= subindex; start++,++j){
                endstr[j] = str[i+start];
            }
            endstr[j] = '\0';
            printf("%s\n",endstr);
            --i;
            subindex = i;

        }
    }
}
