#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 5

int input_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        int result_input = scanf("%d", &array[i]);
        if (result_input != 1) {
            printf("Invalid input. Please enter an integer.\n");
            return i;
        }
    }
    return size;
}

int count_numbers_less_than(int array[], int size, double a) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < a) {
            count++;
        }
    }
    return count;
}

int main() {
    int array[ARRAY_SIZE];
    input_array(array, ARRAY_SIZE);

    double a;
    printf("Enter a number: ");
    if (scanf("%lf", &a) != 1) {
        return 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] < a) {
            printf("%d is less than %.2lf\n", array[i], a);
        }
    }

    int total = count_numbers_less_than(array, ARRAY_SIZE, a);
    printf("Total numbers less than %.2lf (using function): %d\n", a, total);

    return 0;
}
