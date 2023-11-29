#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process

        // Replace child process image with "ls" command
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);

        // If execvp() fails
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process

        // Wait for the child process to complete
        wait(NULL);

        printf("Parent process: Child process completed.\n");
    }

    return 0;
}
