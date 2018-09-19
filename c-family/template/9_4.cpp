#include <iostream>
#include <iomanip>
#include "Array.h"
using namespace std;

int main(){
    Array<int> a(10);
    int count = 0;

    int n;
    cout<<"Enter a value >= 2 as upper limit for prime nmber: ";
    cin>>n;
    int harf = count/2;
    for(int i = 2; i <= n; i++){
        bool isPrime = true;
        for(int j = 0; j <= harf; j++)
            if( i % a[j] == 0 )
    }
}
