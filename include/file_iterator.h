#ifndef FILE_ITERATOR_H
#define FILE_ITERATOR_H

#include <ctype.h>
#include <string.h>

#include "token.h"
#include "util.h"
#include "error.h"

#define INC_BYTE_POS(fit) ((fit)->byte_pos++)
#define INC_LINE_POS(fit) ((fit)->line_pos++)
#define DEC_BYTE_POS(fit) ((fit)->byte_pos--)
#define DEC_LINE_POS(fit) ((fit)->line_pos--)

#define ZERO_LP(fit) ((fit)->line_pos = 0)
#define ZERO_BP(fit) ((fit)->byte_pos = 0)

struct Iterator {
    char* iterable;
    size_t isize;
    int line_pos;
    int byte_pos;
};

struct Iterator* create_iter(char* iterable, size_t isize);

void iterator_free(struct Iterator* iter);

#endif
