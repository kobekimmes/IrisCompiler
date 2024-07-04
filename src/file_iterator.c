#include "../include/include.h"

// char* reserved[] = {"num", "idea", "for", "if", "return"};

Iterator* create_iter(const char* iterable, size_t isize) {
    Iterator* fi = (Iterator*) malloc(sizeof(Iterator));
    if (fi == NULL) {
        perror("create_iter()");
        return NULL;
    }
    fi->iterable = iterable;
    fi->isize = isize;
    fi->byte_pos = 0;
    fi->line_pos = 1;
    fi->file_pos = 0;
    return fi;
}


void iterator_free(Iterator* iter) {
    if (iter != NULL) {
        free(iter->iterable);
        free(iter);
        iter = NULL;
    }
}

char peek(Iterator* fi, int offset) {
    if (fi->file_pos+offset >= fi->isize) {
        return '\0';
    }
    return fi->iterable[fi->file_pos + offset];
}

char pop(Iterator* fi) {
    if (fi->file_pos >= fi->isize) {
        return '\0';
    }
    char pop = fi->iterable[fi->file_pos];
    
    switch (pop) {
        case '\n':
            INC_LINE_POS(fi);
            ZERO_BP(fi);
            break;
        case '\r':
            ZERO_BP(fi);
            break;
        default:
            INC_BYTE_POS(fi);
            break;
    }
    INC_FILE_POS(fi, 1);

    return pop;
}