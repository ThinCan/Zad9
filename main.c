#include <stdio.h>
int main() {
    int i, j, k, n;
    float A[20][20], c, x[10], sum = 0.0;
    printf("\nEnter the order of matrix: ");
    scanf("%d", &n);
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= (n + 1); col++) {
            printf("A[%d][%d] : ", row, col);
            scanf("%f", &A[row][col]);
        }
    }
    for (int col = 1; col <= n; col++) /* loop for the generation of upper triangular matrix*/
    {
        for (int row = 1; row <= n; row++) {
            if (row > col) {
                c = A[row][col] / A[col][col];
                for (k = 1; k <= n + 1; k++) { A[row][k] = A[row][k] - c * A[col][k]; }
            }
        }
    }
    x[n] = A[n][n + 1] / A[n][n];
    /* this loop is for backward substitution*/
    for (int row = n - 1; row >= 1; row--) {
        sum = 0;
        for (int col = row + 1; col <= n; col++) { sum = sum + A[row][col] * x[col]; }
        x[row] = (A[row][n + 1] - sum) / A[row][row];
    }
    printf("\nThe solution is: \n");
    for (int row = 1; row <= n; row++) {
        printf("\nx%d=%f\t", row, x[row]); /* x1, x2, x3 are the required solutions*/
    }
    return (0);
}