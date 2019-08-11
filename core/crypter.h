#ifndef CRYPTER_HEADER_FILE
#define CRYPTER_HEADER_FILE

typedef long long big_int;
typedef struct _public_key public_key_t;
typedef struct _private_key private_key_t;

struct _public_key {
	big_int n;
	big_int e;
};

struct _private_key {
	big_int p;
	big_int q;
	big_int e;
};

int generate_public_key(char *path, big_int p, big_int q, big_int e);

big_int encrypt_char(char c, public_key_t public_key);

char decrypt_char(big_int c, private_key_t private_key);

int encrypt_message(char *path, char *message, public_key_t public_key);

int decrypt_message(char *path, char *message, private_key_t private_key);

#endif
