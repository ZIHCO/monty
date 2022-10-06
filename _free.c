#include "monty.h"

/**
 * freevect - free the malloc allocated to vectors
 * @agv: vector
 * Return: void
 */
void freevect(char **agv)
{
	char **tmp = agv;

	if (agv)
	{
		while (*agv)
			free(*agv++);
		free(tmp);
	}
}
