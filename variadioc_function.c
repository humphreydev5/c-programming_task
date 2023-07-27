#include <stdio.h>
#include <stdarg.h>

int sum(int x, int y, ...);

int main(void)
{
  int n;
  n = sum(50, 46, 23, 34, 43, 12, 60);
  printf("The result is = %d\n", n);

  return (0);
}

int sum(int x, int y, ...)
{

  va_list my_sum;
  va_start(my_sum, y);
  int result;
  int z = va_arg(my_sum, int);
  int k = va_arg(my_sum, int);
  int t = va_arg(my_sum, int);
  int j = va_arg(my_sum, int);
  int i = va_arg(my_sum, int);
  //result = x + y + va_arg(my_sum, int) + va_arg(my_sum, int) + va_arg(my_sum, int) + va_arg(my_sum, int);
  result = (x + y) * k / t * z - j % i;
  va_end(my_sum);

  return (result);
}