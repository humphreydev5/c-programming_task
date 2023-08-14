#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
   pid_t pid;

   /*child process is created*/
  pid = fork();

  /*In the process if the fork fails*/
  if (pid == -1)
  {
    perror("unsupported value");
    return 1;
  }  
  
  /*In the child process*/
  if (pid == 0)
  {
    printf("The child process\n");
  }

  /*In parent process*/
  else
  {
    wait(NULL);
    sleep(60);
    printf("The parent process\n");
  }
  return 0;
}