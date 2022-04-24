#include <stdio.h>

#define TAB_SIZE 4
#define COLUMN 20

int get_line(char line[], int max_size);
void clean_char_array(char arr[], int size);

int main()
{
  int fold_position;
  char line[COLUMN + 2];

  while ((fold_position = get_line(line, COLUMN)) != EOF)
  {
    if (fold_position != 0)
      printf("%s", line);

    clean_char_array(line, COLUMN);
  }

  if (line[0] != '\n')
    printf("%s", line);

  return 0;
}

int get_line(char line[], int limit)
{
  int c;
  int i = 0;
  int ptr = 0;

  for (i = 0; ptr < limit && (c = getchar()) != EOF && c != '\n'; ++i)
  {
    line[i] = c;

    if (c == '\t')
      ptr = ptr + TAB_SIZE;
    else
      ptr = ptr + 1;
  }

  for (i = limit - 1; i >= 0; --i)
    if (line[i] == ' ' || line[i] == '\t' || line[i] == '\0')
      line[i] = 0;
    else
      break;

  line[i + 1] = '\n';
  line[i + 2] = '\0';

  if (c == EOF)
    return EOF;
  else
    return i + 1;
}

void clean_char_array(char arr[], int size)
{
  int i;
  for (i = 0; i < size; ++i)
    arr[i] = 0;
}
