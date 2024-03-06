#include "lexer.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        int num_toks = 0;
        struct Token** toks = tokenize(argv[1], &num_toks);
        tokens_free(toks, num_toks);
    }
    else {
        printf("Please provid a path");
    }

    return 0;
}