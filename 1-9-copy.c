#include <stdio.h>

int main()
{
  int c;
  c = getchar();
  while (c != EOF) {
    if (c != ' ') {
      putchar(c);
      c = getchar();
    } else {
      putchar(' ');
      while ((c = getchar()) == ' ') {}
    }
  }
}
