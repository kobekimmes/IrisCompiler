#Compiler
CC := gcc

#Compiler flag
CFLAGS := -Wall -fsanitize=address -fsanitize=undefined -g


.PHONY: build clean

build: src/*.c
	$(CC) $(CLFAGS) -o iris src/*.c

run: iris
	./iris 

clean: iris
	rm -f iris