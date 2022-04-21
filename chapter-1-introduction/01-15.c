#include <stdio.h>

float fahr_to_celsius(int fahr);

int main()
{
  int fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper)
  {
    printf("%d\t%3.1f\n", fahr, fahr_to_celsius(fahr));
    fahr = fahr + step;
  }
}

float fahr_to_celsius(int fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}
