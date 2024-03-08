#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../include/node.h"
#include <stdlib.h>

struct LinkedList { 
    struct Node* head;
    struct Node* tail;
    int size;
};


struct LinkedList* list_create();

void list_add(struct LinkedList* lst, struct Node* node);

void list_free(struct LinkedList* ll);

#endif