#include <stdio.h>

void expand(char s1[], char s2[])
{
  int i, j;
  char prev, next;

  for (i = j = 0; s1[i] != '\0'; i++) {
    if (s1[i] == '-' && i > 0 && (next = s1[i + 1]) != '\0') {
      prev = s1[i - 1];
      for (char c = prev + 1; c < next; c++)
        s2[j++] = c;
    } else {
      s2[j++] = s1[i];
    }
  }
}

int main()
{
  char s1[] = "-a-c0-9 g-i-l";
  char s2[100];
  expand(s1, s2);

  printf("%s\n%s\n", s1, s2);
}
