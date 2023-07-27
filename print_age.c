#include <stdio.h>

int main(void){
  int age;
  age = 30;
  printf ( "I am %d years old\n", age );

  //adding more than one format speciation in "printf"
  int x = 5, y = 10;
  printf ( "x is %02d and y is %03d\n", x, y );

  //Printing Strings
  int year = 15;
  char * grade;
  if ( year == 13 ) grade = "junior";

  else grade = "Senior";

  printf ( "%s is a %s\n", "Fred", grade );

  return (0);


}