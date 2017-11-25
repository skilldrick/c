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

char rightrot(char x, int n)
{
  // Have to mask out left n bits when shifting right by n bits
  // to emulate a logical bit shift
  char mask = ~(~0 << (8 - n));
  char rightSide = (x >> n) & mask;

  char leftSide = x << (8 - n);

  return rightSide | leftSide;
}

int bitcount(char x)
{
  int bits = 0;

  while (x) {
    x &= x - 1;
    bits++;
  }

  return bits;
}

int main()
{
  printf("%d\n", bitcount(0b10111010));
}
