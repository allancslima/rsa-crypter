#include <stdio.h>
#include "core/crypter.h"

#define PATH_PUBLIC_KEY        "public_key.txt"
#define PATH_ENCRYPTED_MESSAGE "encrypted.txt"
#define PATH_DECRYPTED_MESSAGE "decrypted.txt"

#define MENU_GENERATE_PUBLIC_KEY 1
#define MENU_ENCRYPT_MESSAGE     2
#define MENU_DECRYPT_MESSAGE     3
#define MENU_EXIT                0

#define LABEL_APP                 "RSA CRYPTER\n"
#define LABEL_GENERATE_PUBLIC_KEY "Generate public key\n"
#define LABEL_ENCRYPT_MESSAGE 	  "Encrypt a message\n"
#define LABEL_DECRYPT_MESSAGE 	  "Decrypt a message\n"
#define LABEL_EXIT 	  			  "Exit\n"

#define INPUT_OPTION                      "Option: "
#define INPUT_GENERATE_PUBLIC_KEY_PRIMES  "Type two primes P and Q: "
#define INPUT_GENERATE_PUBLIC_KEY_EXPOENT "Type expoent E: "
#define INPUT_MESSAGE                     "Type a message: "
#define INPUT_PUBLIC_KEY                  "Type the public key (N, E): "
#define INPUT_PRIVATE_KEY                 "Type the private key (P, Q, E): "

#define MSG_SUCCESS_GENERATE_PUBLIC_KEY "The public key has been generated successfully at %s\n"
#define MSG_ERROR_GENERATE_PUBLIC_KEY   "A problem occured during the public key generation process, please check your input numbers.\n"
#define MSG_SUCCESS_ENCRYPT_MESSAGE     "The message has been encrypted successfully at %s\n"
#define MSG_ERROR_ENCRYPT_MESSAGE       "A problem occured during the encryptation process.\n"
#define MSG_SUCCESS_DECRYPT_MESSAGE     "The message has been decrypted successfully at %s\n"
#define MSG_ERROR_DECRYPT_MESSAGE       "A problem occured during the decryptation process.\n"
#define MSG_ERROR_DECRYPT_NO_FILE       "There is no an encrypted file!\n"
#define MESSAGE_EXITED                  "You left from program.\n"
#define MESSAGE_INVALID_OPTION          "Choose a valid option!\n"

void start();

void show_menu();

void handle_input(int option);

void on_generate_public_key();

void on_encrypt_message();

void on_decrypt_message();

int main(int argc, char const *argv[])
{
	start();
	return 0;
}

/**
 * Not compatible with all termianals.
 */
void clear_console()
{
	printf("\033[H\033[J");
}

void new_line()
{
	printf("\n");
}

void clear_buffer()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void hold_output()
{
	clear_buffer();
	printf("\nPress enter to continue...");
	char c;
	scanf("%c", &c);
}

void start()
{
	clear_console();
	int option;

	while (1) {
		show_menu();
		new_line();
		printf(INPUT_OPTION);
		scanf("%d", &option);
		new_line();

		if (option == MENU_EXIT) {
			printf(MESSAGE_EXITED);
			break;
		} else {
			handle_input(option);
			hold_output();
		}
	}
	new_line();
}

void show_menu()
{
	clear_console();
	printf("    %s\n", LABEL_APP);
	printf("%d - %s", MENU_GENERATE_PUBLIC_KEY, LABEL_GENERATE_PUBLIC_KEY);
	printf("%d - %s", MENU_ENCRYPT_MESSAGE, LABEL_ENCRYPT_MESSAGE);
	printf("%d - %s", MENU_DECRYPT_MESSAGE, LABEL_DECRYPT_MESSAGE);
	printf("%d - %s", MENU_EXIT, LABEL_EXIT);
}

void handle_input(int option)
{
	switch (option) {
		case MENU_GENERATE_PUBLIC_KEY:
			on_generate_public_key();
			break;
		case MENU_ENCRYPT_MESSAGE:
			on_encrypt_message();
			break;
		case MENU_DECRYPT_MESSAGE:
			on_decrypt_message();
			break;
		default:
			printf(MESSAGE_INVALID_OPTION);
			break;
	}
}

void on_generate_public_key()
{
	big_int p, q, e;
	
	printf(INPUT_GENERATE_PUBLIC_KEY_PRIMES);
	scanf("%lld %lld", &p, &q);
	
	printf(INPUT_GENERATE_PUBLIC_KEY_EXPOENT);
	scanf("%lld", &e);
	
	new_line();

	if (generate_public_key(PATH_PUBLIC_KEY, p, q, e)) {
		printf(MSG_SUCCESS_GENERATE_PUBLIC_KEY, PATH_PUBLIC_KEY);
	} else {
		printf(MSG_ERROR_GENERATE_PUBLIC_KEY);
	}
}

void on_encrypt_message()
{
	clear_buffer();

	char message[1000];
	printf(INPUT_MESSAGE);
	fgets(message, 1000, stdin);

	big_int n, e;
	printf(INPUT_PUBLIC_KEY);
	scanf("%lld %lld", &n, &e);

	public_key_t public_key;
	public_key.n = n;
	public_key.e = e;
	
	new_line();

	if (encrypt_message(PATH_ENCRYPTED_MESSAGE, message, public_key)) {
		printf(MSG_SUCCESS_ENCRYPT_MESSAGE, PATH_ENCRYPTED_MESSAGE);
	} else {
		printf(MSG_ERROR_ENCRYPT_MESSAGE);
	}
}

void on_decrypt_message()
{
	big_int p, q, e;
	printf(INPUT_PRIVATE_KEY);
	scanf("%lld %lld %lld", &p, &q, &e);
	new_line();
	
	private_key_t private_key;
	private_key.p = p;
	private_key.q = q;
	private_key.e = e;
	
	FILE *encrypted_file = fopen(PATH_ENCRYPTED_MESSAGE, "r");
	
	if (encrypted_file == NULL) {
		printf(MSG_ERROR_DECRYPT_NO_FILE);
		return;
	}
	char encrypted_message[10000];
	fgets(encrypted_message, 10000, encrypted_file);

	if (decrypt_message(PATH_DECRYPTED_MESSAGE, encrypted_message, private_key)) {
		printf(MSG_SUCCESS_DECRYPT_MESSAGE, PATH_DECRYPTED_MESSAGE);
	} else {
		printf(MSG_ERROR_DECRYPT_MESSAGE);
	}
}
