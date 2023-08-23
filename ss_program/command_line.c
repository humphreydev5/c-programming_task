/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
  char  *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
  char *delim = " \n";
  size_t n = 0;
  int argc, i = 0;
  char **argv = NULL;

  printf("$ ");
  if (getline (&cmd, &n, stdin) == -1)
  {
    return -1;
  }
  cmd_cpy = strdup(cmd);

  while (cmd[i])
  {
    if (cmd[i] == '\n')
    {
      printf("\\n ---> Input has %ld characters ", strlen(cmd));
    }
    else
    {
      printf("%c", cmd[i]);
      i++;
    }
  }
  
  return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
  char *cmd = NULL, *cmd_cpy = NULL;
  size_t n = 0;
  int i = 0;

  printf("$ ");
  if (getline(&cmd, &n, stdin) == -1)
  {
    return -1;
  }
  cmd_cpy = strdup(cmd);

  while (cmd[i])
  {
    if (cmd[i] == '\n')
    {
      printf("\\n ---> Input has %ld characters\n", strlen(cmd));
    }
    else
    {
      printf("%c", cmd[i]);
    }
    i++;
  }
  
  free(cmd);
  free(cmd_cpy);
  return 0;
}
