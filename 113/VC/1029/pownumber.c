#include <stdio.h>
#include <math.h>

int main() {
    double n, x;
    int i;
    double sum = 0;
    int length_count = 0;

    scanf("%lf", &n);
    x = n;

    // Calculate the number of digits
    while (n >= 1) {
        length_count += 1;
        n = n / 10;
    }

    n = x; // Reset n to the original value

    // Calculate the sum of each digit raised to the power of length_count
    for (i = 0; i < length_count; i++) {
        n = n * 10;
        sum += pow((int)trunc(n), length_count);
        n = n - (int)trunc(n);
    }

    // Check if the original number is equal to the calculated sum
    if (x == sum) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
