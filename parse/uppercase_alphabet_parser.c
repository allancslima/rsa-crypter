#include <stdio.h>
#include "parser.h"

int parse_char(char c)
{
	return c == ' ' ? 26 : c - 65;
}

char unparse_char(int i)
{
	return i == 26 ? ' ' : i + 65;
}
