#ifndef ERROR_H
#define ERROR_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "file_iterator.h"

enum error_type {NONE = 0, SYN = 1, TYPE = 2};

struct Error { 
    struct Iterator* fi;
    enum error_type type;
    char* msg;
};


struct Error* error_create(struct Iterator* fit, enum error_type type, char* msg);

void error_throw(struct Error* err);

void error_free(struct Error* err);

#endif