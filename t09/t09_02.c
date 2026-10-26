#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 100

int input_to_store_int_array(int* arr) {
    int n = 0;
    int x;

    while (n < MAX_ARRAY_SIZE) {
        printf("Enter element %d (0 to stop): ", n + 1);
        scanf("%d", &x);

        if (x == 0) break;

        arr[n] = x;
        n++;
    }
    return n;
}

void print_int_array(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

bool is_sqr(int x) {
    if (x < 0) return false;
    int root = (int)sqrt(x + 0.5);
    return root * root == x;
}

bool is_cube(int x) {
    int root = (int)cbrt(x + 0.5); // cbrt - cube root
    return root * root * root == x;
}

void print_sqr_and_cube_elements(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (is_sqr(arr[i])) {
            printf("%d is a perfect square\n", arr[i]);
        }

        if (is_cube(arr[i])) {
            printf("%d is a perfect cube\n", arr[i]);
        }
    }
}

int main() {
    int* arr = (int*)malloc(MAX_ARRAY_SIZE * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    int n = input_to_store_int_array(arr);

    printf("The elements of the array are:\n");
    print_int_array(arr, n);

    print_sqr_and_cube_elements(arr, n);

    // Free the allocated memory
    free(arr);

    return EXIT_SUCCESS;
}