/*************************************************************************
	> File Name: practice3_6.cpp
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Tue Jun 29 09:48:04 2021
 ************************************************************************/

#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int main() {
	string str("Hello world!");
	for (auto ch : str) {
		ch = 'X';
	}
    cout << str << endl;
	return 0;
}
