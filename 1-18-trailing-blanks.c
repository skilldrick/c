#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxline);
int copyWithoutTrailingBlanks(char to[], char from[]);

int main()
{
  int len;
  char line[MAXLINE];
  char other[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    copyWithoutTrailingBlanks(other, line);
    if (len > 1) {
      printf("%s", other);
    }
  }


  return 0;
}

int getLine(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    i++;
  }

  s[i] = '\0';

  if (i >= lim - 1) {
    for (; (c = getchar()) != EOF && c != '\n'; i++) {}
  }

  return i;
}

int copyWithoutTrailingBlanks(char to[], char from[])
{
  int i, trailingBlanks, len;
  i = trailingBlanks = 0;

  while ((to[i] = from[i]) != '\0') {
    if (to[i] == ' ') {
      trailingBlanks++;
    } else if (to[i] != '\0' && to[i] != '\n') {
      trailingBlanks = 0;
    }

    i++;
  }

  len = i - (trailingBlanks + 1);
  to[len] = '\n';
  to[len + 1] = '\0';

  return len;
}
