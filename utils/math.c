#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#include "math.h"

typedef struct _remainder remainder_t;

remainder_t *create_remainder(long a, long b);

void fill_remainder_stack(stack_t *stack, long a, long b);

struct _remainder {
	int value;
	int dividend;
	int divisor;
	int quotient;
};

int is_prime(long n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int mdc(long a, long b)
{
	if (b == 0) {
		return a;
	}
	return mdc(b, a % b);
}

int coprime_mod_inverse(long a, long m)
{
	stack_t *remainder_stack = create_stack();
	fill_remainder_stack(remainder_stack, a, m);
	
	if (is_empty(remainder_stack)) return -1;

	remainder_t *current_remainder = pop(remainder_stack);
	int secondLast = 1;
	int last = current_remainder->quotient;
	int s = secondLast;
	int pop_count = 0;

	free(current_remainder);
	
	while (!is_empty(remainder_stack)) {
		current_remainder = pop(remainder_stack);
		pop_count++;
		
		if (pop_count > 2) secondLast = last;
		if (pop_count > 1) last = s;

		s = secondLast + (last * current_remainder->quotient);
		free(current_remainder);
	}
	int t = last * -1;

	free(remainder_stack);
	return a < m ? s : t;
}

void fill_remainder_stack(stack_t *stack, long a, long b)
{
	if (b > 1) {
		if (a > b) {
			remainder_t *new_remainder = create_remainder(a, b);
			push(stack, new_remainder);
			fill_remainder_stack(stack, b, new_remainder->value);
		} else {
			fill_remainder_stack(stack, b, a);
		}
	}
}

remainder_t *create_remainder(long a, long b)
{
	remainder_t *new_remainder = (remainder_t*) malloc(sizeof(remainder_t));
	new_remainder->dividend = a;
	new_remainder->divisor = b;
	new_remainder->quotient = a / b;
	new_remainder->value = a - (new_remainder->quotient * b);
	return new_remainder;
}
