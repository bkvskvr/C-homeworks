#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "vector.h"

int main(){

    int n;
    printf("Enter the size of the vectors: ");
    scanf("%d", &n);

    double *vect1 = input_vector(n);
    if(vect1 == NULL){
        printf("Failed to allocate memory for vect1\n");
        return 1;
    }

    double *vect2 = input_vector(n);
    if(vect2 == NULL){
        printf("Failed to allocate memory for vect2\n");
        delete_vector(vect1);
        return 1;
    }

    double *vect_sum = add_vectors(vect1, vect2, n);

    print_vector(vect_sum, n);

    delete_vector(vect1);
    delete_vector(vect2);
    delete_vector(vect_sum);
}
