#include "monty.h"

void monty_run(const char *file_name)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	monty_stack_t *stack = NULL;
	instruction_t instructions[] =
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	file = fopen(file_name, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		int i;
		char *token;
		line_number++;
		token = strtok(line, " \n\t\r");
		if (token)
		{
			for (i = 0; instructions[i].opcode; i++)
			{
				if (strcmp(token, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_number, strtok(NULL, " \n\t\r"));
					break;
				}
			}
		}
	}
	free(line);
	fclose(file);

	while (stack)
	{
		monty_stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}

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
