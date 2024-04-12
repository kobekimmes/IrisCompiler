#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "./node.h"
#include <stdlib.h>

//typedef struct Node;

typedef struct LinkedList { 
    struct Node* head;
    struct Node* tail;
    int size;
} LinkedList;


LinkedList* list_create();

void list_add(LinkedList* lst, Node* node);

void list_free(LinkedList* ll);

#endif