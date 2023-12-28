#include "shell.h"

int my_exit(char **argv)
{
    	if (strcmp (argv[0], "exit") == 0)
			{
				printf("about to exit\n");
				/*break;*/
				exit(0);
			}
		return (0);
}
