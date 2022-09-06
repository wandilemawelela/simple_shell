#include "shell.h"

/**
  * _strchr - Searches a string for a character
  * @strn: String
  * @chr: Character
  *
  * Return: Pointer to index of first occurence and NULL otherwise
  *
  */

char *_strchr(char *strn, int chr)
{
	while (*strn == chr)
	{
		return (strn);
		strn++;
	}
	return (NULL);
}
