#include <stdio.h>

#define BUFFER 101

int main()
{
  // Init histogram
  int words[BUFFER];

  int i;
  for (i = 0; i < BUFFER; ++i)
    words[i] = 0;

  char c;
  int current_word_length = 0;

  // Collect words amount by length
  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t' || c == '\n')
    {
      if (current_word_length > 0)
      {
        ++words[current_word_length];
      }

      current_word_length = 0;
    }
    else
      ++current_word_length;
  }

  if (current_word_length > 0)
    ++words[current_word_length];

  int longest_word = 0;
  int greatest_index = 0;

  for (i = 0; i < BUFFER; ++i)
  {
    if (words[i] > longest_word)
      longest_word = words[i];
    if (words[i] > 0)
      greatest_index = i;
  }

  if (longest_word == 0)
  {
    printf("There is no words\n");
    return 0;
  }

  // Print horizontal histogram
  printf("\nHorizontal Histogram\n--------------------\n");

  int col_index = 1;
  int line_index = 0;

  while (col_index <= greatest_index)
  {
    printf("%3d: \t", col_index);

    for (line_index = 0; line_index < words[col_index]; ++line_index)
      putchar('#');

    putchar('\n');
    ++col_index;
  }

  // Print vertical histogram
  printf("\nVertical Histogram\n--------------------\n");

  col_index = 1;
  line_index = 1;

  while (line_index <= longest_word)
  {
    while (col_index <= greatest_index)
    {
      if (line_index > longest_word - words[col_index])
      {
        printf("   # ");
      }
      else
      {
        printf("     ");
      }
      ++col_index;
    }
    printf("\n");
    col_index = 1;
    ++line_index;
  }

  while (col_index <= greatest_index)
  {
    printf("%4d ", col_index);
    ++col_index;
  }
  printf("\n");

  return 0;
}
