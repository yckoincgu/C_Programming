#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// �B��Ÿ����|
char operatorStack[100];
int opTop = -1;

// �Ȱ��|
int valueStack[100];
int valTop = -1;

// ���ɨB�J����
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
    sprintf(buf, "(%c %c %c) �� %c", a ? 'T' : 'F', op, b ? 'T' : 'F', result ? 'T' : 'F');
    strcpy(steps[stepCount++], buf);
}

void recordNotStep(char var, int val) {
    char buf[100];
    sprintf(buf, "(~%c) �� %c", var, val ? 'T' : 'F');
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
    printf("�п�J�޿��F�� (�ϥ� 'p', 'q', 'A', 'V', '>', '<>', '~', '()'):\n");
    scanf("%s", expression);

    printf("\n�u�Ȫ� for: %s\n", expression);
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
        printf("\n�o�O�@�ӫ�u�D (Tautology)\n");
    else if (isContradiction)
        printf("\n�o�O�@�ӥ٬��D (Contradiction)\n");
    else
        printf("\n�o�O�@�Ӱ��M�D (Contingency)\n");

    // === �睊���ʼҦ��}�l ===
    while (1) {
        char inputP[10], inputQ[10];

        printf("\n[���ʼҦ�] �Х���J p (T/F)�G");
        scanf("%s", inputP);
        printf("�п�J q (T/F)�G");
        scanf("%s", inputQ);
        p = (inputP[0] == 'T' || inputP[0] == 't');
        q = (inputQ[0] == 'T' || inputQ[0] == 't');

        int mainResult = evaluateExpression(expression, p, q);
        printf("�D��F�����G�G%c\n", mainResult ? 'T' : 'F');

        while (1) {
            printf("\n[���ʿ��] p = %c, q = %c\n", p ? 'T' : 'F', q ? 'T' : 'F');
            printf("1. �d�ݤl��F�����G\n");
            printf("2. ��ܷ�e�զX�����ɨB�J\n");
            printf("3. ��ܩҦ��զX�����ɨB�J\n");
            printf("4. ���s��J p/q ��\n");
            printf("5. ���}���ʼҦ�\n");
            printf("�п�J�ﶵ�G");

            char choice[10];
            scanf("%s", choice);

            if (strcmp(choice, "1") == 0) {
                char subExpr[100];
                printf("��J�l��F���]�ο�J exit ��^�^�G");
                scanf("%s", subExpr);
                if (strcmp(subExpr, "exit") == 0) continue;
                int subResult = evaluateSubExpr(expression, subExpr, p, q);
                if (subResult == -1)
                    printf("�l��F�� \"%s\" ���s�b�C\n", subExpr);
                else
                    printf("�l��F�� \"%s\" �����G���G%c\n", subExpr, subResult ? 'T' : 'F');
            }
            else if (strcmp(choice, "2") == 0) {
                printf("\n=== ���ɨB�J for p = %c, q = %c ===\n", p ? 'T' : 'F', q ? 'T' : 'F');
                evaluateExpression(expression, p, q);
                for ( j = 0; j < stepCount; j++) {
                    printf("%d. %s\n", j + 1, steps[j]);
                }
            }
            else if (strcmp(choice, "3") == 0) {
                printf("\n=== �Ҧ��զX���ɨB�J ===\n");
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
                break; // �^�� p/q ��J
            }
            else if (strcmp(choice, "5") == 0 || strcmp(choice, "exit") == 0) {
                printf("�w�h�X���ʼҦ��C\n");
                exit(0);
            }
            else {
                printf("�L�Ŀﶵ�A�Э��s��J�C\n");
            }
        }
    }

    return 0;
}

