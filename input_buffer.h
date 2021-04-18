#ifndef INPUT_BUFFER_H_
#define INPUT_BUFFER_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *buffer; // pointer to char
    ssize_t input_length; // signed int
} InputBuffer;

InputBuffer *new_input_buffer();
char *getInput(FILE* fp, size_t size, InputBuffer *input_buffer);

#endif
