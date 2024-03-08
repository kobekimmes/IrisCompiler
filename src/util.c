#include "../include/util.h"

off_t get_file_size(char* path) {
    struct stat file_stat;

    if (stat(path, &file_stat) != 0) {
        perror("get_file_size()");
        return -1;
    }

    return file_stat.st_size;
}

void get_file_count(char* path, int* wc, int* lc) {
    FILE* f = fopen(path, "r");

    if (f == NULL) {
        perror("get_file_count()");
        return;
    }

    char* line;
    size_t len = 0;
    ssize_t read = 0;

    int in_word = 0;

    while ((read = getline(&line, &len, f)) != 0) {
        (*lc)++;
        for (int i = 0; i < read; i++) {
            if (isspace(line[i])) {
                in_word = 0;
            }
            else if (in_word == 0) {
                (*wc)++;
                in_word = 1;
            }
        }
    }

    free(line);
    
    if (fclose(f) != 0) {
        perror("get_file_count()");
        return;
    }
    
}

char* get_file_contents(char* path) {
    
    off_t file_size = get_file_size(path);

    char* buffer = malloc(file_size + 1);
    
    if (buffer == NULL) {
        perror("get_file_contents()");
        return NULL;
    }

    FILE* f = fopen(path, "r");

    if (f == NULL) {
        perror("get_file_contents()");
        free(buffer);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, file_size, f);

    if (bytes_read != file_size) {
        if (feof(f)) {
            printf("End of file reached");
        }
        else if (ferror(f)) {
            perror("get_file_contents()");
        }
        else {
            printf("Read only %zu bytes", bytes_read);
        }
    }

    if (fclose(f) != 0) {
        perror("get_file_contents()");
        free(buffer);
        return NULL;
    }

    buffer[bytes_read] = '\0';

    return buffer;
}