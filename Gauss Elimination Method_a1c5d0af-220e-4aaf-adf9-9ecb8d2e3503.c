#include <stdio.h>
#include <math.h>

#define MAX 11

// Gauss Elimination method le solution nikalcha
void gaussElimination(float matrix[MAX][MAX], int n) {
    int i, j, k;
    float ratio;

    // Forward Elimination (paila matrix lai simplify garne)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            // Zero division check garne
            if (matrix[i][i] == 0) {
                printf("Error: Division by zero.\n");
                return;
            }
            ratio = matrix[j][i] / matrix[i][i];

            // Row update garne
            for (k = 0; k <= n; k++) {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }

    // Back Substitution (last bata solution nikalne)
    float solution[MAX];
    for (i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    // Solution print garne
    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }
}

int main() {
    int n, i, j;
    float matrix[MAX][MAX];

    // Equation ko number input garne
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    // Augmented matrix input garne
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Gauss Elimination method call garne
    gaussElimination(matrix, n);

    return 0;
}

