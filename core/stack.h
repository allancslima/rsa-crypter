#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct node node;
typedef struct stack stack;

stack* create_stack();

void push(stack *stack, void *data);

void* pop(stack *stack);

int is_empty(stack *stack);

void* peek(stack *stack);

#endif
