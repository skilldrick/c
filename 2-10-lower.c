#include <stdio.h>

int lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main()
{
  printf("%c %c %c %c", lower('a'), lower('A'), lower('z'), lower('Z'));
}
