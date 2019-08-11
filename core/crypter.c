#include <stdio.h>
#include "math.h"
#include "crypter.h"

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
	fprintf(public_key, "%lld\n%lld\n", e, n);
	fclose(public_key);
	return 1;
}
