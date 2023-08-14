#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[] = "Tell someone about God's love today";
  char *delim = " ";
  char *token;

  token = strtok(str, delim);

  printf("%s\n", token);
  return 0;
}