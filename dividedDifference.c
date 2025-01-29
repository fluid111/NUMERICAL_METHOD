#include <stdio.h>

int main() {
    float x[100], y[100], dt[100][100];
    int n, i, j;

    // Input the order of the matrix
    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter the value of x & y``:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
        dt[i][0] = y[i]; // Initialize the first column of the table
    }

    // Compute the divided difference table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            dt[i][j] = (dt[i + 1][j - 1] - dt[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Print the divided difference table
    printf("\nThe divided difference table is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("%.2f\t", dt[i][j]); // Use %.2f for float values
        }
        printf("\n");
    }

    printf("AASHISH THAPA MAGAR\n");
    return 0;
}
