/*
 * This header contains useful mathematic functions for the RSA encryptation algorithm.
 */

#ifndef MATH_HEADER_FILE
#define MATH_HEADER_FILE

/**
 * Alias for long long int type.
 */
typedef long long big_int;

/**
 * Check if the given integer is prime.
 *
 * @param n integer.
 * @return 1 if is prime or 0 otherwise.
 */
int is_prime(big_int n);

/**
 * Get the minimum between two integers.
 *
 * @param a integer.
 * @param b integer.
 * @return minimum integer.
 */
big_int min(big_int a, big_int b);

/**
 * Get the maximum between two integers.
 *
 * @param a integer.
 * @param b integer.
 * @return maximum integer.
 */
big_int max(big_int a, big_int b);

/**
 * Calculate the MDC between two integers. Should be implemented with Euclid's algorithm because of the listener
 * parameter.
 *
 * @param a integer.
 * @param b integer.
 * @param listener pointer to function that receives the quotient and the remainder of each division in MDC.
 * @return the MDC.
 *
 * @see https://en.wikipedia.org/wiki/Euclidean_algorithm
 */
big_int mdc(big_int a, big_int b, void (*listener)(big_int quotient, big_int remainder));

/**
 * Check if two integers are coprime, that's if the MDC between they is 1.
 *
 * @param a integer.
 * @param b integer.
 * @return 1 if are coprime or 0 otherwise.
 */
int are_coprime(big_int a, big_int b);

/**
 * Get the modular multiplicative inverse between two coprime integers.
 *
 * @param a integer.
 * @param m integer.
 * @return the modular multiplicative inverse.
 */
big_int mod_inverse(big_int a, big_int m);

/**
 * Get the modular exponentiation.
 *
 * @param base integer.
 * @param expoent integer.
 * @param mod prime that don't divide the base.
 * @return the modular exponentiation.
 */
big_int mod_exponentiation(big_int base, big_int expoent, big_int mod);

#endif
