#include <stdio.h>

int main()
{
  int c;

  while ((c = getchar()) != EOF) {
    putchar(c);
    putchar(c);
  }

  printf("EOF: %d\n", EOF);
}
