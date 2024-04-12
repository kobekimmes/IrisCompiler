
#include "../include/include.h"

 Node* node_create(Token* token_val) {
     Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        return NULL;
    }
    new_node->tok = token_val;
    new_node->next = NULL;

    return new_node;

}

void node_free( Node* node) {
    free(node);
    node = NULL;
}