#include "shell.h"

int my_strtok(char *buffer, char** argv)
{
    char *token, *delim = " \n";
    int counter;

    token = strtok(buffer, delim);
    printf("this is the TOKEN: %s", token);
    counter = 0;
    while (token)
    {
        argv[counter] = token;
        counter++;
        token = strtok(NULL, delim);
    }
    argv[counter] = NULL;
    return (0);
}
