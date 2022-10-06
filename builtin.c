#include "monty.h"

/**
 * check_op - check to see if input is a built in
 * @str: a string argument
 * Return: i on success or -1 on failure
 */
int check_op(char *str)
{
	int i = 0;
	char *built_op[] = {"push", "pall", NULL};

	while (built_op[i])
	{
		if (strcmp(built_op[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * pushf - adds a new node at the  beginning of a the stack_t
 * @stack: a pointer to head pointer
 * @n: the data to add
 * Return: void
 */
void pushf(stack_t **stack, unsigned int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;

	if (*stack)
	{
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
	}
}

/**
 * pallf - prints all the elements of a stack_t
 * @stack: pointer to a stack top
 * Return: void
 */
void pallf(stack_t **stack, unsigned int n)
{
	while (*stack && n)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
