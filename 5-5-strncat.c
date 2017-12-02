#include <stdio.h>

void mystrncat(char *s, char *t, int n)
{
  // move *s to end of string
  while (*s++)
    ;

  s--;

  while ((*s++ = *t++) && --n)
    ;
}

int main()
{
  char s[100] = "hello";
  char *t = "howdy";
  mystrncat(s, t, 3);
  printf("%s\n", s);
}
