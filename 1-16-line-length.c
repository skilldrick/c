#include <stdio.h>

#define MAXLINE 10

int getLine(char line[], int maxline);
void copy(char to[], char from[]);


int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0) 
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  int i;
  for (i = 0; i < MAXLINE; i++) {
    printf("x %d %c\n", longest[i], longest[i]);
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
  } else if (s[i] != '\n' && i > 0) {
    s[i - 1] = 'x';
  }

  s[i] = '\0';

  if (i >= lim - 1) {
    for (; (c = getchar()) != EOF && c != '\n'; i++) {}
  }

  return i;
}

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}


