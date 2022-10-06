#include "monty.h"

/**
 * isinteger - check if all of string is int
 * @str: string argument
 * @n: integer value
 * Return: 0 on success, or -1
 */
int isinteger(char *str, int n)
{
	int i = 0;

	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			not_integer(n);
		i++;
	}
	return (0);
}
