/*************************************************************************
	> File Name: first.cpp
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Fri Dec  4 10:16:35 2020
 ************************************************************************/

#include<iostream>
#include "Sales_item.h"
using namespace std;

int main() {
	Sales_item item1, item2;
	cin >> item1;
	while (cin >> item2)
	{
		item1 += item2;
	}
	cout << item1 << endl;
	return 0;
}
