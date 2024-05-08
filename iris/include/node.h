#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

#include "./token.h"

enum VALUE_TYPE { TOK, INST, DATA };

typedef struct Node {
    void* val;
    int type;
    struct Node* next;
} Node;

Node* node_create(void* val, enum VALUE_TYPE node_type);

void node_free(Node** node);

#endif