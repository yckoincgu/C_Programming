#include <stdio.h>

int main() {
    // 宣告兩個變數來儲存使用者的輸入
    double num1, num2;
    char choice;

    // 提示使用者輸入兩個數字
    printf("請輸入第一個數字: ");
    scanf("%lf", &num1);  // 使用 %lf 讀取浮點數
    
    printf("請輸入第二個數字: ");
    scanf("%lf", &num2);  // 使用 %lf 讀取浮點數
    
    // 清理緩衝區，丟掉換行符
    getchar();  // 清除前次輸入中的換行符

    // 顯示選項，讓使用者選擇運算
    printf("\n請選擇你要進行的運算:\n");
    printf("+. 加法 (+)\n");
    printf("-. 減法 (-)\n");
    printf("*. 乘法 (*)\n");
    printf("/. 除法 (/)\n");

    // 讀取使用者的選擇
    printf("請輸入選項 (+,-,*,/): ");
    scanf("%c", &choice); // 使用 %c 讀取選擇的運算符

    // 根據使用者的選擇執行相應的運算
    switch (choice) {
        case '+':  // 加法
            printf("結果: %.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
            break;
        case '-':  // 減法
            printf("結果: %.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
            break;
        case '*':  // 乘法
            printf("結果: %.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
            break;
        case '/':  // 除法
            if (num2 != 0) {
                printf("結果: %.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            } else {
                printf("錯誤: 除數不能為零。\n");
            }
            break;        

        default:
            printf("錯誤: 無效選擇! 請選擇選項(+,-,*,/)。\n");
            break;
    }

    return 0;
}
