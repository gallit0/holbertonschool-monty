#include "monty.h"

int execution(char *cont, unsigned int i, stack_t *head)
{
	char *current = 0;
	char *word = 0;
	int j, n = 0;
	instruction_t inst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL},
	};

	if (!cont)
		return (1);
	current = strdup(cont);
	word = strtok(current, " \t$");
	for (j = 0; j < 2; j++)
	{
		if (strcmp(inst[j].opcode, word) == 0)
		{
			word = strtok(NULL, " \t$");
			if (word)
			{
				n = atoi(word);
			}
			inst[j].f(&head , n);
			return (0);
		}
	}

	dprintf(STDERR_FILENO, "L%d: unknown instruction %s", i, word);
	exit(1);
}

int main(int ac, char **av)
{
	FILE *o;
	unsigned int i = 0;
	char *cont = 0;
	size_t len = 0;
	stack_t *head = 0;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (1);
	}
	o = fopen(av[1], "r");
	if (!o)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		return (1);
	}
	while (getline(&cont, &len, o) != -1)
	{
		cont = strtok(cont, "\n");
		i++;
		if (1 == execution(cont, i, head))
			return (1);
	}
	fclose(o);
	return (0);
}
