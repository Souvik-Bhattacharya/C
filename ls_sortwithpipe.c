#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe_fd[2];
    pid_t ls_pid, sort_pid;

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Fork first child process to run "ls"
    ls_pid = fork();

    if (ls_pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (ls_pid == 0) {
        // Child process (ls)

        // Close the read end of the pipe
        close(pipe_fd[0]);

        // Redirect stdout to the write end of the pipe
        dup2(pipe_fd[1], STDOUT_FILENO);

        // Execute "ls" command
        execlp("ls", "ls", (char *)NULL);

        // If execlp() fails
        perror("execlp(ls) failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process

        // Fork second child process to run "sort"
        sort_pid = fork();

        if (sort_pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (sort_pid == 0) {
            // Child process (sort)

            // Close the write end of the pipe
            close(pipe_fd[1]);

            // Redirect stdin to the read end of the pipe
            dup2(pipe_fd[0], STDIN_FILENO);

            // Execute "sort" command
            execlp("sort", "sort", (char *)NULL);

            // If execlp() fails
            perror("execlp(sort) failed");
            exit(EXIT_FAILURE);
        } else {
            // Parent process

            // Close both ends of the pipe in the parent process
            close(pipe_fd[0]);
            close(pipe_fd[1]);

            // Wait for both child processes to complete
            waitpid(ls_pid, NULL, 0);
            waitpid(sort_pid, NULL, 0);

            printf("Parent process: ls | sort completed.\n");
        }
    }

    return 0;
}
