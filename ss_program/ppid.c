#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av){

  int i;

  while (*av != NULL){
    printf(" the argv is %s\n", *av);
    av++;

  }
  return (0);
}