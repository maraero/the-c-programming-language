#include <stdio.h>

#define TAB 4

int main()
{
  int c;
  int i;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      for (i = 0; i < TAB; ++i)
        putchar(' ');
    else
      putchar(c);
  }

  return 0;
}
