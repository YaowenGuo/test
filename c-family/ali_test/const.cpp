#include <iostream>
using namespace std;

int main(){
    int aa = 0;
    const int *a ;
    int  * const b = 0;
    const int *  c;
    int * const d = 0;
    if( a > b ){
        cout<<"A"<<endl;
    }else{
        cout<<"B"<<endl;
    }
}
