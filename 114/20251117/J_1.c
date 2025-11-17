#include <stdio.h> 
 
int main() { 
    int number;      // 整數變數 
    char letter;     // 字元變數   
    float price;     // 小數變數（單精度） 
    double score;    // 小數變數（雙精度） 
 
    // 輸入資料 
    printf("請輸入整數: "); 
    scanf("%d", &number); 
     
    printf("請輸入字元: "); 
    scanf(" %c", &letter); 
     
    printf("請輸入小數: "); 
    scanf("%f", &price); 
     
    printf("請輸入更精確的小數: "); 
    scanf("%lf", &score); 
 
    // 輸出結果 
    printf("\n顯示結果:\n"); 
printf("整數: %d\n", number); 
printf("字元: %c\n", letter); 
printf("小數: %.2f\n", price); 
printf("精確小數: %.2lf\n", score); 
return 0; 
}