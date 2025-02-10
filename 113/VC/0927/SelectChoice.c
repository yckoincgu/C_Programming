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

  switch (op) {
    case 1:
      EX01();
      break;
    case 2:
      EX02();
      break;
    case 3:
      printf("case 3");
      break;
    case 4:
      printf("case 5");
      break;
    // operator doesn't match any case constant
    default:
      printf("others ...");

  }
  printf("\n");
    return 0;
}
