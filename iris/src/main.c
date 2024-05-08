#include "../include/include.h"
#include <string.h>

int main(int argc, char** argv) {
    int num_toks = 0;
    if (argc > 1) {
        
        LinkedList* toks = tokenize(argv[1], &num_toks);
        if (toks == NULL) {
            printf("Failed");
            return 1;
        }

        // parse_tokens(toks);


        tokens_free(toks);
        list_free(&toks);

    }
    else {
        printf("Please enter a path");
    }

    return 0;
}