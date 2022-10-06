#include "monty.h"

/**
 * invalidargc - write to the stderr output
 *
 * Return: void
 */
void invalidargc(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 19);
	exit(EXIT_FAILURE);
}

/**
 * splitstr - return a pointer to an array
 * @str: string argument to split
 * @wc: integer argument for word count
 * @delim: what char to split at
 * Return: a pointer to an array of delimit string
 */
char **splitstr(char *str, char *delim, int wc)
{
	char *token = NULL;
	char *tmp = NULL;
	char **ptoken;
	int i = 0;

	ptoken = malloc(sizeof(char *) * (wc + 1));
	if (ptoken == NULL)
		return (NULL);
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	tmp = strdup(str);
	token = strtok(tmp, delim);
	while (token)
	{
		ptoken[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	ptoken[i] = NULL;
	free(tmp);
	return (ptoken);
}

/**
 * deniedaccess - write to stderr
 * str: string argument
 * Return: void
 */
void deniedaccess(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}

/**
 * invalid_op - write to stderr
 * @str: string argument
 * @n: integer argument
 * Return: void
 */
void invalid_op(char *str, int n)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", n, str);
	exit(EXIT_FAILURE);
}

/**
 * not_integer - write to stderr
 * @n: integer argument
 * Return: void
 */
void not_integer(int n)
{
	fprintf(stderr, "L%d: usage: push integer\n", n);
	exit(EXIT_FAILURE);
}
