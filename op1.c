#include "monty.h"

/**
 * op_add - adds top nodes
 * @stack: head of list
 * @line_number: int
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);
	(void)line_number;

	(*stack) = (*stack)->next;
	(*stack)->n = (*stack)->n + p->n;
	(*stack)->prev = NULL;
	free(p);
}
