#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE_TASK3 10
#define EULER_E 2.718281828459045

int input_array(double array[], int size){
    for(int i = 0; i < size; i++){
        printf("a[%d]= ", i + 1);
        int result_input = scanf("%lf", &array[i]);
        if(result_input != 1){
            printf("Invalid input\n");
            return i;
        }
    }
    return size;
}

void print_array(double array[], int size){
    for(int i = 0; i < size - 1; i++){
        printf("%e, ", array[i]);
    }
    printf("%e\n", array[size - 1]);
}

double sum_greater_than_e(double array[], int size){
    double sum = 0.0;
    for(int i = 0; i < size; i++){
        if(array[i] > EULER_E){
            sum += array[i];
        }
    }
    return sum;
}

int main(){
    double array[ARRAY_SIZE_TASK3];
    int array_size = input_array(array, ARRAY_SIZE_TASK3);

    printf("You entered %d elements:\n", array_size);
    print_array(array, array_size);

    double sum = sum_greater_than_e(array, array_size);
    printf("Sum of elements greater than e: %lf\n", sum);

    return 0;
}
