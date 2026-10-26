#include <stdio.h>
#define NMAX 25
#define MMAX 25

void input_matrix(int n, int m, double matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        printf("enter elements of the matrix row %d: ", i+1);
        for (int j = 0; j < m; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}
void print_matrix(int n, int m, double matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, m;
    do {
        printf("enter the numbers n and m less then 25: ");
        scanf("%d %d", &n, &m);
    } while (n>=NMAX && m>=MMAX);
    double matrix[n][m];
    printf("enter the N by M matrix: ");
    printf("\n");
    input_matrix(n, m, matrix);
    printf("your matrix is:\n");
    print_matrix(n, m, matrix);
}