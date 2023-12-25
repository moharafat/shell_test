#include "shell.h"
int main()
{

	pid_t child_pid;
	int status, counter = 0;
	char *buffer = NULL, *token, *delim = " \n";
	char *argv[1024];
	while (1)
	{
		my_prompt(buffer);
		
		token = strtok(buffer, delim);
		counter = 0;
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
		if (strcmp (argv[0], "exit") == 0)
			{
				printf("about to exit\n");
				break;
			}
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
	free(buffer);
	}
	return (0);
}
/*free (argv[counter]);*/
