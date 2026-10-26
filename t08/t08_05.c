#include <stdio.h>

void input_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}
void print_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
void transpose_matrix(int n, double matrix[n][n]) { // 1 method
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
void transpose_matrix_out(int n, const double matrix[n][n], double result[n][n]) { // 2 method
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double matrix[n][n];
    double result[n][n];
    printf("enter the n by n matrix: ");
    printf("\n");
    input_matrix(n, matrix);
    printf("your matrix is:\n");
    print_matrix(n, matrix);

    transpose_matrix(n, matrix);
    printf("method 1 result:\n");
    print_matrix(n, matrix);
    transpose_matrix_out(n, matrix,  result);
    printf("method 2 result:\n");
    print_matrix(n, result);
}