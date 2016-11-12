#include <stdio.h>
#include <stdlib.h>
void sort(int * arr, int len){
    int temp = 0;
    int tempMax = 0;

    for( int i = len-1; i > 0; --i  ){
        tempMax = 0;
        for( int j = 0; j <= i ; ++j ){
            if( arr[j] > arr[tempMax] ) tempMax = j;
        }
        if( tempMax != i ){
            temp = arr[i];
            arr[i] = arr[tempMax];
            arr[tempMax] = temp;
        }
    }
    return ;
}


int getNum(int * arr, int len){
    int i = 0;
    int num = 0;
    while( i < len ){
        if( i+3 > len  ){
            num += (len - i);
            return num;
        }
        if(arr[i+1] - arr[i] > 20 ){
            num += 2;
            i++;
        }else if(arr[i+1] - arr[i] > 10){
            num += 1;
            i += 2;
        }else{
            if( arr[i+2] - arr[i+1] > 10 ){
                num += 1;
                i += 2;
            }else{
                i += 3;
            }
        }
    }
    return num;
}


int main(){
    int n = 0;
    int * arr;
    while( 1 == scanf("%d", &n) ){

        arr = (int *)malloc( sizeof(int) * n );
        for(int i = 0; i < n; ++i){
            scanf("%d",&arr[i]);
        }
        sort(arr, n);
        for( int i = 0; i < n; ++i ){
            printf("%d ",arr[i]);
        }
        putchar('\n');
        printf("%d\n",getNum( arr,n ));
        free(arr);
    }
    return 0;
}
