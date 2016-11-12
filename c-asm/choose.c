// 汇编语言和Ｃ语言相互调用示例
//

void myprint( char* str, int len );

int choose(int a, int b){
    if( a >= b ){
        myprint("the 1st biger\n", 15);
    }else{
        myprint("the 2nd biger\n", 15);
    }
    return 0;
}
