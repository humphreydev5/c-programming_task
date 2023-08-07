#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
  //File Handling Part 2
  FILE *fileName; //pointer variable (1 step) for handling files in C
  char ch[100];
  fileName = fopen("filename.txt", "r");
  printf("%s", fgets(ch,50,fileName));
  fclose(fileName);
  return(0);
}

// getc - Reading a character from a file
// getw - Reading a integer from a file
// fgets - Read string of character from a file

//writing into the file
//putc, putw, fprintf, fputs