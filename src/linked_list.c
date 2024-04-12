
#include "../include/include.h"


LinkedList* list_create() {
    LinkedList* ll = (LinkedList*) malloc(sizeof(LinkedList));
    if (ll == NULL) {
        return NULL;
    }
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;

    return ll;


}

void list_add(LinkedList* lst,  Node* node) {
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

void list_free(LinkedList* ll) {
    Node* ptr = ll->head;
    while (ptr != NULL) {
        Node* temp = ptr->next;
        node_free(ptr);
        ptr = temp;
    }
    free(ll);
}

