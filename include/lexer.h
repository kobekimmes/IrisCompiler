#ifndef LEXER_H
#define LEXER_H

#include "./linked_list.h"
#include "./file_iterator.h"

#define IDENT_SIZE 128
#define NUMERAL_SIZE 128

LinkedList* tokenize(char* path, int* token_count);

void gen_toks(Iterator* iter, LinkedList* tokens);

Token* get_next_token(Iterator* iter);

// char* peek(char* source, int* ptr);

// char* eat(char* source, int* ptr);

int find_reserved_keyword(char* str);

char* handle_numeric_literal(Iterator* iter, char curr);

char* handle_identifier(Iterator* iter, char curr);

char* handle_arithmetic_operators(Iterator* iter, char curr);

#endif