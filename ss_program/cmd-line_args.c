#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

  //argv looks like this
  //char *argv[] = {"./cmd-line_args", "coding", "with", "cogent", "is", "fun", "and", "interesting", NULL};

  printf("argc: %d\n", argc);

  for (int i = 0; argv[i] != NULL; i++)
    printf("argv[%d]: %s\n", i, argv[i]);

  return 0;  
}

#ifndef MAIN_H
#define MAIN_H

#endif

