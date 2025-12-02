#include <stdio.h>
#include <string.h> //includes string handling functions, ex strcmp
#include <ctype.h> //includes character classification helpers, ex isdigit
 
char *p; //p as char points to string, tracks CURRENT character
double add_sub(); //double to declare/support decimal points, more accurate than float
double mult_div();
double num_par();
//above declared in global
 
 
//calls functions in correct arithmetic order-> add_sub calls mult_div first which calls num_par first
//breaks the arithmetic into chunks
double add_sub() {
    double result = mult_div();
    while (*p == '+' || *p == '-') {//loop as long as the current character is + or -
        char op = *p++;//read *p as op, then ++ point to next in line
        double t = mult_div();
        if (op == '+') result += t;
        else result -= t;
    }
    return result;
}
 
double mult_div() {
    double result = num_par();
    while (*p == '*' || *p == '/') {
        char op = *p++;
        double f = num_par();
        if (op == '*') result *= f;
        else result /= f;
    }
    return result;
}
 
//handles parsing of the equation
double num_par() {
    double result = 0.0; //set fresh numeric value
 
    if (*p == '(') {
        p++;//skip ( to next
        result = add_sub();//loop back to start
        p++;//skip ) -> no error check! assumes ) exists
    } else {
        double sign = 1.0;//default positive
        if (*p == '-') { sign = -1; p++; }//handles whether number is positive or negative
        else if (*p == '+') { p++; }
 
        while (isdigit(*p)) {//parse interger portion digit by digit to create value, isdigit checks if 0-9
            result = result * 10 + (*p - '0');//converts ascii digit to numeric due to how numb and char are stored in c
            p++;
        }
 
        if (*p == '.') {
            p++;//skip decimal .
            double place = 0.1;
            while (isdigit(*p)) {
                result += (*p - '0') * place;//add decimal digits
                place *= 0.1;//parse decimal digits
                p++;
            }
        }
 
        result *= sign;//assign postive/negative
    }
    return result;
}
 
//main code, interface with user and calls defined functions
int main() {
    char input[200];//limit character count
    while (2) {//(2)forever loop(can be any number) broken by if function conditions
        printf("Enter arithmetics (or type 'exit'): ");
        scanf("%199s", input);//reads whitespace into input,%199s limits characters to 199//plus \0 terminate->can't read spaces
 
        if (strcmp(input, "exit") == 0)//strcmp=string compare following(a,b); 0 if equal, < if first string alphabetically less
            break;//break while loop
           
        p = input;//set global pointer to start of input string
        double ans = add_sub();//starts arithmetic function chain
        printf("Result = %lf\n", ans);//%lf prints decimals to 6 places(format specifier like %d,%s)
    }
    return 0;
}
 
