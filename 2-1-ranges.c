#include <stdio.h>
#include <limits.h>

int main()
{
  printf("char: %d - %d\n", CHAR_MIN, CHAR_MAX);
  printf("uchar: 0 - %d\n", UCHAR_MAX);

  printf("int: %d - %d\n", INT_MIN, INT_MAX);
  printf("uint: 0 - %d\n", UINT_MAX);
}
