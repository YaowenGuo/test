// 无法拼接元组，将报错。
// #define FOO(A, B) int foo(A x, B y)
// #define BAR(A, B) FOO(REMOVE_PARENS ## A, REMOVE_PARENS ## B)
// BAR(bool, (std::pair<int, int>));


#define BAR() bar

// #define PP_CONCAT(A, B) PP_CONCAT_IMPL(A, B)
#define PP_CONCAT_IMPL(A, B) A##B

#define FOO(N) PP_CONCAT_IMPL(foo_, N)

FOO(bar)    // -> foo_bar
FOO(BAR())  // -> foo_bar
