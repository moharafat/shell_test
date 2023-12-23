#include "shell.h"
int main()
{
	size_t n = 0;
	pid_t child_pid;
	int iread, status, counter = 0;
   char *buffer = NULL, *token, *delim = " ", *argv[1024];
	while (1)
	{
		write(1, "($) ", 4);
		buffer = malloc(2000);
		iread = getline(&buffer, &n, stdin);
		if (iread == -1)
			perror("Error:");
		token = strtok(buffer, delim);
		while (token)
		{
			argv[counter] = token;
			counter++;
			token = strtok(NULL, delim);
		}
		argv[counter] = NULL;
		printf("ARG[0] = %s\n", argv[0]);
		printf("COUNTER = %d\n", counter);
		printf("token before forking%s\n", token);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("ERROR");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("executing\n");
			if (execve("/usr/bin/ls", argv, __environ) == -1)
				perror("ERROR");
			printf("I am the child, father wait for me\n");
		}
		else
		{ 
			printf("waiting");
			wait(&status);
		}
	}
	return (0);
}
