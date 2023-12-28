#include "shell.h"

int my_prompt(char **buffer)
{
	int iread;
	size_t n = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		write(1, "($) ", 4);
		iread = getline(buffer, &n, stdin);
		if (iread == -1)
		{
			perror("Error:");
			free(buffer);
			exit (1);
		}
	}
	return (0);
}
