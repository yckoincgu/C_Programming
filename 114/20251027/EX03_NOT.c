#include <stdio.h>

int main() {
    int is_raining = 1; // 1 means true
    int go_outside;

    // Condition: NOT is_raining
    go_outside = !is_raining;

    printf("Result: %d\n", go_outside); // Output: 0 (False, because !1 is 0)

    is_raining = 0; // 0 means false
    go_outside = !is_raining;

    printf("Result: %d\n", go_outside); // Output: 1 (True, because !0 is 1)

    return 0;
}