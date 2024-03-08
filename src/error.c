#include "../include/error.h"

struct Error* error_create(struct Iterator* fit, enum error_type type, char* msg) {
    struct Error* err = (struct Error*) malloc(sizeof(struct Error));
    if (fit == NULL || err == NULL) {
        return NULL;
    }
    else {
        err->fi = fit;
    }
    err->type = type;
    err->msg = msg;

    return err;
}

void error_throw(struct Error* err) {
    char out_msg[256];
    switch (err->type) {
        case NONE:
            snprintf(out_msg, sizeof(out_msg), "No errors detected, exited successfully");
            break;

        case SYN:
            snprintf(out_msg, sizeof(out_msg), "Error detected at ln:%d:%d; %s", err->fi->line_pos, err->fi->byte_pos, err->msg);
            break;

        case TYPE:
            snprintf(out_msg, sizeof(out_msg), "Error detected at ln:%d:%d; %s", err->fi->line_pos, err->fi->byte_pos, err->msg);
            break;
        default:
            break;
    }
    fprintf(stderr, "%s", out_msg);
    error_free(err);
}


void error_free(struct Error* err) {
    if (err != NULL) {
        free(err);
    }
}