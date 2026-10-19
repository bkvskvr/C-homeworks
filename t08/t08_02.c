#include <stdio.h>
#define N 3
#define M 3

void input_matrix(double matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}
void print_matrix(double matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
int swap_number(double matrix[N][M], int i, int j, double a) {
    int change_done=0;
    matrix[i][j] = a;
    change_done=1;
    return change_done;
}
int main() {
    double matrix[N][M];
    int n, m;
    double a;
    printf("enter the N by M matrix: ");
    input_matrix(matrix);

    printf("enter the numbers n and m: ");
    scanf("%d %d", &n, &m);

    printf("enter the number a: ");
    scanf("%d %d", &n, &m);

    swap_number(matrix, n, m, a);
    printf("matrix with swapped elements: \n");
    print_matrix(matrix);
}