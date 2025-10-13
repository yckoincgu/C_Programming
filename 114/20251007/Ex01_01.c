#include <stdio.h>

/**
 * Main function: Calculates the sum of numbers from 1 to 10
 * using a for loop and prints the result.
 */
int main() {
    int sum = 0; // Initialize sum to 0
    int i;       // Loop counter

    // Loop from i = 1 up to i = 10 (inclusive)
    /*
        Visual Table of Loop Execution:
        Iteration	i value	Operation: sum = sum + i	New sum value
        1	i = 1	sum = 0 + 1	sum = 1
        2	i = 2	sum = 1 + 2	sum = 3
        3	i = 3	sum = 3 + 3	sum = 6
        4	i = 4	sum = 6 + 4	sum = 10
        5	i = 5	sum = 10 + 5	sum = 15
        6	i = 6	sum = 15 + 6	sum = 21
        7	i = 7	sum = 21 + 7	sum = 28
        8	i = 8	sum = 28 + 8	sum = 36
        9	i = 9	sum = 36 + 9	sum = 45
        10	i = 10	sum = 45 + 10	sum = 55 
        
        Step 0: sum = 0
                ─────

        Step 1: sum = 0 + 1 = 1
                ─────   ↑
                        i=1

        Step 2: sum = 1 + 2 = 3
                ─────   ↑
                        i=2

        Step 3: sum = 3 + 3 = 6
                ─────   ↑
                        i=3

        Step 4: sum = 6 + 4 = 10
                ─────   ↑
                        i=4

        Step 5: sum = 10 + 5 = 15
                ──────   ↑
                        i=5

        Step 6: sum = 15 + 6 = 21
                ──────   ↑
                        i=6

        Step 7: sum = 21 + 7 = 28
                ──────   ↑
                        i=7

        Step 8: sum = 28 + 8 = 36
                ──────   ↑
                        i=8

        Step 9: sum = 36 + 9 = 45
                ──────   ↑
                        i=9

        Step 10: sum = 45 + 10 = 55
                ──────   ↑
                        i=10        

    */
    for (i = 1; i <= 10; i++) {
        sum = sum + i; // Add the current value of i to sum
        // This is equivalent to: sum += i;
    }

    // Print the final result
    printf("The sum of numbers from 1 to 10 is: %d\n", sum);

    return 0;
}