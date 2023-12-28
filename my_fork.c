#include "shell.h"
int my_fork(char **argv)
{
    	int status;
       	pid_t child_pid;

        child_pid = fork();
		if (child_pid == -1)
		{
			perror("ERROR");
			exit (EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			printf("executing\n");
			if (execve(argv[0], argv, __environ) == -1)
			{
				perror("ERROR");
				exit (EXIT_FAILURE);
				
			}
			printf("I am the child, father wait for me\n");
		}
		else
		{
			printf("waiting\n");
			wait(&status);
		}
        return (0);
}
