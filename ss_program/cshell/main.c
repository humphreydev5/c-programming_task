#include "main.h"

int main(int argc, char **argv)
{
  // Print a prompt on the terminal
  //printf("$$ ");
  char *prompt = "(Cshell) $ ";
  //char *f_command = NULL, *c_command = NULL; // Declare character pointers
  char *lineptr = NULL, *lineptr_copy = NULL;
  size_t n = 0;
  ssize_t n_read;
  const char *delim = " \n";
  int n_tokens = 0;
  char *token;
  int i;
  //char **argv;

  /* declaring void variables */
  (void)argc;

  /* Create a loop for the shell's prompt */
  while (1)
  {
    printf("%s", prompt);
    n_read = getline(&lineptr, &n, stdin);
    /* Check if the getline function failed or reached EOF or The user uses CTRL + D */
    if (n_read == -1)
    {
      printf("Shell Exiting.....\n");
      return (-1);
    }

    /* allocate space for a copy of the lineptr */
    lineptr_copy = malloc(sizeof(char) * n_read);
    if (lineptr_copy == NULL)
    {
      perror("tsh: memory allocation error");
      return (-1);
    }
    /* copy lineptr to lineptr_copy */
    strcpy(lineptr_copy, lineptr);

    /****** split the string (lineptr) into an array of words ******/
    /* calculate the total number of tokens */
    token = strtok(lineptr, delim);

    while (token != NULL)
    {
      n_tokens++;
      token = strtok(NULL, delim);
    }
    n_tokens++;

    /* Allocate space to hold the array of strings */
    argv = malloc(sizeof(char *) * n_tokens);

    /* Store each token in the argv array of strings */
    token = strtok(lineptr_copy, delim);

    for (i = 0; token != NULL; i++)
    {
      argv[i] = malloc(sizeof(char) * strlen(token));
      strcpy(argv[i], token);

      token = strtok(NULL, delim);
    }
    argv[i] = NULL;
    /* execute the command */
    execmd(argv);
  }

  /* free up allocated memory */
  free(lineptr_copy);
  free(lineptr);
  

  /*
  // Read input from the user
  n_read = getline(&f_command, &n, stdin);

  // Allocate memory for c_command
  c_command = malloc(sizeof(char) * n_read);

  if (c_command == NULL)
  {
    perror("tsh: memory allocation error");
    return -1;
  }

  // Copy the input to c_command
  strcpy(c_command, f_command);

  if (n_read == -1)
  {
    printf("Shell Exit.....\n"); // Print an exit message
    return -1;
  }
  else
  {
    // Tokenize the input string using space and newline as delimiters
    const char *delim = " \n";
    token = strtok(f_command, delim);

    while (token != NULL)
    {
      n_tokens++;
      token = strtok(NULL, delim);
    }
    n_tokens++;

    // Allocate space to hold the array of strings (tokens)
    argv = malloc(sizeof(char *) * n_tokens);

    // Store each token in the argv array
    token = strtok(c_command, delim);

    for (i = 0; token != NULL; i++)
    {
      argv[i] = malloc(sizeof(char) * (strlen(token) + 1)); // Allocate memory for each token
      strcpy(argv[i], token); // Copy the token to argv
      token = strtok(NULL, delim);
    }
    argv[i] = NULL; // Set the last element of argv to NULL to indicate the end of the array

    // Free allocated memory after execution
    for (int j = 0; j < n_tokens; j++)
    {
      free(argv[j]); // Free memory for each token
    }
    free(argv); // Free memory for the argv array
    free(f_command); // Free memory for f_command
    free(c_command); // Free memory for c_command
  }
  */

  return (0);
}
