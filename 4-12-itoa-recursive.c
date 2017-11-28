#include <stdio.h>

int itoa(int num, char a[])
{
  int index;

  if (num / 10)
    index = itoa(num / 10, a);
  else {
    index = 0;
  }

  a[index] = num % 10 + '0';
  a[index + 1] = '\0';

  return index + 1;
}

int main()
{
  char output[100];

  itoa(123, output);
  printf("%s\n", output);
}
