#include <stdio.h>

int strend(char *s, char *t)
{
  char *torig = t;

  // move *s to end of string
  while (*s++)
    ;
  s--;

  // move *t to end of string
  while (*t++)
    ;
  t--;

  while (t >= torig) {
    if (*s != *t)
      return 0;

    s--; t--;
  }

  return 1;
}

int main()
{
  char s[100] = "hello";
  char *t = "ello";
  char *u = "xello";
  printf("%d %d\n", strend(s, t), strend(s, u));
}
