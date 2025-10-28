#include <stdio.h>

int main() {
    int score = 85;
    char grade;

    printf("Student Score: %d\n\n", score);

    // We divide the score to level the ranges for easier case handling
    if(score >= 90) grade = 'A';
    else if(score >= 80) grade = 'B';
    else if(score >= 70) grade = 'C';
    else if(score >= 60) grade = 'D';
    else grade = 'F';
    printf("The corresponding grade by if-else is: %c\n", grade);

    switch (score / 10) {
        case 10: // Score 100
        case 9:  // Scores 90-99
            grade = 'A';
            break;
        case 8:  // Scores 80-89
            grade = 'B';
            break;
        case 7:  // Scores 70-79
            grade = 'C';
            break;
        case 6:  // Scores 60-69
            grade = 'D';
            break;
        default: // Scores 0-59 (everything else)
            grade = 'F';
            break;
    }

    printf("The corresponding grade by switch is: %c\n", grade);



    return 0;
}