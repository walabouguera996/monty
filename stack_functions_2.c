#include "monty.h"

/**
 * nop_nop - Does nothing.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number the opcode.
 */
void nop_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_node- Swaps the elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void swap_node(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mor_error(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nod- Add the elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void add_nod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mor_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nod- Adds the elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void sub_nod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		mor_error(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nod - Adds the elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void div_nod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		mor_error(8, line_number, "div");

	if ((*stack)->n == 0)
		mor_error(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

