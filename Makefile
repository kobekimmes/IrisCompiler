

build: main.c error.c file_iterator.c lexer.c util.c token.c
	gcc main.c error.c file_iterator.c lexer.c util.c token.c -o main

run: main
	./main

clean: main
	rm -f main