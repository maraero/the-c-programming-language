#include <stdio.h>

#define LETTERS 26
#define NUMBERS 10

int main()
{
  int i;
  char freq[LETTERS + NUMBERS];

  for (i = 0; i < LETTERS + NUMBERS; ++i)
    freq[i] = 0;

  char c;

  while ((c = getchar()) != EOF)
  {
    if (c >= 'a' && c <= 'z')
      ++freq[c - 'a'];
    if (c >= '0' && c <= '9')
      ++freq[c - '0' + LETTERS];
  }

  int j;
  char symbol;

  printf("\n");

  for (i = 0; i < LETTERS + NUMBERS; ++i)
  {
    if (freq[i] > 0)
    {
      if (i < LETTERS)
      {
        symbol = 'a' + i;
      }
      else
      {
        symbol = '0' + i - LETTERS;
      }

      printf("%c: ", symbol);
      for (j = 0; j < freq[i]; ++j)
        printf("#");
      printf("\n");
    }
  }
}
