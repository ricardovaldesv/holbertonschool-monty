#include "monty.h"

/**
 * delete_dnodeint_at_index - func that delet a new node at a given position
 * @head: pointer to the header of the nodes
 * @index: the index of the list where the new node should be added
 * Return: 1 if it succeeded, -1 if it failed
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node_to_delete;
	(void)line_number;/*Parametro no Utilizado*/
	
	if (stack == NULL)
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
