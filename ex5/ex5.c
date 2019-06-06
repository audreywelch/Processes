// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Create an array of however many characters are in the message size
    char buffer[MSGSIZE];

    // Create an array of integers
    // fd[0] will be the read-end of the pipe
    // fd[1] will be the write-end of the pipe
    int fd[2];

    // Create the pipe and populate 'fd'
    pipe(fd);

    // Check for pipe failure
    if (pipe(fd) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(1);
    }

    // Fork in order to do interprocess communication
    int pid = fork();

    // Check for fork failure
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(2);

    // Child
    } else if (pid == 0) {
        printf("Child writing to pipe\n");

        // Send data down the pipe
        // (PLACE I'm writing to, WHAT I'm writing, SIZE)
        write(fd[1], msg1, MSGSIZE);
        write(fd[1], msg2, MSGSIZE);
        write(fd[1], msg3, MSGSIZE);

    // Parent
    } else {
        // Wait until child has finished writing
        int wc = waitpid(pid, NULL, 0);
        
        close(fd[1]);

        printf("Parent reading from pipe\n");

        // While there are still messages left in the pipe,
        while (read(fd[0], buffer, MSGSIZE) > 0) {
            // print the messages
            printf("%s\n", buffer);
        }
        printf("finished reading from pipe\n");
    }
    
    return 0;
}
