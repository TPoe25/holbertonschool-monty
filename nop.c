#include "monty.h"

/**
 * nop - func to perfrom a no-op
 * @stack: ptr to top of stack
 * @line_number: instructions
 **/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Suppress unused parameter warning */
	(void)line_number; /* Suppress unused parameter warning */

	/* This function does nothing, it's used to satisfy the opcode */
}
