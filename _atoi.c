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

/**
 * emptystack - write to stderr
 * @n: integer argument
 * Return: void
 */
void emptystack(int n)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", n);
	exit(EXIT_FAILURE);
}

/**
 * popf - frees the top of the stack
 * @stack: pointer to the top
 * @n: integer
 * Return: void
 */
void popf(stack_t **stack, unsigned int n)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}
