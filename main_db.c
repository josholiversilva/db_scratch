#include <stdio.h> // for printf
#include <stdlib.h> // for malloc
#include <string.h> // for strlen

typedef struct {
    char *buffer; // pointer to char
    ssize_t input_length; // signed int
} InputBuffer;

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
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        // len++, increases the value of len
        buffer[len++]=ch; // able to change buffer char @ runtime bc char is basically an array
        //printf("WHILE: %zu\n",len);
        if(len==size){
            buffer = realloc(buffer, sizeof(*buffer)*(size+=16));
            if(!buffer)return buffer;
        }
    }

    printf("LEN: %zu\n",len);
    input_buffer->input_length = len;
    buffer[len++]='\0';

    return realloc(buffer, sizeof(*buffer)*len);
}

int main(int argc, char **argv){
    // Temporary storage area for input/output
    // needs to be cleared before the next input is taken in 
    InputBuffer *input_buffer = new_input_buffer(); // variable input_buffer points to type InputBuffer
    printf("Buffer: %s\n Input Length: %d\n", input_buffer->buffer, input_buffer->input_length); //InputBuffer hasValues = {"whook",6,6};
    while(1){
        printf(".db > ");
        input_buffer->buffer = getInput(stdin,10,input_buffer);
        printf("%s\n",input_buffer->buffer);
        printf("INPUT LENGTH: %zu\n",input_buffer->input_length) 
        //strcmp(str,input_buffer->buffer_length);
    }
    return 0;
    // strcmp (C Library) - compares string pointed to by str1 to string pointed to by str2
    //if (strcmp(input_buffer->buffer, ".exit") == 0){
        //close_input_buffer(input_buffer);
        //exit(EXIT_SUCCESS);
    //}
    //else{
        //printf("Unrecognized command '%s'", input_buffer->buffer);
    //} 
} 
