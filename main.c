#include "monty.h"
/**
 * _isdigit - checks if a string is a number
 * @str: string
 * Return: int
 */
int _isdigit(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	if (str[0] == '-')
		i = 1;
	for (; str[i]; i++)
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
		{"pint", op_pint},
		{"pop", op_pop},
		{NULL, NULL},
	};

	if (!cont)
		return (1);
	current = strdup(cont);
	word = strtok(current, " \t$");
	for (j = 0; inst[j].opcode  && word; j++)
	{
		if (strcmp(inst[j].opcode, word) == 0)
		{
			word = strtok(NULL, " \t$");
			if (strcmp(inst[j].opcode, "push") == 0)
			{
				if (_isdigit(word))
					n = atoi(word);
				else
				{
					dprintf(STDERR_FILENO, "L%d: usage: push integer\n", i);
					free(current);
					return (1);
				}
			}
			if (strcmp(inst[j].opcode, "pint") == 0 && !(*head))
			{
				dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", i);
				free(current);
				return (1);
			}
			if (strcmp(inst[j].opcode, "pop") == 0 && !(*head))
			{
				dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", i);
				free(current);
				return (1);
			}

			free(current);
			inst[j].f(head, n);
			return (0);
		}
	}
	if (!(inst[j].opcode))
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", i, word);
		return (1);
	}
	free(current);
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
	FILE *o = 0;
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
			{
				fclose(o);
				free(cont);
				garbage_collector(&head);
				return (1);
			}
		}
	}
	free(cont);
	fclose(o);
	garbage_collector(&head);
	return (0);
}
