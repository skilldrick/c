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

char getbits(unsigned char x, int p, int n)
{
  return (x >> (p + 1 - n)) & ~(~0 << n);
}

char setbits(char x, int p, int n, char y)
{
  char mask = ~(~(~0 << n) << (p - n));
  return x & mask | (getbits(y, n - 1, n) << (p - n));
}


int main()
{
  printf("%s\n", byte_to_binary(setbits(0b11111111, 5, 3, 0b10101010)));
}
