#include <stdio.h>
#include <stdlib.h>
/*
 * 比较两两异或过之后大于com参数的个数
 * arr：要抑或的数组
 * len：数组长度
 * con：要比较的基数
 * return: 返回大于com的个数
 */
int compare(int * arr, int len, int com){
    int count = 0;
    for( int i = 0; i < len-1; ++i ){
        for( int j = i; j < len; ++j ){
            if( (arr[i] ^ arr[j]) > com ) count++;
        }
    }
    return count;
}

int main(){
    int n,m;
    int * arr = 0;
    while( 1 == scanf("%d", &n)  ){
        scanf("%d",&m);
        if( n <= 0 ){
            printf("%d", 0 );
            return 0;
        }
        arr = (int *)malloc( sizeof(int)*n );
        for(int i = 0; i < n; ++i){
            scanf("%d",&arr[i]);
        }
        printf("%d\n", compare(arr, n, m));
        free(arr);
    }
    return 0;
}
