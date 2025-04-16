#include <stdio.h>
#include <stdlib.h>

// (A) 定義 getStr 函數，返回一個字串指標
char* getStr()
{
    char *s = NULL;             // 動態分配字串空間
    size_t bufferSize = 0;      // 初始化緩衝區大小為 0

    // 提示使用者輸入
    printf("Enter a string like hello world:  ");
    
    // 讀取整行輸入，getline 會自動調整緩衝區大小
    getline(&s, &bufferSize, stdin);
    
    return s;  // 返回字串指標
}

int main()
{
    char *inputString;  // (B) 宣告指向字串的指標

    // (C) 呼叫 getStr 來取得字串
    inputString = getStr();

    // (D) 輸出結果並加換行
    printf("The getline function succeeded in reading the input\n");
    printf("The getStr function : \"%s\"\n", inputString);

    // 釋放動態分配的記憶體
    free(inputString);

    return 0;
}
