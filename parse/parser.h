/*
 * This header proposes the implementation of a code that simplifies the characteres handling using integers.
 * 
 * The mapping of characters is useful for data encryption, once operations can be made over the integer representation
 * of the character for hide the real integer value. An example of this encryption type is the Caesar Cipher.
 *
 * @see https://en.wikipedia.org/wiki/Caesar_cipher
 */

#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

/**
 * Parse a character into an integer.
 *
 * @param c character.
 * @return mapped integer.
 */
int parse_char(char c);

/**
 * Parse an integer into a character.
 *
 * @param i integer.
 * @return mapped character.
 */
char unparse_char(int i);

#endif
