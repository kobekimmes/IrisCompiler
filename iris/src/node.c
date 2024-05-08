
#include "../include/include.h"


Node* node_create(void* val, enum VALUE_TYPE node_type) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        return NULL;
    }

    switch (node_type) {
        case TOK:
            new_node->val = (Token*) val;
            break;
        // case INST:
        //     new_node->val = (Instruction*) val;
        //     break;
        default:
            new_node->val = NULL;
            break;
    }
    
    new_node->type = node_type;
    new_node->next = NULL;

    return new_node;

}

void node_free(Node** node) {
    free(*node);
    *node = NULL;
}