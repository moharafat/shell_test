#include "shell.h"
int my_prompt(char * buffer)
{
	int iread;
	size_t n = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		sdwrite(1, "($) ", 4);
		buffer = malloc(2000);
		iread = getline(&buffer, &n, stdin);
		if (iread == -1)
		{
			perror("Error:");
			free(buffer);
			exit (1);
		}
	}
	return (iread);
}