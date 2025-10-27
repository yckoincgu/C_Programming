#include <stdio.h>

int main() {
    int x = 10;
    int y = 20;
    int z = 10;
    int result;

    printf("--- C Relational Operators Demonstration ---\n");
    printf("Variables: x = %d, y = %d, z = %d\n\n", x, y, z);

    // 1. Equal to (==)
    result = (x == z); // Is x equal to z? (10 == 10) -> True (1)
    printf("1. x == z (10 == 10) is: %d\n", result);

    result = (x == y); // Is x equal to y? (10 == 20) -> False (0)
    printf("2. x == y (10 == 20) is: %d\n", result);

    // 2. Not Equal to (!=)
    result = (x != y); // Is x not equal to y? (10 != 20) -> True (1)
    printf("3. x != y (10 != 20) is: %d\n", result);

    result = (x != z); // Is x not equal to z? (10 != 10) -> False (0)
    printf("4. x != z (10 != 10) is: %d\n", result);

    // 3. Greater Than (>)
    result = (y > x); // Is y greater than x? (20 > 10) -> True (1)
    printf("5. y > x (20 > 10) is: %d\n", result);

    // 4. Less Than (<)
    result = (x < y); // Is x less than y? (10 < 20) -> True (1)
    printf("6. x < y (10 < 20) is: %d\n", result);

    // 5. Greater Than or Equal to (>=)
    result = (x >= z); // Is x greater than or equal to z? (10 >= 10) -> True (1)
    printf("7. x >= z (10 >= 10) is: %d\n", result);

    result = (x >= y); // Is x greater than or equal to y? (10 >= 20) -> False (0)
    printf("8. x >= y (10 >= 20) is: %d\n", result);

    // 6. Less Than or Equal to (<=)
    result = (x <= y); // Is x less than or equal to y? (10 <= 20) -> True (1)
    printf("9. x <= y (10 <= 20) is: %d\n", result);

    result = (y <= x); // Is y less than or equal to x? (20 <= 10) -> False (0)
    printf("10. y <= x (20 <= 10) is: %d\n", result);

    return 0;
}