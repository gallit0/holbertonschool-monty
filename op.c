#include "monty.h"


void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(1);
	}
	new->n = (int)line_number;
	new->next = (*stack);
	new->prev = NULL;
	(*stack) = new;

	if (new->next != NULL)
	{
		temp = new;
		new = new->next;
		new->prev = temp;
	}
}
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);

	(void)line_number;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
