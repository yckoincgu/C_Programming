#include <stdio.h>
#include <setjmp.h>

jmp_buf jump_buffer;

void second_function() {
    printf("Entering second_function()\n");
    
    // Jump back to where setjmp was called
    longjmp(jump_buffer, 1);
    
    // This code will not be executed
    printf("Exiting second_function()\n");
}

int main() {
    int jump_result;

    // Set up the jump point
    jump_result = setjmp(jump_buffer);

    if (jump_result == 0) {
        printf("setjmp() returned 0\n");
        
        // Call the second function
        second_function();
    } else {
        printf("setjmp() returned %d through longjmp()\n", jump_result);
    }

    printf("Exiting main()\n");

    return 0;
}

