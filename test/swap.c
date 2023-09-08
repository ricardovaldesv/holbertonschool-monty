#include "monty.h"

/**
 * delete_dnodeint_at_index - func that delet a new node at a given position
 * @head: pointer to the header of the nodes
 * @index: the index of the list where the new node should be added
 * Return: 1 if it succeeded, -1 if it failed
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
