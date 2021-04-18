#include "input_buffer.h"
#include <stdio.h>
#include <stdlib.h>

InputBuffer *new_input_buffer(){
    InputBuffer *input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->input_length = 0;

    return input_buffer;
}

char *getInput(FILE* fp, size_t size, InputBuffer *input_buffer) {
    char *buffer; 
    int ch;
    size_t len = 0;
    //printf("SIZE: %d\n",size);
    buffer = realloc(NULL, sizeof(*buffer)*size);
    if(!buffer)return buffer;
    // fgetc = pointer to a FILE object (stream) that gets next char (unsigned char)
    // from the specified stream & advances the position indicator for the stream
    // fgetc returns a zero value on success & EOF on error
    // can use parenthesis to first do an action before comparisons
    while(EOF!=(ch=fgetc(fp)) && ch != ';'){
        // len++, increases the value of len
        buffer[len++]=ch; // able to change buffer char @ runtime bc char is basically an array
        //printf("WHILE: %zu\n",len);
        if(len==size){
            buffer = realloc(buffer, sizeof(*buffer)*(size+=16));
            if(!buffer)return buffer;
        }
    }

    input_buffer->input_length = len;
    buffer[len++]='\0';

    return realloc(buffer, sizeof(*buffer)*len);
}
