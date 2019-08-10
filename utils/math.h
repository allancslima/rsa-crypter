#ifndef HEADER_FILE
#define HEADER_FILE

int is_prime(long n);

long min(long a, long b);

long max(long a, long b);

long mdc(long a, long b, void (*listener)(long quotient, long remainder));

int are_coprime(long a, long b);

long coprime_mod_inverse(long a, long m);

#endif
