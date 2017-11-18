#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxline);
void copyAndReverse(char to[], char from[]);

int main()
{
  int len;
  char line[MAXLINE];
  char other[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    copyAndReverse(other, line);
    printf("%s", other);
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

void copyAndReverse(char to[], char from[])
{
  int i, len;
  i = 0;

  while (from[i] != '\0' && from[i] != '\n') i++;

  len = i;

  while (i > 0) {
    to[len - i] = from[i - 1];
    i--;
  }

  to[len] = '\n';
  to[len + 1] = '\0';
}
