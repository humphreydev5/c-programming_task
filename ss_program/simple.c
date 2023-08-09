#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100
#define PROMPT "myShell> "

void parseInput(char *input, char **command, char **args) {
    *command = strtok(input, " ");
    
    int i = 0;
    while ((args[i] = strtok(NULL, " ")) != NULL) {
        i++;
    }
    args[i] = NULL;  // Set the last element to NULL
}

void executeCommand(char *command, char **args) {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        execvp(command, args);
        perror("execvp");  // Print an error if execvp fails
        _exit(1);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);  // Wait for the child process to finish
    } else {
        perror("fork");  // Print an error if fork fails
    }
}

void sigintHandler(int sig) {
    // Do nothing, just catch the signal
    printf("\n");
    printf(PROMPT);
    fflush(stdout);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    
    signal(SIGINT, sigintHandler);  // Register the signal handler

    while (1) {
        printf(PROMPT);
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';  // Remove the newline character
        
        char *command;
        char *args[MAX_INPUT_LENGTH];
        parseInput(input, &command, args);

        if (strcmp(command, "exit") == 0) {
            // Exit the shell
            break;
        }

        executeCommand(command, args);
    }

    return 0;
}