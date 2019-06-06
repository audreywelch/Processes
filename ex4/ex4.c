// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// Takes an int argument and an array of character arguments
int main(int argc, char *argv[])
{
    printf("Exec program (pid: %d)\n", (int) getpid());
    int pid = fork();

    // Child process begins here 

    // Failure
    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    
    // Child
    } else if (pid == 0) {

        // Using execl
        // execl("/bin/ls", "ls", "-l", (char *) NULL);
        // Output:
        // Exec program (pid: 38179)
        // total 32
        // -rwxr-xr-x@ 1 audreywelch  staff  8756 Jun  6 14:00 ex4
        // -rw-r--r--@ 1 audreywelch  staff  1102 Jun  6 14:00 ex4.c

        // Using execv
        // char *args[] = {"ls", "-l", NULL};
        // execv("/bin/ls", args);
        // Output:
        // Exec program (pid: 38224)
        // total 32
        // -rwxr-xr-x@ 1 audreywelch  staff  8888 Jun  6 14:04 ex4
        // -rw-r--r--@ 1 audreywelch  staff  1394 Jun  6 14:03 ex4.c

        // Using execlp
        // execlp("ls", "ls", "-l", (char *) NULL);
        // Output:
        // Exec program (pid: 38245)
        // total 32
        // -rwxr-xr-x@ 1 audreywelch  staff  8888 Jun  6 14:04 ex4
        // -rw-r--r--@ 1 audreywelch  staff  1686 Jun  6 14:05 ex4.c

        // using execvp
        char *args[] = {"ls", "-l", NULL};
        execvp("ls", args);
        // Output
        // Exec program (pid: 38262)
        // total 32
        // -rwxr-xr-x@ 1 audreywelch  staff  8888 Jun  6 14:04 ex4
        // -rw-r--r--@ 1 audreywelch  staff  1998 Jun  6 14:06 ex4.c

    // Parent
    } else {
        int wc = waitpid(pid, NULL, 0);
    }

    return 0;
}
