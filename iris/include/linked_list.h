#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "./node.h"
#include <stdlib.h>

//typedef struct Node;

typedef struct LinkedList { 
    struct Node* head;
    struct Node* tail;
    int size;
    int type;
} LinkedList;


LinkedList* list_create(enum VALUE_TYPE type);

void list_push_front(LinkedList* lst, Node* node);

void list_push_back(LinkedList* lst, Node* node);

Node* list_pop_head(LinkedList* lst);

Node* list_peek_head(LinkedList* lst);

Node* list_pop_tail(LinkedList* lst);

Node* list_peek_tail(LinkedList* lst);

void list_free(LinkedList** ll);

#endif