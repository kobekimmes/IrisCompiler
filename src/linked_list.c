
#include "../include/linked_list.h"


struct LinkedList* list_create() {
    struct LinkedList* ll = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    if (ll == NULL) {
        return NULL;
    }
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;

    return ll;


}

void list_add(struct LinkedList* lst, struct Node* node) {
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

void list_free(struct LinkedList* ll) {
    struct Node* ptr = ll->head;
    while (ptr != NULL) {
        struct Node* temp = ptr->next;
        node_free(ptr);
        ptr = temp;
    }
}

