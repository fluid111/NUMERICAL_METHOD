#include <stdio.h>
#define MAX 9

void gaussJordan(float matrix[MAX][MAX], int n) {
    int i, j, k;
    float ratio;
    // Forward Elimination and Diagonalize garne
    for (i = 0; i < n; i++) {
        // Pivot element check garne (division by zero ko lagi)
        if (matrix[i][i] == 0) {
            printf("Error: Division by zero.\n");
            return;
        }
        // Row normalize garne
        float pivot = matrix[i][i];
        for (j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }
        // Baaki row adjust garne
        for (j = 0; j < n; j++) {
            if (j != i) {
                ratio = matrix[j][i];
                for (k = 0; k <= n; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }
}

int main() {
    int n, i, j;
    float matrix[MAX][MAX];
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
    gaussJordan(matrix, n);
    return 0;
}

