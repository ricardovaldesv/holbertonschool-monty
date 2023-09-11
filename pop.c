#include "monty.h"

/**
 * pop - func that delete a new node
 * @stack: pointer to the stack
 * @line_number: Line number in the script
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node_to_delete;
	(void)line_number;/*Parametro no Utilizado*/

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_to_delete = *stack;

	*stack = node_to_delete->next;
	if (node_to_delete->next)
		node_to_delete->next->prev = NULL;
	free(node_to_delete);
}
