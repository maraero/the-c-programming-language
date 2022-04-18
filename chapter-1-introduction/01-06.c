#include <stdio.h>

int main()
{
  printf("value of expression: %d", getchar() != EOF);
  return 0;
}

// NOTE: The expression getchar() != EOF is equal with 1 only if input char
// is != with EOF. The EOF char is accessible with CTRL+D on Unix like systems
