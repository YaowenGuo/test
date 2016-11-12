#include <stdio.h>
/*
 * 获取相同字的个数，
 * c:首个字符，
 * def:返回下一个不同的字符
 * return 相同的字符的个数
 */
int getSameChar(char c,char* def){
    int ret = 0;
    do{
        ret++;
        *def = getchar();
    }while( *def == c );
    return ret;
}
int main(){
    char ch = getchar();
    int num[36] = {0,0,0};
    int temp,index,class = 0;;
    while(ch != EOF || ch != '\n'){
        index = ch - 'a';
        temp = getSameChar(ch,&ch);
        if(temp > num[index]) num[index] = temp;
    }
    for(int i = 0; i < 36; ++i){
        class += num[i];
    }
    printf("%d\n",class);
    return 0;
}
