#ifndef STACK_HEADER_FILE
#define STACK_HEADER_FILE

typedef struct _stack stack_t;

stack_t* create_stack();

void push(stack_t *stack, void *data);

void* pop(stack_t *stack);

int is_empty(stack_t *stack);

void* peek(stack_t *stack);

#endif
