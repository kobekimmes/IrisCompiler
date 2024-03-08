#include "../include/file_iterator.h"

char* reserved[] = {"num", "idea", "for", "if", "return"};

struct Iterator* create_iter(char* iterable, size_t isize) {
    struct Iterator* fi = (struct Iterator*) malloc(sizeof(struct Iterator));
    if (fi == NULL) {
        perror("create_iter()");
        return NULL;
    }
    fi->iterable = iterable;
    fi->isize = isize;
    fi->byte_pos = 1;
    fi->line_pos = 1;
    return fi;
}

void generate_tokens(struct Iterator* iter, struct Token** tokens, int* token_count) {
    // char* source = iter->iterable;
    // printf("\nThe size of the file is %zu\n", iter->isize);
    // char curr = source[0];
    // int ptr = 0;

    // while (ptr < iter->isize && (curr = source[ptr]) != '\0') {
    //     printf("\nCurrent val at ptr: %d, is %c", ptr, curr);

    //     if (isdigit(curr) == 1) {
    //         int b_pos = iter->byte_pos;
    //         int l_pos = iter->line_pos;

    //         char numeral[64] = "";
    //         int idx = 0;

    //         while (isdigit(curr = source[ptr]) && idx < sizeof(numeral)-1) {
    //             numeral[idx++] = curr;
    //             INC_BYTE_POS(iter);
    //             ptr++;
    //         }

    //         numeral[idx] = '\0';

    //         tokens[(*token_count)++] = token_create(NUMERIC, numeral, l_pos, b_pos);
    //         continue;
    //     }

    //     if (isalpha(curr) == 1) {
    //         int b_pos = iter->byte_pos;
    //         int l_pos = iter->line_pos;

    //         char identifier[64] = "";
    //         int idx = 0;

    //         int res = 0;

    //         while (isalpha(curr = source[ptr]) && idx < sizeof(identifier)-1) {
    //             identifier[idx++] = curr;
    //             INC_BYTE_POS(iter);
    //             ptr++;
    //         }

    //         identifier[idx] = '\0';

    //         for (int i = 0 ; i < NUM_RESERVED; i++) {
    //             if (strcmp(reserved[i], identifier) == 0) {
    //                 res = 1;
    //                 tokens[(*token_count)++] = token_create(i+10, identifier, l_pos, b_pos);
                    
    //                 continue;
    //             }
    //         }
    //         if (!res) {
    //             tokens[(*token_count)++] = token_create(IDENT, identifier, l_pos, b_pos);
    //         }

    //         continue;
    //     }
    //     char err_msg[64];
    //     switch (curr) {
    //         case '\n':
    //             INC_LINE_POS(iter);
    //             ZERO_BP(iter);
    //             break;
    //         case '\r':
    //             ZERO_BP(iter);
    //         case '(':
    //             tokens[(*token_count)++] = token_create(LPAREN, &curr, iter->line_pos, iter->byte_pos);
    //             break;
    //         case ')':
    //             tokens[(*token_count)++] = token_create(RPAREN, &curr, iter->line_pos, iter->byte_pos);
    //             break;
    //         case '{':
    //             tokens[(*token_count)++] = token_create(LBRCKT, &curr, iter->line_pos, iter->byte_pos);
    //             break;
    //         case '}':
    //             tokens[(*token_count)++] = token_create(RBRCKT, &curr, iter->line_pos, iter->byte_pos);
    //             break;
    //         case '=': 
    //             tokens[(*token_count)++] = token_create(EQ, &curr, iter->line_pos, iter->byte_pos);
    //             break;
    //         case '+':
    //         case '/':
    //         case '-':
    //         case '*':
    //             tokens[(*token_count)++] = token_create(BIN_OP, &curr, iter->line_pos, iter->byte_pos);
    //             break;
    //         case ':':
    //             tokens[(*token_count)++] = token_create(COLON, &curr, iter->line_pos, iter->byte_pos);
    //             break;
    //         case ' ':
    //         case '\t':
    //             break;
    //         default:
    //             snprintf(err_msg, sizeof(err_msg), "Unexpected value; '%c' read from stream, could not tokenize\n", curr);
    //             struct Error* err = error_create(iter, TYPE, err_msg);
    //             if (err == NULL) {
    //                 fprintf(stderr, "Error: failed throwing error");
    //                 return;
    //             }
    //             error_throw(err);
    //             return;
    //     }
    //     INC_BYTE_POS(iter);
    //     ptr++;
    // }
}


void iterator_free(struct Iterator* iter) {
    if (iter != NULL) {
        free(iter->iterable);
        free(iter);
        iter = NULL;
    }
}

