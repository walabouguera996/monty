#include "monty.h"

/**
 * prt_chr - Prints the Ascii value.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void prt_chr(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		stri_error(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		stri_error(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_string - Prints a string.
 * @stack: Pointer to top node of the stack.
 * @ln: Interger the line number of the opcode.
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rot_l - Rotates the first node of the stack.
 * @stack: Pointer to top node of the stack.
 * @ln: Interger the line number  of the opcode.
 */
void rot_l(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rot_r - Rotates the node to the top.
 * @stack: Pointer to top node of the stack.
 * @ln: Interger the line number of the opcode.
 */
void rot_r(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}

