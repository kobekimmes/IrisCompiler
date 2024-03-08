#ifndef LEXER_H
#define LEXER_H

#include "file_iterator.h"

struct LinkedList* tokenize(char* path, int* token_count);

void gen_toks(struct Iterator* iter, struct LinkedList* tokens);

struct Token* get_next_token(struct Iterator* iter, char* source, int* start);

char* peek(char* source, int* ptr);

char* eat(char* source, int* ptr);

#endif