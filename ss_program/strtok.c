#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
  char *src = "Tell someone about God's love today";
  char *str = malloc(sizeof(char) * strlen(src));
  char *delim = " ";
  char *token;

  /*token = strtok(str, delim);
  printf("%s\n", token);

  token = strtok(NULL, delim);
  printf("%s\n", token);*/
  strcpy(str, src);

  // using while loop to get our token
  token = strtok(str, delim);
  while (token)
  {
    printf("%s\t", token);
    token = strtok(NULL, delim);
  }
  

  return 0;
}