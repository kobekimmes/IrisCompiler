#Compiler
CC := gcc

#Compiler flag
CFLAGS := -Wall -fsanitize=address -fsanitize=undefined -g

TARGET := iris/iris

SRC := iris/src/*.c

.PHONY: build clean

build: $(SRC)
	$(CC) $(CLFAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

test: $(TARGET) iris/testing/test.iri
	./$(TARGET) iris/testing/test.iri

clean: $(TARGET)
	rm -f $(TARGET)