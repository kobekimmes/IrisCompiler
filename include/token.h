#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <stdio.h>
#include "../include/linked_list.h"

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
    SPACE,

    NUMERIC,
    IDENT, 

    //reserved
    NUM,
    IDEA,
    FOR,
    IF,
    RETURN

};

struct Token {
    enum token_type type;
    char* val;
    
    int line_pos;
    int byte_pos;
};

struct Token* token_create(enum token_type type, char* val, int line_pos, int byte_pos);

void token_print(struct Token*);

void tokens_print(struct LinkedList* ll);

void token_free(struct Token* tok);

void tokens_free(struct LinkedList* ll);

#endif