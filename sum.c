#include <stdio.h>

int sum(int x, int y);

int main(void)
{
  int n;
  n = sum(10, 46);
  printf("The result is = %d\n", n);

  return (0);
}

int sum(int x, int y)
{
  int result;
  result = x + y;

  return (result);
}