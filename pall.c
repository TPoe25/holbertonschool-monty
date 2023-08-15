#include "monty.h"

/**
 * pall - prints all values of the stack
 * @stack: top of stack
 * @line_number: instuctions appear
 **/

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number; /* To suppress unused parameter warning */
	stack_t *current = *stack;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
