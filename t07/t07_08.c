#include <stdio.h>
#include <stdlib.h>

int is_fibonacci(int num) {
    if (num < 0) return 0;
    if (num == 0 || num == 1) return 1;

    int a = 0;
    int b = 1;
    int c = a + b;

    while (c < num) {
        a = b;
        b = c;
        c = a + b;
    }

    return (c == num);
}

int input_array_int(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d]= ", i + 1);
        int result_input = scanf("%d", &array[i]);
        if (result_input != 1) {
            printf("Invalid input\n");
            return i;
        }
    }
    return size;
}

void task8() {
    int size;
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Error: Invalid dimension\n");
        return;
    }

    int array[size];

    int d1 = input_array_int(array, size);
    if (d1 != size) {
        printf("Error: Array input mismatch\n");
        return;
    }

    int fib_count = 0;
    for (int i = 0; i < size; i++) {
        if (is_fibonacci(array[i])) {
            fib_count++;
        }
    }

    printf("Number of Fibonacci numbers in the array: %d\n", fib_count);
}

int main() {
    task8();
    return 0;
}