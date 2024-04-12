#ifndef FILE_ITERATOR_H
#define FILE_ITERATOR_H

#include <ctype.h>
#include <string.h>


#define INC_BYTE_POS(fit) ((fit)->byte_pos++)
#define INC_LINE_POS(fit) ((fit)->line_pos++)
#define DEC_BYTE_POS(fit) ((fit)->byte_pos--)
#define DEC_LINE_POS(fit) ((fit)->line_pos--)
#define INC_FILE_POS(fit, offset) ((fit)->file_pos+=offset)
#define DEC_FILE_POS(fit, offset) ((fit)->file_pos-=offset)

#define ZERO_LP(fit) ((fit)->line_pos = 1)
#define ZERO_BP(fit) ((fit)->byte_pos = 0)
#define ZERO_FP(fit) ((fit)->file_pos = 0)

typedef struct Iterator {
    char* iterable;
    size_t isize;
    int line_pos;
    int byte_pos;
    int file_pos;
} Iterator;

Iterator* create_iter(char* iterable, size_t isize);

void iterator_free(Iterator* iter);

char peek(Iterator* fi, int offset);

char pop(Iterator* fi);


#endif
