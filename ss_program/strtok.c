#include <stdio.h>
#include <string.h>

int main(void)
{
  char str[] = "Tell someone about God's love today";
  char *delim = " ";
  char *token;

  /*token = strtok(str, delim);
  printf("%s\n", token);

  token = strtok(NULL, delim);
  printf("%s\n", token);*/

  // using while loop to get our token
  token = strtok(str, delim);
  while (token)
  {
    printf("%s\t", token);
    token = strtok(NULL, delim);
  }
  

  return 0;
}