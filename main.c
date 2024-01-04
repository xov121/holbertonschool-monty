#include "monty.h"

/**
 * monty_run - executes the monty bytecodes from a given file
 * @file_name: the name of the file containing monty bytecodes
*/
void monty_run(const char *file_name)
{
	FILE *file = fopen(file_name, "r");
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	monty_stack_t *stack = NULL;
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
	{"pint", pint}, {"pop", pop}, {NULL, NULL}};

	if (!file)
	{
		fprintf(stderr, "error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		char *token = strtok(line, " $\n\t\r");

		line_number++;
		if (token)
		{
			for (int i = 0; instructions[i].opcode; i++)
			{
				if (strcmp(token, instructions[i].opcode) == 0)
				{
				instructions[i].f(&stack, line_number, strtok(NULL, " $\n\t\r"));
				break;
			}
		}
	}
}

free(line);
fclose(file);

for (monty_stack_t *temp; stack; stack = temp)
{
	temp = stack->next;
	free(stack);
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
