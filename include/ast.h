#ifndef AST_H
#define AST_H

#include "./util.h"

enum stmt_sig {
        STMT_DEF,
        STMT_COND,
        STMT_FUNC,
        STMT_RETURN
};

enum expr_type {
        NUM_TYPE,
        WORD_TYPE,
        CONTAINER_TYPE
};


typedef struct {

    union value
    {
        int int_literal;
        float float_literal;
        char* string_literal;
    };

    char* symbolic_identifier;

    enum expr_type type;

} Expression;

typedef struct {
    char* var_name;


} StatementDef;

typedef struct {
    char* var_name;
    Expression* condition;





} StatementCond;


typedef struct {



} StatementFunc;






typedef union {
    StatementDef stmt_def;
    StatementCond stmt_cond;
    StatementFunc stmt_fun;

} StatementUnion;



typedef struct  {

    enum stmt_sig type;
    
    StatementUnion stmt;
    

} Statement;


typedef struct {
    
    Statement** code;

} Program;


#endif