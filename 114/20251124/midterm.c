#include <stdio.h>​
​int main() {​
    // 第一步：宣告四個基本資料型別的變數​
    int integer_var;​
    char char_var;​
    float float_var;​
    double double_var;​
    ​
    // 第二步：讀取變數值​
    printf("請輸入一個整數: ");​
    scanf("%d", &integer_var);​
    ​
    printf("請輸入一個字元: ");​
    scanf(" %c", &char_var);  ​
    printf("請輸入一個浮點數: ");​
    scanf("%f", &float_var);​
    ​
    printf("請輸入一個雙精度浮點數: ");​
    scanf("%lf", &double_var);​
    // 第三步：印出變數值（格式輸出）​
    printf("\n=== 變數值輸出 ===\n");​
    printf("整數 (int):    %d\n", integer_var);​
    printf("字元 (char):   %c\n", char_var);​
    printf("浮點數 (float):  %.2f\n", float_var);​
    printf("雙精度浮點數 (double): %.5lf\n", double_var);
    // 第四步：記憶體空間圖像（ASCII藝術）​
    printf("\n=== 記憶體空間配置圖 ===\n");​
    printf("┌──────────────────────────────────────────────┐\n");​
    printf("│               記憶體位址空間                 │\n");​
    printf("├──────────────────────────────────────────────┤\n");​
    printf("│ 高位址 → ┌──────────────────────────────┐   │\n");​
    printf("│          │ ███ double_var (8 bytes) ███ │   │\n");​
    printf("│          │ 值: %-20.5lf     │   │\n", double_var);​
    printf("│          │ 位址: %-18p │   │\n", (void*)&double_var);​
    printf("│          ├──────────────────────────────┤   │\n");​
    printf("│          │ ███ float_var  (4 bytes) ███ │   │\n");​
    printf("│          │ 值: %-20.2f     │   │\n", float_var);​
    printf("│          │ 位址: %-18p │   │\n", (void*)&float_var);​
    printf("│          ├──────────────────────────────┤   │\n");​
    printf("│          │ ███ char_var   (1 byte)  ███ │   │\n");​
    printf("│          │ 值: '%c'                      │   │\n", char_var);​
    printf("│          │ 位址: %-18p │   │\n", (void*)&char_var);​
    printf("│          ├──────────────────────────────┤   │\n");​
    printf("│          │ ███ integer_var(4 bytes) ███ │   │\n");​
    printf("│          │ 值: %-20d     │   │\n", integer_var);​
    printf("│          │ 位址: %-18p │   │\n", (void*)&integer_var);​
    printf("│ 低位址 → └──────────────────────────────┘   │\n");​
    printf("└──────────────────────────────────────────────┘\n");​
    ​ // 記憶體大小資訊​
    printf("\n=== 記憶體大小資訊 ===\n");​
    printf("整數 (int) 大小:    %zu bytes\n", sizeof(integer_var));​
    printf("字元 (char) 大小:   %zu byte\n", sizeof(char_var));​
    printf("浮點數 (float) 大小: %zu bytes\n", sizeof(float_var));​
    printf("雙精度 (double) 大小: %zu bytes\n", sizeof(double_var));​
    printf("總記憶體使用: %zu bytes\n", ​
           sizeof(integer_var) + sizeof(char_var) + sizeof(float_var) + sizeof(double_var));​
    ​
    return 0;​
}​
