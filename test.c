#include <stdio.h>

int main()
{
  char *a = "abc";
  int b[] = {1,2,3};
  char *p = a;
  int *q = b;

  printf("%c %d %d %d %d\n", *p, *q, q > p, q < p, q == p);
}
