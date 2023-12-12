#include "monty.h"

/**
 * mul_node - Add the top elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void mul_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mor_error(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mode_node - Add the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void mode_node(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		mor_error(8, line_number, "mod");


	if ((*stack)->n == 0)
		mor_error(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

