/*************************************************************************
	> File Name: practice1_11.cpp
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Mon Jun 28 10:07:29 2021
 ************************************************************************/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	cout << "Input 2 number to print interger betwen them." << endl;

	int num1, num2;
	cin >> num1 >> num2;

	int start, end;
	if (num1 < num2) {
		start = num1;
		end = num2;
	} else {
		start = num2;
		end = num1;
	}

	while (start < end - 1) {
		++start;
		cout << start << endl;
	}
	return 0;
}
