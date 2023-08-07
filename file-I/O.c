#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//C File 

//C programming can handle file as string oriented data files - the data is stored in the same manner as it appears on the screen 
//System oriented data files - the data files are more closely associated with the Operating System(OS)
//Binary oriented data

//C files Operations
// 1 - Creation of a new file
// 2 - Opening of files 
// 3 - Reading of files 
// 4 - Writing Data in a files
// 5 - Closing files after using it.

// Steps for processing a file
// 1 - Declare a file-pointer variable
// 2 - Open a file using fopen()
// 3 - Process the file using suitable function
// 4 - Close the file using fclose() function
// fopen, fclose, getr, putc, getv, putw, fprintf, fscanf, fgets, fputs, feof 


int main()
{
  //FILE *fopen( const char * filePath, const char * node );
  FILE *fp;
  fp = fopen("filename.txt", "w");
  //processing of the files
  fprintf(fp, "%s", "Hello World");
  //end of processing
  fclose(fp);
  return(0);
}