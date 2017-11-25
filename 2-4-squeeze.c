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

void squeeze(char s1[], char s2[])
{
  int i, j, c;

  for (i = j = 0; s1[i] != '\0'; i++)
    if (!charInString(s1[i], s2))
      s1[j++] = s1[i];

  s1[j] = '\0';
}


int main()
{
  char s[10] = "abcdefg";
  squeeze(s, "eg");
  printf("%s\n", s);
}
