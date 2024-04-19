#include "../include/include.h"
#include <string.h>

Token* token_create(enum token_type type, char* val, int line_pos, int byte_pos) {
    Token* tok = (Token*) malloc(sizeof(Token));
    if (tok == NULL || val == NULL) {
        perror("token_create()");
        return NULL;
    }
    tok->type = type;
    int val_size = strlen(val);
    
    tok->val = (char*) malloc(val_size+1);
    if (tok->val == NULL) {
        perror("token_create()");
        free(tok);
        return NULL;
    }
    
    strncpy(tok->val, val, val_size);
    tok->val[val_size] = '\0';
    
    tok->line_pos = line_pos;
    tok->byte_pos = byte_pos;

    return tok;
}

void token_print(Token* tok) {
    if (tok != NULL) {
        if (tok->val == NULL) {
            printf("\n{ token value is NULL }");
        }
        else {
            printf("\n{ type: %d ; value: %s, ln%d:%d }", tok->type, tok->val, tok->line_pos, tok->byte_pos);
        }
    }
    else {
        printf("\n{ token is NULL }");
    }
}

void tokens_print( LinkedList* ll) {
    Node* ptr = ll->head;
    printf("\nThere are %d tokens", ll->size);
    while (ptr != NULL) {
        if (ptr->tok->type != SPACE) {
            token_print(ptr->tok);
        }
        ptr = ptr->next;
    }
}

void token_free( Token* tok) {
    free(tok->val);
    tok->val = NULL;
    free(tok);
    tok = NULL;
}

void tokens_free( LinkedList* ll) {
     Node* ptr = ll->head;
    while (ptr != NULL) {
        if (ptr->tok->type != SPACE) {
            token_free(ptr->tok);
        }
        ptr = ptr->next;
    }

}
