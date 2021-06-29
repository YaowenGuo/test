/*************************************************************************
	> File Name: test_string.cpp
	> Author: YaowenGuo
	> Mail: 1441250996@qq.com 
	> Created Time: Sat Jun 26 10:25:07 2021
 ************************************************************************/

#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;


int main() {
	char s1[] = "hiya";
	string s6 = s1;
	cout << "s1 addr: " << &s1 <<  ", s6 addr: " <<  &s6 << endl;
	
	return 0;	
		
}
