#include "monty.h"



int main(int ac, char **av)
{
	FILE *o;
	int r, i;
	char *cont = 0;
	size_t len = 0;

	if (ac < 2)
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
		printf("%s\n", cont);
	}
	fclose(o);
	return (0);
}
