#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    int mat1[r1][c1], mat2[r2][c2], result[r1][c2];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Resultant Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//      +----------------------------+
//      |           Start            |
//      +----------------------------+
//                 |
//                 v
//      +----------------------------+
//      | Input r1, c1 (matrix1 size)|
//      | Input r2, c2 (matrix2 size)|
//      +----------------------------+
//                 |
//                 v
//      +----------------------------+
//      | Check if c1 == r2 ?       |
//      +----------------------------+
//        |          |
//       Yes         No
//        |          |
//        v          Break
//  +----------------------------+
//  | Input elements of matrix1  |
//  +----------------------------+
//        |
//        v
//  +----------------------------+
//  | Input elements of matrix2  |
//  +----------------------------+
//        |
//        v
//  +----------------------------+
//  | Initialize result[][] = 0  |
//  +----------------------------+
//        |
//        v
//  +----------------------------+
//  | i = 0 to r1-1              |
//  |   j = 0 to c2-1            |
//  |      k = 0 to c1-1         |
//  |         result[i][j] +=    |
//  |         mat1[i][k]*mat2[k][j] |
//  +----------------------------+
//        |
//        v
//  +----------------------------+
//  | Print result matrix        |
//  +----------------------------+
//        |
//        v
//      +----------------------------+
//      |           End              |
//      +----------------------------+