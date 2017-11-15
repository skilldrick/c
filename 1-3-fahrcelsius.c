#include <stdio.h>

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Fahrenheit  Celsius\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3.0f\t%11.1f\n", fahr, celsius);
    fahr += step;
  }

  celsius = lower;
  printf("\nCelsius  Fahrenheit\n");

  while (celsius <= upper) {
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf("%3.0f\t%11.1f\n", celsius, fahr);
    celsius += step;
  }
}
