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
    // Your code here
    int x = 100;

    fork();

    printf("x is %d\n", x);

    return 0;
}
