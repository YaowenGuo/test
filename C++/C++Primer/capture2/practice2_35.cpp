/*************************************************************************
	> File Name: practice2_35.cpp
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Wed Jun 23 12:05:31 2021
 ************************************************************************/

#include<iostream>
using namespace std;

int main () {
	const int i = 42;
	auto j = i; // j 是值为 42 的 int 变量。
	const auto &k = i; // k 是 i 的常量引用。
	auto *p = &i; // 指向常量的指针。

	const auto j2 = i, &k2 = i; // j2 是 int 型常量。 k2 是和 k 相同的常引用。

	j = 53;
	printf("i: %d, j: %d\n", i, j);
	// k = 53; // 错误, 给 const int 赋值。
	// *p = 53; // 错误，p 指向的是一个 int 型常量。
	p = &j; // 正确。p 本身不是常量指针。
	j2 = 53; // 错误，给 int 型常量赋值。
	k2 = 53; // 错误，给 int 型常量引用赋值。
	return 0;
}
