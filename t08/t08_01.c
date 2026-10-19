#include <stdio.h>
#define N 3
#define M 3

void input_matrix(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void print_matrix(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int swap_number(int matrix[N][M], int n, int m) {
    int change_done=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == n) {
                matrix[i][j] = m;
                change_done = 1;
            }
        }
    }
    return change_done;
}
int main() {
    int matrix[N][M];
    int n, m;
    printf("enter the N by M matrix: ");
    input_matrix(matrix);
    printf("enter the numbers n and m: ");
    scanf("%d %d", &n, &m);
    swap_number(matrix, n, m);
    printf("matrix with swapped elements: \n");
    print_matrix(matrix);
}