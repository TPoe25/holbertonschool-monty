#include "monty.h"
/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char buffer[1024];
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE); }
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE); }
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		line_number++;
		char *opcode = strtok(buffer, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number); }
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number); }
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number); }
		else if (strcmp(opcode, "pop") == 0) 
		{
			pop(&stack, line_number); }
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number); }
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, line_number); }
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, line_number); }
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free_stack(&stack);
			return (EXIT_FAILURE); } }
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
