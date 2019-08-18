#ifndef STACK_HEADER_FILE
#define STACK_HEADER_FILE

/**
 * Represents the stack data structure.
 * @see https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */
typedef struct _stack stack_t;

/**
 * Allocate memory to an empty stack.
 *
 * @return pointer to a stack.
 */
stack_t* create_stack();

/**
 * Put a data on the top of a stack.
 *
 * @param stack pointer to a stack.
 * @param data pointer to any data type.
 */
void push(stack_t *stack, void *data);

/**
 * Remove the data on the top of a stack.
 *
 * @param stack pointer to a stack.
 * @return pointer to the removed data.
 */
void* pop(stack_t *stack);

/**
 * Check if a stack is empty.
 *
 * @param stack pointer to a stack.
 * @return 1 if is empty or 0 otherwise.
 */
int is_empty(stack_t *stack);

/**
 * Get the data on the top of a stack.
 *
 * @param stack pointer to a stack.
 * @return pointer to any data type.
 */
void* peek(stack_t *stack);

#endif
