#include "monty.h"

int _isdigit(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * execution - chooses what to do with input
 * @cont: string
 * @i: int
 * @head: linked list
 * Return: int
 */
int execution(char *cont, unsigned int i, stack_t **head)
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
	for (j = 0; j < 2 && word; j++)
	{
		if (strcmp(inst[j].opcode, word) == 0)
		{
			word = strtok(NULL, " \t$");
			if (_isdigit(word))
			{
				n = atoi(word);
			}
			inst[j].f(head, n);
			return (0);
		}
	}
	if (j == 2)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s", i, word);
		exit(1);
	}
	return (0);
}
/**
 * main - main function
 * @ac: argument counter
 * @av: arguments
 * Return: 0 on success
 */
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
		i++;
		if (cont[0] != '\n')
		{
		
			cont = strtok(cont, "\n");
			if (execution(cont, i, &head) == 1)
				return (1);
		}
	}
	fclose(o);
	garbage_collector(&head);
	if (head)
		free(head);
	return (0);
}
