#include "monty.h"
/**
 * op_push - push instruction
 * @stack: head of list
 * @line_number: int
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(1);
	}
	new->n = (int)line_number;
	new->next = NULL;
	new->prev = NULL;
	if ((*stack) != NULL)
	{
		new->next = (*stack);
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * op_pall - pall instruction
 * @stack: head of list
 * @line_number: int
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);

	(void)line_number;
	for (; p ; p = p->next)
	{
		printf("%d\n", p->n);
	}
}
