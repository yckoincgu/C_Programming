#include <stdio.h>

int main() {
    int cities = 4; // Number of cities
    int months = 4; // Number of months
    double temperatures[cities][months];

    // Input average temperatures for each city and month
    for (int i = 0; i < cities; i++) {
        printf("City %d:\n", i + 1);
        for (int j = 0; j < months; j++) {
            printf("  Month %d: ", j + 1);
            scanf("%lf", &temperatures[i][j]);
        }
    }

    // Print the temperature table
    printf("\nTwo-dimensional array:\n");
    printf("  Jan.  Feb.  Mar.  Apr.\n");
    for (int i = 0; i < cities; i++) {
        printf("City %d  ", i + 1);
        for (int j = 0; j < months; j++) {
            printf("%6.1f ", temperatures[i][j]);
        }
        printf("\n");
    }

    return 0;
}