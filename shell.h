#ifndef MY_SHELL
#define MY_SHELL


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int my_prompt(char **buffer);
int my_strtok(char *buffer, char** argv);
int my_exit(char **argv);
int my_fork(char **argv);


#endif
