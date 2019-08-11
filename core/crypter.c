#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypter.h"
#include "math.h"
#include "../parse/parser.h"

#define FILE_PATTERN_PUBLIC_KEY "(n, e) = (%lld, %lld)\n"

typedef long long big_int;

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

big_int encrypt_char(char c, public_key_t public_key)
{
	return mod_exponentiation(parse_char(c), public_key.e, public_key.n);
}

char decrypt_char(big_int c, private_key_t private_key)
{
	big_int m = (private_key.p - 1) * (private_key.q - 1);
	big_int d = coprime_mod_inverse(private_key.e, m);
	big_int n = private_key.p * private_key.q;

	return unparse_char(mod_exponentiation(c, d, n));
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

int decrypt_message(char *path, char *message, private_key_t private_key)
{
	FILE *decrypted_message = fopen(path, "w+");

	if (decrypted_message == NULL) {
		return 0;
	}
	char *message_char = strtok(message, " ");
	while (message_char != NULL) {
		big_int message_char_int = atoll(message_char);
		fprintf(decrypted_message, "%c", decrypt_char(message_char_int, private_key));
		message_char = strtok(NULL, " ");
	}
	fprintf(decrypted_message, "\n");
	fclose(decrypted_message);

	return 1;
}
