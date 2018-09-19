#include <iostream>
using namespace std;

class A{
public:
    A( int a );
    A():x(2){};
private:
    int x;
};

A::A( int a ){
    x = a;
}


int main(){
    A a[2] = { A(1) };
    cout<<"xcvxcv"<<endl;
}
