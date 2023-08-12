#include <stdio.h>

int sumAdd(int A, int B);

int main(void)
{
  int n = sumAdd(45, 56);
  printf("The result is: %d\n", n);
  return(0);
}

int sumAdd(int A, int B)
{
  int result = A + B;
  return(result);
}
