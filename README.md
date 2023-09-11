# Monty Interpreter

The Monty Interpreter is a simple implementation of an interpreter for a fictional programming language called Monty. This interpreter can read and execute Monty script sequences from a file.

## Requirements

To compile and run the Monty Interpreter, you need to have a C compiler like `gcc` installed and run the following commands:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$ ./monty <input_file>
```
Make sure to replace <input_file> with the name of the Monty script file you want to execute.

# Usage
> The Monty interpreter supports various instructions, including push, pop, pall, pint, swap, add, and nop. You can write Monty script sequences in a text file and execute them using the interpreter as shown in the Requirements section.

# Files

## monty.h
Header file that contains the structure definitions and function prototypes used throughout the Monty interpreter. It defines the stack_t and instruction_t structures and declares the functions used for stack manipulation and execution of Monty commands.

## add.c
Implementation of the add function, which adds the top two elements of the stack. This file also includes error-handling functions for usage errors and file opening failures.

## fuc_print_error.c
Contains error-handling functions used in the interpreter. It includes functions for printing usage errors, file open errors, and handling unknown instructions.

## main.c
The main entry point of the Monty interpreter. It reads the Monty script from a file, tokenizes the input, and executes the corresponding instructions. This file also contains the push function for pushing values onto the stack.

## nop.c
Implementation of the nop function, which is used when no operation is required. It's a placeholder function and doesn't perform any actual operations.

## pall.c
Implementation of the pall function, which prints all values on the stack. It traverses the stack and prints the values.

## pint.c
Implementation of the pint function, which prints the value at the top of the stack, followed by a new line.

## pop.c
Implementation of the pop function, which deletes the top element of the stack.

## swap.c
Implementation of the swap function, which exchanges the values of the top two elements of the stack.

# Examples
Here are some examples of valid Monty commands:

```bash
push 1
push 2
push 3
pall
```
This Monty script pushes three values (1, 2, and 3) onto the stack and then prints all the values on the stack using the pall instruction.
```bash
push 4
push 5
add
pint
```
This Monty script pushes two values (4 and 5) onto the stack, then adds them together using the add instruction, and finally prints the value at the top of the stack using the pint instruction.
# Credits
> This Monty interpreter was developed by Gilberto lozano and Ricardo Valdés.
