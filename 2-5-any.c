#include <stdio.h>

int charInString(char c, char s[])
{
  int i = 0;
  char other;

  while ((other = s[i++]) != '\0')
    if (c == other)
      return 1;

  return 0;
}

// Returns first index of any char from s2 in s1
int any(char s1[], char s2[])
{
  int i;

  for (i = 0; s1[i] != '\0'; i++)
    if (charInString(s1[i], s2))
      return i;

  return -1;
}

int main()
{
  char s[10] = "abcdefg";
  printf("%d\n", any(s, "ag"));
  printf("%d\n", any(s, "ba"));
  printf("%d\n", any(s, "bc"));
  printf("%d\n", any(s, "gh"));
  printf("%d\n", any(s, "hij"));
}
