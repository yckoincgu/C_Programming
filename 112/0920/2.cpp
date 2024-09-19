#include <stdio.h>
int main() {    

    int number1, number2, result,a=0;
    char op;
	
    while(a<=20)
    {
    printf("Enter two integers: \n");
    scanf("%d  \n   %d", &number1, &number2);
    printf("Enter one of following operators: +, -, *, / --> \n ");
    fflush(stdin); 

    scanf("%c", &op);
        
    switch(op){
        case '+': result = number1 + number2;  break;
        case '-': result = number1 - number2;  break;
        case '*': result = number1 * number2;  break;
        case '/': result = number1 / number2;  break;
	}
    printf("The result:%d %c %d = %d", number1,op,number2,result);

    printf("\nContinue with a<=20, input in the followings \n");
    fflush(stdin); 
    scanf("%d", &a);
	
		}

	return 0;
}
