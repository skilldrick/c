#include <stdio.h>
#include <string.h>

int htoi(char s[])
{
  int i = strlen(s) - 1;
  int c;
  int cAsInt;
  int digitValue = 1;
  int output = 0;

  while (i >= 0 && (c = s[i]) != 'x' && c != 'X') {
    if (c >= '0' && c <= '9') {
      cAsInt = c - '0';
    } else if (c >= 'A' && c <= 'F') {
      cAsInt = c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
      cAsInt = c - 'a' + 10;
    } else {
      return -1;
    }

    output += cAsInt * digitValue;
    digitValue *= 16;
    i--;
  }

  return output;
}

int main()
{
  printf("%d\n", htoi("0x123"));
  printf("%d\n", htoi("CCC"));
}
