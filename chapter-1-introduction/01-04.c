#include <stdio.h>

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = -20;
  upper = 100;
  step = 10;

  celsius = lower;

  printf("%s %s\n", "Celsius", "Fahrenheit");

  while (celsius <= upper)
  {
    fahr = celsius * (9.0 / 5.0) + 32;
    printf("%7.1f %10.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
