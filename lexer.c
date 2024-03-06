
#include "lexer.h"

struct Token** tokenize(char* path, int* token_count) {
    int file_byte_count = (int) get_file_size(path);
    
    char* source = get_file_contents(path);

    struct Token** tokens = malloc(sizeof(struct Token) * file_byte_count);
    if (tokens == NULL) {
        perror("tokenize()");
        return NULL;
    }

    printf("%s", source);
    
    struct Iterator* fi = create_iter(source);
    if (fi == NULL) {
        fprintf(stderr, "tokenize(): Failed to initialize iterator");
        return NULL;
    }
    
    generate_tokens(fi, tokens, token_count);

    iterator_free(fi);

    tokens_print(tokens, *token_count);

    return tokens;
}

