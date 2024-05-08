#ifndef AST_H
#define AST_H

#include "./util.h"


typedef struct {

    union value
    {
        int int_literal;
        float float_literal;
        char* string_literal;
    };

    char* symbolic_identifier;

    enum value_type {
        NUM_TYPE,
        WORD_TYPE,
        LIST_TYPE
    };

} Expression;


typedef struct {

    enum sig_type {
        STMT_NONE,
        STMT_DEC,
        STMT_DEF,
        STMT_IF,
        STMT_ELIF,
        STMT_ELSE,
        STMT_FOR,
        STMT_WHILE,
        STMT_FUNC,
        STMT_RETURN
    };

    Expression** body;
    

} Statement;


typedef struct {
    
    Statement** code;

} Program;


#endif