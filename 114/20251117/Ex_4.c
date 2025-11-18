#include <stdio.h>

int main() {
    int rows1, cols1, rows2, cols2;
    
    // Input dimensions for first matrix
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    // Input dimensions for second matrix
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Error: Matrix multiplication not possible!\n");
        printf("Columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }
    
    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];
    
    // Input first matrix
    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    // Input second matrix
    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Initialize result matrix to zero
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Multiply matrices using FOR loops
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Print first matrix
    printf("\nFirst Matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("%d\t", matrix1[i][j]);
        }
        printf("\n");
    }
    
    // Print second matrix
    printf("\nSecond Matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d\t", matrix2[i][j]);
        }
        printf("\n");
    }
    
    // Print result matrix
    printf("\nResultant Matrix:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}