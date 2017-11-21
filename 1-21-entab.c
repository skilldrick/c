#include <stdio.h>

#define TABWIDTH 8

int main()
{
  int charInLine, charsToTab, consecutiveSpaces, c;

  charInLine = 0;
  consecutiveSpaces = 0;


  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      consecutiveSpaces++;
    } else {
      if (consecutiveSpaces > 0) {
        int tabs, spaces, i, spacesUntilTabstop;

        // is the number of tabs to get to the current char less than the number of
        // tabs to get to the char + spaces?
        if (((charInLine + consecutiveSpaces) / TABWIDTH) > (charInLine / TABWIDTH)) {
          spacesUntilTabstop = TABWIDTH - (charInLine % TABWIDTH);

          // put a single tab
          putchar('\t');
          // and update charInLine and consecutiveSpaces
          charInLine += spacesUntilTabstop;
          consecutiveSpaces -= spacesUntilTabstop;

          // now figure out how many tabs we need for the remaining spaces
          tabs = consecutiveSpaces / TABWIDTH;
          for (i = 0; i < tabs; i++) {
            putchar('\t');
            charInLine += TABWIDTH; // don't really need to do this as we're always modding
          }

          // and how many spaces
          spaces = consecutiveSpaces % TABWIDTH;
          for (i = 0; i < spaces; i++) {
            putchar(' ');
            charInLine++;
          }
        } else {
          spaces = consecutiveSpaces % TABWIDTH;
          for (i = 0; i < spaces; i++) {
            putchar(' ');
            charInLine++;
          }
        }
      }

      consecutiveSpaces = 0;
      putchar(c);
      charInLine++;
    }

    if (c == '\n') {
      charInLine = 0;
    }
  }
}
