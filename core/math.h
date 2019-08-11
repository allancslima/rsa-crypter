#ifndef HEADER_FILE
#define HEADER_FILE

typedef long long big_int;

int is_prime(big_int n);

big_int min(big_int a, big_int b);

big_int max(big_int a, big_int b);

big_int mdc(big_int a, big_int b, void (*listener)(big_int quotient, big_int remainder));

int are_coprime(big_int a, big_int b);

big_int coprime_mod_inverse(big_int a, big_int m);

#endif
