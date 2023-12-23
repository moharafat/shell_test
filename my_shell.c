#include "shell.h"
int main()
{
	size_t n = 0;
	pid_t child_pid;
	int iread, status;
   char *buffer = NULL, *token, *delim = " ", *argv[1024];
	while (1)
	{
		write(1, "($) ", 4);
		buffer = malloc(2000);
		iread = getline(&buffer, &n, stdin);
		if (iread == -1)
			perror("Error:");
		argv[0] = token;
		token = strtok(buffer, delim);
		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, delim);
			child_pid = fork();
		if (child_pid == -1)
		{
			perror("ERROR");
			return (1);
		}
		if (child_pid == 0)
			printf("I am the child, father wait for me\n");
		else
		{ 
			wait(&status);
			printf("I am the father\n");
		}
		if (execve(argv[0], argv, NULL) == -1 )
		{
		 perror("Error:");   
		}
		printf("AFTER EXECUTION\n");
		}
		printf("BEFORE EXECUTION & FORKING\n");
	}
	return (0);
}
