#include <stdio.h>

int main(void)
{
  int h;
  h = sum1(32, 40);
  
  printf("the result is: %d\n", h);
  
  return (0);
}

int sum1(int x, int y)
{
  int result;
  result = x * y;
  
  return(result);

}