#include "shell.h"

/**
 * _strlen - Finds the length of a string
 * @str: string
 *
 * Return: The length of string
 * 
 */

int _strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;
	return (i);
}