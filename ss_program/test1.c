#include <stdio.h>
#include <unistd.h>

int main(void)
{
  int number = 17;

  pid_t process_id;
  process_id = getpid();

  printf("%d\n", number);
  printf("Print the process ID of the program: %u", process_id);

  return(0);

}