#include <stdio.h>
#include <unistd.h>

int sum(int i, int j);
int sum1(int a, int b);

int main(void)
{
  pid_t pid;
  pid = getpid();
  int n, k;
  n = sum(45, 12);
  k = sum1(5, 82);
  printf(" add = %d\t sub = %d\n", n, k);
  printf("Print the process %u\n", pid );
  return(0);
}

int sum(int i, int j)
{
  int results;
  results = i + j;
  return(results);
}

int sum1(int a, int b)
{
  int results1;
  results1 = a - b;
  return(results1);
}
