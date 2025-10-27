#include <stdio.h>

int main() {
    int age = 25;
    int money = 100;
    int is_adult_and_rich;

    // Condition: age is greater than 18 AND money is greater than 50
    is_adult_and_rich = (age > 18) && (money > 50);

    printf("Result: %d\n", is_adult_and_rich); // Output: 1 (True, because 25 > 18 and 100 > 50)

    age = 15;
    is_adult_and_rich = (age > 18) && (money > 50);

    printf("Result: %d\n", is_adult_and_rich); // Output: 0 (False, because 15 > 18 is false)

    return 0;
}
