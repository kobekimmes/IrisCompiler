#include <stdlib.h>
#include <stdio.h>

enum token_type {
    NUMERIC_LIT,
    STRING_LIT, 
    IDENT, 
    BIN_OP,
    UN_OP,
    LPAREN,
    RPAREN,
    EQ,
    COLON,
    LBRCKT,
    RBRCKT,

};


struct Token {
    enum token_type type;
    char* val;
};

struct Token* token_create(enum token_type type, char* val);

void token_print(struct Token*);

void tokens_print(struct Token* toks[], int num_tokens);

void token_free(struct Token* tok);

void tokens_free(struct Token* toks[], int num_tokens);