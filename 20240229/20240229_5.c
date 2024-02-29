#include <stdio.h>
#include <setjmp.h>

// Declare a global variable to hold the jump buffer
jmp_buf jump_buffer;

void functionWithJump() {
    printf("Inside functionWithJump\n");

    // Setjmp returns 0 when called directly, but returns a non-zero value
    // when returning from longjmp
    if (setjmp(jump_buffer) != 0) {
        // This code is executed when longjmp is called
        printf("Returning from longjmp\n");
        return;
    }

    printf("About to call longjmp\n");

    // Use longjmp to jump back to the point of setjmp
    longjmp(jump_buffer, 1);
}

int main() {
    printf("Before calling functionWithJump\n");

    // Call the function with setjmp
    functionWithJump();

    printf("After calling functionWithJump\n");

    return 0;
}

