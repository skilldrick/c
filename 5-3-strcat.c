#include <stdio.h>

void mystrcat(char *s, char *t)
{
  // move *s to end of string
  while (*s++)
    ;

  s--;

  while ((*s++ = *t++))
    ;
}

int main()
{
  char s[100] = "hello";
  char *t = "howdy";
  mystrcat(s, t);
  printf("%s\n", s);
}
