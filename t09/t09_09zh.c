#include <stdio.h>
#include <stdlib.h>

double** input_matrix(int n, int m){
    double** mat = (double**)malloc(n * sizeof(double*));
    if(mat == NULL) return NULL;

    for(int i = 0; i < n; i++){
        mat[i] = (double*)malloc(m * sizeof(double));
        if(mat[i] == NULL){
            for(int j = 0; j < i; j++) free(mat[j]);
            free(mat);
            return NULL;
        }
        for(int j = 0; j < m; j++){
            scanf("%lf", &mat[i][j]);
        }
    }
    return mat;
}

void print_matrix(double** mat, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
}

void delete_matrix(double** mat, int n){
    if(mat == NULL) return;
    for(int i = 0; i < n; i++) free(mat[i]);
    free(mat);
}

double** add_columns(double** mat, int n, int m, int k){
    double** result = (double**)malloc(n * sizeof(double*));
    if(result == NULL) return NULL;

    for(int i = 0; i < n; i++){
        result[i] = (double*)malloc((m + k) * sizeof(double));
        if(result[i] == NULL){
            delete_matrix(result, i);
            return NULL;
        }
        for(int j = 0; j < m; j++)
            result[i][j] = mat[i][j];

        for(int j = m; j < m + k; j++){
            printf("Enter new element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &result[i][j]);
        }
    }
    return result;
}

int main(){
    int n, m, k;
    printf("Enter n and m: ");
    scanf("%d%d", &n, &m);
    if(n <= 0 || m <= 0) return 1;

    double** mat = input_matrix(n, m);
    if(mat == NULL) return 1;

    printf("Enter k: ");
    scanf("%d", &k);
    if(k < 0){
        delete_matrix(mat, n);
        return 1;
    }

    double** result = add_columns(mat, n, m, k);
    if(result == NULL){
        delete_matrix(mat, n);
        return 1;
    }

    print_matrix(result, n, m + k);

    delete_matrix(mat, n);
    delete_matrix(result, n);
    return 0;
}
