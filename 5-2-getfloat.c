#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
  int c;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF) {
    ungetch(c);
    return 0; // not a number
  }

  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  if (c == '.') {
    float place = 10.0;
    while (isdigit(c = getch())) {
      *pn += (c - '0') / place;
      place *= 10;
    }
  }

  if (c != EOF)
    ungetch(c);

  return c;
}

int main()
{
  double f;
  while (getfloat(&f) != EOF)
    printf("%.8g\n", f);
}

#define BUFSIZE   100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
