#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#include "math.h"

stack_t* create_quotients_stack(long a, long b);

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

long min(long a, long b)
{
	return a < b ? a : b;
}

long max(long a, long b)
{
	return a > b ? a : b;
}

long mdc(long a, long b, void (*listener)(long quotient, long remainder))
{
	if (b == 0) {
		return a;
	}
	long mod = a % b;
	if (listener != NULL) {
		listener(a / b, mod);
	}
	return mdc(b, mod, listener);
}

int are_coprime(long a, long b)
{
	return mdc(a, b, NULL) == 1;
}

long coprime_mod_inverse(long a, long m)
{
	stack_t *quotients_stack = create_quotients_stack(max(a, m), min(a, m));
	pop(quotients_stack);

	long secondLast = 1;
	long last = *((long*) pop(quotients_stack));
	long inverse = last;
	int quotients_count = 1;
	
	while (!is_empty(quotients_stack)) {
		long current = *((long*) pop(quotients_stack));
		inverse = (current * last) + secondLast;
		secondLast = last;
		last = inverse;
		quotients_count++;
	}

	if (quotients_count % 2 == 0) secondLast *= -1;
	else inverse *= -1;

	if (a > m) inverse = secondLast;

	while (inverse < 0) inverse += m;
	while (inverse > m) inverse -= m;

	return inverse;
}

stack_t* create_quotients_stack(long a, long b)
{
	stack_t *stack = create_stack();
	
	void quotients_listener(long quotient, long remainder) {
		long *q = (long*) malloc(sizeof(long));
		*q = quotient;
		push(stack, q);
	}
	
	mdc(a, b, quotients_listener);
	return stack;
}
