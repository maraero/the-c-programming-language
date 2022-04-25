#include <stdio.h>

#define NORMAL 10
#define DOUBLE_SLASH_COMMENT 11
#define ASTERISK_COMMENT 12
#define DOUBLE_QUOTE 13
#define SINGLE_QUOTE 14

#define STACK_MAX_SIZE 1024

#define TRUE 1
#define FALSE 0

int check_pair(char close, char open);

int main()
{
  int c, status, stack_position;
  char prev;
  char stack[STACK_MAX_SIZE];

  status = NORMAL;
  stack_position = 0;

  while ((c = getchar()) != EOF)
  {
    if (status == NORMAL)
    {
      if (c == '(' || c == '[' || c == '{')
      {
        stack[stack_position] = c;
        ++stack_position;
      }
      else if (c == ')' || c == ']' || c == '}')
      {
        --stack_position;

        if (check_pair(c, stack[stack_position]) == FALSE)
        {
          printf("Error\n");
          return -1;
        }
      }

      if (prev == '/' && c == '/')
        status = DOUBLE_SLASH_COMMENT;
      else if (prev == '/' && c == '*')
        status = ASTERISK_COMMENT;
      else if (prev != '\\' && c == '"')
        status = DOUBLE_QUOTE;
      else if (prev != '\\' && c == '\'')
        status = SINGLE_QUOTE;
    }

    else if (status == DOUBLE_SLASH_COMMENT)
    {
      if (prev != '\\' && c == '\n')
        status = NORMAL;
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
    }

    else if (status == SINGLE_QUOTE)
    {
      if (prev != '\\' && c == '\'')
        status = NORMAL;
    }

    prev = c;
  }

  if (stack_position == 0)
  {
    printf("No error\n");
    return 0;
  }
  else
  {
    printf("Error\n");
    return -1;
  }
}

int check_pair(char close, char open)
{
  if (close == ')' && open == '(')
    return TRUE;
  else if (close == ']' && open == '[')
    return TRUE;
  else if (close == '}' && open == '{')
    return TRUE;
  else
    return FALSE;
}
