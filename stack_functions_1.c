#include "monty.h"


/**
 * add_stack - Add the node to the stack.
 * @new_node: Pointer new node.
 * @ln: Interger the line number of the opcode.
 */
void add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * prit_stk - Add the node to the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void prit_stk(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * top_pop - Add the node to the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void top_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		mor_error(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * prt_top - Prints the top node of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger the line number of the opcode.
 */
void prt_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		mor_error(6, line_number);
	printf("%d\n", (*stack)->n);
}

