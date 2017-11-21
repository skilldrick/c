#include <stdio.h>

#define TABWIDTH 4

int main()
{
  int charInLine, charsToTab, c;

  charInLine = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int i;
      charsToTab = TABWIDTH - (charInLine % TABWIDTH);
      for (i = 0; i < charsToTab; i++) {
        putchar(' ');
      }
      charInLine += charsToTab;
    } else {
      putchar(c);
      charInLine++;
    }

    if (c == '\n') {
      charInLine = 0;
    }
  }
}
