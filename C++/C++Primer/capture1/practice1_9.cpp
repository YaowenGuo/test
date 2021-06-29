/*************************************************************************
	> File Name: practice1_9.cpp
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Mon Jun 28 09:33:25 2021
 ************************************************************************/

#include<iostream>
using std::cout;
using std::endl;

int main() {
	uint32_t sum = 0;
	uint32_t counter = 50;
	while (counter <= 100) {
		sum += counter;
		++counter;
	}
	cout << "Sum of 50 to 100 is: " << sum << endl;
	return 0;
}
