#include <stdio.h>
#include <stdlib.h>

int minStep(int *arr,int at, int len){
    int lastStep,temp;
    if( arr[at] <= 0 ){//如果所在的柱子弹力为0,则不可达，因为len个柱子，
        //最多跳len-1次，所以返回len认为是无限大，既不可达
        return len;
    }else if(arr[at] + at > len-1 ){//所在的柱子+弹力 > 最后一个柱子的下标
        //(柱子下标从0开始，所以需要-1)，则只需要跳一次就能到达。
        return 1;
    }else {
        lastStep = len;//要选剩余最小跳数，所以设个最大的阀置
        for(int i = 1; i <= arr[at]; ++i ){//
            temp = minStep(arr,at+i,len);
            lastStep = (lastStep <= temp) ? lastStep : temp;
        }
        return ++lastStep;//将本次跳的加上，返回
    }
}

int getStep(int *arr, int len){
    int step = minStep(arr, 0, len);
    if( step >= len )
        return -1;
    else
        return step;
}

int main(){
    int num = 0;
    int *arr = NULL;
    while( 1 == scanf("%d",&num) ){
        arr = (int *)malloc(sizeof(int)*num);
        for(int i = 0; i < num; i++){
            scanf("%d",&arr[i]);
        }
        printf("%d\n",getStep(arr,num));
    }
    return 0;
}
