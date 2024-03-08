
#include "../include/node.h"

struct Node* node_create(struct Token* token_val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if (new_node == NULL) {
        return NULL;
    }
    new_node->tok = token_val;
    new_node->next = NULL;

    return new_node;

}

void node_free(struct Node* node) {
    free(node);
    node = NULL;
}