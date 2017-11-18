#include <stdio.h>

#define MAXLINE 100

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0)
    if (len > 15) {
      printf("%s", line);
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
