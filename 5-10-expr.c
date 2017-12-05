#include <stdio.h>
#include <stdlib.h>

#define MAXOP   100
#define NUMBER  '0'

int getop(char *, char *);
void push(double);
double pop(void);

int main(int argc, char **argv)
{
  char *arg;
  int type;
  double op2;
  char s[MAXOP];

  while (argc-- && (arg = *++argv) && (type = getop(arg, s))) {
    //printf("%s\n", s);
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push((int) pop() % (int) op2);
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }

  printf("\t%.8g\n", pop());
}


#include <ctype.h>

int getop(char *arg, char *s)
{
  int i, c;

  *s = c = *arg;
  s[1] = '\0';

  if (!isdigit(c) && c != '.')
    return c; // not a number

  if (isdigit(c))
    while (isdigit(*++s = c = *++arg))
      ;

  if (c == '.')
    while (isdigit(*++s = c = *++arg))
      ;

  *++s = '\0';

  return NUMBER;
}

#define MAXVAL  100

double val[MAXVAL];
double *sp = val;

void push(double f)
{
  if (sp < val + MAXVAL)
    *sp++ = f;
  else
    printf("error: stack full\n");
}

double pop(void)
{
  if (sp > val)
    return *--sp;
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

