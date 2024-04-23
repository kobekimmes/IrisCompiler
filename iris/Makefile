#Compiler
CC := gcc

#Compiler flag
CFLAGS := -Wall -fsanitize=address -fsanitize=undefined -g

TARGET := iris.x

SRC := src/*.c

.PHONY: build clean

build: $(SRC)
	$(CC) $(CLFAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

test: $(TARGET) testing/test.iri
	./$(TARGET) testing/test.iri

clean: $(TARGET)
	rm -f $(TARGET)