#ifndef MONTY_H
#define MONTY_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data Structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list structure for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} monty_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(monty_stack_t **stack, unsigned int line_number, char *arg);
} instruction_t;

/* Function Prototypes */
int main(int argc, char *argv[]);
void push(monty_stack_t **stack, unsigned int line_number, char *arg);
void pall(monty_stack_t **stack, unsigned int line_number, char *arg);
void monty_run(const char *file_name);
void pint(monty_stack_t **stack, unsigned int line_number, char *arg);
void pop(monty_stack_t **stack, unsigned int line_number, char *arg);

#endif /* MONTY_H */
