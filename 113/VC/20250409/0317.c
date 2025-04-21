#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// 運算符號堆疊
char operatorStack[100];
int opTop = -1;

// 值堆疊
int valueStack[100];
int valTop = -1;

// 推導步驟紀錄
char steps[100][100];
int stepCount = 0;

void pushOperator(char op) {
    operatorStack[++opTop] = op;
}

char popOperator() {
    return operatorStack[opTop--];
}

void pushValue(int val) {
    valueStack[++valTop] = val;
}

int popValue() {
    return valueStack[valTop--];
}

void recordStep(char op, int a, int b, int result) {
    char buf[100];
    sprintf(buf, "(%c %c %c) → %c", a ? 'T' : 'F', op, b ? 'T' : 'F', result ? 'T' : 'F');
    strcpy(steps[stepCount++], buf);
}

void recordNotStep(char var, int val) {
    char buf[100];
    sprintf(buf, "(~%c) → %c", var, val ? 'T' : 'F');
    strcpy(steps[stepCount++], buf);
}

int applyOperator(char op, int a, int b) {
    int result = 0;
    if (op == 'A') result = a && b;
    else if (op == 'V') result = a || b;
    else if (op == '>') result = !a || b;
    else if (op == '<') result = (a == b);
    recordStep(op, a, b, result);
    return result;
}

int evaluateExpression(char expr[], int p, int q) {
    opTop = valTop = -1;
    stepCount = 0;
    int i;
    for (i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == 'p') pushValue(p);
        else if (ch == 'q') pushValue(q);
        else if (ch == '~') {
            i++;
            int val = (expr[i] == 'p') ? p : q;
            int result = !val;
            recordNotStep(expr[i], result);
            pushValue(result);
        }
        else if (ch == '(') pushOperator(ch);
        else if (ch == ')') {
            while (opTop >= 0 && operatorStack[opTop] != '(') {
                char op = popOperator();
                int b = popValue();
                int a = popValue();
                pushValue(applyOperator(op, a, b));
            }
            popOperator();
        }
        else if (ch == 'A' || ch == 'V') {
            while (opTop >= 0 && operatorStack[opTop] != '(') {
                char prevOp = operatorStack[opTop];
                if ((ch == 'V' && (prevOp == 'A' || prevOp == '>')) ||
                    (ch == 'A' && prevOp == 'A')) {
                    char op = popOperator();
                    int b = popValue();
                    int a = popValue();
                    pushValue(applyOperator(op, a, b));
                } else break;
            }
            pushOperator(ch);
        }
        else if (ch == '>') pushOperator('>');
        else if (ch == '<' && i + 1 < strlen(expr) && expr[i + 1] == '>') {
            pushOperator('<');
            i++;
        }
    }

    while (opTop >= 0) {
        char op = popOperator();
        int b = popValue();
        int a = popValue();
        pushValue(applyOperator(op, a, b));
    }

    return popValue();
}

int evaluateSubExpr(char expr[], char sub[], int p, int q) {
    char* found = strstr(expr, sub);
    if (!found) return -1;
    return evaluateExpression(sub, p, q);
}

int main() {
    char expression[100];
    int p, q;
    int results[4];
    int i = 0;
    int j, a, b;
    printf("請輸入邏輯表達式 (使用 'p', 'q', 'A', 'V', '>', '<>', '~', '()'):\n");
    scanf("%s", expression);

    printf("\n真值表 for: %s\n", expression);
    printf("p | q | %s\n", expression);
    printf("-------------------------\n");

    for (p = 1; p >= 0; p--) {
        for (q = 1; q >= 0; q--) {
            results[i] = evaluateExpression(expression, p, q);
            printf("%c | %c |   %c\n", p ? 'T' : 'F', q ? 'T' : 'F', results[i] ? 'T' : 'F');
            i++;
        }
    }

    int isTautology = 1, isContradiction = 1;
    for (i = 0; i < 4; i++) {
        if (results[i] == 0) isTautology = 0;
        if (results[i] == 1) isContradiction = 0;
    }

    if (isTautology)
        printf("\n這是一個恆真題 (Tautology)\n");
    else if (isContradiction)
        printf("\n這是一個矛盾題 (Contradiction)\n");
    else
        printf("\n這是一個偶然題 (Contingency)\n");

    // === 改版互動模式開始 ===
    while (1) {
        char inputP[10], inputQ[10];

        printf("\n[互動模式] 請先輸入 p (T/F)：");
        scanf("%s", inputP);
        printf("請輸入 q (T/F)：");
        scanf("%s", inputQ);
        p = (inputP[0] == 'T' || inputP[0] == 't');
        q = (inputQ[0] == 'T' || inputQ[0] == 't');

        int mainResult = evaluateExpression(expression, p, q);
        printf("主表達式結果：%c\n", mainResult ? 'T' : 'F');

        while (1) {
            printf("\n[互動選單] p = %c, q = %c\n", p ? 'T' : 'F', q ? 'T' : 'F');
            printf("1. 查看子表達式結果\n");
            printf("2. 顯示當前組合的推導步驟\n");
            printf("3. 顯示所有組合的推導步驟\n");
            printf("4. 重新輸入 p/q 值\n");
            printf("5. 離開互動模式\n");
            printf("請輸入選項：");

            char choice[10];
            scanf("%s", choice);

            if (strcmp(choice, "1") == 0) {
                char subExpr[100];
                printf("輸入子表達式（或輸入 exit 返回）：");
                scanf("%s", subExpr);
                if (strcmp(subExpr, "exit") == 0) continue;
                int subResult = evaluateSubExpr(expression, subExpr, p, q);
                if (subResult == -1)
                    printf("子表達式 \"%s\" 不存在。\n", subExpr);
                else
                    printf("子表達式 \"%s\" 的結果為：%c\n", subExpr, subResult ? 'T' : 'F');
            }
            else if (strcmp(choice, "2") == 0) {
                printf("\n=== 推導步驟 for p = %c, q = %c ===\n", p ? 'T' : 'F', q ? 'T' : 'F');
                evaluateExpression(expression, p, q);
                for ( j = 0; j < stepCount; j++) {
                    printf("%d. %s\n", j + 1, steps[j]);
                }
            }
            else if (strcmp(choice, "3") == 0) {
                printf("\n=== 所有組合推導步驟 ===\n");
                for ( a = 1; a >= 0; a--) {
                    for ( b = 1; b >= 0; b--) {
                        printf("\n[p = %c, q = %c]\n", a ? 'T' : 'F', b ? 'T' : 'F');
                        evaluateExpression(expression, a, b);
                        for ( j = 0; j < stepCount; j++) {
                            printf("%d. %s\n", j + 1, steps[j]);
                        }
                    }
                }
            }
            else if (strcmp(choice, "4") == 0) {
                break; // 回到 p/q 輸入
            }
            else if (strcmp(choice, "5") == 0 || strcmp(choice, "exit") == 0) {
                printf("已退出互動模式。\n");
                exit(0);
            }
            else {
                printf("無效選項，請重新輸入。\n");
            }
        }
    }

    return 0;
}

