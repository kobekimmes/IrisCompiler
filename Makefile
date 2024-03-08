

build: src/*.c
	gcc -Wall -fsanitize=address -fsanitize=undefined -g -o main src/*.c

run: main
	./main

clean: main
	rm -f main