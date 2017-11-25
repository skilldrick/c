#include <stdio.h>

const char *byte_to_binary(int x)
{
  static char b[9];
  int z, i;
  for (z = 128, i = 0; z > 0; z >>= 1, i++)
    b[i] = ((x & z) == z) ? '1' : '0';
  b[i] = '\0';

  return b;
}

char invert(char x, int p, int n)
{
  char mask = ~(~0 << n) << (p - n);
  printf("mask: %s\n", byte_to_binary(mask));
  return x ^ mask;
}

int main()
{
  printf("%s\n", byte_to_binary(invert(0b10101010, 5, 3)));
  printf("%s\n", byte_to_binary(invert(0b10101010, 6, 6)));
}
