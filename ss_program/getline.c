#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  size_t n = 10;
  /*Manully allocate the memory using malloc*/ 
  char *buff = malloc(sizeof(char) * n);

 
  printf("Enter your full name ");
  getline(&buff, &n, stdin);
  free(buff);

  printf ("Your Names are %sBuffur size is %ld\n", buff, n);

  return 0;
}