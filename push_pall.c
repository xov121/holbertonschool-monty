#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the script
 * @arg: argument for the push opcode
*/
void push(monty_stack_t **stack, unsigned int line_number, char *arg)
{
	monty_stack_t *new_node;
	int num;
	char *endptr;

	if (arg == NULL || *arg == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);
	for (endptr = arg; *endptr; endptr++)
	{
	if (!isdigit(*endptr) && !(*endptr == '-' && endptr == arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	}

	new_node = malloc(sizeof(monty_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

		new_node->n = num;
		new_node->prev = NULL;
		new_node->next = *stack;
		if (*stack != NULL)
		{
			(*stack)->prev = new_node;
		}
		*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number in the script
 * @arg: unused
*/
void pall(monty_stack_t **stack, unsigned int line_number, char *arg)
{
	monty_stack_t *current = *stack;
	(void)line_number;
	(void)arg;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
