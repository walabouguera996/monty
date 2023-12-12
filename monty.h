#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack.
 * @n: int.
 * @prev: points the previous element of stack.
 * @next: points the next element of stack.
 *
 * Descrip: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: opcode.
 * @f: function to handle the opcode
 *
 * Descrip: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void op_files(char *file_name);
int par_line(char *buffer, int line_number, int format);
void readfiles(FILE *);
int len_chars(FILE *);
void find_functions(char *, char *, int, int);

stack_t *crt_node(int n);
void f_node(void);
void prit_stk(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_functions(op_func, char *, char *, int, int);

void prt_top(stack_t **, unsigned int);
void top_pop(stack_t **, unsigned int);
void nop_nop(stack_t **, unsigned int);
void swap_node(stack_t **, unsigned int);

void add_nod(stack_t **, unsigned int);
void sub_nod(stack_t **, unsigned int);
void div_nod(stack_t **, unsigned int);
void mul_node(stack_t **, unsigned int);
void mode_node(stack_t **, unsigned int);

void prt_chr(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rot_l(stack_t **, unsigned int);

void err(int error_code, ...);
void mor_error(int error_code, ...);
void stri_error(int error_code, ...);
void rot_r(stack_t **, unsigned int);

#endif
