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


void iterator_free(struct Iterator* iter) {
    if (iter != NULL) {
        free(iter->iterable);
        free(iter);
        iter = NULL;
    }
}

