// Implement sparse matrices using arrays
#include <stdio.h>
#include <stdlib.h>
struct SparseMatrix {
    int row, col, value;
};
struct SparseMatrix matrix[100];

void createSparseMatrix(int mat[][100], int row, int col) {
    int k = 1, i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (mat[i][j] != 0) {
                matrix[k].row = i;
                matrix[k].col = j;
                matrix[k].value = mat[i][j];
                k++;
            }
        }
    }
    matrix[0].row = row;
    matrix[0].col = col;
    matrix[0].value = k - 1;
}
void displaySparseMatrix(int mat[][100], int row, int col) {
    int i, j;
    printf("\nSparse Matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
void displayCompactSparseMatrix(int mat[][100], int row, int col) {
    int i, j, k = 1;
    printf("\nCompact Sparse Matrix:\n");
    printf("\t%d\t%d\t%d\n", matrix[0].row, matrix[0].col, matrix[0].value);

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (mat[i][j] != 0) {
                printf("\t%d\t%d\t%d\n", matrix[k].row, matrix[k].col, matrix[k].value);
                k++;
            }
        }
    }
}
int main() {
    int mat[100][100], row, col, i, j;
    printf("Enter number of rows and columns:\n");
    scanf("%d%d", &row, &col);
    printf("Enter elements of matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    createSparseMatrix(mat, row, col);
    displaySparseMatrix(mat, row, col);
    displayCompactSparseMatrix(mat, row, col);
    return 0;
}
/*Sparse Matrix Using Arrays Algorithm:
1. Create a class SparseMatrix that contains three arrays, data, row, and col, to store the non-zero elements of the matrix, their row indices, and column indices, respectively.
2. Initialize the data, row, and col arrays with the non-zero elements and their indices.
3. Implement the following operations:
    • Display:
        * Print the matrix by iterating over the data, row, and col arrays and printing the elements in the corresponding row and column.
    • Transpose:
        * Create a new SparseMatrix object and initialize its data, row, and col arrays with zeros.
        * For each non-zero element in the original matrix, insert it into the corresponding position in the transposed matrix with the row and column indices swapped.
*/