#include "monty.h"
/**
 * nop - doesn't do anything.
 * @stack: pointer to the head of the stack
 * @line_number: line number in the Monty file where nop was called
 * @arg: argument (unused in this function)
 */
void nop(monty_stack_t **stack, unsigned int line_number, char *arg)
{
    (void)stack;        // Unused parameters, suppresses compiler warning
    (void)line_number;
    (void)arg;
    // The nop opcode doesn't perform any operations.
    // It's just a placeholder function that does nothing.
}

