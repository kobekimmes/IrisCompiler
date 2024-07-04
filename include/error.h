#ifndef ERROR_H
#define ERROR_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "./file_iterator.h"

enum error_type {NONE = 0, SYN = 1, TYPE = 2};

typedef struct Iterator;

typedef struct Error { 
    struct Iterator* fi;
    enum error_type type;
    char* msg;
} Error;


Error* error_create(Iterator* fit, enum error_type type, char* msg);

void error_throw(Error* err);

void error_free(Error* err);

#endif