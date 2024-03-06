#include "error.h"

struct Error* error_create(struct Iterator* fit, enum error_type type, char* msg) {
    struct Error* err = (struct Error*) malloc(sizeof(struct Error));
    err->fi = fit;
    err->type = type;
    err->msg = msg;

    return err;
}

void error_message(struct Error* err) {
    char out_msg[256];
    switch (err->type) {
        case NONE:
            snprintf(out_msg, sizeof(out_msg), "No errors detected, exited successfully");
            break;

        case SYN:
            snprintf(out_msg, sizeof(out_msg), "Syntax error detected at line:%d, character:%d", err->fi->line_pos, err->fi->byte_pos);
            break;

        case TYPE:
            snprintf(out_msg, sizeof(out_msg), "Type error detected at line:%d, character:%d", err->fi->line_pos, err->fi->byte_pos);
            break;
    }
    fprintf(stderr, "%s", out_msg);
    error_free(err);
}


void error_free(struct Error* err) {
    free(err);
}