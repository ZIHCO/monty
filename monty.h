#ifndef _MONTY_H_
#define _MONTY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *strdup(const char *s);
void invalidargc(void);
int wordcount(char *str);
void freevect(char **agv);
int check_op(char *str);
void pushf(stack_t **stack, unsigned int n);
void pallf(stack_t **stack, unsigned int n);
char **splitstr(char *str, char *delim, int wc);
void deniedaccess(char *str);
void invalid_op(char *str, int n);
void not_integer(int n);
int isinteger(char *str, int n);
void pintf(stack_t **stack, unsigned int n);

#endif
