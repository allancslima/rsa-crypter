#ifndef CRYPTER_HEADER_FILE
#define CRYPTER_HEADER_FILE

typedef long long big_int;
typedef struct _public_key public_key_t;

struct _public_key {
	big_int n;
	big_int e;
};

int generate_public_key(char *path, big_int p, big_int q, big_int e);

int encrypt_message(char *path, char *message, public_key_t public_key);

#endif
