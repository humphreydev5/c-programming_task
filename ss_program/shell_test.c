#include <stdio.h>
#include <unistd.h>

int main(void)
{
  pid_t pid;
  pid_t ppid;
  /*written before fork */

  /* called fork */
  pid = fork();
  if (pid == -1)
  {
    perror("unsupported value");
    return 1;
  }  

  if (pid == 0)
  {
    sleep(30);
    printf("I am the child\n");
  }
  else
  {
    ppid = getpid();
    printf("I am the parent is %u\n", ppid);
  }
  return 0;
}