#include <stdio.h>

#define swap(t, x, y) {\
  t temp = x;\
  x = y;\
  y = temp;\
}


int main()
{
  int a, b;
  a = 10; b = 20;
  printf("%d %d\n", a, b);
  swap(int, a, b);
  printf("%d %d\n", a, b);
}
