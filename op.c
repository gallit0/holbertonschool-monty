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
		printf("%d\n", p->n);
}
/**
 * op_pint - pint instruction
 * @stack: head of list
 * @line_number: int
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	printf("%i\n", (*stack)->n);
}
/**
 * op_pop - pops element at top
 * @stack: head of list
 * @line_number: int
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);
	(void)line_number;

	(*stack) = (*stack)->next;
	free(p);
}

void op_swap(stack_t **stack, unsigned int line_number)
{
	unsigned int temp = 0;
	stack_t *p = (*stack);
	(void)line_number;

	p = p->next;
	temp = (*stack)->n;
	(*stack)->n = p->n;
	p->n = temp;
}
