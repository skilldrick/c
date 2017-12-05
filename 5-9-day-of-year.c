#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
  char *p, leap;
  char *tabForYear;

  leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
  tabForYear = *(daytab + leap);

  for (p = tabForYear + 1; p < tabForYear + month; p++)
    day += *p;

  return day;
}

int main()
{
  printf("%d\n", day_of_year(2016, 12, 2));
  printf("%d\n", day_of_year(2017, 12, 2));
}
