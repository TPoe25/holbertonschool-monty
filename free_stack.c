#include "monty.h"

/**
 * free_stack - frees memory from nodes in stack
 * @stack: top of stack
 **/

void free_stack(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
