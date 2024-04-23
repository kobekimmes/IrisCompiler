#ifndef PARSER_H
#define PARSER_H


#include "./linked_list.h"
#include "./ast.h"

// int peek( LinkedList* tokens, int offset);

//  Node* eat( LinkedList* tokens);

Program* parse_tokens(LinkedList* tokens);


#endif