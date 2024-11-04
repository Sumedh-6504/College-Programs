// Always run this program in wsl terminal

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// The red line is ignored by WSL but not ignored by CMD!

// #include<sys/wait.h> --> Instead of this library we can use CreateProcess() or WaitForSingleObject() in windows as this library is UNIX-specific

int main()
{
    // initalize process ID using pid_t data type.
    pid_t pid;

    // Fork a child process using fork() function.
    pid = fork();
    // 1st Condition
    if (pid < 0)
    {
        perror("Fork Failed!");
        exit(EXIT_FAILURE);
    }

    // 2nd Condition
    else if (pid == 0)
    {
        printf("Child process created with (PID : %d)\n ", getpid());
        // Create a new running image for the above line of code
        execlp("/bin/ls", "ls", "-1", NULL); // Rule: Usage of Double quotes is mandatory! as in C double quotes represent a string.
        perror("Process Failure");
        exit(EXIT_FAILURE);
    }

    // Otherwise Condition
    else
    {
        printf("Parent process is waiting for the child process to complete (PID : %d) \n", getpid());
        // Wait for the child process to finish using the below function
        wait(NULL);
        // Confirmation msg from the OS.
        printf(" \n Child Process has terminated!");
    }
    return 0;
}

// RULE : For Windows stick to windows.h library which includes CreateProcess() and WaitForSingleObject() --> instead of the UNIX-ike system's library wait.h which includes fork(), wait() etc.

// RULE : Always try to use WSL to run these College OS C-Files!

// new Unix username : sumedh_dev
// new password : Cubone6504

// We can change directories using cd and remove by rm