#include "shell.h"
int main()
{
	char *buffer = NULL;
	char *argv[1024];

	while (1)
	{
		my_prompt(&buffer);
		printf("BUFFER IS: %s", buffer);
		my_strtok(buffer, argv);
		printf("ARG[0] = %s\n", argv[0]);
		my_exit(argv);
		my_fork(argv);
		free(buffer);
	}
	return (0);
}
/*free (argv[counter]);*/
