#include <stdio.h>
#include <string.h>
#include "crypter.h"
#include "math.h"
#include "../parse/parser.h"

#define FILE_PATTERN_PUBLIC_KEY "%lld\n%lld\n"

typedef long long big_int;

big_int encrypt_char(char c, public_key_t public_key);

int generate_public_key(char *path, big_int p, big_int q, big_int e)
{
	if (!is_prime(p) || !is_prime(q)) {
		return 0;
	}
	big_int n = p * q;
	big_int m = (p - 1) * (q - 1);

	if (mdc(e, m, NULL) != 1) {
		return 0;
	}
	FILE *public_key = fopen(path, "w+");
	
	if (public_key == NULL) {
		return 0;
	}
	fprintf(public_key, FILE_PATTERN_PUBLIC_KEY, n, e);
	fclose(public_key);
	return 1;
}

int encrypt_message(char *path, char *message, public_key_t public_key)
{
	FILE *encrypted_message = fopen(path, "w+");

	if (encrypted_message == NULL) {
		return 0;
	}
	int message_len = strlen(message) - 1;
	int i;
	
	for (i = 0; i < message_len - 1; i++) {
		fprintf(encrypted_message, "%lld ", encrypt_char(message[i], public_key));
	}
	fprintf(encrypted_message, "%lld\n", encrypt_char(message[i], public_key));
	fclose(encrypted_message);
	
	return 1;
}

big_int encrypt_char(char c, public_key_t public_key)
{
	printf("encrypting %c...\n", c);
	return mod_exponentiation(parse_char(c), public_key.e, public_key.n);
}
