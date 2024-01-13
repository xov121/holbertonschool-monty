#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty file where swap was called
 * @arg: argument (unused in this function)
 */
void swap(monty_stack_t **stack, unsigned int line_number, char *arg)
{
    monty_stack_t *temp;
    (void)arg;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    *stack = temp;
}
