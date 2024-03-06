#include <ctype.h>
#include "token.h"
#include "util.h"

#define INC_BYTE_POS(fit) ((fit)->byte_pos++)
#define INC_LINE_POS(fit) ((fit)->line_pos++)

#define ZERO_LP(fit) ((fit)->line_pos = 0)
#define ZERO_BP(fit) ((fit)->byte_pos = 0)

struct Iterator {
    char* iterable;
    int line_pos;
    int byte_pos;
};

struct Iterator* create_iter(char* iterable);

void generate_tokens(struct Iterator* iter, struct Token* tokens[], int* token_count);

void iterator_free(struct Iterator* iter);
