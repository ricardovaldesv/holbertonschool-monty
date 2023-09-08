#include "monty.h"
/**
 *add- Function that adds the top two elements of the stack.
 *@stack: stack struct
 *@line_number: line_number
 *Return: no return
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	size_t nodes;


	nodes = dlistint_len(*stack);

	if (nodes < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = sum_dlistint(*stack);
	pop(stack, line_number);
	(*stack)->n = sum;
}
