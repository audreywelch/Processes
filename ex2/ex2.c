// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Open the text.txt file
    FILE *fp;
    fp = fopen("text.txt", "w");

    // Fork returns the process id
    int process_id = fork();

    // Check for a failed fork
    if (process_id < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (process_id == 0) {
        printf("Child process executing\n");
        
        // Create a string to write
        char *child_string = "This is the child string.\n";

        // Write to child's string to the file
        fwrite(child_string, sizeof(char), strlen(child_string), fp);

    } else {
        printf("Parent process executing\n");
        
        // Create string to write
        char *parent_string = "This is the parent string.\n";

        // Write the parent's string to the file
        fwrite(parent_string, sizeof(char), strlen(parent_string), fp);
    }

    // Close the file
    fclose(fp);
    
    return 0;
}
