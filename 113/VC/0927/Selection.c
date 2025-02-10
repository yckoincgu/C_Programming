#include <stdio.h>

void EX01();
void EX02();         // function prototype

void EX01()         // function definition   
{
    printf("Hello World\n");
}

void EX02()
{
    int number1, number2, sum;
    
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    // calculate the sum
    sum = number1 + number2;      
    
    printf("%d + %d = %d\n", number1, number2, sum);
}
int main() {

  int op;
  printf("Enter your choice (1, 2, 3, .....): ");
  scanf("%d", &op);

  if (op == 1) { EX01();}
  else if (op==2) {EX02();}
  else printf("others ...");
  
  return 0;
}
