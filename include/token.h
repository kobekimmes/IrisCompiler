#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <stdio.h>

#include "./linked_list.h"

#define NUM_RESERVED 5

enum token_type {
    BIN_OP,
    UN_OP,
    
    LPAREN,
    RPAREN,
    EQ,
    COLON,
    SEMICOLON,
    LBRCKT,
    RBRCKT,
    LSQBRCKT,
    RSQBRCKT,
    SPACE,

    NUMERIC_LITERAL,
    STRING_LITERAL,
    IDENT, 

    //reserved
    NUM,
    WORD,
    IDEA,
    FOR,
    IF,
    ELIF,
    ELSE,
    RETURN

};

//typedef struct LinkedList;

typedef struct Token {
    enum token_type type;
    char* val;
    
    int line_pos;
    int byte_pos;
} Token;

Token* token_create(enum token_type type, char* val, int line_pos, int byte_pos);

void token_print(Token* tok);

void tokens_print(LinkedList* ll);

void token_free(Token* tok);

void tokens_free(LinkedList* ll);

#endif