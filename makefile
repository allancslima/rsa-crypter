CRYPTER = core/crypter.c
APP_MATH = core/math.c
INPUT_PARSER = parse/uppercase_alphabet_parser.c
STACK = util/stack.c

crypter:
	mkdir -p output/
	gcc main.c -o output/crypter.out $(CRYPTER) $(APP_MATH) $(INPUT_PARSER) $(STACK) -lm
