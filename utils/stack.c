#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct _node node_t;

struct _node {
	void *data;
	node_t *next;
};

struct _stack {
	node_t *top;
};

stack_t* create_stack()
{
	stack_t *new_stack = (stack_t*) malloc(sizeof(stack_t));
	new_stack->top = NULL;
	return new_stack;
}

void push(stack_t *stack, void *data)
{
	node_t *new_node = (node_t*) malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
}

int is_empty(stack_t *stack)
{
	return stack->top == NULL;
}

void* pop(stack_t *stack)
{
	if (is_empty(stack)) {
		return NULL;
	}
	node_t *top = stack->top;
	stack->top = top->next;

	void *data = top->data;
	free(top);
	return data;
}

void* peek(stack_t *stack)
{
	if (is_empty(stack)) {
		return NULL;
	}
	return stack->top->data;
}
