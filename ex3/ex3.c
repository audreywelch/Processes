// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("Hello\n");
    } else {
        // wait(NULL);
        
        int wc = waitpid(pid, NULL, 0);

        printf("Goodbye\n");
    }

    return 0;
}
