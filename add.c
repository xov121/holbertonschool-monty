#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty file where add was called
 * @arg: argument (unused in this function)
 */
void add(monty_stack_t **stack, unsigned int line_number, char *arg)
{
    monty_stack_t *temp;
    (void)arg;  // Unused parameter, suppresses compiler warning

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    temp->n += (*stack)->n;  // Add the values of the top two elements
    *stack = temp;           // Update the stack pointer to the second top element
    free(*stack);            // Free the top element that is no longer needed
}
