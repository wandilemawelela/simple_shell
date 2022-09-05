#include "shell.h"
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
  * Main program for simple shell
  */

int main (int argc, char **argv)
{
	char *cmd;

	do {
		/* Prints the prompt string */
		print_prompt1();

		/* Reads the next line of input. */
		cmd = read_cmd();

		if (!cmd)
		{
			exit (EXIT_SUCCESS); /* If there is an error reading the command exit the shell */
		}

		/* If the command is empty (i.e. the user pressed ENTER without writing anything, we skip this input and continue with the loop.*/
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			free (cmd);
			continue;
		}

		/* If the command is exit, we exit the shell. */
		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}

		/*Otherwise, we echo back the command, free the memory we used to store the command, and continue with the loop.*/
		printf("%s\n", cmd);
		free(cmd);
	} while (1);

	exit (EXIT_SUCCESS);
}

char *read_cmd(void)
{
	char buf[1024];
	char *ptr = NULL;
	char ptrlen = 0;

	while(fgets(buf, 1024, stdin))
    {
        int buflen = strlen(buf);

        if(!ptr)
        {
            ptr = malloc(buflen+1);
        }
        else
        {
            char *ptr2 = realloc(ptr, ptrlen+buflen+1);

            if(ptr2)
            {
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }

        if(!ptr)
        {
            fprintf(stderr, "error: failed to alloc buffer: %s\n",
                    strerror(errno));
            return NULL;
        }

        strcpy(ptr+ptrlen, buf);

        if(buf[buflen-1] == '\n')
        {
            if(buflen == 1 || buf[buflen-2] != '\\')
            {
                return ptr;
            }

            ptr[ptrlen+buflen-2] = '\0';
            buflen -= 2;
            print_prompt2();
        }

        ptrlen += buflen;
    }

    return ptr;
}
