#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
	void *data;
	node *next;
};

struct stack {
	node *top;
};

stack* create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->top = NULL;
	return new_stack;
}

void push(stack *stack, void *data)
{
	node *new_node = (node*) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = stack->top;
	stack->top = new_node;
}

int is_empty(stack *stack)
{
	return stack->top == NULL;
}

void* pop(stack *stack)
{
	if (is_empty(stack)) {
		printf("Stack underflow\n");
		return NULL;
	}
	node *top = stack->top;
	stack->top = top->next;

	void *data = top->data;
	free(top);
	return data;
}

void* peek(stack *stack)
{
	if (is_empty(stack)) {
		printf("Stack overflow\n");
		return NULL;
	}
	return stack->top->data;
}
