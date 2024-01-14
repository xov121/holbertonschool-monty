#include "monty.h"

/**
 * monty_run - executes the monty bytecodes from a given file
 * @file_name: the name of the file containing monty bytecodes
*/
void monty_run(const char *file_name)
{
	FILE *file = fopen(file_name, "r");
	char *line = NULL, *token;
	size_t len = 0;
	unsigned int line_number = 0;
	monty_stack_t *stack = NULL, *temp;
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
	{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
	{"pint", pint}, {NULL, NULL}};
	int i, found;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
		while (getline(&line, &len, file) != -1)
		{
			token = strtok(line, " \n\t\r");
			line_number++, found = 0;
				if (!token)
				continue;

				for (i = 0; instructions[i].opcode && !found; i++)
				if (!strcmp(token, instructions[i].opcode))
				instructions[i].f(&stack, line_number, strtok(NULL, " \n\t\r")), found = 1;
					if (!found)
					{
						fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
						fclose(file), free(line), free_stack(stack);
						exit(EXIT_FAILURE);
					}
		}
	fclose(file), free(line), free_stack(stack);
}

/**
 * free_stack - Frees a stack.
 * @stack: A pointer to the top of the stack.
*/
void free_stack(monty_stack_t *stack)
{
	monty_stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack->next;
		free(temp);
	}
}

/**
 * main - entry point for the monty interpreter program
 * @argc: the number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: 0 on success
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_run(argv[1]);
	return (0);
}
