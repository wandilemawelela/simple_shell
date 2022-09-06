#include "shell.h"

/**
 * _strcmp - compares two strings
 * @str1:First string
 * @str2: Second string
 *
 * Return: 0
 */

int _strcmp(char *str1, char *str2)
{
    int total;

	if (str1 == NULL || str2 == NULL)
		return (0);

	while (*str1 && *str2)
	{
		total = *str1 - *str2;

		if (total != 0)
			break;
		str1++;
		str2++;
	}
	return (total);
}
