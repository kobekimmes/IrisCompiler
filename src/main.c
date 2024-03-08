#include "../include/lexer.h"
#include <string.h>

int main(int argc, char** argv) {
    int num_toks = 0;
    if (argc > 1) {
    //     char* path = argv[1];
    //     int file_byte_count = (int) get_file_size(path);
    
    // char* source = get_file_contents(path);

    // if (source == NULL) {
    //     fprintf(stderr, "tokenize(): Failed to read from file\n");
    //     return NULL;
    // }

    //  struct Iterator* fi = create_iter(source, file_byte_count);
    //     if (fi == NULL) {
    //     fprintf(stderr, "tokenize(): Failed to initialize iterator\n");
    //     free(source);
    //     return NULL;
    // }

    // char err_msg[64];
    //     snprintf(err_msg, sizeof(err_msg), "Unexpected value;");
    //     struct Error* err = error_create(fi, TYPE, err_msg);
    //     error_throw(err);
        
        struct LinkedList* toks = tokenize(argv[1], &num_toks);
        if (toks == NULL) {
            printf("Failed");
        }
        else {
            tokens_free(toks);
            list_free(toks);
        }


        // char* src = get_file_contents(argv[1]);
        // if (strcmp(src, "num x = 10") == 0) {
        //     printf("success");
        // }
        // else {
        //     printf("fail");
        // }
    }
    else {
        //  struct Token** toks = tokenize(stdin, &num_toks);
        // if (toks == NULL) {
        //     printf("Failed");
        // }
        // else {
        //     tokens_free(toks, num_toks);
        // }
        printf("Please enter a path");
    }

    return 0;
}