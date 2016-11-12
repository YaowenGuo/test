#include <iostream>
using namespace std;
#pragma pack(2)
typedef struct A{
    bool a;
    double & pa;
    short d;
    double b;
    short c;
} ST;
#pragma pack()
int main(){
    double b;
    double c;
    ST a = {0,b,0,1,1};
    a.pa = b;
    cout<<sizeof(ST)<<endl;
    cout<<sizeof(a.pa)<<endl;
    //printf("%u\n",&a.b);
    //printf("%u\n",&a.c);
    return 0;
}
