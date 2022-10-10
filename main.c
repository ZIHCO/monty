#include "monty.h"

/**
 * main - monty program
 * @argc: argument count
 * @argv: argument vector
 * Return: execute the opcode
 */
int main(int argc, char **argv)
{
	FILE *stream = fopen(argv[1], "r");
	char *buff = NULL;
	ssize_t nread;
	size_t len = 0;
	char **agv = NULL;
	int lc = 1;
	int wc, n;
	stack_t *head = NULL;
	instruction_t opcodes[] = {
		{"push", pushf},
		{"pall", pallf},
		{"pint", pintf},
		{"pop", popf}
	};

	if (argc != 2)
		invalidargc();
	if (stream == NULL)
		deniedaccess(argv[1]);
	for (; (nread = getline(&buff, &len, stream)) != -1; lc++)
	{
		buff[strlen(buff) - 1] = '\0';
		wc = wordcount(buff);
		agv = splitstr(buff, " \t", wc);
		if ((agv[1]) && (strcmp(agv[0], "pall") != 0 && strcmp(agv[0], "pint") != 0 &&
					strcmp(agv[0], "pop") != 0))
			isinteger(agv[1], lc);
		if (wc > 0)
		{
			n = check_op(agv[0]);
			if (n == 0 && agv[1])
				opcodes[n].f(&head, atoi(agv[1]));
			else if (n == 0 && !(agv[1]))
			{
				freevect(agv);
				isinteger(agv[1], lc);
			}
			if (n == 1 || n == 2 || n == 3)
				opcodes[n].f(&head, lc);
			if (n == -1)
				invalid_op(agv[0], lc);
		}
		freevect(agv);
	}
if (strlen(buff) > 1)
	free(buff);
printf("%d\n", 0);
return (EXIT_SUCCESS);
}
