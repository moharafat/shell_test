#include "shell.h"
int main()
{
	pid_t child_pid;
	int status;
	char *buffer = NULL;
	char *argv[1024];

	while (1)
	{
		my_prompt(&buffer);
		printf("BUFFER IS: %s", buffer);
		my_strtok(buffer, argv);
		printf("ARG[0] = %s\n", argv[0]);
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
