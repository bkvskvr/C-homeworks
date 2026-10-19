#include <stdio.h>
#include <stdlib.h>

double* input_vector(int n){
    double* vect = (double*)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i);
        scanf("%lf", &vect[i]);
    }
    return vect;
}

double* add_vectors(const double* vect1, const double* vect2, int n){
    double* vect_sum = (double*)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        vect_sum[i] = vect1[i] + vect2[i];
    }
    return vect_sum;
}

void print_vector(const double* vect, int n){
    for(int i = 0; i < n; i++){
        printf("%lf ", vect[i]);
    }
    printf("\n");
}

void delete_vector(double* vect){
    free(vect);
}
