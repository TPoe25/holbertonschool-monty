#include "monty.h"

/**
 * pop - pops top element from stack
 * @stack: pointer to top of stack
 * @line_number: instructions printed
 **/

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE); }
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
