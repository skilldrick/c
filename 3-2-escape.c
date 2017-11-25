#include <stdio.h>

void escape(char s[], char t[])
{
  int i, j;
  i = j = 0;

  while (t[j] != '\0') {
    switch (t[j]) {
      case '\t':
        s[i++] = '\\';
        s[i] = 't';
        break;
      case '\n':
        s[i++] = '\\';
        s[i] = 'n';
        break;
      default:
        s[i] = t[j];
    }
    i++; j++;
  }
  t[j] = '\0';
}

void unescape(char s[], char t[])
{
  int i, j;
  i = j = 0;

  while (t[j] != '\0') {
    if (t[j] == '\\') {
      j++;
      switch (t[j]) {
        case 't':
          s[i] = '\t';
          break;
        case 'n':
          s[i] = '\n';
          break;
        default:
          s[i] = '\\';
      }
    } else {
      s[i] = t[j];
    }

    i++; j++;
  }
}

int main()
{
  char s[100];
  char t1[] = "hell\no\tthere";
  char t2[] = "hell\\no\\tthere";

  escape(s, t1);
  printf("%s\n", s);

  unescape(s, t2);
  printf("%s\n", s);
}
