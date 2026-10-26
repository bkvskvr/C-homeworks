#include <stdio.h>
#include "matrix.h"

int main(){
    int n;
    scanf("%d", &n);

    MATRIX mat1 = input_matrix(n);
    if(mat1 == NULL){
        return 1;
    }

    MATRIX mat2 = input_matrix(n);
    if(mat2 == NULL){
        delete_matrix(mat1, n);
        return 1;
    }

    MATRIX sum = add_matrices(mat1, mat2, n, n);
    MATRIX product = multiply_matrices(mat1, mat2, n, n);

    print_matrix(sum, n);
    print_matrix(product, n);

    delete_matrix(mat1, n);
    delete_matrix(mat2, n);
    delete_matrix(sum, n);
    delete_matrix(product, n);

    return 0;
}
