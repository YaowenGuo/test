#ifndef HELLO_CPP
#define HELLO_CPP

#define PI 3.1415926
#define FOO(A, B) int foo(A x, B y)

#endif

// hello.cpp

using namespace std;

using IntPair = std::pair<int, int>;


#define REMOVE_PARENS(...) __VA_ARGS__

#define BAR(A, B) int foo(REMOVE_PARENS A, REMOVE_PARENS B)

FOO(bool, IntPair);                  // -> int foo(bool x, IntPair y)
BAR((bool), (std::pair<int, int>));  // -> int foo(bool x, std::pair<int, int> y)

// TODO 思考，如何同时处理带括号和不带括号的？
// BAR(bool, (std::pair<int, int>))


int main() {
  int radius = 4;
  int air = PI * radius * radius;
}