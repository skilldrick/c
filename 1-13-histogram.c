#include <stdio.h>

#define IN   1
#define OUT  0

int main()
{
  int i, j, c, state, currlength;
  int wordlength[10];

  state = OUT;
  currlength = 0;

  for (i = 0; i < 10; i++) {
    wordlength[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else {
      currlength++;

      if (state == OUT) {
        state = IN;
        if (currlength >= 9) currlength = 9;
        wordlength[currlength]++;
        currlength = 0;
      }
    }
  }

  for (i = 1; i < 10; i++) {
    if (i == 9) {
      printf("9+: ");
    } else {
      printf("%d:  ", i);
    }

    printf("%d  ", wordlength[i]);

    for (j = 0; j < wordlength[i]; j++)
      printf("%s", "\u25A0");

    putchar('\n');
  }
}
