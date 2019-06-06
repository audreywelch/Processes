// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// gcc -o stack -Wall -Wextra stack.c
// ./stack

int main(void)
{
    // Assign a variable
    int x = 100;

    // Print the process ID of the parent
    printf("forking project pid is %d\n", (int) getpid());

    // Fork returns the process id
    int process_id = fork();

    // Check for a failed fork
    if (process_id < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
        
    } else if (process_id == 0) {
        printf("Child with id: %d where x is: %d\n", (int) getpid(), x);
        
        // Change the variable
        x++;

        printf("Child with x changed to %d\n", x);

    } else {
        printf("Parent of %d (pid: %d) where x is: %d\n", process_id, (int) getpid(), x);
        
        // Change the variable
        x--;

        printf("Parent with x changed to %d\n", x);
    }

    return 0;
}
