#include "monty.h"

/**
 * delete_dnodeint_at_index - func that delet a new node at a given position
 * @head: pointer to the header of the nodes
 * @index: the index of the list where the new node should be added
 * Return: 1 if it succeeded, -1 if it failed
 */

int pop(stack_t **stack, unsigned int line_number)
{
	unsigned int i;
	stack_t *node_to_delete;

	if (!stack || !*stack)
		return (-1);
	node_to_delete = *stack;

	if (line_number == 0)
	{
		*stack = node_to_delete->next;
		if (node_to_delete->next)
			node_to_delete->next->prev = NULL;
		free(node_to_delete);
		return (1);
	}
	for (i = 0; node_to_delete && i < line_number; i++)
	{
		node_to_delete = node_to_delete->next;
	}
	if (!node_to_delete)
		return (-1);
	if (!node_to_delete->next)
	{
		node_to_delete->prev->next = NULL;
		free(node_to_delete);
		return (1);
	}
	node_to_delete->prev->next = node_to_delete->next;
	node_to_delete->next->prev = node_to_delete->prev;
	free(node_to_delete);
	return (1);
}
