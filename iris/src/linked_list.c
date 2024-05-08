
#include "../include/include.h"


LinkedList* list_create(enum VALUE_TYPE type) {
    LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));
    if (ll == NULL) {
        return NULL;
    }
    ll->type = type;
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;

    return ll;
}

void list_push_front(LinkedList* lst, Node* node) {
    if (node == NULL) {
        return;
    }

    node->next = lst->head;
    lst->head = node;
    lst->size++;
}


void list_push_back(LinkedList* lst,  Node* node) {
    if (node == NULL) {
        return;
    }
    if (lst->head == NULL) {
        lst->head = node;
        lst->tail = node;
        lst->size = 1;
    }
    else {
        lst->tail->next = node;
        lst->tail = lst->tail->next;
        lst->size++;
    }
}

Node* list_pop_head(LinkedList* lst) {
    Node* temp = lst->head;
    lst->head = lst->head->next;
    lst->size--;
    return temp;
}

Node* list_peek_head(LinkedList* lst) {
    return lst->head;
}

Node* list_pop_tail(LinkedList* lst) {
    Node* ptr = lst->head;
    int idx = 1;

    while (ptr != NULL && idx < lst->size-1) {
        ptr = ptr->next;
    }
    Node* temp = lst->tail;
    lst->tail = ptr;
    lst->tail->next = NULL;
    return temp;

}

Node* list_peek_tail(LinkedList* lst) {
    return lst->tail;
}



void list_free(LinkedList** ll) {
    Node* ptr = (*ll)->head;
    while (ptr != NULL) {
        Node* temp = ptr->next;
        node_free(&ptr);
        ptr = temp;
    }
    free(*ll);
    *ll = NULL;
}

