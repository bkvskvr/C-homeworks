#ifndef MATRIX_H
#define MATRIX_H

typedef double** MATRIX;

MATRIX input_matrix(int n);
MATRIX add_matrices(const MATRIX mat1, const MATRIX mat2, int n1, int n2);
MATRIX multiply_matrices(const MATRIX mat1, const MATRIX mat2, int n1, int n2);
void print_matrix(const MATRIX mat, int n);
void delete_matrix(MATRIX mat, int n);

#endif // MATRIX_H
