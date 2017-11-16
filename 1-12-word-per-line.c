#include <stdio.h>

int main()
{
  int c;

  c = getchar();

  while (c != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      putchar('\n');

      while (c == ' ' || c == '\t' || c == '\n') {
        c = getchar();
      }
    } else {
      putchar(c);
      c = getchar();
    }

  }
}
