#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE_TASK5 50


int input_array(double array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("v[%d]= ", i + 1);
        int result_input = scanf("%lf", &array[i]);
        if (result_input != 1) {
            printf("Invalid input\n");
            return i;
        }
    }
    return size;
}

void print_array(double array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        printf("%g, ", array[i]);
    }
    if (size > 0) {
        printf("%g\n", array[size - 1]);
    }
}

int add_vectors(const double vector1[], const double vector2[], double result[], int dim) {
    for (int i = 0; i < dim; i++) {
        result[i] = vector1[i] + vector2[i];
    }
    return dim;
}

double dot_product(const double vector1[], const double vector2[], int dim) {
    double product = 0;
    for (int i = 0; i < dim; i++) {
        product += vector1[i] * vector2[i];
    }
    return product;
}

void task6() {
    int dim;
    printf("Enter the dimension of the vector: ");
    scanf("%d", &dim);

    double vector1[dim];
    double vector2[dim];
    double vector_sum[dim];

    int d1 = input_array(vector1, dim);
    int d2 = input_array(vector2, dim);
    if (d1 != dim || d2 != dim) {
        printf("Error: Dimension mismatch\n");
        return;
    }

    add_vectors(vector1, vector2, vector_sum, dim);
    double dot_prod = dot_product(vector1, vector2, dim);

    printf("Vector sum:\n");
    print_array(vector_sum, dim);
    printf("Dot product: %g\n", dot_prod);
}

int main() {
    task6();
    return 0;
}
