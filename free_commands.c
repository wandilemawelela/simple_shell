#include "shell.h"

/**
 * free_cmds - This frees the cmd array
 * @str: pointer to an array of command line arguments
 *
 * Return: void
 * 
 */

void free_cmds(char **str)
{
	int index = 0;

	if (str == NULL)
		return;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}