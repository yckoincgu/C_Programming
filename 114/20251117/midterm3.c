#include <stdio.h>
#include <math.h>

int main() {
    int num, temp, digit, sum = 0;

    printf("Enter a 5-digit integer: ");
    scanf("%d", &num);

    temp = num;
  
    while (temp != 0) {
        digit = temp % 10;          
        sum += pow(digit, 5);       
        temp /= 10;                 
    }

    if (sum == num) {
        printf("%d is a 5-digit Armstrong number.\n", num);
    } else {
        printf("%d is NOT a 5-digit Armstrong number.\n", num);
    }

    return 0;
}
//      +-----------------+
//      |      Start      |
//      +-----------------+
//              |
//              v
//      +-----------------------------+
//      | Prompt: "Enter 5-digit int" |
//      +-----------------------------+
//              |
//              v
//      +-----------------+
//      | Read num        |
//      | temp = num      |
//      | sum = 0         |
//      +-----------------+
//              |
//              v
//      +-----------------+
//      | temp != 0 ?     |
//      +-----------------+
//        |         |
//       Yes        No
//        |         |
//        v         v
//  +-------------------+
//  | digit = temp % 10 |
//  | sum += digit^5    |
//  | temp /= 10        |
//  +-------------------+
//        |
//        +---------------------+
//        |                     |
//        +-------> (back to temp != 0?)
//              |
//              v
//      +-----------------+
//      | sum == num ?    |
//      +-----------------+
//        |         |
//       Yes        No
//        |         |
//        v         v
// +------------------------+
// | Print: "Armstrong"     |
// +------------------------+
//        |         
//        v         
// +------------------------+
// | Print: "NOT Armstrong" |
// +------------------------+
//        |
//        v
//      +-----------------+
//      |       End       |
//      +-----------------+