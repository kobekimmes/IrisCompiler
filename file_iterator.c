#include "file_iterator.h"

struct Iterator* create_iter(char* iterable) {
    struct Iterator* fi = (struct Iterator*) (sizeof(struct Iterator));
    if (fi == NULL) {
        perror("create_iter()");
        return NULL;
    }
    fi->iterable = iterable;
    fi->byte_pos = 0;
    fi->line_pos = 0;
    return fi;
}

void generate_tokens(struct Iterator* iter, struct Token* tokens[], int* token_count) {
    char* source = iter->iterable;
    char curr;

    while ((curr = (source[iter->byte_pos])) != '\0') {
        switch (curr) {
        case '\n':
            INC_LINE_POS(iter);
            ZERO_BP(iter);
        case '(':
            tokens[(*token_count)++] = token_create(LPAREN, &curr);
            break;
        case ')':
            tokens[(*token_count)++] = token_create(RPAREN, &curr);
            break;
        case '=': 
            tokens[(*token_count)++] = token_create(EQ, &curr);
            break;
        default:
            break;
            
        }
        INC_BYTE_POS(iter);
    }
}


void iterator_free(struct Iterator* iter) {
    free(iter->iterable);
    free(iter);
    iter = NULL;
}

