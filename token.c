#include "token.h"

struct Token* token_create(enum token_type type, char* val) {
    struct Token* tok = (struct Token*) malloc(sizeof(struct Token));
    if (tok == NULL) {
        perror("token_create()");
        return NULL;
    }
    tok->type = type;
    tok->val = val;

    return tok;
}

void token_print(struct Token* tok) {
    printf(" { type: %d ; value: %s }\n", tok->type, tok->val);
}

void tokens_print(struct Token* toks[], int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        token_print(toks[i]);
    }
}

void token_free(struct Token* tok) {
    free(tok);
    tok = NULL;
}

void tokens_free(struct Token* toks[], int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        token_free(toks[i]);
    }
    free(toks);
    toks = NULL;
}