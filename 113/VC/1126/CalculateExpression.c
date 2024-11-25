#include <stdio.h>
#include <string.h>

double sum = 0, product = 0, num=0;
char activeOperator = '\0', lastOperator = '\0';
int divisionError = 0, inputError=0;
char inputStr[100], trimedStr[100];

double getNumber();
char getOperator();
double calculatorKernel(double result, double num, char operatorChar);
void printResult();
void finalTerminate();
double getSum_lastOperator();
double getProduct_lastOperator();






double getNumber() {
    
    //double num;
    int i=0, dotCount=0, breakFlag=0;

    printf("Enter a floating number: ");
    while(1){
        scanf("%s", inputStr);
        for(i=0; inputStr[i]!= '\0'; i++) {
            if(inputStr[i] == '.') {dotCount++; continue;}
            if(!(inputStr[i]>='0' && inputStr[i]<='9'))  {breakFlag++; break;}
        }
        if(dotCount>1 || breakFlag>0) {printf("Invalid number, please enter again \n");  dotCount=0; breakFlag=0; continue;}
        if (sscanf(inputStr, "%lf", &num) == 1) {  break;} //printf("Converted number: %.5f\n", num);
    }
    return num;
}

char getOperator(){
    char operator='\0';
    int i=0, length=0;

    printf("Enter an operator: ");
    while(1){
        scanf("%s", inputStr);
        printf("\n");
        for(i=0; inputStr[i]!='\0'; i++) {
            if (inputStr[i] != ' ') trimedStr[length++]=inputStr[i];
        }
        if(length>1) {printf("Error!! more than one operator; please enter an operator ");  length=0; continue;}
        if(!(trimedStr[0] == '+' || trimedStr[0] == '-' || trimedStr[0] == '*' || trimedStr[0] == '/' || trimedStr[0] == '='))
            {printf("Invalid operator; please enter an operator ");  length=0; continue;}
        break;
    }


    return trimedStr[0];
}




double calculatorKernel(double result, double num, char operatorChar) {
    if (operatorChar == '\0') {
        result = num;
    } else {
        switch (operatorChar) {
            case '+':
            case '=':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '*':
                result *= num;
                break;
            case '/':
                if (num == 0) {
                    printf("Error: Division by zero\n");
                    divisionError = 1;
                    return 0;
                }
                result /= num;
                break;
            default:
                printf("Invalid operator\n");
        }
    }
    return result;
}

void printResult() {
    if (!divisionError) {
        printf("Terminated calculation.  sum = %.2f\n", sum);
    }
}

void finalTerminate() {
    switch (activeOperator) {
        case '\0':
        case '+':
        case '-':
            sum = product + calculatorKernel(sum, num, activeOperator);
            break;
        case '*':
            sum = sum + calculatorKernel(product, num, activeOperator);
            break;
        case '/':
            if (num == 0) {
                printf("divisor cannot be 0\n");
                divisionError = 1;
            } else {
                sum = sum + calculatorKernel(product, num, activeOperator);
            }
            break;
    }
    if (!divisionError) {
        printResult();
    } else {
        printf("Arithmetic expression gets wrong operator.\n");
    }
}

double getSum_lastOperator() {
    switch (activeOperator) {
        case '\0':
        case '+':
        case '-':
            sum = product + calculatorKernel(sum, num, activeOperator);
            break;
        case '*':
            sum = sum + calculatorKernel(product, num, activeOperator);
            break;
        case '/':
            if (num == 0) {
                printf("divisor cannot be 0\n");
                divisionError = 1;
            } else {
                sum = sum + calculatorKernel(product, num, activeOperator);
            }
            break;
    }
    product = 0;
    // printf("sum = %.2f    product = %.2f\n", sum, product);
    return sum;
}

double getProduct_lastOperator() {
    switch (activeOperator) {
        case '\0':
        case '+':
            product = num;
            break;
        case '-':
            product = -1 * num;
            break;
        case '*':
            product = calculatorKernel(product, num, activeOperator);
            break;
        case '/':
            if (num == 0) {
                printf("divisor cannot be 0\n");
                product = 0;
                divisionError = 1;
            } else {
                product = calculatorKernel(product, num, activeOperator);
            }
            break;
    }
    return product;
}

int main(){

        char expression[100];

	    while (1) {
		   	activeOperator=lastOperator;
	    	num=getNumber();
            strcat(expression, inputStr);
			lastOperator = getOperator();
			strcat(expression, trimedStr);

	        if(lastOperator == '=') {
                strcat(expression, ""); 
                printf("%s\n", expression); 
                finalTerminate(); 
                break;}
	        if(lastOperator == '+' || lastOperator == '-') sum=getSum_lastOperator();			// if last operator is '+' or '-'
	        if(lastOperator == '*' || lastOperator == '/') product=getProduct_lastOperator(); 	// if last operator is '*' or '/'

	        printf("expression = %s" , expression);
	        printf("\n");
	   } // end of while 	
    return 0;
}
