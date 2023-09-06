#include "monty.h"
/**
 * main - Monty interpreter main function
 * @argc: Argument count
 * @argv: Argument values
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
        char *opcode, *value, *line = NULL;
        size_t line_number = 0, len = 0;
        FILE *file;

        if (argc != 2)
        {
                fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        file = fopen(argv[1], "r");
        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        while (getline(&line, &len, file) != -1)
        {
                line_number++;
                opcode = strtok(line, " \n");
                if (opcode == NULL || opcode[0] == '#')
                continue;

                if (strcmp(opcode, "push") == 0)
                {
                        value = strtok(NULL, " \n");
                        if (value == NULL || !isdigit(value[0]))
                        {
                                fprintf(stderr, "L%lu: usage: push integer\n", line_number);
                                fclose(file);
                                free(line);
                                exit(EXIT_FAILURE);
                        }
                        push(&stack, atoi(value));
                }
                else if (strcmp(opcode, "pall") == 0)
                {
                        pall(&stack, line_number);
                }
        free(line); /*libera el bufer de la linea asignada*/
        line = NULL;
        }
        fclose(file);
        return (0);
}
/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
        stack_t *new_node;

        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack != NULL)
                (*stack)->prev = new_node;
        *stack = new_node;
}
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
