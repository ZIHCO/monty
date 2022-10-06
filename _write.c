#include "monty.h"

/**
 * invalidargc - write to the stderr output
 *
 * Return: void
 */
void invalidargc(void)
{
	write(STDERR_FILENO, "USAGE: monty file\n", 19);
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
