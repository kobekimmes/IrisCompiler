#Compiler
CC := gcc

#Compiler flag
CFLAGS := -Wall -fsanitize=address -fsanitize=undefined -g

TARGET := iris

SRC := src/*.c

.PHONY: build clean

build: $(SRC)
	$(CC) $(CLFAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean: iris
	rm -f $(TARGET)