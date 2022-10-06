#include "monty.h"

/**
 * main - monty program
 * @argc: argument count
 * @argv: argument vector
 * Return: execute the opcode
 */
int main(int argc, char **argv)
{

	FILE *stream;
	char *buff = NULL;
	ssize_t nread;
	size_t len = 0;
	char **agv = NULL;	
	int lc = 1;
	int wc;
	int n;
	stack_t *head = NULL;
	instruction_t opcodes[] = {
		{"push", pushf},
		{"pall", pallf}
	};

	if (argc != 2)
	{
		invalidargc();
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&buff, &len, stream)) != -1)
	{
		buff[strlen(buff) - 1] = '\0';
		wc = wordcount(buff);
		agv = splitstr(buff, " \t", wc);
		if (wc > 0)
		{
			n = check_op(agv[0]);
			if (n == 0)
			{
				opcodes[n].f(&head, atoi(agv[1]));
			}
			else if (n == 1)
				opcodes[n].f(&head, 1);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", lc, agv[0]);
				exit(EXIT_FAILURE);
			}
		}
		lc++;
		freevect(agv);
	}

if (strlen(buff) > 1)
	{
		free(buff);
	}
	return (EXIT_SUCCESS);
}
