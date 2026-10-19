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
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
double determinant(int n, double matrix[n][n]) {
    if (n==1) {
        return matrix[0][0];
    }
    if (n==2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double sum = 0;
    for (int j = 0; j < n; j++) { // формування мінорів
        double al_major[n - 1][n - 1];
        int major_i = 0;
        for (int k = 1; k < n; k++) {
            int major_j = 0;
            for (int f = 0; f < n; f++) {
                if (f == j) {
                    continue;
                }
                al_major[major_i][major_j] = matrix[k][f];
                major_j++;
            }
            major_i++;
        }
        double sign=(j % 2 == 0) ? 1.0 : -1.0; // if j%2==0, sign=1, else sign=-1
        sum+=sign*matrix[0][j]*determinant(n - 1, al_major);
    }
    return sum;
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double matrix[n][n];
    printf("enter the n by n matrix: ");
    printf("\n");
    input_matrix(n, matrix);
    printf("your matrix is:\n");
    print_matrix(n, matrix);

    printf("\n");
    double det = determinant(n, matrix);
    printf("determinant is: %lf\n", det);
}