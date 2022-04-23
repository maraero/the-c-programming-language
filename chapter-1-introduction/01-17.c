#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int get_line(char line[], int maxline);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    // count after overflow
    if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n')
    {
      int c;
      while ((c = getchar()) != EOF && c != '\n')
      {
        len++;
      }
    }

    // print out
    if (len > LIMIT)
    {
      if (len > MAXLINE)
        printf("line: %s...\n", line);
      else
        printf("line: %s\n", line);

      // clean char array
      int i;
      for (i = 0; i < MAXLINE; ++i)
        line[i] = 0;
    }
  }

  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
