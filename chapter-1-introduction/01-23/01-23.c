#include <stdio.h>

#define NORMAL 0
#define DOUBLE_SLASH_COMMENT 1
#define ASTERISK_COMMENT 2
#define DOUBLE_QUOTE 3
#define SINGLE_QUOTE 4

#define NOT_COMMENT 5
#define PROBABLY_COMMENT 6
#define FINALLY_NOT_COMMENT 7

int main()
{
  int c, status, possibleComment;
  char prev;

  status = NORMAL;
  possibleComment = NOT_COMMENT;

  while ((c = getchar()) != EOF)
  {
    if (status == NORMAL)
    {
      if (prev == '/' && c == '/')
        status = DOUBLE_SLASH_COMMENT;
      else if (prev == '/' && c == '*')
        status = ASTERISK_COMMENT;
      else if (prev != '\\' && c == '"')
        status = DOUBLE_QUOTE;
      else if (prev != '\\' && c == '\'')
        status = SINGLE_QUOTE;

      // handle different cases with slash char (/)
      if (status == NORMAL)
      {
        if (c == '/' && possibleComment == NOT_COMMENT)
          possibleComment = PROBABLY_COMMENT;
        else if (possibleComment == PROBABLY_COMMENT)
          possibleComment = FINALLY_NOT_COMMENT;
      }
      else
        possibleComment = NOT_COMMENT;

      if (status == NORMAL || status == DOUBLE_QUOTE || status == SINGLE_QUOTE)
      {
        if (possibleComment == NOT_COMMENT)
          putchar(c);
        else if (possibleComment == FINALLY_NOT_COMMENT)
        {
          possibleComment = NOT_COMMENT;
          putchar(prev);
          putchar(c);
        }
      }
    }

    else if (status == DOUBLE_SLASH_COMMENT)
    {
      if (prev != '\\' && c == '\n')
      {
        status = NORMAL;
        putchar('\n');
      }
    }

    else if (status == ASTERISK_COMMENT)
    {
      if (prev == '*' && c == '/')
        status = NORMAL;
    }

    else if (status == DOUBLE_QUOTE)
    {
      if (prev != '\\' && c == '"')
        status = NORMAL;
      putchar(c);
    }

    else if (status == SINGLE_QUOTE)
    {
      if (prev != '\\' && c == '\'')
        status = NORMAL;
      putchar(c);
    }

    prev = c;
  }

  return 0;
}
