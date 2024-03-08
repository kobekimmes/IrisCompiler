#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

struct Node {
    struct Token* tok;
    struct Node* next;
};

struct Node* node_create(struct Token* token_val);

void node_free(struct Node* node);

#endif