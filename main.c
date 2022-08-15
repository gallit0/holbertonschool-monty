#include "monty.h"

int execution(char *cont, int i)
{
	char *current;
	char *word;
	int j;
	instruction_t inst[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL},
	};
	if (!cont)
		return (0);
	current = strdup(cont);
	word = strtok(word, " \t$");
	for (j = 0; j < 2; j++)
	{
		if (strcmp(inst[j].opcode, word) == 0)
		{
			printf("found\n");	
			return (0);
		}
	}

	dprintf(STDERR_FILENO, "L%d: unknown instruction %s", i, word);
	return (1);
}

int main(int ac, char **av)
{
	FILE *o;
	int i = 0;
	char *cont = 0;
	size_t len = 0;

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
		if (1 == execution(cont, i))
			return (1);
	}
	fclose(o);
	return (0);
}
