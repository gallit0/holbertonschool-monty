#include "monty.h"

/**
 * garbage_collector - frees all the stack
 * @head: head of list
 */

void garbage_collector(stack_t **head)
{
	stack_t *p = (*head);

	while ((*head) != NULL)
	{
		p = (*head);
		(*head) = (*head)->next;
		free(p);

	}

}
