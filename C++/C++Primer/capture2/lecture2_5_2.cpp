/*************************************************************************
	> File Name: lecture2_5_2.cpp
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Wed Jun 23 10:26:27 2021
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
	auto i = 0, *p = &i;
	//auto sz = 0, pi = 3.14;
	
	int &r = i;
	auto a = r; // a 是一个整数，而不是别名。

	const int ci = i, &cr = ci;
	auto b = ci; // b 是一个整数（ci 的顶层const特性被忽略掉了。）
	auto c = cr; // c 也是一个整数
	auto d = &i; // d 是一个整型指针
	auto e = &ci; // e 是一个指向整常数的指针。（对常量对象去地址是一种底层 const）


	const auto f = ci; // ci 的推演类型是 int, f 是 const int.

	return 0;
}

