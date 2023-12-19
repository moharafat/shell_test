#include "shell.h"
int main(int argc, char **argv)
{
    char **buffer = 0;
    size_t *n = 0;
    int iread;
    FILE *stream = 0;
    while (1)
    {
        write(stdout, "($) ", 4);
        iread = getline(buffer, n, stream);
        if (iread == -1)
        {
        /*exit ();[it produces errors]*/
        }
    }
}

/*when do i know i should use argc and argv*/