#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

MATRIX input_matrix(int n){
    MATRIX mat = (MATRIX)calloc(n, sizeof(mat[0]));
    if(mat == NULL){
        return NULL;
    }
    for(int i = 0; i < n; i++){
        mat[i] = (double*)malloc(n * sizeof(mat[i][0]));
        if(mat[i] == NULL){
            delete_matrix(mat, n);
            return NULL;
        }
        for(int j = 0; j < n; j++){
            scanf("%lf", &mat[i][j]);
        }
    }
    return mat;
}

MATRIX add_matrices(const MATRIX mat1, const MATRIX mat2, int n1, int n2){
    if(n1 != n2){
        return NULL;
    }

    MATRIX result = (MATRIX)calloc(n1, sizeof(result[0]));
    if(result == NULL){
        return NULL;
    }

    for(int i = 0; i < n1; i++){
        result[i] = (double*)malloc(n1 * sizeof(result[i][0]));
        if(result[i] == NULL){
            delete_matrix(result, n1);
            return NULL;
        }
        for(int j = 0; j < n1; j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

MATRIX multiply_matrices(const MATRIX mat1, const MATRIX mat2, int n1, int n2){
    if(n1 != n2){
        return NULL;
    }

    MATRIX result = (MATRIX)calloc(n1, sizeof(result[0]));
    if(result == NULL){
        return NULL;
    }

    for(int i = 0; i < n1; i++){
        result[i] = (double*)malloc(n1 * sizeof(result[i][0]));
        if(result[i] == NULL){
            delete_matrix(result, n1);
            return NULL;
        }
        for(int j = 0; j < n1; j++){
            result[i][j] = 0;
            for(int k = 0; k < n1; k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

void print_matrix(const MATRIX mat, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%lf ", mat[i][j]);
        }
        printf("\n");
    }
}

void delete_matrix(MATRIX mat, int n){
    if(mat == NULL){
        return;
    }
    for(int i = 0; i < n; i++){
        free(mat[i]);
    }
    free(mat);
}
