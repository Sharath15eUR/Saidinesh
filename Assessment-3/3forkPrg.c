#include <stdio.h>
#include <unistd.h>
int main()
{
    // Write C code here

    if (fork() && (!fork()))
    {
        if (fork() || fork())
        {
            fork();
        }
    }
    printf("2 ");

    return 0;
}


//answer

//here the parent process creates the child process multiple times so multiple child process will be created.
//the number of child process is depending on the system os and execution order.
//there are one or multiple 2's will be printed as output

//2 2 2 2