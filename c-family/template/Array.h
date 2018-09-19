//Array.h

#ifndef ARRAY_H
#define ARRAY_H
#include <cassert>

//数组类模板定义
template<typename T>
class Array{
private:
    T* list;
    int size;
public:
    Array(int sz = 50);
    Array(const Array<T>& a);
    ~Array();
    Array<T>& operator =(const Array<T>& rhs);//“=”运算符重载
    T & operator [](int i)const;        //"[]"重载
    T operator *();      //"*"重载，使Array可以转换到普通数组类型
    const T operator *() const;//"*"重载，对象到数组的常成员函数
    int getSize() const;//获取数组大小
    void resize(int sz);//修改数组大小
}

Array<T>::Array(int sz){
    assert( sz >= 0 );
    size = sz;
    list = new T[size];
}

Array<T>::Array(const Array<T>& a){
    size = a.size;
    list = new T[size];
    for(int i = 0; i < size; i++)
        list[i]  = a.list[i];
}

Array<T>& Array<T>::operator =(const Array<T>& rhs){
    if( &ths != this ){
        if( size != rhs.size ){
            delete[] list;
            size = rhs.size;
            list = new T[size];
        }
        for(int i = 0; i < size; i++)
            list[i] = rhs.list[i];
    }
    return this;
}

T & Array<T>::operator [](int n){
    assert( n >= 0 && n < size ){
        return list[i];
    }
}

const T& Array<T>::operator [](int n)const{
    assert( n >= 0 && n < size );
    return list[i];
}

T Array<T>::operator *(){
    return list;
}

const T Array<T>::operator *(){
    return list;
}

int Array<T>::getSize() const{
    return size;
}

void Array<T>::resize(int sz){
    assert( sz >= 0 );
    if( sz ==size )
        return;
    T * newList = new T[size];
    int n = sz<size ? sz : size;
    for( int n = 0; i < n; ++i )
        newList[i] = list[i];
    delete[] list;
    list = newList;
    size = sz;
}
#endif //ARRAY_H
