#include <stdio.h>

int main() {
    char str[100];
    double num;

    printf("Enter a number: ");
    scanf("%s", &str);


    if (sscanf(str, "%lf", &num) == 1) {
        printf("Converted number: %.3f\n", num);
    } else {
        printf("Invalid number \n");
    }

    return 0;
}