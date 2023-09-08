#include "monty.h"

/**
 * delete_dnodeint_at_index - func that delet a new node at a given position
 * @head: pointer to the header of the nodes
 * @index: the index of the list where the new node should be added
 * Return: 1 if it succeeded, -1 if it failed
 */

void swap(stack_t **stack, unsigned int line_number)
{
	size_t node;

	node = dlistint_len(*stack);
        stack_t *node_to_swap = *stack;
	(void)line_number;/*Parametro no Utilizado*/
	if (node == 2)
	{
		*stack = node_to_swap->next;
		(*stack)->prev = NULL;
		node_to_swap->prev = node_to_swap->next;
		(*stack)->next = node_to_swap;
		node_to_swap->next = NULL;
		
	}
	else
	{
        	*stack = node_to_swap->next;
        	(*stack)->prev = NULL;
        	node_to_swap->prev = (*stack)->next;
        	(*stack)->next->prev = node_to_swap;
        	node_to_swap->next = (*stack)->next;
        	(*stack)->next = node_to_swap;
	}
}
