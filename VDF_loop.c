#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...);

int main(void)
{
  int n, my_sum;

  scanf("%d", &my_sum);
  n = sum(my_sum, 46, 23, 34, 43, 12, 60);
  printf("The result is = %d\n", n);

  return (0);
}

int sum(int count, ...)
{
  va_list my_sum;
  va_start(my_sum, count);
  int result = 0, i;
  /*access all members of the lists*/
  for (i = 0; i < count; i++)
  {
    result = result + va_arg(my_sum, int);
  }
  //result = count + va_arg(my_sum, int) + va_arg(my_sum, int) + va_arg(my_sum, int) + va_arg(my_sum, int);
  va_end(my_sum);
  return (result);
}
