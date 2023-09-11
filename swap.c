#include "monty.h"

/**
 * swap - function to exchange values
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp2;
	size_t nodes;
	stack_t *node_to_swap = *stack;
	(void)line_number;/*Parametro no Utilizado*/

	nodes = dlistint_len(*stack);

	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_to_swap = *stack;
	temp2 = node_to_swap->n;
	node_to_swap->n = node_to_swap->next->n;
	node_to_swap->next->n = temp2;
}
