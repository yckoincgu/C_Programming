#include <stdio.h>

int main() {
    int integerVar;
    char characterVar;
    float floatVar;
    double doubleVar;
    
    printf("Enter an integer: ");
    scanf("%d", &integerVar);
    
    printf("Enter a character: ");
    scanf(" %c", &characterVar);  
    
    printf("Enter a float: ");
    scanf("%f", &floatVar);
    
    printf("Enter a double: ");
    scanf("%lf", &doubleVar);
    
    printf("\n--- Values Entered ---\n");
    printf("Integer: %d\n", integerVar);
    printf("Character: %c\n", characterVar);
    printf("Float: %.2f\n", floatVar);
    printf("Double: %.2lf\n", doubleVar);
    
    return 0;
}