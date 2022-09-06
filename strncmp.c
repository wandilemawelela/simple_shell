#include "shell.h"

/**
 * _strncmp - Compares two strings up to n bytes
 * @first: first str to compare
 * @second: second str to compare
 * @n: the number of bytes in n to check
 *
 * Return: value < 0 if (first < second)
 * value > 0 if (first > second)
 * value = 0 if (first == second)
 */

int _strncmp(const char *first, const char *second, int n)
{
	int idx;

	for (idx = 0; first[idx] && second[idx] && idx < n; idx++)
	{
		if (first[idx] != second[idx])
			return (first[idx] - second[idx]);
	}
	return (0);
}
