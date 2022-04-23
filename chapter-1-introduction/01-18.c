#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main()
{
  int i;
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
  {
    for (i = len - 1; i > 0; --i)
      if (i == ' ' || i == '\t')
        line[i] = '\0';
      else if (i == '\n' || i == '\0')
        continue;
      else
        break;

    if (line[0] != '\n' && line[0] != '\0')
      printf("line: %s\n", line);

    // clean char array
    int i;
    for (i = 0; i < MAXLINE; ++i)
      line[i] = 0;
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
