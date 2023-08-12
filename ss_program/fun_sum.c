#include <stdio.h>

int sum(int i, int j);
int sum1(int a, int b);

int main(void)
{
  int n, k;
  n = sum(45, 12);
  k = sum1(5, 82);
  printf(" add = %d\n sub = %d\n", n, k);
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
