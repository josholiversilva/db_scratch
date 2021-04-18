#include <stdio.h> // for printf
#include <stdlib.h> // for malloc
#include <string.h> // for strlen, strstr

// Custom files to include
#include "action_sql.h"
#include "input_buffer.h"

int main(int argc, char **argv){
    // Temporary storage area for input/output
    // needs to be cleared before the next input is taken in 
    InputBuffer *input_buffer = new_input_buffer(); // variable input_buffer points to type InputBuffer
    printf("Buffer: %s\n Input Length: %d\n", input_buffer->buffer, input_buffer->input_length);

    while(1){
        printf(".db> ");
        input_buffer->buffer = getInput(stdin,10,input_buffer);

        if(strcmp(input_buffer->buffer, ".exit") == 0) {
            printf("Exiting..\n");
            return 0;
        }
	action(input_buffer->buffer);
        printf("%s\n",input_buffer->buffer);
    }
    return 0;
} 
