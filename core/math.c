#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../util/stack.h"
#include "math.h"

typedef long long big_int;

stack_t* create_quotients_stack(big_int a, big_int b);

int is_prime(big_int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

big_int min(big_int a, big_int b)
{
	return a < b ? a : b;
}

big_int max(big_int a, big_int b)
{
	return a > b ? a : b;
}

big_int mdc(big_int a, big_int b, void (*listener)(big_int quotient, big_int remainder))
{
	if (b == 0) {
		return a;
	}
	big_int mod = a % b;
	if (listener != NULL) {
		listener(a / b, mod);
	}
	return mdc(b, mod, listener);
}

int are_coprime(big_int a, big_int b)
{
	return mdc(a, b, NULL) == 1;
}

big_int coprime_mod_inverse(big_int a, big_int m)
{
	stack_t *quotients_stack = create_quotients_stack(max(a, m), min(a, m));
	pop(quotients_stack);

	big_int secondLast = 1;
	big_int last = *((big_int*) pop(quotients_stack));
	big_int inverse = last;
	int quotients_count = 1;
	
	while (!is_empty(quotients_stack)) {
		big_int current = *((big_int*) pop(quotients_stack));
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

stack_t* create_quotients_stack(big_int a, big_int b)
{
	stack_t *stack = create_stack();
	
	void quotients_listener(big_int quotient, big_int remainder) {
		big_int *q = (big_int*) malloc(sizeof(big_int));
		*q = quotient;
		push(stack, q);
	}
	
	mdc(a, b, quotients_listener);
	return stack;
}
