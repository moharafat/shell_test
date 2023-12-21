#include "shell.h"
int main()
{
    char *buffer = NULL;  
    size_t n = 0;
    int iread;
    pid_t child_pid;
    int status;
    while (1)
    {
        write(1, "($) ", 4);
        buffer = malloc(2000);
        iread = getline(&buffer, &n, stdin);
        if (iread == -1)
         perror("Error:");
        printf("BEFORE EXECUTION & FORKING");
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("ERROR");
            return (1);
        }
        if (child_pid == 0)
            printf("I am the child, father wait for me");
        else
        { 
            wait(&status);
            printf("I am the father");
        }
        if (execve(argv[0], argv, NULL) == -1 )
        {
         perror("Error:");   
        }
        printf("AFTER EXECUTION");
    }
    return (0);
}
