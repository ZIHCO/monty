#include "monty.h"

/**
 * wordcount - return the number of arguments
 * @str: pointer to string in the buffer
 * Return: an integer value
 */
int wordcount(char *str)
{
	int button = 0;
	int i = 0;
	int wc = 0;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			button = 0;
		else if (button == 0)
		{
			button = 1;
			wc++;
		}
		i++;
	}
	return (wc);
}
