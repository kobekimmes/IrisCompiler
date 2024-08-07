#include "../include/include.h"


int peek( LinkedList* tokens, int offset) {
     Node* ptr = tokens->head;
    int count = 0;
    while (ptr != NULL && (count++) < offset) {
        ptr = ptr->next;
    }

    if (ptr != NULL) {
        return 1;
    }
    return 0;

}

 Node* eat( LinkedList* tokens) {
     Node* eat_node = tokens->head;

    if (eat_node == NULL) {
        return NULL;
    }

    tokens->head = tokens->head->next;
    
    return eat_node;
}


Program* parse_tokens( LinkedList* tokens) {
    if (tokens == NULL) {
        return NULL;
    }

    Program* AST = (Program*) malloc();

    Node* ptr = tokens->head;
    while (peek(tokens, 0)) {

        Token* t = (Token*) eat(tokens)->val;
        switch (t->type){
            case NUM:
                
                break;

            case WORD:

                break;
            
            case RETURN:
                break;
                
            default:
                break;
        }

    }
}
