#include "shell.h"
int main()
{
    char **buffer = 0;
    size_t *n = 0;
    int iread;
    FILE *stream = 0;

  char *argv[] = {"/usr/bin/pwd", NULL};

    while (1)
    {
        write(1, "($) ", 4);
        iread = getline(buffer, n, stream);
        if (iread == -1)
        {
         perror("Error:");
        }
        printf("BEFORE EXECUTION");
        if (execve(argv[0], argv, NULL) == -1 )
        {
         perror("Error:");   
        }
        printf("AFTER EXECUTION");
    }
}