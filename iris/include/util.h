#ifndef UTIL_H
#define UTIL_H

#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

off_t get_file_size(char* path);

void get_file_count(char* path, int* wc, int* lc);

char* get_file_contents(char* path);

#endif