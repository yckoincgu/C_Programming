#include <stdio.h>
int a;
char b;
float c;
double d;


int main(){


printf("Pleace input :/n one integer/n one character/n one float/n one double , on your keyboard\n");
    scanf("%d \n %c \n %f \n %lf \n" ,&a,&b,&c,&d);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Discard the character
    }

    printf("\n %d, %c, %.2f, %.2lf \n" ,a,b,c,d);
return 0 ;

}
