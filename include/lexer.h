#ifndef LEXER_H
#define LEXER_H

#include "./linked_list.h"
#include "./file_iterator.h"

LinkedList* tokenize(char* path, int* token_count);

void gen_toks(Iterator* iter, LinkedList* tokens);

Token* get_next_token(Iterator* iter);

// char* peek(char* source, int* ptr);

// char* eat(char* source, int* ptr);

int findReservedKeyword(char* str);

#endif