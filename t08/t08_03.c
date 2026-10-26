#include <stdio.h>
#define NMAX 20
#define MMAX 20

void input_matrix(int n, int m, double matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("enter element of matrix[%d][%d]: ", i+1, j+1);
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
        printf("enter the numbers n and m less then 20: ");
        scanf("%d %d", &n, &m);
    } while (n>=NMAX && m>=MMAX);
    double matrix[n][m];
    printf("enter the N by M matrix: ");
    input_matrix(n, m, matrix);
    printf("your matrix is:\n");
    print_matrix(n, m, matrix);
}