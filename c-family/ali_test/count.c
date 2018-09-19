#include <stdio.h>

/*
 *计算每组数据运行的次数
 *str是否要检查的01字符串
 *len整个字符串的长度
 *最多运行次数
 *return 最小区间最大长度
 */
int runTime(char *str,int len, int time){
    int maxlen = len/time;
    int mixlen = 0;
    int temp = 0;
    if(maxlen*time < len) maxlen++;
    for(int i = 0; i < len; i++){

    }
}

int main(){
    int zu= 0;
    int len, time;
    char * str = 0;
    int run;
    scanf("%d",&zu);
    for( int i = 0; i < zu; ++i ){
        scanf("%d%d",&len,&time);
        str = (char *)malloc(sizeof(char)*len +1);
        scanf("%s",str);
        run = runTime(str, len, time);
        printf("Case: %d;",i, run);

    }
    return 0;
}
