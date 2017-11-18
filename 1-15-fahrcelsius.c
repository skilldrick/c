#include <stdio.h>

#define   LOWER  0
#define   UPPER  300
#define   STEP   20

float convert(int);

int main()
{
  int fahr;

  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
    printf("%3d %6.1f\n", fahr, convert(fahr));
  }
}

float convert(int fahr)
{
  return (5.0 / 9.0) * (fahr - 32);
}
