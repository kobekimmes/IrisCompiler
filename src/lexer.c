
#include "../include/lexer.h"
#include "../include/linked_list.h"

struct LinkedList* tokenize(char* path, int* token_count) {
    int file_byte_count = (int) get_file_size(path);
    
    char* source = get_file_contents(path);

    if (source == NULL) {
        fprintf(stderr, "tokenize(): Failed to read from file\n");
        return NULL;
    }

     struct Iterator* fi = create_iter(source, file_byte_count);
    if (fi == NULL) {
        fprintf(stderr, "tokenize(): Failed to initialize iterator\n");
        free(source);
        return NULL;
    }

    struct LinkedList* tokens = list_create();
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

void gen_toks(struct Iterator* iter, struct LinkedList* tokens) {
    char* source = iter->iterable;
    struct Token* next_tok;
    int ptr = 0;
    //printf("\nThe isize of the file is %zu, and the strlen() of the file is %zu\n", iter->isize, strlen(source));

    while (ptr < iter->isize && (next_tok = get_next_token(iter, source, &ptr)) != NULL) {
        if (next_tok->type != SPACE) {
            list_add(tokens, node_create(next_tok));
            //token_print(next_tok);
        }

    }

}

struct Token* get_next_token(struct Iterator* iter, char* source, int* ptr) {
    if (*ptr >= iter->isize) {
        return NULL;
    }

    
    //char* get_char = eat(source, ptr);

    //char curr = *get_char; 

    char curr = source[*ptr];   
    
    //printf("%lu", sizeof(curr));
    printf("\nCurrent val at ptr: %d, is %c", *ptr, curr);
    
    
    struct Token* ret_tok;
    char err_msg[64];

    switch (curr) {
        case '\0':
            return NULL;
        case ' ':
        case '\t':
            ret_tok = token_create(SPACE, &curr, iter->line_pos, iter->byte_pos);
            break;
        case '\n':
            INC_LINE_POS(iter);
            ZERO_BP(iter);
            ret_tok = token_create(SPACE, &curr, iter->line_pos, iter->byte_pos);
            break;
        case '\r':
            ZERO_BP(iter);
            ret_tok = token_create(SPACE, &curr, iter->line_pos, iter->byte_pos);
            break;
        case '(':
            ret_tok = token_create(LPAREN, &curr, iter->line_pos, iter->byte_pos);
            break;
        case ')':
            ret_tok = token_create(RPAREN, &curr, iter->line_pos, iter->byte_pos);
            break;
        case '{':
            ret_tok = token_create(LBRCKT, &curr, iter->line_pos, iter->byte_pos);
            break;
        case '}':
            ret_tok = token_create(RBRCKT, &curr, iter->line_pos, iter->byte_pos);
            break;
        case '=': 
            ret_tok = token_create(EQ, &curr, iter->line_pos, iter->byte_pos);
            break;
        case '+':
        case '/':
        case '-':
        case '*':
            ret_tok = token_create(BIN_OP, &curr, iter->line_pos, iter->byte_pos);
            break;
        case ':':
            ret_tok = token_create(COLON, &curr, iter->line_pos, iter->byte_pos);
            break;
        case ';':
            ret_tok = token_create(SEMICOLON, &curr, iter->line_pos, iter->byte_pos);
            break;
        default:

            if (isdigit(curr)) {
                int l_pos = iter->line_pos;
                int b_pos = iter->byte_pos;

                char numeral[32] = "";
                int idx = 0;
                while (isdigit(curr = source[(*ptr)++]) && idx < sizeof(numeral)-1) {
                    //printf("\n%s", numeral);
                    numeral[idx++] = curr;
                    INC_BYTE_POS(iter);
                    
                }
                numeral[idx] = '\0';
                (*ptr)--;
                //INC_BYTE_POS(iter);
                return token_create(NUMERIC, numeral, l_pos, b_pos);
            }

            else if (isalpha(curr)) {
                int l_pos = iter->line_pos;
                int b_pos = iter->byte_pos;

                char identifier[64] = "";
                int idx = 0;
                while (isalpha(curr = source[(*ptr)++]) && idx < sizeof(identifier)-1) {
                    //printf("\n%s", identifier);
                    identifier[idx++] = curr;
                    INC_BYTE_POS(iter);
                    
                }
                identifier[idx] = '\0';
                (*ptr)--;
                //INC_BYTE_POS(iter);
                return token_create(IDENT, identifier, l_pos, b_pos);
            }

            else {
                snprintf(err_msg, sizeof(err_msg), "Unexpected value; '%c' read from stream, could not tokenize\n", curr);
                struct Error* err = error_create(iter, TYPE, err_msg);
                if (err == NULL) {
                    fprintf(stderr, "Error: failed throwing error");
                    return NULL;
                }
                error_throw(err);
                return NULL;
            }
        }

    INC_BYTE_POS(iter);
    (*ptr)++;
    return ret_tok;
}


char* peek(char* source, int* ptr) {
    if (*ptr < strlen(source) && source[*ptr] != '\0') {
        return &source[*ptr];
    }
    else {
        return NULL;
    }
}


char* eat(char* source, int* ptr) {
    char* new_char = peek(source, ptr++);
    if (new_char == NULL) {
        return NULL;
    }
    else {   
        (*ptr)++;
        return new_char;
    }
}