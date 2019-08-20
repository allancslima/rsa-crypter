/**
 * This header is based on RSA algorithm.
*/

#ifndef CRYPTER_HEADER_FILE
#define CRYPTER_HEADER_FILE

/**
 * Alias for long long int type.
 */
typedef long long big_int;

/**
 * Alias for public key struct.
 */
typedef struct _public_key public_key_t;

/**
 * Alias for private key struct.
 */
typedef struct _private_key private_key_t;

/**
 * Public key struct.
 */
struct _public_key {
	/**
	 * Product between two prime numbers p and q.
	 */
	big_int n;
	/**
	 * A number relatively prime to (p - 1) * (q - 1).
	 */
	big_int e;
};

struct _private_key {
	/**
	 * A prime number.
	 */
	big_int p;
	/**
	 * Another prime number.
	 */
	big_int q;
	/**
	 * A number relatively prime to (p - 1) * (q - 1).
	 */
	big_int e;
};

/**
 * Generate the public key (N,E) which N is the product between two prime numbers and E is a number relatively prime to
 * (p - 1) * (q - 1).
 *
 * @param path pointer to path which public key file will be saved.
 * @param p a prime number.
 * @param q another prime number.
 * @param e a number relatively prime to (p - 1) * (q - 1).
 * @return 1 if the public key has been generated or 0 otherwise.
 */
int generate_public_key(char *path, big_int p, big_int q, big_int e);

/**
 * Map character into an integer M and make M^E mod N which E is {@link public_key_t#e} property and N is
 * {@link public_key_t#n}.
 *
 * @param c character to encrypt.
 * @param public_key public key with the values of public key generation step.
 * @return encrypted character into an integer.
 */
big_int encrypt_char(char c, public_key_t public_key);

/**
 * @param c integer to decrypt.
 * @param private_key private key with the values used to generate the public key.
 * @return decrypted integer into a character.
 */
char decrypt_char(big_int c, private_key_t private_key);

/**
 * Encrypt a message applying to each character the {@link #encrypt_char(char, public_key_t)} function.
 *
 * @param path pointer to path which encrypted message file will be saved.
 * @param message pointer to message string that will be encrypted.
 * @param public_key public key with the values of public key generation step.
 * @return 1 if the message has been encrypted or 0 otherwise.
 */
int encrypt_message(char *path, char *message, public_key_t public_key);

/**
 * Decrypt a message applying to each character the {@link #decrypt_char(char, private_key_t)} function.
 *
 * @param path pointer to path which decrypted message file will be saved.
 * @param message pointer to message string that will be decrypted, each encrypted character must be separated by space.
 * @param private_key private key with the values used to generate the public key.
 * @return 1 if the message has been decrypted or 0 otherwise.
 */
int decrypt_message(char *path, char *message, private_key_t private_key);

#endif
