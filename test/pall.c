#include "monty.h"

/**
 * pall - Prints all values on the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /*Parametro no utilizado*/

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
