#include <stdio.h>

int main() {
    int score = 75;

    // Check if the score is high enough for a passing grade
    if (score >= 60) {
        printf("Congratulations, you Passed! 🎉\n");
    } else {
        printf("You Failed. Please try again. 😔\n");
    }

    return 0;
}