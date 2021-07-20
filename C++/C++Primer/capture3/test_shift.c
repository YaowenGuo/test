#include <stdio.h>

int main() {
  char a = 0xf;
  printf("%d\n", a);
  a = a << 8;
  printf("%d\n", a);
  return 0;
}
