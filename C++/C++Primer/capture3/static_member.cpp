#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Test
{
public:
    void test() {
        name = new string("hello");
        cout << (*name) << endl;
    }

private:
    string *name;
};


int main() {
    Test test;
    test.test();
    return 0;
}