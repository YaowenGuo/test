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