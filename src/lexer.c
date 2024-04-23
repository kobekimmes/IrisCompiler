#include "../include/include.h"



 LinkedList* tokenize(char* path, int* token_count) {
    int file_byte_count = (int) get_file_size(path);
    
    char* source = get_file_contents(path);

    if (source == NULL) {
        fprintf(stderr, "tokenize(): Failed to read from file\n");
        return NULL;
    }

    Iterator* fi = create_iter(source, file_byte_count);
    if (fi == NULL) {
        fprintf(stderr, "tokenize(): Failed to initialize iterator\n");
        free(source);
        return NULL;
    }

    LinkedList* tokens = list_create();
    if (tokens == NULL) {
        fprintf(stderr, "tokenize(): Failed to initialize tokens array\n");
        free(fi);
        return NULL;
    }

    printf("%s", source);
    
    gen_toks(fi, tokens);

    iterator_free(fi);

    tokens_print(tokens);

    return tokens;
}

void gen_toks(Iterator* iter,  LinkedList* tokens) {
    const char* source = iter->iterable;
    Token* next_tok;

    while (iter->file_pos < iter->isize && (next_tok = get_next_token(iter)) != NULL) {
        if (next_tok->type != SPACE || next_tok->type != -1) {
            list_push_back(tokens, node_create(next_tok));
        }

    }

}

 Token* get_next_token(Iterator* iter) {
    
    char curr = pop(iter);
    char buf[2];
    int index = 0;
    buf[index++] = curr;

    int l_pos;
    int b_pos;
    
    Token* ret_tok;
    
    char err_msg[64];


    switch (curr) {
        case '\0':
            return NULL;
        case ' ':
        case '\t':
            ret_tok = token_create(SPACE, buf, iter->line_pos, iter->byte_pos);
            break;
        case '\n':
            ret_tok = token_create(SPACE, buf, iter->line_pos, iter->byte_pos);
            break;
        case '\r':
            ret_tok = token_create(SPACE, buf, iter->line_pos, iter->byte_pos);
            break;
        case '(':
            ret_tok = token_create(LPAREN, buf, iter->line_pos, iter->byte_pos);
            break;
        case ')':
            ret_tok = token_create(RPAREN, buf, iter->line_pos, iter->byte_pos);
            break;
        case '{':
            ret_tok = token_create(LBRCKT, buf, iter->line_pos, iter->byte_pos);
            break;
        case '}':
            ret_tok = token_create(RBRCKT, buf, iter->line_pos, iter->byte_pos);
            break;
        case '[':
            ret_tok = token_create(LSQBRCKT, buf, iter->line_pos, iter->byte_pos);
            break;
        case ']':
            ret_tok = token_create(RSQBRCKT, buf, iter->line_pos, iter->byte_pos);
            break;
        case '=': 
            if (peek(iter, 1) == '=') {
                buf[index++] = pop(iter);
                ret_tok = token_create(BIN_OP, buf, iter->line_pos, iter->byte_pos);
            }
            else {
                ret_tok = token_create(EQ, buf, iter->line_pos, iter->byte_pos);
                
            }
            break;
        case '+':
        case '/':
            
        case '-':
        case '*':
            
        case '<':
        case '>':
            if (peek(iter, 1) == '=') {
                buf[index++] = pop(iter);
                ret_tok = token_create(BIN_OP, buf, iter->line_pos, iter->byte_pos);
            }
            else {
                ret_tok = token_create(BIN_OP, buf, iter->line_pos, iter->byte_pos);
            }
            break;
        case ':':
            ret_tok = token_create(COLON, buf, iter->line_pos, iter->byte_pos);
            break;
        case ';':
            ret_tok = token_create(SEMICOLON, buf, iter->line_pos, iter->byte_pos);
            break;
        // Single-line comments are to begin with '#'
        case '#':
            while (peek(iter, 0) != '\n') { pop(iter); }
            ret_tok = empty_token();
            break;
        case '"':
            l_pos = iter->line_pos;
            b_pos = iter->byte_pos;
            char* string = handle_string_literal(iter);
            ret_tok = token_create(STRING_LITERAL, string, l_pos, b_pos);
            break;
        default:

            if (isdigit(curr)) {
                l_pos = iter->line_pos;
                b_pos = iter->byte_pos;

                char* numeral = handle_numeric_literal(iter);
                                
                return token_create(NUMERIC_LITERAL, numeral, l_pos, b_pos);
            }

            else if (isalpha(curr)) {
                l_pos = iter->line_pos;
                b_pos = iter->byte_pos;

                char* identifier = handle_identifier(iter);

                int reserved_tok_val;
                if ((reserved_tok_val = find_reserved_keyword(identifier)) != -1) { 
                    return token_create(reserved_tok_val, identifier, l_pos, b_pos); 
                }

                else { 
                    return token_create(IDENT, identifier, l_pos, b_pos); 
                }
            }

            else {
                snprintf(err_msg, sizeof(err_msg), "Unexpected value; '%c' read from stream, could not tokenize\n", curr);
                Error* err = error_create(iter, TYPE, err_msg);
                if (err == NULL) {
                    fprintf(stderr, "Error: failed throwing error");
                    return NULL;
                }
                error_throw(err);
                return NULL;
            }
        }
    return ret_tok;
}


int find_reserved_keyword(char* str) {
    
    if (strcmp(str, "num") == 1) {
        return NUM;
    }
    else if (strcmp(str, "word") == 1) {
        return WORD;
    }

    return -1;

}


char* handle_numeric_literal(Iterator* iter) {
    int start_file_pos = iter->file_pos-1;

    while (isdigit(peek(iter, 0))) {
         printf("%c", peek(iter, 0));
        pop(iter);
    }
    int size = iter->file_pos - start_file_pos;
    char* numeral = (char*) malloc(sizeof(char) * size + 1);
    if (numeral == NULL) {
        exit(1);
    }

    memcpy(numeral, &iter->iterable[start_file_pos], size);
    numeral[size] = '\0';
    return numeral;
}

char* handle_identifier(Iterator* iter) {
    int start_file_pos = iter->file_pos-1;

    while (isalnum(peek(iter, 0))) {
        printf("%c", peek(iter, 0));
        pop(iter);
    }
    int size = iter->file_pos - start_file_pos;
    char* identifier = (char*) malloc(sizeof(char) * size + 1);
    if (identifier == NULL) {
        exit(1);
    }
    
    memcpy(identifier, &iter->iterable[start_file_pos], size);
    identifier[size] = '\0';
    return identifier;
}

char* handle_string_literal(Iterator* iter) {
    int start_file_pos = iter->file_pos-1;
    
    while ((peek(iter, 0) != '"')) {
         printf("string lit: %c\n", peek(iter, 0));
        pop(iter);
        
    }
    int size = iter->file_pos - start_file_pos;
    char* string = (char*) malloc(sizeof(char) * size + 1);
    if (string == NULL) {
        exit(1);
    }

    memcpy(string, &iter->iterable[start_file_pos], size);
    string[size] = '\0';
    return string;
}

char* handle_arithmetic_operators(Iterator* iter, char curr) {
    return NULL;
}

int is_seperator(char ch) {
    switch (ch) {
        case '\n': 
        case ';':
        case ' ':
        case '\t':
            return 1;
        default:
            return 0;


    }
}