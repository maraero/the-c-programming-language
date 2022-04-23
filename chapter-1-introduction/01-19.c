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
    for (i = len - 1; i >= 0; --i)
      printf("%c", line[i]);

    printf("\n");

    // clean char array
    int i;
    for (i = 0; i < MAXLINE; ++i)
      line[i] = 0;
  }

  return 0;
}

// without '\0' in the end
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n')
  {
    s[i] = c;
    ++i;
  }

  return i;
}
