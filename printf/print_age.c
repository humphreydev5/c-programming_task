#include <stdio.h>

int main(void){
  int age;
  age = 30;
  printf ( "I am %d years old\n", age );

  //adding more than one format speciation in "printf"
  int x = 5, y = 10;
  printf ( "x is %-8d and y is %2d\n", x, y );

  return (0);

}