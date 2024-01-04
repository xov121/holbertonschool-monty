#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the script, used for error messaging
 * @arg: unused
*/
void pop(monty_stack_t **stack, unsigned int line_number, char *arg)
{
	monty_stack_t *temp;
	(void)arg;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
