#include <stdio.h>

#define TAB_SIZE 4

int main()
{
  int c;
  int i;
  int space_counter = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      ++space_counter;

      if (space_counter == TAB_SIZE)
      {
        putchar('\t');
        space_counter = 0;
      }
    }
    else
    {
      for (i = 0; i < space_counter; ++i)
        putchar(' ');
      space_counter = 0;
      putchar(c);
    }
  }

  return 0;
}
